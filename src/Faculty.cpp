#include "Faculty.h"
#include <iostream>

Faculty::Faculty(int id, const std::string &name) : User(id, name) {}

void Faculty::viewTransactions()
{
    Database db("library.db");
    db.fetchUserTransactions(id);
}
