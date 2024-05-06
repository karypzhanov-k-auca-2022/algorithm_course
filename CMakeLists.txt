cmake_minimum_required(VERSION 3.26)
project(algorithms_personal_repo_karypzhanov_k_auca_2022)

set(CMAKE_CXX_STANDARD 20)

Include(FetchContent)

FetchContent_Declare(json URL https://github.com/nlohmann/json/releases/download/v3.11.3/json.tar.xz)
FetchContent_MakeAvailable(json)

FetchContent_Declare(json URL https://github.com/nlohmann/json/releases/download/v3.11.3/json.tar.xz)
FetchContent_MakeAvailable(json)

#oj
add_executable(oj1 oj/oj1.cpp)
add_executable(oj2 oj/oj2.cpp)
add_executable(oj3 oj/oj3.cpp)
add_executable(oj4 oj/oj4.cpp)
add_executable(oj5 oj/oj5.cpp)
add_executable(oj6 oj/oj6.cpp)
add_executable(oj7 oj/oj7.cpp)
add_executable(oj8 oj/oj8.cpp)
add_executable(oj9 oj/oj9.cpp)
add_executable(oj10 oj/oj10.cpp)
add_executable(oj11 oj/oj11.cpp)
add_executable(oj12 oj/oj12.cpp)
add_executable(oj13 oj/oj13.cpp)
add_executable(oj14 oj/oj14.cpp)
add_executable(oj15 oj/oj15.cpp)

#ojjj
add_executable(ojjj1 oj/ojjj1.cpp)
add_executable(ojjj2 oj/ojjj2.cpp)
add_executable(ojjj3 oj/ojjj3.cpp)
add_executable(ojjj4 oj/ojjj4.cpp)
add_executable(ojjj8 oj/ojjj8.cpp)
add_executable(ojjj11 oj/ojjj11.cpp)
add_executable(ojjj12 oj/ojjj12.cpp)
add_executable(ojjj13 oj/ojjj13.cpp)
add_executable(ojjj14 oj/ojjj14.cpp)
add_executable(ojjj15 oj/ojjj15.cpp)
add_executable(ojjj18 oj/ojjj18.cpp)

#stuff
add_executable(bucket stuff/bucket.cpp)
add_executable(dfs_test stuff/dfs.cpp)
add_executable(dp_test stuff/test_2d_dp.cpp)
add_executable(GAME stuff/My_Game/main.cpp stuff/My_Game/Animal.cpp stuff/My_Game/Animal.h)
add_executable(test_ojjj_11 stuff/test_ojjj_11.cpp)
add_executable(test_ojjj_12 stuff/test_ojjj_12.cpp)
add_executable(test_ojjj_13 stuff/test_ojjj_13.cpp)
add_executable(test_ojjj_8 stuff/test_ojjj_8.cpp)
add_executable(test_ojjj_15 stuff/test_ojjj_15.cpp)
add_executable(test_ojjj_18 stuff/test_ojjj_18.cpp)
add_executable(test_ojjj_20 stuff/test_ojjj_20.cpp)
add_executable(test_json stuff/My_Game/json_check.cpp)
add_executable(fun4_train stuff/fun4_train.cpp)
add_executable(exam_prepare stuff/exam_prepare.cpp)

#funs
add_executable(plane_routes_creator fun1/main.cpp fun1/City.h fun1/Graph.h fun1/Flight.h)
add_executable(kamar fun3/main.cpp)
add_executable(leader fun4/supreme_leader_simulator.cpp)

include_directories(${CMAKE_SOURCE_DIR}/fun1)
include_directories(${CMAKE_SOURCE_DIR}/fun3)

target_link_libraries(kamar PRIVATE nlohmann_json::nlohmann_json)
target_link_libraries(test_json PRIVATE nlohmann_json::nlohmann_json)