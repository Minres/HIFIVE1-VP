cmake_minimum_required(VERSION 3.12)
# Set the name of your project here
project("external")

set(LIB_SOURCES
    libGIS/atmel_generic.c
    libGIS/ihex.c
    libGIS/srecord.c
)

# Define the library
add_library(${PROJECT_NAME} ${LIB_SOURCES})
target_include_directories(${PROJECT_NAME} PUBLIC ${PROJECT_SOURCE_DIR}/libGIS)

