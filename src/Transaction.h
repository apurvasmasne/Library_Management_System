#ifndef TRANSACTION_H
#define TRANSACTION_H

#include <string>
#include "Database.h"

class Transaction
{
public:
    static void issueBook(int userId, int bookId);
    static void returnBook(int userId, int bookId);
};

#endif
