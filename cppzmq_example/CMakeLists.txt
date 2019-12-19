cmake_minimum_required(VERSION 3.0.0)
project(tardis VERSION 0.1.0)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED on)

include(CTest)
enable_testing()

find_package(Threads REQUIRED)
find_package(cppzmq CONFIG REQUIRED)
find_package(fmt CONFIG REQUIRED)

add_executable(service service.cpp)
target_link_libraries(service PRIVATE cppzmq fmt::fmt)

add_executable(client client.cpp)
target_link_libraries(client PRIVATE cppzmq)

add_executable(publisher publisher.cpp)
target_link_libraries(publisher PRIVATE cppzmq)

add_executable(subscriber subscriber.cpp)
target_link_libraries(subscriber PRIVATE cppzmq)

add_executable(ventilator ventilator.cpp)
target_link_libraries(ventilator PRIVATE cppzmq)

add_executable(worker worker.cpp)
target_link_libraries(worker PRIVATE cppzmq)

add_executable(sink sink.cpp)
target_link_libraries(sink PRIVATE cppzmq)

add_executable(broker broker.cpp)
target_link_libraries(broker PRIVATE cppzmq Threads::Threads)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
