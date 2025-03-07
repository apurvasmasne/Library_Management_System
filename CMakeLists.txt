cmake_minimum_required(VERSION 3.10)
project(LibraryManagementSystem)

set(CMAKE_CXX_STANDARD 14)

# Find SQLite3
find_package(SQLite3 REQUIRED)

# Include directories
include_directories(${SQLite3_INCLUDE_DIRS})

# Add source files
add_executable(LibraryManagementSystem main.cpp Database.cpp Book.cpp User.cpp Student.cpp Faculty.cpp Transaction.cpp)

# Link SQLite3
target_link_libraries(LibraryManagementSystem ${SQLite3_LIBRARIES})
