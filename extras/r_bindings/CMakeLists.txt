find_package(R 4.0)

include(CMakePrintHelpers)

set(R_PKG_NAME cpptest)
set(R_PKG_VERSION ${CMAKE_PROJECT_VERSION})

string(TIMESTAMP R_PKG_DATE "%Y-%m-%d")

# Copy all R package files to the build directory
set(R_PKG_IN_DIR ${CMAKE_CURRENT_SOURCE_DIR}/${R_PKG_NAME})
set(R_PKG_OUT_DIR ${CMAKE_CURRENT_BINARY_DIR}/${R_PKG_NAME})

set(PKG_FILES ${R_PKG_IN_DIR}/NAMESPACE ${R_PKG_IN_DIR}/R ${R_PKG_IN_DIR}/src)

file(COPY ${PKG_FILES} DESTINATION ${R_PKG_OUT_DIR})

# Configure DESCRIPTION and LICENSE
configure_file(${R_PKG_IN_DIR}/DESCRIPTION.in ${R_PKG_OUT_DIR}/DESCRIPTION
               @ONLY)

string(TIMESTAMP LICENSE_YEAR "%Y")
configure_file(${R_PKG_IN_DIR}/LICENSE.md.in ${R_PKG_OUT_DIR}/LICENSE @ONLY)

# Copy all C++ source files to the build directory
set(CPP_SRC_DIR "${CMAKE_SOURCE_DIR}/src/cpptest")

file(
  GLOB_RECURSE CPP_SRC_FILES
  RELATIVE ${CPP_SRC_DIR}
  ${CPP_SRC_DIR}/*.hpp ${CPP_SRC_DIR}/*.cpp)

foreach(file ${CPP_SRC_FILES})
  file(COPY ${CPP_SRC_DIR}/${file} DESTINATION ${R_PKG_OUT_DIR}/src/cpptest)
endforeach()

file(COPY ${CPP_SRC_DIR}/test.cpp DESTINATION ${R_PKG_OUT_DIR}/src/cpptest)

# foreach(file ${CPP_SRC_FILES}) add_custom_command( TARGET r_copy PRE_BUILD
# COMMAND ${CMAKE_COMMAND} -E copy_if_different ${CPP_SRC_DIR}/${file}
# ${CMAKE_CURRENT_BINARY_DIR}/cpptest/src/cpptest/${file}) endforeach()

add_custom_target(r_build ALL COMMENT "Add target for R package build")

# add_custom_command( TARGET r_build POST_BUILD COMMAND ${CMAKE_COMMAND} -E
# copy_if_different "${CPP_SRC_FILES}/bla.cpp" ${R_PKG_OUT_DIR}/src/cpptest

add_custom_command(
  TARGET r_build
  POST_BUILD
  COMMAND ${RSCRIPT_EXECUTABLE} ARGS "-e" "'Rcpp::compileAttributes()'"
  WORKING_DIRECTORY "${R_PKG_OUT_DIR}"
  COMMENT "Call Rcpp::compileAttributes() to generate bindings to R.")

add_custom_command(
  TARGET r_build
  POST_BUILD
  COMMAND ${RSCRIPT_EXECUTABLE} ARGS "-e" "'roxygen2::roxygenize(\".\")'"
  WORKING_DIRECTORY "${R_PKG_OUT_DIR}"
  COMMENT "Document R package code using roxygen2.")

add_custom_command(
  TARGET r_build
  POST_BUILD
  COMMAND ${R_EXECUTABLE} CMD build cpptest
  WORKING_DIRECTORY "${CMAKE_CURRENT_BINARY_DIR}"
  COMMENT "Build the R package.")

install(
  CODE "execute_process(COMMAND ${R_EXECUTABLE} CMD INSTALL cpptest_${R_PKG_VER}.tar.gz
                        WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR})")

# cmake_print_variables(CPP_SRC_FILES)
