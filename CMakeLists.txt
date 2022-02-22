cmake_minimum_required(VERSION 3.20)
project(rockpaperscissors)

set(CMAKE_CXX_STANDARD 20)

set(FULL_PATH_TO_MYSQL_CONNECTOR_CPP_DIR "C:/Program Files (x86)/MySQL/Connector C++ 8.0")
include_directories(${FULL_PATH_TO_MYSQL_CONNECTOR_CPP_DIR}/include/mysqlx)
link_directories(${FULL_PATH_TO_MYSQL_CONNECTOR_CPP_DIR}/lib/vs14)

add_executable(rockpaperscissors main.cpp game.cpp)
target_link_libraries(rockpaperscissors mysqlcppconn8)
