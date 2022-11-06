cmake_minimum_required(VERSION 3.12)
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} ${CMAKE_CURRENT_SOURCE_DIR}/cmake ${CMAKE_CURRENT_SOURCE_DIR}/scc/cmake)

project(RISCV-VP VERSION 1.0.0 LANGUAGES CXX)

set(ENABLE_SCV TRUE CACHE BOOL "Enable use of SCV")

set(ENABLE_SHARED TRUE CACHE BOOL "Build shared libraries")

set(WITH_LLVM FALSE CACHE BOOL "Build LLVM based backend")

include(GNUInstallDirs)
#include(Submodules)
include(Conan)

#enable_testing() 

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_POSITION_INDEPENDENT_CODE ON)

include(CheckCXXCompilerFlag)
CHECK_CXX_COMPILER_FLAG("-march=native" COMPILER_SUPPORTS_MARCH_NATIVE)
if(COMPILER_SUPPORTS_MARCH_NATIVE)
	if("${CMAKE_BUILD_TYPE}" STREQUAL "") 
	    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -march=native")
	elseif(NOT(${CMAKE_BUILD_TYPE} STREQUAL "RelWithDebInfo"))
	    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -march=native")
	endif()
endif()

if ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "GNU" OR "${CMAKE_CXX_COMPILER_ID}" STREQUAL "Clang")
    set(warnings "-Wall -Wextra -Werror")
    #set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -D_GLIBCXX_USE_CXX11_ABI=0")
    set(CMAKE_CXX_FLAGS_RELEASE "-O3 -DNDEBUG")
    set(CMAKE_C_FLAGS_RELEASE "-O3 -DNDEBUG")
elseif ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "MSVC")
    set(warnings "/W4 /WX /EHsc")
endif()

include(GNUInstallDirs)
include(ConanInline)

set(CONAN_BOOST_OPTIONS
boost:fPIC=True
boost:shared=True
boost:header_only=False 
boost:without_contract=True
boost:without_graph=True
boost:without_graph_parallel=True
boost:without_iostreams=True
boost:without_json=True
boost:without_locale=True
boost:without_log=True
boost:without_math=True
boost:without_mpi=True
boost:without_nowide=True
boost:without_python=True
boost:without_random=True
boost:without_regex=True
boost:without_stacktrace=True
boost:without_test=True
boost:without_timer=True
boost:without_type_erasure=True
boost:without_wave=True
)

set(B2_VERSION 4.8.0)
set(CONAN_PACKAGE_LIST fmt/6.1.2 zlib/1.2.11 b2/${B2_VERSION} boost/1.75.0 gsl-lite/0.37.0 elfio/3.8 seasocks/1.4.4)

set(CONAN_PACKAGE_OPTIONS seasocks:shared=True fmt:header_only=True ${CONAN_BOOST_OPTIONS})
if(FORCE_SYSTEMC OR NOT DEFINED ENV{SYSTEMC_HOME})
    list(APPEND CONAN_PACKAGE_LIST systemc/2.3.3 systemc-cci/1.0.0)
    list(APPEND CONAN_PACKAGE_OPTIONS systemc-cci:shared=False)
endif()

conan_check()
conan_add_remote(NAME minres URL https://git.minres.com/api/packages/Tooling/conan)

# Boost on CentOS 7 quirks: the b2 of conan-center is build against a newer libstdc++ and therefore does not run
# with the oooooold libs on CentOS 7. Therefore we build our own version of b2 if it is not there
set(B2_META $ENV{HOME}/.conan/data/b2/${B2_VERSION}/_/_/metadata.json)
if(DEFINED ENV{CONAN_USER_HOME})
	set(B2_META $ENV{CONAN_USER_HOME}/.conan/data/b2/${B2_VERSION}/_/_/metadata.json)
endif()
if(NOT EXISTS ${B2_META})
	conan_configure(REQUIRES b2/${B2_VERSION})
	conan_cmake_autodetect(settings)
	conan_cmake_install(PATH_OR_REFERENCE . BUILD b2 SETTINGS ${settings})
endif()
# Boost on CentOS 7 quirks end

conan_cmake_configure(REQUIRES ${CONAN_PACKAGE_LIST}
                      GENERATORS cmake_find_package cmake
                      OPTIONS ${CONAN_PACKAGE_OPTIONS}
                      )

conan_install()
# forca a local build of tcc to make sure path to libtcc1.a is correct
conan_configure(REQUIRES tcc/0.9.27)
conan_cmake_autodetect(settings)
set(settings ${settings} compiler.cppstd=${CMAKE_CXX_STANDARD})
conan_cmake_install(PATH_OR_REFERENCE . BUILD tcc SETTINGS ${settings})

#conan_setup(TARGETS)
include(conanbuildinfo)
find_package(tcc)
find_package(elfio)
find_package(fmt)
find_package(gsl-lite)
find_package(ZLIB)
find_package(Seasocks)
find_package(Threads REQUIRED)

# This line finds the boost lib and headers. 
set(Boost_NO_BOOST_CMAKE ON) #  Don't do a find_package in config mode before searching for a regular boost install.
set(BOOST_ROOT ${CONAN_BOOST_ROOT})

find_package(Threads)
find_package(Tcmalloc)
find_package(ZLIB)
find_package(OSCISystemC)
if(SystemC_FOUND)
        message(STATUS "SystemC headers at ${SystemC_INCLUDE_DIRS}")
        message(STATUS "SystemC library at ${SystemC_LIBRARY_DIRS}")
        if(SCV_FOUND)
            message(STATUS "SCV headers at ${SCV_INCLUDE_DIRS}")
            message(STATUS "SCV library at ${SCV_LIBRARY_DIRS}")
        endif(SCV_FOUND)
        if(CCI_FOUND)
            message(STATUS "CCI headers at ${CCI_INCLUDE_DIRS}")
            message(STATUS "CCI library at ${CCI_LIBRARY_DIRS}")
        endif()
endif(SystemC_FOUND)

#find_package(Verilator)
if(VERILATOR_FOUND)
	message(STATUS "Verilator found at ${VERILATOR_EXECUTABLE}")
else()
	message(STATUS "Verilator not found, omitting RTL parts in build")
endif()

set(PROJECT_3PARTY_DIRS external)
include(clang-format)

set(ENABLE_CLANG_TIDY OFF CACHE BOOL "Add clang-tidy automatically to builds")
if (ENABLE_CLANG_TIDY)
    find_program (CLANG_TIDY_EXE NAMES "clang-tidy" PATHS /usr/local/opt/llvm/bin )
    if (CLANG_TIDY_EXE)
        message(STATUS "clang-tidy found: ${CLANG_TIDY_EXE}")
        set(CLANG_TIDY_CHECKS "-*,modernize-*")
        set(CMAKE_CXX_CLANG_TIDY "${CLANG_TIDY_EXE};-checks=${CLANG_TIDY_CHECKS};-header-filter='${CMAKE_SOURCE_DIR}/*';-fix"
            CACHE STRING "" FORCE)
    else()
        message(AUTHOR_WARNING "clang-tidy not found!")
        set(CMAKE_CXX_CLANG_TIDY "" CACHE STRING "" FORCE) # delete it
    endif()
endif()
  
add_subdirectory(external)
add_subdirectory(dbt-rise-core)
add_subdirectory(dbt-rise-riscv)
add_subdirectory(scc)
add_subdirectory(platform)
