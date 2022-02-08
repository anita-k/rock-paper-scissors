cmake_minimum_required(VERSION 3.20)
project(rockpaperscissors)

set(CMAKE_CXX_STANDARD 20)

set(FULL_PATH_TO_MYSQL_CONNECTOR_CPP_DIR "C:/Program Files/MySQL/Connector C++ 8.0")
include_directories(${FULL_PATH_TO_MYSQL_CONNECTOR_CPP_DIR}/include/jdbc)
include_directories(${FULL_PATH_TO_MYSQL_CONNECTOR_CPP_DIR}/include/jdbc/cppconn)
link_directories(${FULL_PATH_TO_MYSQL_CONNECTOR_CPP_DIR}/lib64/vs14)

#target_compile_features(main PRIVATE cxx_range_for)


add_executable(rockpaperscissors main.cpp game.cpp)
target_link_libraries(rockpaperscissors mysqlcppconn)

#target_link_options(rockpaperscissors PRIVATE /machine:x64)