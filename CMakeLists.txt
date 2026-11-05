cmake_minimum_required(VERSION 3.20)
project(VulpineC VERSION 0.1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

file(READ "${CMAKE_CURRENT_SOURCE_DIR}/metadata.json" METADATA_JSON_CONTENT)

string(JSON VULPINE_NAME GET "${METADATA_JSON_CONTENT}" "compiler_name")
string(JSON VULPINE_VERSION GET "${METADATA_JSON_CONTENT}" "version")

include_directories(VulpineC PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}/include")

configure_file(
    "${CMAKE_CURRENT_SOURCE_DIR}/include/metadata.hpp.in"
    "${CMAKE_CURRENT_BINARY_DIR}/generated/metadata.hpp"
    @ONLY
)

add_executable(VulpineC src/main.cpp)

target_include_directories(VulpineC PRIVATE 
    include
    ${CMAKE_CURRENT_BINARY_DIR}/generated
)

target_link_libraries(VulpineC PRIVATE stdc++exp)