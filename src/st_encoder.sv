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

    st_intf.slave       i_msg_type,

    input fields_t      i_fields,

    st_pkt_intf.master  o_pkt_intf
);


endmodule


The input field i_fields should contain all the fields necessary to encode a given message type.
If you generate the encoder for message udp_msg1, you should only have the fields from that message.
The example generated st_encoder_pkg, creates the type of i_fields for the message udp_msg1.

The interface st_intf takes as a parameter the type of the data field. The default value is logic, but for the exercise
you should create and instance the interface with the correct type - msg_type_supported_t.
