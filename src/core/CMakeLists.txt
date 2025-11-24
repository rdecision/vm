add_library(core STATIC chunk.cpp
        value.cpp
        VirtualMachine.cpp
)
target_include_directories(core PUBLIC ${CMAKE_SOURCE_DIR}/include)
