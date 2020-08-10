cmake_minimum_required(VERSION 3.12)
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} ${CMAKE_CURRENT_SOURCE_DIR}/cmake ${CMAKE_CURRENT_SOURCE_DIR}/scc/cmake)

project(RISCV-VP VERSION 1.0.0 LANGUAGES CXX)

set(ENABLE_SCV TRUE CACHE BOOL "Enable use of SCV")

set(ENABLE_SHARED TRUE CACHE BOOL "Build shared libraries")

set(WITH_LLVM FALSE CACHE BOOL "Build LLVM based backend")

include(GitFunctions)
get_branch_from_git()
# if we are not on master or develop set the submodules to develop
#IF(NOT ${GIT_BRANCH} MATCHES "master") 
#	IF(NOT ${GIT_BRANCH} MATCHES "develop") 
#		message(STATUS "main branch is '${GIT_BRANCH}', setting submodules to 'develop'")
#		set(GIT_BRANCH develop)
#	endif()
#endif()

### set the directory names of the submodules
set(GIT_SUBMODULES elfio libGIS scc dbt-core)
set(GIT_SUBMODULE_DIR_scc .)
set(GIT_SUBMODULE_DIR_dbt-core .)
set(GIT_SUBMODULE_DIR_riscv .)
### set each submodules's commit or tag that is to be checked out
### (leave empty if you want master)
#set(GIT_SUBMODULE_VERSION_sc-comp 3af6b9836589b082c19d9131c5d0b7afa8ddd7cd)
set(GIT_SUBMODULE_BRANCH_scc ${GIT_BRANCH})
set(GIT_SUBMODULE_BRANCH_dbt-core ${GIT_BRANCH})
set(GIT_SUBMODULE_BRANCH_riscv ${GIT_BRANCH})

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

setup_conan(TARGETS)

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
add_subdirectory(dbt-core)
add_subdirectory(riscv)
add_subdirectory(scc)
add_subdirectory(platform)
