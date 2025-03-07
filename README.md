# Library Management System

A C++ based Library Management System that manages books, users, and transactions. It uses inheritance and polymorphism to handle different user types (students and faculty). The system is integrated with **SQLite** for persistent data storage and provides functionality to add, update, delete, and view books and transactions.

## Features

- **Book Management**: Add, update, and delete books in the library.
- **User Management**: Handle different user types (students and faculty).
- **Transactions**: Issue and return books, with transaction logging.
- **Database**: SQLite used to persist books, users, and transactions.
- **Polymorphism**: Different user types can be handled through inheritance.
- **Transaction Handling**: Books can be issued and returned, and transaction logs are maintained.

## Technologies

- **C++**: Programming language used for the system.
- **SQLite**: Used for persistent data storage.
- **Inheritance & Polymorphism**: Object-oriented principles for managing users (Student, Faculty).
- **CMake**: Build management tool.

## Prerequisites

### SQLite Installation

To run this system, ensure **SQLite3** is installed on your system. You can install SQLite using one of the following methods:

Database Setup
Before running the program, make sure to set up the SQLite database (library.db) with the following tables:

sql
-- Table to store books
CREATE TABLE books (
    id INTEGER PRIMARY KEY AUTOINCREMENT,
    title TEXT NOT NULL,
    author TEXT NOT NULL
);

-- Table to store users
CREATE TABLE users (
    id INTEGER PRIMARY KEY AUTOINCREMENT,
    name TEXT NOT NULL,
    user_type TEXT NOT NULL
);

-- Table to store transactions
CREATE TABLE transactions (
    id INTEGER PRIMARY KEY AUTOINCREMENT,
    user_id INTEGER,
    book_id INTEGER,
    type TEXT, -- "issue" or "return"
    FOREIGN KEY(user_id) REFERENCES users(id),
    FOREIGN KEY(book_id) REFERENCES books(id)
);
