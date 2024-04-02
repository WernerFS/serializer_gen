import st_encoder_pkg::*;

module top_module 
    #(
        parameter WIDTH = 32
    )   
    (
        input logic rst_n,
        input logic clk,

        input logic i_fields_field6_avail,
		input logic[3:0][7:0] i_fields_field6,
		input logic i_fields_field7_avail,
		input logic[3:0][7:0] i_fields_field7,
		input logic i_fields_field8_avail,
		input logic[3:0][7:0] i_fields_field8,
		input logic i_fields_field9_avail,
		input logic[2:0][7:0] i_fields_field9
        );

    // Instantiate interfaces

    st_intf #(.data_t(msg_type_supported_t)) i_msg_intf();
    st_pkt_intf o_pkt_intf();

    fields_t i_fields;

    assign i_fields.field6_avail = i_fields_field6_avail;
    assign i_fields.field6 = i_fields_field6;
    assign i_fields.field7_avail = i_fields_field7_avail;
    assign i_fields.field7 = i_fields_field7;
    assign i_fields.field8_avail = i_fields_field8_avail;
    assign i_fields.field8 = i_fields_field8;
    assign i_fields.field9_avail = i_fields_field9_avail;
    assign i_fields.field9 = i_fields_field9;

    st_encoder #() st_encoder_inst (
        .rst_n(rst_n),
        .clk(clk),
        .i_msg_type(i_msg_intf),
        .i_fields(i_fields),
        .o_pkt_intf(o_pkt_intf)
    );

endmodule
