cmake_minimum_required(VERSION 3.13)
project(curllib C)

set(CMAKE_C_STANDARD 99)

add_executable(curllib main.c)

set(CURL_LIBRARY "-lcurl")
FIND_PACKAGE(CURL)
INCLUDE_DIRECTORIES(${CURL_INCLUDE_DIR})
target_link_libraries(curllib ${CURL_LIBRARIES})
#SET(requiredlibs ${CURL_LIBRARIES})

#target_link_libraries()