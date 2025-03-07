#include "Student.h"
#include <iostream>

Student::Student(int id, const std::string &name) : User(id, name) {}

void Student::viewTransactions()
{
    Database db("library.db");
    db.fetchUserTransactions(id);
}
