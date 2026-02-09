cmake_minimum_required(VERSION 3.20)
project(aim-analyzer VERSION 0.1.0)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

file(GLOB_RECURSE SOURCES "src/*.cpp")

find_package(tomlplusplus CONFIG REQUIRED)
find_package(libpqxx CONFIG REQUIRED)

add_executable(aim-analyzer ${SOURCES})

target_include_directories(aim-analyzer PRIVATE
  ${CMAKE_CURRENT_SOURCE_DIR}/include
)

target_link_libraries(aim-analyzer PRIVATE
  tomlplusplus::tomlplusplus
  libpqxx::pqxx
)

configure_file(config.toml ${CMAKE_BINARY_DIR}/config.toml COPYONLY)
