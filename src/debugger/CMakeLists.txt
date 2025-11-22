add_library(debugger STATIC debugger.cpp)
target_link_libraries(debugger PUBLIC core)
target_include_directories(debugger PUBLIC ${CMAKE_SOURCE_DIR}/include)
message(STATUS "Debug library added")