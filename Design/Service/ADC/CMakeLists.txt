# Minimum CMake version
cmake_minimum_required(VERSION 3.10)

# Project name
project(ADC_Project)

# Set the C standard
set(CMAKE_C_STANDARD 11)
set(CMAKE_BUILD_TYPE Debug)

# Add include directories
include_directories(
    ${CMAKE_CURRENT_SOURCE_DIR}/public
    ${CMAKE_CURRENT_SOURCE_DIR}/private
)

# Add source files
set(SOURCES
    private/adc_chip1.c
    private/adc_chip2.c
    public/adc.c
    main.c
)

# Add the executable
add_executable(main ${SOURCES})
