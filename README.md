# RISCV-VP
Am instruction set simulator based on DBT-RISE implementing the RISC-V ISA. The project is hosted at https://git.minres.com/DBT-RISE/DBT-RISE-RISCV .

**RISCV-VP README**

This is work in progress, so use at your own risk. Goal is to implement an open-source ISS which can easily embedded e.g. into SystemC Virtual Prototypes. It uses code generation to allow easy extension and adaptation of the used instruction. Please see also [https://git.minres.com/DBT-RISE/DBT-RISE-RISCV](https://git.minres.com/DBT-RISE/DBT-RISE-RISCV)
The RISC-V ISS reaches about 65MIPS running on a decent Intel Processor.

The implementation is based on LLVM > v4.0. Eclipse CDT 4.7 (Oxygen) is recommended as IDE.

RISCV-VP uses libGIS (https://github.com/vsergeev/libGIS) as well as ELFIO (http://elfio.sourceforge.net/), both under MIT license 


**Quick start**

* you need to have a C++11 capable compiler (e.g. gcc >= 4.8), make, python, and cmake installed
* install LLVM >= 4.0 according to http://apt.llvm.org/ (if it is not already provided by your distribution e.g by Ubuntu 18.04)
* install conan.io (see also http://docs.conan.io/en/latest/installation.html):
```
    pip install conan
```
* setup conan to use the minres repo:
```
    conan remote add minres https://api.bintray.com/conan/minres/conan-repo
    conan remote add bincrafters https://api.bintray.com/conan/bincrafters/public-conan
```
* checkout source from git
* start an out-of-source build:
```
    cd RISCV-VP
    mkdir build
    cd build
    cmake ..
    cmake --build .
```
* if you encounter issues when linking wrt. c++11 symbols you might have run into GCC ABI incompatibility introduced from GCC 5.0 onwards. You can fix this by adding '-s compiler.libcxx=libstdc++11' to the conan call or changing compiler.libcxx to
```
compiler.libcxx=libstdc++11
```
in $HOME/.conan/profiles/default

** Detailed Setup steps**

*** prepare Ubuntu 18.04 ***

```
    sudo apt-get install -y git python-pip build-essential cmake libloki-dev zlib1g-dev libncurses5-dev \	
        libboost-dev libboost-program-options-dev libboost-system-dev libboost-thread-dev llvm-dev llvm-doc
    pip install --user conan
```

*** prepare Fedora 28 ***

```
    #prepare system
    dnf install @development-tools gcc-c++ boost-devel zlib-devel loki-lib-devel cmake python2 python3 llvm-devel llvm-static
    #install conan
    pip3 install --user conan
    export PATH=${PATH}:$HOME/.local/bin
```
 
*** Build the ISS ***

```
    # configure conan
    conan remote add minres https://api.bintray.com/conan/minres/conan-repo
    conan remote add bincrafters https://api.bintray.com/conan/bincrafters/public-conan
    conan profile new default --detect
    # clone and build DBT-RISE-RISCV
    git clone --recursive https://github.com/Minres/DBT-RISE-RISCV.git
    cd DBT-RISE-RISCV/
    git checkout develop
    mkdir build;cd build
    MAKE_FLAGS="-j4" cmake ..
    make -j4
```
