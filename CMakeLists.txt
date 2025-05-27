cmake_minimum_required(VERSION 3.19)
project(net-herald CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Vcpkg integration
find_package(spdlog CONFIG REQUIRED)

add_executable(net-herald src/main.cc)

target_link_libraries(net-herald PRIVATE spdlog::spdlog pcap)

