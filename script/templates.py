class interface:
    '''
    Provides the templates for the raw fields interface of the encoder.
    '''
    
    header = '''//****************************************************//
//     AUTOMATICALLY GENERATED FILE - DO NOT EDIT     //
//****************************************************//

package st_encoder_pkg;
    
    typedef logic[7:0] msg_type_t;
    '''
    
    msg_type = '''{name} = {index}'''

    types_enum = '''
    typedef enum logic[7:0] {{ 
        {types} 
    }} msg_type_supported_t;
    '''

    type_struct = '''
    typedef struct packed {{ {fields}
    }} fields_t;
endpackage
    '''
    
    union = '''
    union packed {{ 
        {data_fields}
        logic [{tsize}:0][7:0] bytes;
    }} fields_bytes_t;
    '''

    state = '{name}_w{n}'

    states = '''
    typedef enum {{ 
        {valid_states}
    }} stateCoding_t;
    '''

    data_field = '''logic[{size}:0][7:0] {name};'''

    fields = '''\n\t\tlogic {name}_avail;\n\t\tlogic[{size}:0][7:0] {name};'''

Little = 0
Big = 1

class encoder():
    # default states (idle, reset) are fixed 
    def __init__(self, tsize, states):  
        field_byte = 'fields_bytes.bytes[{n}]'
        self.field_bytes = [field_byte.format(i) for i in range(tsize, -1, -1)]
        self.states = states

    def get_field_bytes(self):
        fields = self.field_bytes[:4]
        self.field_bytes = self.field_bytes[4:]
        pad = ["8h00"] * (4 - len(fields))
        return ','.join(pad + fields)
    

    '''
    Provides the templates for the encoder.
    '''
    header = '''//****************************************************//
//     AUTOMATICALLY GENERATED FILE - DO NOT EDIT     //
//****************************************************//

/* Streaming encoder

The streaming encoder serializes a subset of the available fields
at specific offsets defined by the packet template of the chosen
message type.

Generics:

Inputs:
    i_msg_type: Input streaming interface with the type of the message to be serialized.
        When the a message type is received, the module starts to encode and serialize
        the fields of the message into a packet. The ready of the interface is down
        while the module is encoding a message. Message types not encodable by the module,
        are ignored.

    i_fields: struct with all fields for a given set of messages and their
        respective available signals. The *_avail signal is set high, for one cycle, in the cycle
        the field becomes available. The field stays constant until the i_msg_type.ready is set high.
        Fields start to become available in the cycle the msg_type is consumed.

Outputs:
    o_pkt_intf: output packet interface with the serialized message
        The valid signal cannot drop while the packet is not completely
        transmitted - valid must remain up between sop and eop being set.
*/

module st_encoder
    import st_encoder_pkg::*;
#(
)
(
    input               rst_n,
    input               clk,

    st_intf.slave #(.data_t (msg_type_supported_t))      i_msg_type,

    input fields_t      i_fields,

    st_pkt_intf.master  o_pkt_intf
);
    '''

    field_avail = ''''logic {field}_avail;'''

    internals = '''
    msg_type_supported_t msg_type_supported;
    logic sop, eop, valid;
    logic[WIDTH-1:0] data;
    logic[$clog2(WIDTH/8)-1:0] len;

    fields_bytes_t fields_bytes;

    logic[31:0] counter;
    logic pkt_valid;
    stateCoding_t state, nextstate;

    {fields_avails}
'''

    initials = '''
    initial msg_type_supported = {supported_msg_type};
    initial fields_bytes = '0;

    assign i_msg_type.ready = !pkt_valid;
    assign o_pkt_intf.sop = sop;
    assign o_pkt_intf.valid = valid;
    assign o_pkt_intf.eop = eop;
    assign o_pkt_intf.len = len;
    assign o_pkt_intf.data = valid ? data : '0;
'''

    fsm_start = '''
    // counter
    always_ff @(posedge clk) begin
        if (!rst_n)
            counter <= 0;
        else
            if (pkt_valid)
                counter <= counter + 1;
            else
                counter <= 0;
    end

    // update serial field
    always_ff @(posedge clk) begin
        if (!rst_n)
            state <= rst;
        else
            state <= nextstate;
    end
'''

    update_fields = '''
                if (i_fields.{field}_avail)
                begin
                    {field}_avail <= 1;
                    fields_bytes.data.{field} <= i_fields.{field};
                end
'''

    avail_reset = '''{field}_avail <= 0;'''

    update_avails = '''
    // update avail fields
    always_ff @(posedge clk) begin
        if (!rst_n)
        begin
            {avail_fields_reset}
        end
        else
            if (((i_msg_type.data == msg_type_supported) && i_msg_type.valid) || pkt_valid)
            begin
                {update_fields}
            end else begin
                {avail_fields_reset}
            end
    end
'''
    pkt_start_s = '''
            pkt_start:
            begin
                if (counter < {pkt_ready}) // wait to guarantee that all fields get registered before sending
                    nextstate = pkt_start;
                else begin
                    if (o_pkt_intf.ready && {first_field}_avail)
                        nextstate = {first_field};
                    else begin
                        nextstate = idle;
                        pkt_valid = 0;
                    end
                end
            end
'''

    first_field_s = '''
            {first_field}:
            begin
                if (o_pkt_intf.ready && {next_field}_avail) begin
                    sop = 1;
                    valid = 1;
                    len = 0;
                    data = {{{field_bytes}}};
                    nextstate = {next_state};
                end else begin
                    valid = 0;
                    eop = 1;
                    nextstate = idle;
                    pkt_valid = 0;
                end
            end
'''

    field_word_s = '''
            {field_word}:
            begin
                sop = 0;
                if (o_pkt_intf.ready) begin
                    data = {{{field_bytes}}};
                    nextstate = {next_state};
                end else begin
                    valid = 0;
                    eop = 1;
                    nextstate = idle;
                    pkt_valid = 0;
                end
            end
'''

    last_field_word_s = '''
            {field_word}:
            begin
                sop = 0;
                if (o_pkt_intf.ready && {next_field}_avail) begin
                    data = {{{field_bytes}}};
                    nextstate = {next_state};
                end else begin
                    valid = 0;
                    eop = 1;
                    nextstate = idle;
                    pkt_valid = 0;
                end
            end
'''

    fields_s = '''
            {field}:
            begin
                sop = 0;
                if (o_pkt_intf.ready) begin
                    data = {{{field_bytes}}};
                    nextstate = {next_field};
                end else begin
                    valid = 0;
                    eop = 1;
                    nextstate = idle;
                    pkt_valid = 0;
                end
            end
'''

    last_field = '''
            {field}:
            begin
                nextstate = idle;
                eop = 1;
                if (o_pkt_intf.ready) begin
                    len = {len};
                    data = {{{field_bytes}}};
                end else begin
                    valid = 0;
                    pkt_valid = 0;
                end
            end
'''

    fsm_outputs = '''
    // update nextfield
    always_comb begin
        case (state)
            rst:
            begin
                data = '0;
                sop = 0;
                valid = 0;
                eop = 0;
                pkt_valid = 0;
                len = '0;
                nextstate = idle;
            end
            idle:
            begin
                data = '0;
                sop = 0;
                valid = 0;
                eop = 0;
                pkt_valid = 0;
                len = '0;
                if (i_msg_type.data == msg_type_supported && i_msg_type.valid) begin
                    pkt_valid = 1;
                    nextstate = pkt_start;
                end
            end
            {pkt_start_s}
            {first_field_s}
            {field_s}
            {last_field}
        endcase
    end
'''