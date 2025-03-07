#include "Transaction.h"

void Transaction::issueBook(int userId, int bookId)
{
    Database db("library.db");
    std::string query = "INSERT INTO transactions (user_id, book_id, type) VALUES (" +
                        std::to_string(userId) + ", " + std::to_string(bookId) + ", 'issue')";
    db.executeInsertQuery(query);
}

void Transaction::returnBook(int userId, int bookId)
{
    Database db("library.db");
    std::string query = "INSERT INTO transactions (user_id, book_id, type) VALUES (" +
                        std::to_string(userId) + ", " + std::to_string(bookId) + ", 'return')";
    db.executeInsertQuery(query);
}
