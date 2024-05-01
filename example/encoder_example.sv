import st_encoder_pkg::*;

module st_encoder

#(
    parameter WIDTH = 32
)
(
    input               rst_n,
    input               clk,

    st_intf.slave       i_msg_type,

    input fields_t      i_fields,

    st_pkt_intf.master  o_pkt_intf
);

    msg_type_supported_t msg_type_supported;
    logic sop, eop, valid;
    logic[WIDTH-1:0] data;
    logic[$clog2(WIDTH/8)-1:0] len;
    
    fields_bytes_t fields_bytes;
    
    logic[31:0] counter;
    logic pkt_valid;
    stateCoding_t state, nextstate;
    
    logic field6_avail;
    logic field7_avail;
    logic field8_avail;
    logic field9_avail;
    
    initial msg_type_supported = msg3;
    initial fields_bytes = '0;

    assign i_msg_type.ready = !pkt_valid;
    assign o_pkt_intf.sop = sop;
    assign o_pkt_intf.valid = valid;
    assign o_pkt_intf.eop = eop;
    assign o_pkt_intf.len = len;
    assign o_pkt_intf.data = valid ? data : '0;

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

    // update avail fields
    always_ff @(posedge clk) begin
        if (!rst_n)
        begin
            field6_avail <= 0;
            field7_avail <= 0;
            field8_avail <= 0;
            field9_avail <= 0;
        end
        else
            if (((i_msg_type.data == msg_type_supported) && i_msg_type.valid) || pkt_valid)
            begin
                if (i_fields.field6_avail)
                begin
                    field6_avail <= 1;
                    fields_bytes.data.field6 <= i_fields.field6;
                end
                if (i_fields.field7_avail)
                begin
                    field7_avail <= 1;
                    fields_bytes.data.field7 <= i_fields.field7;
                end
                if (i_fields.field8_avail)
                begin
                    field8_avail <= 1;
                    fields_bytes.data.field8 <= i_fields.field8;
                end
                if (i_fields.field9_avail)
                begin
                    field9_avail <= 1;
                    fields_bytes.data.field9 <= i_fields.field9;
                end
            end else begin
                field6_avail <= 0;
                field7_avail <= 0;
                field8_avail <= 0;
                field9_avail <= 0;
            end
    end

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
            pkt_start: 
            begin
                if (counter < 3) // wait to guarantee that all fields get registered before sending
                    nextstate = pkt_start;
                else begin
                    if (o_pkt_intf.ready && field6_avail) 
                        nextstate = field6;
                    else begin
                        nextstate = idle;
                        pkt_valid = 0;
                    end
                end
            end
            field6:
            begin
                if (o_pkt_intf.ready && field7_avail) begin 
                    sop = 1;
                    valid = 1;
                    len = 0;
                    data = {fields_bytes.bytes[3], fields_bytes.bytes[2], fields_bytes.bytes[1] ,fields_bytes.bytes[0]};
                    nextstate = field7;
                end else begin
                    valid = 0;
                    eop = 1;
                    nextstate = idle;
                    pkt_valid = 0;
                end
            end
            field7:
            begin
                sop = 0;
                if (o_pkt_intf.ready && field8_avail) begin
                    data = {fields_bytes.bytes[7], fields_bytes.bytes[6], fields_bytes.bytes[5] ,fields_bytes.bytes[4]};
                    nextstate = field8;
                end else begin
                    valid = 0;
                    eop = 1;
                    nextstate = idle;
                    pkt_valid = 0;
                end
            end
            field8:
            begin
                sop = 0;
                if (o_pkt_intf.ready && field9_avail) begin
                    data = {fields_bytes.bytes[11], fields_bytes.bytes[10], fields_bytes.bytes[9] ,fields_bytes.bytes[8]};
                    nextstate = field9;
                end else begin
                    valid = 0;
                    eop = 1;
                    nextstate = idle;
                    pkt_valid = 0;
                end
            end
            field9:
            begin
                nextstate = idle;
                eop = 1;
                if (o_pkt_intf.ready) begin
                    len = 3;
                    data = {8'h00, fields_bytes.bytes[14], fields_bytes.bytes[13], fields_bytes.bytes[12]};
                end else begin
                    valid = 0;
                    pkt_valid = 0;
                end
            end
        endcase
    end
    
    `ifdef FORMAL
        always @(posedge clk) begin
            if(!rst) begin
                i_msg_ready: assert(i_msg_type.ready == 0);

                sop: assert(o_pkt_intf.sop == 0);
                eop: assert(o_pkt_intf.eop == 0);
                data: assert(o_pkt_intf.data == '0);
                valid: assert(o_pkt_intf.valid == '0);

                counter: assert(counter == 0);
                pkt_valid: assert(pkt_valid == '0);
                state: assert(state == idle);
            end
        end
    `endif

endmodule;