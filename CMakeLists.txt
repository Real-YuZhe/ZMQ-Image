project(ZMQ_Sample)
cmake_minimum_required(VERSION 3.10)

find_package(OpenCV REQUIRED)
include_directories(${OpenCV_INCLUDE_DIRS})

add_executable(Sub Sub.cpp)
target_link_libraries(Sub zmq ${OpenCV_LIBS})
add_executable(Pub Pub.cpp)
target_link_libraries(Pub zmq ${OpenCV_LIBS})