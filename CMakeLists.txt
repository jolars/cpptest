cmake_minimum_required(VERSION 3.15)

project(
  cpptest
  LANGUAGES CXX
  VERSION 0.1.0)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_CURRENT_SOURCE_DIR}/cmake")

add_subdirectory(src)
add_subdirectory(extras)

add_executable(cpptest src/main.cpp)

target_link_libraries(cpptest PUBLIC hello)

include(FetchContent)

FetchContent_Declare(
  Catch2
  GIT_REPOSITORY https://github.com/catchorg/Catch2.git
  GIT_TAG v3.4.0)

FetchContent_MakeAvailable(Catch2)

add_executable(unit_tests tests/test.cpp)

target_include_directories(unit_tests PUBLIC tests)

target_link_libraries(unit_tests PRIVATE Catch2::Catch2WithMain hello)

list(APPEND CMAKE_MODULE_PATH ${catch2_SOURCE_DIR}/extras)

include(CTest)
include(Catch)

catch_discover_tests(unit_tests)
