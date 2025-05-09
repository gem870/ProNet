cmake_minimum_required(VERSION 3.10)
project(ProfessionalNetworkingApp)

set(CMAKE_CXX_STANDARD 17)

# Winsock library for Windows
if(WIN32)
    add_definitions(-D_CRT_SECURE_NO_WARNINGS)
    link_libraries(ws2_32)
endif()

# Shared include path
include_directories(shared)

# Server target
add_executable(server
    server/Server.cpp
    server/main.cpp
    shared/Message.h
    shared/json.hpp
)
target_link_libraries(server ws2_32)

# Client target
add_executable(client
    client/Client.cpp
    client/main.cpp
    shared/Message.h
    shared/json.hpp
)
target_link_libraries(client ws2_32)
