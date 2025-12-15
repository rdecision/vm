add_library(frontend STATIC
        scanner.cpp
        compiler.cpp
        file_io.cpp
)
target_link_libraries(frontend PUBLIC core)
target_include_directories(frontend PUBLIC ${CMAKE_SOURCE_DIR}/include)