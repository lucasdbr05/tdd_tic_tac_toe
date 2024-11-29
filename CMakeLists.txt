cmake_minimum_required(VERSION 3.10...3.30)

project(tdd_tic_tac_toe LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)

Include(FetchContent)

FetchContent_Declare(
  Catch2
  GIT_REPOSITORY https://github.com/catchorg/Catch2.git
  GIT_TAG        v3.4.0 
)

FetchContent_MakeAvailable(Catch2)

add_executable(testa_velha velha.cpp velha.hpp testa_velha.cpp)
target_link_libraries(testa_velha PRIVATE Catch2::Catch2WithMain)

include(CTest)
include(Catch)
catch_discover_tests(testa_velha)