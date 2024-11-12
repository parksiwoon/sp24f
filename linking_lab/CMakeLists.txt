cmake_minimum_required(VERSION 3.10)
project(linking_lab)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_BUILD_TYPE Debug)  # 디버그 모드 설정 추가
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g")  # 디버깅 플래그 추가

include_directories(${CMAKE_SOURCE_DIR}/leveldb/include)
link_directories(${CMAKE_SOURCE_DIR}/leveldb/build)


add_executable(linking_lab main.cpp)
target_link_libraries(linking_lab leveldb snappy pthread)
