file(GLOB SRCS *.cpp)
add_executable(tester test.cpp)
include_directories(../)
target_link_libraries(tester structure gtest gtest_main)
include(CTest)
add_test(NAME onlytest COMMAND tester)