cmake_minimum_required(VERSION 3.14)
project(sticker2smilebot_telegram)

set(CMAKE_CXX_STANDARD 17)

add_compile_definitions(HAVE_CURL)

include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup()

add_executable(sticker2smilebot_telegram main.cpp)
target_link_libraries(sticker2smilebot_telegram ${CONAN_LIBS})
