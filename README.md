# HIFIVE1-VP

An instruction set simulator based on DBT-RISE implementing the RISC-V ISA. The project is hosted at https://github.com/Minres/HIFIVE1-VP.

## HIFIVE1-VP README

This is work in progress, so use at your own risk. Goal is to implement an open-source ISS which can easily embedded e.g. into SystemC Virtual Prototypes. It uses code generation to allow easy extension and adaptation of the used instruction. Please see also [https://github.com/Minres/DBT-RISE-RISCV](https://github.com/Minres/DBT-RISE-RISCV)
The RISC-V ISS reaches about 65MIPS running on a decent Intel Processor.

HIFIVE1-VP uses libGIS (https://github.com/vsergeev/libGIS) under MIT license 

## Setup steps

* you need to have a C++11 capable compiler (e.g. gcc >= 4.8), make, python, and cmake installed
* install conan.io (see also http://docs.conan.io/en/latest/installation.html):

### prepare Ubuntu 18.04/20.04

```
sudo apt-get install -y git python3-pip build-essential cmake libloki-dev zlib1g-dev libncurses5-dev \	
    libboost-dev libboost-program-options-dev libboost-system-dev libboost-thread-dev llvm-dev llvm-doc
pip3 install --user conan
```

### prepare Fedora 28

```
#prepare system
dnf install @development-tools gcc-c++ boost-devel zlib-devel loki-lib-devel cmake python2 python3 llvm-devel llvm-static
#install conan
pip3 install --user conan
export PATH=${PATH}:$HOME/.local/bin
```
 
### Build the ISS

```
# checkout source from git: 
git clone --recursive https://github.com/Minres/HIFIVE1-VP.git
# build ISS:
cd HIFIVE1-VP
cmake -S . -B build
cmake --build build -j8
```

### Build the ISS

```
build/platform/src/riscv-vp <elf file> -v4 -m 500ms

```
