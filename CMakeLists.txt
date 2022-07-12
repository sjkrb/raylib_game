cmake_minimum_required(VERSION 3.0.0)
project(myGame VERSION 0.1.0)

enable_testing()

add_library(structure structure.cpp)

add_executable(myGame main.cpp)

target_include_directories(myGame PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

set_property(TARGET myGame PROPERTY CXX_STANDARD 17) 
# set_property(TARGET myGame PROPERTY ENABLE_EXPORTS 1)

target_link_libraries(myGame raylib structure)

add_subdirectory(Test)

target_include_directories(myGame PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}
)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)

