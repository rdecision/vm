add_library(core STATIC chunk.cpp
        value.cpp
        VirtualMachine.cpp
        ../frontend/compiler.cpp
)
target_include_directories(core PUBLIC ${CMAKE_SOURCE_DIR}/include)
