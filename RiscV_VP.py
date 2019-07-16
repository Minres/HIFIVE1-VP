import os.path
import logging
import cppyy
from cppyy import gbl as cpp
from array import array
import pysysc
from pysysc.structural import Connection, Module, Signal, Simulation

###############################################################################
# setup  and load
###############################################################################
logging.basicConfig(level=logging.INFO)
build_type='Debug'
###############################################################################
myDir = os.path.dirname( os.path.realpath(__file__))
pysysc.read_config_from_conan(os.path.join(myDir, 'conanfile.txt'), build_type)
pysysc.load_systemc()
###############################################################################
logging.debug("Loading Components lib")
pysysc.add_include_path(os.path.join(myDir, 'scc/incl'))
pysysc.add_include_path(os.path.join(myDir, 'dbt-core/incl'))
pysysc.add_include_path(os.path.join(myDir, 'riscv/incl'))
pysysc.add_include_path(os.path.join(myDir, 'platform/incl'))
pysysc.add_library('sysc/top/system.h', os.path.join(myDir, 'build/%s/lib/libplatform.so'%build_type))
cppyy.include("iss/llvm/jit_helper.h")
cppyy.include("scc/configurer.h")
cppyy.include("sysc/top/system.h")
###############################################################################
# configure
###############################################################################
Simulation.setup(logging.root.level)
cpp.iss.init_jit();
cfg=cpp.scc.configurer("system.json");
###############################################################################
# instantiate
###############################################################################
dut = Module(cpp.sysc.system).create("i_system")
cfg.set_value("i_system.i_hifive1.i_fe310.i_core_complex.elf_file", "../RISCV-Tests/hello/hello");
of=cpp.std.ofstream("hier.txt")
cfg.dump_configuration(of);
of.close()
###############################################################################
# run if it is standalone
###############################################################################
if __name__ == "__main__":
    Simulation.configure(enable_vcd=False)
    Simulation.run()
    logging.debug("Done")
