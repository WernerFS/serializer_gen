SIM ?= verilator
TOPLEVEL_LANG ?= verilog

VERILOG_SOURCES += $(PWD)/msg3.sv
VERILOG_SOURCES += $(PWD)/src/st_intf.sv
VERILOG_SOURCES += $(PWD)/encoder_example.sv
VERILOG_SOURCES += $(PWD)/top.sv

# set precision
#COCOTB_HDL_TIMEPRECISION ?= 1ns

EXTRA_ARGS += --trace

encoder:
	$(MAKE) sim MODULE=test_encoder TOPLEVEL=top_module
include $(shell cocotb-config --makefiles)/Makefile.sim