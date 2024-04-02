//****************************************************//
//     AUTOMATICALLY GENERATED FILE - DO NOT EDIT     //
//****************************************************//

package st_encoder_pkg;
    
    typedef logic[7:0] msg_type_t;
    
    typedef enum logic[7:0] { 
        msg3 = 4 
    } msg_type_supported_t;
    
    typedef enum { 
		rst,
		idle,
		pkt_start,
		field6,
		field7,
		field8,
		field9
	} stateCoding_t;

	typedef struct packed {
		logic[2:0][7:0] field9;
		logic[3:0][7:0] field8;
		logic[3:0][7:0] field7;
        logic[3:0][7:0] field6;
	} fields_data_t;

    typedef union packed { 
		fields_data_t data;
        logic [15:0][7:0] bytes;
    } fields_bytes_t;

    typedef struct packed { 
		logic field6_avail;
		logic[3:0][7:0] field6;
		logic field7_avail;
		logic[3:0][7:0] field7;
		logic field8_avail;
		logic[3:0][7:0] field8;
		logic field9_avail;
		logic[2:0][7:0] field9;
    } fields_t;
endpackage
