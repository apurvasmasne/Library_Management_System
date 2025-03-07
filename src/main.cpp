#include <iostream>
#include "Database.h"
#include "Student.h"
#include "Faculty.h"
#include "Transaction.h"

int main()
{
    Database db("library.db");

    // Example: Add books to the library (assuming table 'books' already exists)
    db.executeQuery("INSERT INTO books (title, author) VALUES ('C++ Programming', 'Bjarne Stroustrup')");
    db.executeQuery("INSERT INTO books (title, author) VALUES ('The Catcher in the Rye', 'J.D. Salinger')");

    // Creating user instances
    Student student1(1, "Alice");
    Faculty faculty1(2, "Dr. Smith");

    // View transactions for each user
    student1.viewTransactions();
    faculty1.viewTransactions();

    // Issue a book
    Transaction::issueBook(student1.getId(), 1);

    // View transactions again
    student1.viewTransactions();

    // Return a book
    Transaction::returnBook(student1.getId(), 1);

    return 0;
}
