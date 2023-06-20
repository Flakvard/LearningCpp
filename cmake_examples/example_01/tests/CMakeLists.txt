# include(FetchContent)
# 
# FetchContent_Declare(
#   googletest
#   GIT_REPOSITORY https://github.com/google/googletest.git
#   GIT_TAG        release-1.11.0
# )
# FetchContent_MakeAvailable(googletest)
# add_library(GTest::GTest INTERFACE IMPORTED)
# target_link_libraries(GTest::GTest INTERFACE gtest_main)

add_executable(multiply_test multiply_test.cpp)
# Locate GTest
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})
 
target_link_libraries(multiply_test
# PRIVATE
# GTest::GTest
  ${GTEST_LIBRARIES}
  )
target_include_directories(multiply_test
  PUBLIC
  ${CMAKE_CURRENT_SOURCE_DIR}/src/multiply/include
  )


add_test(multiply_gtest multiply_test)