cmake_minimum_required(VERSION 3.24)
project(algorithms_personal_repo_karypzhanov_k_auca_2022)
set(CMAKE_CXX_STANDARD 20)

include(FetchContent)
FetchContent_Declare(json URL https://github.com/nlohmann/json/releases/download/v3.11.3/json.tar.xz)
FetchContent_MakeAvailable(json)

add_executable(kamar_2 fun3/main.cpp)  #
target_link_libraries(kamar_2 PRIVATE nlohmann_json::nlohmann_json)

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
add_executable(dfs_test stuff/dfs.cpp)
add_executable(dp_test stuff/test_2d_dp.cpp)
add_executable(ojjj1 oj/ojjj1.cpp)
add_executable(ojjj2 oj/ojjj2.cpp)
add_executable(ojjj3 oj/ojjj3.cpp)
add_executable(ojjj4 oj/ojjj4.cpp)
add_executable(bucket stuff/bucket.cpp)

add_executable(plane_routes_creator
        fun1/main.cpp
        fun1/City.h
        fun1/Graph.h
        fun1/Flight.h
)

add_executable(kamar_1
        fun3/main.cpp
)


add_executable(GAME
        stuff/My_Game/main.cpp
        stuff/My_Game/Animal.cpp
        stuff/My_Game/Animal.h
)
