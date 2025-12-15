cmake_minimum_required(VERSION 4.0)
project(vm)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_subdirectory(src/core)
add_subdirectory(src/frontend)
add_subdirectory(src/debugger)
add_subdirectory(src/interpreter)
add_subdirectory(test)

add_executable(vm src/main.cpp)
target_link_libraries(vm PRIVATE core debugger)

include(FetchContent)
FetchContent_Declare(
        googletest
        URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)

FetchContent_MakeAvailable(googletest)
enable_testing()





#FetchContent_Declare(
#        asmjit
#        GIT_REPOSITORY https://github.com/asmjit/asmjit
#        GIT_TAG master   # or a real version like 2024-05-02
#)

#FetchContent_MakeAvailable(asmjit)
#target_link_libraries(core PUBLIC asmjit)

