add_executable(raylib_test test.cpp)

target_link_libraries(raylib_test gtest gtest_main)

# add_test(
#   NAME
#     tests
#   COMMAND
#     $<TARGET_FILE:raylib_test>
# )

include(GoogleTest)
gtest_discover_tests(raylib_test)
