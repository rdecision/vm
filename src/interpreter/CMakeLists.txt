add_library(interpreter STATIC
        interpreter.cpp
)

target_link_libraries(interpreter
        PUBLIC core
        PUBLIC frontend
)

target_include_directories(interpreter
        PUBLIC ${CMAKE_SOURCE_DIR}/include
)