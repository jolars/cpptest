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

add_executable(cpptest src/cpptest.cpp)

target_link_libraries(${PROJECT_NAME} PUBLIC Test)

# add_subdirectory(bindings)

# include(FetchContent)
#
# FetchContent_Declare( Catch2 GIT_REPOSITORY
# https://github.com/catchorg/Catch2.git GIT_TAG v3.4.0)
#
# FetchContent_MakeAvailable(Catch2)
#
# add_executable(tests tests/test.cpp) target_link_libraries(tests PRIVATE
# Catch2::Catch2WithMain)
