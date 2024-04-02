/* st_intf - streaming interface

Synthesizable interface definition of a ready/valid streaming interface.

Parameters:
    data_t: type of the interface's data signal.

Signals:
    ready: signal driven up when slave modport is ready to receive data.
    valid: signal driven up when the master modport module is sending data.
    data: signal of type data_t driven by the master modport.

Modports:
    master: Master modport for sender/producer modules.
    slave: Slave modport for receiver/consumer modules.
*/
interface st_intf
#(
    parameter type data_t = logic
)
(
);
    logic ready;
    logic valid;
    data_t data;

    modport master (input  ready ,
                    output valid , data   );

    modport slave  (input  valid , data ,
                    output ready          );

endinterface


/* st_pkt_intf - streaming packet interface

Synthesizable interface definition of a ready/valid streaming packet interface.

Generics:
    WIDTH : WIDTH of data signal.

Signals:
    ready: signal driven up when slave modport is ready to receive data.
    valid: signal driven up when the master modport module is sending data.
    data: signal of width WIDTH driven by the master modport.
    len: signal of width log2(WIDTH/8) driven by the master modport.
        It represents the number of bytes valid in the data signal.
        len is zero when all bytes are enabled. All bytes in the data signal must be valid
        throught the packet transmision and only the last word is allowed to have
        a different number of enabled bytes.
    sop: signal driven up for one cycle at the beginning of the packet by the master modport.
    eop: signal driven up for one cycle at the end of the packet by the master modport.

Modports:
    master: Master modport for sender/producer modules.
    slave: Slave modport for receiver/consumer modules.
*/
interface st_pkt_intf
#(
    parameter WIDTH = 32
)
(
);
    logic                       ready ;
    logic                       valid ;
    logic                       sop   ;
    logic                       eop   ;
    logic[WIDTH-1:0]            data  ;
    logic[$clog2(WIDTH/8)-1:0]  len   ;

    modport master(input  ready ,
                   output valid , sop   ,
                          eop   , data  ,
                          len           );

    modport slave (input  valid , sop   ,
                          eop   , data  ,
                          len   ,
                   output ready         );

endinterface
