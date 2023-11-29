cmake_minimum_required(VERSION 3.10)
project(Threads)

file(GLOB HEADER_FILES "*.h")
file(GLOB SRC_FILES "*.c")

set(CMAKE_CXX_STANDARD 17)

add_executable(${PROJECT_NAME} ${HEADER_FILES} ${SRC_FILES})
