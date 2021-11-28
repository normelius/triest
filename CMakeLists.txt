

cmake_minimum_required(VERSION 3.10)

project(Triest)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# add the executable
add_executable(triest example.cc src/stream.cc src/triestBase.cc src/sample.cc)