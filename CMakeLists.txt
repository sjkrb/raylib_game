cmake_minimum_required(VERSION 3.0.0)
project(myGame VERSION 0.1.0)


add_executable(myGame main.cpp)
set_property(TARGET myGame PROPERTY CXX_STANDARD 17) 
target_link_libraries(myGame raylib gtest gtest_main)

include(GoogleTest)

include(CTest)
enable_testing()
add_subdirectory(Test)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
