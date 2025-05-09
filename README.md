# ProNet
<<<<<<< HEAD
ProNet is a minimal yet professional client-server application built in modern C++ using Winsock and CMake. It enables structured peer-to-peer message exchange using JSON (via json.hpp) without relying on third-party libraries like Boost. It's designed to showcase clean architecture, real-time communication, and professional code organization in a native Windows environment.
=======

# Professional Networking App (Client-Server Model)

A lightweight C++ client-server networking application built using the Winsock API on Windows. This project demonstrates the networking fundamentals, socket programming, and clean software design principles. The app simulates a basic professional networking platform where users can connect and exchange messages.

##  Purpose

This project is designed to showcase:
- Understanding of TCP socket communication using Winsock.
- Clean separation of concerns between client and server logic.
- Well-structured code with modern C++ practices.
- Readable, documented code with proper error handling.

It can be extended to support multiple clients, user registration, or even integrate a database in the future.

---

##  Features

 TCP connection between a client and server  
 Modular code with `.cpp` and `.h` separation  
 Basic message exchange functionality  
 Winsock initialization and teardown  
 Easily extensible architecture  

---

##  Technologies Used

- C++17
- Winsock2 API
- CMake
- Ninja or MinGW Make
- Windows (MINGW64 / MSYS2)

---

##  Project Structure
ProNet/
├── client/
│ ├── Client.cpp # Client logic implementation
│ └── Client.h # Client interface
├── server/
│ ├── Server.cpp # Server logic implementation
│ └── Server.h # Server interface
├── shared/
│ ├── Message.h # Message structure for communication
│ └── User.h # User structure
├── CMakeLists.txt # CMake build configuration
└── README.md # Project description


---

##  Building the Project

###  Requirements

- [CMake ≥ 3.10](https://cmake.org/download/)
- [Ninja](https://ninja-build.org/) or MinGW
- MSYS2 / Git Bash terminal
- Windows OS

###  Setup Instructions

1. **Clone the repo**  
   ```bash
   git clone https://github.com/gem870/ProNet.git
   cd ProNet

Create the build directory
mkdir build && cd build

Run CMake
cmake -G "Ninja" ..

Build the app
cmake --build .

Run the executables
Open two terminals:

Terminal 1 (server):
./server.exe

Terminal 2 (client):
./client.exe
>>>>>>> 7838905 (first commit)
