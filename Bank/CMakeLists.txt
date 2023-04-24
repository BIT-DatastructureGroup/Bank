cmake_minimum_required(VERSION 3.0)
project(bank)
 
set(CMAKE_CXX_FLAGS ${CMAKE_CXX_FLAGS} -g)
set(SOURCE Account.cpp AccountManager.cpp AccountNode.cpp Bank.cpp)
 
add_executable(main ${SOURCE})