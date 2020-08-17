cmake_minimum_required(VERSION 3.12)

project(platform VERSION 1.0.0)

include(GNUInstallDirs)

# library files
FILE(GLOB RiscVSCHeaders ${PROJECT_SOURCE_DIR}/incl/sysc/*.h ${PROJECT_SOURCE_DIR}/incl/sysc/*/*.h)

set(LIB_HEADERS ${RiscVSCHeaders} )

set(LIB_SOURCES 
	sysc/aon.cpp
	sysc/BLDC.cpp
	sysc/clint.cpp
	sysc/dcmotor.cpp
	sysc/gpio.cpp
	sysc/h_bridge.cpp
	sysc/hifive1.cpp
	sysc/fe310.cpp
	sysc/mcp_adc.cpp
	sysc/plic.cpp
	sysc/prci.cpp
	sysc/pwm.cpp
	sysc/sc_comm_singleton.cpp
	sysc/spi.cpp
	sysc/system.cpp
	sysc/terminal.cpp
	sysc/uart.cpp	
	CLIParser.cpp )

add_library(platform ${LIB_SOURCES})
target_include_directories(platform PUBLIC ../incl)
target_link_libraries(platform PUBLIC riscv_sc CONAN_PKG::seasocks external)
set_target_properties(platform PROPERTIES
  VERSION ${PROJECT_VERSION}  # ${VERSION} was defined in the main CMakeLists.
  FRAMEWORK FALSE
  PUBLIC_HEADER "${LIB_HEADERS}" # specify the public headers
)

add_executable(riscv-vp sc_main.cpp)
# include files for this application
target_include_directories(riscv-vp SYSTEM PRIVATE ${LLVM_INCLUDE_DIRS})
target_link_libraries(riscv-vp PUBLIC platform riscv_sc)
if (Tcmalloc_FOUND)
    target_link_libraries(riscv-vp PUBLIC ${Tcmalloc_LIBRARIES})
endif(Tcmalloc_FOUND)

install(TARGETS platform riscv-vp
  EXPORT ${PROJECT_NAME}Targets            # for downstream dependencies
  ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR} COMPONENT libs   # static lib
  RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR} COMPONENT libs   # binaries
  LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR} COMPONENT libs   # shared lib
  FRAMEWORK DESTINATION ${CMAKE_INSTALL_LIBDIR} COMPONENT libs # for mac
  PUBLIC_HEADER DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}/${PROJECT_NAME} COMPONENT devel   # headers for mac (note the different component -> different package)
  INCLUDES DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}             # headers
)

