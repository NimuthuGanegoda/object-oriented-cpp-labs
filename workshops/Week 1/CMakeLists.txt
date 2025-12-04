# Week 1 Workshop Exercises

add_executable(HelloWorld "${CMAKE_CURRENT_SOURCE_DIR}/HelloWorld.cpp")
target_compile_features(HelloWorld PRIVATE cxx_std_17)
