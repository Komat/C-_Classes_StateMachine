cmake_minimum_required(VERSION 3.6)
project(StateMachine)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp classes/core/PubSub/PubSub.h StateMachine.cpp StateMachine.h State.cpp State.h)
add_executable(StateMachine ${SOURCE_FILES})
