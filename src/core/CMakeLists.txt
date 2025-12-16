add_library(core STATIC chunk.cpp
        value.cpp
        virtualmachine.cpp
)
target_include_directories(core
        PUBLIC ${CMAKE_SOURCE_DIR}/include
)
