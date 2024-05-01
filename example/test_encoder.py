import cocotb
from cocotb.triggers import Timer, RisingEdge, ClockCycles
from cocotb_bus.drivers import BusDriver
from cocotb.clock import Clock

sep = '\n'.join(['-'*20, ''])

size = [4,4,4,3]
avail_cycl = [2,4,1,3]
tvals = ['A', 'B', 'C', 'D', 'E', 'F']
expected_value = []
for i, s in enumerate(size):
    expected_value.append(int(tvals[i % len(tvals)]*s, 16))

def sb_fn(actual_value):
    if len(expected_value) > 0:
        assert hex(actual_value) == hex(expected_value.pop(0)), "Scoreboard Matching Failed"

def dump(obj):
  for attr in dir(obj):
    print("obj.%s = %r" % (attr, getattr(obj, attr)))

@cocotb.test()
async def ifc_test(dut):
    fields = i_fields(dut, 'i_fields', dut.clk)
    cocotb.start_soon(Clock(dut.clk, 10, units="ns").start())
    await RisingEdge(dut.clk)
    dut.rst_n.value = 1
    await RisingEdge(dut.clk)
    dut.rst_n.value = 0
    await RisingEdge(dut.clk)
    dut.rst_n.value = 1

    dut.o_pkt_intf.ready.value = 1

    for i in range(4):
        await RisingEdge(dut.clk)

    await i_msg_intf(dut.i_msg_intf, dut.clk, 4, fields)
    await RisingEdge(dut.o_pkt_intf.sop)
    await o_pkt_intf(dut.o_pkt_intf, dut.clk, sb_fn)

async def i_msg_intf(intf, clk, value, fields):
    intf.valid.value = 0
    if intf.ready.value != 1:
        await RisingEdge(intf.ready)
    fields.load_fields()
    await RisingEdge(clk)
    intf.valid.value = 1
    intf.data.value = value
    await RisingEdge(clk)
    intf.valid.value = 0
    intf.data.value = 0

class i_fields(BusDriver):
    _signals = ['field6_avail','field6','field7_avail','field7','field8_avail','field8','field9_avail','field9']

    def __init__(self, dut, name, clk):
        BusDriver.__init__(self, dut, name, clk)
        self.bus.field6_avail = 0
        self.bus.field7_avail = 0
        self.bus.field8_avail = 0
        self.bus.field9_avail = 0
        self.clk = clk
        self.avails = [self._signals[i] for i in range(0, len(self._signals), 2)]
        self.data = [self._signals[i] for i in range(1, len(self._signals), 2)]

    @cocotb.coroutine
    async def load_field(self, value, cycle, field_avail, field, size):
        await ClockCycles(self.clk, cycle)
        field_avail.value = 1
        field.value = int(value * size, 16)
        await RisingEdge(self.clk)
        field_avail.value = 0
        await RisingEdge(self.clk)

    def load_fields(self):
        for i, cyc in enumerate(avail_cycl):
            cocotb.start_soon(self.load_field(tvals[i % len(tvals)], cyc, self.bus._signals[self.avails[i]], self.bus._signals[self.data[i]], size[i]))

async def o_pkt_intf (intf, clk, sb_fn) :
    while intf.valid == 1:
        await RisingEdge(clk)
        sb_fn(intf.data.value)