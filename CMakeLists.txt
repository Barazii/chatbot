cmake_minimum_required(VERSION 3.11.3)

set(CMAKE_CXX_STANDARD 17)

project(Membot)

# debug symbols and disable optimization for debugging
if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Debug)
endif()
set(CMAKE_CXX_FLAGS_DEBUG "-g -O0 -Wall -Wextra")

find_package(wxWidgets REQUIRED COMPONENTS core base)
find_package(Boost REQUIRED COMPONENTS unit_test_framework)

include(${wxWidgets_USE_FILE})

file(GLOB project_SRCS src/*.cpp)
file(GLOB test_SRCS tests/*.cpp)

set(project_INCLUDE_DIRS ${CMAKE_CURRENT_SOURCE_DIR}/src)

add_executable(membot ${project_SRCS})
target_link_libraries(membot ${wxWidgets_LIBRARIES})
target_include_directories(membot PRIVATE ${wxWidgets_INCLUDE_DIRS})


add_executable(tests ${test_SRCS} ${project_SRCS})
target_compile_definitions(tests PRIVATE TESTING=1)
target_link_libraries(tests 
    ${Boost_UNIT_TEST_FRAMEWORK_LIBRARY}
    ${wxWidgets_LIBRARIES}
)
target_include_directories(tests PRIVATE 
    ${Boost_INCLUDE_DIRS}
    ${wxWidgets_INCLUDE_DIRS}
    ${project_INCLUDE_DIRS}
)
