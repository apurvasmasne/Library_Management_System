#include "Database.h"
#include <iostream>

Database::Database(const std::string &dbName)
{
    openDatabase(dbName);
}

Database::~Database()
{
    sqlite3_close(db);
}

bool Database::openDatabase(const std::string &dbName)
{
    if (sqlite3_open(dbName.c_str(), &db))
    {
        std::cerr << "Error opening database: " << sqlite3_errmsg(db) << std::endl;
        return false;
    }
    return true;
}

bool Database::executeQuery(const std::string &query)
{
    char *errMsg = nullptr;
    int rc = sqlite3_exec(db, query.c_str(), nullptr, nullptr, &errMsg);
    if (rc != SQLITE_OK)
    {
        std::cerr << "SQL Error: " << errMsg << std::endl;
        sqlite3_free(errMsg);
        return false;
    }
    return true;
}

bool Database::executeInsertQuery(const std::string &query)
{
    return executeQuery(query);
}

void Database::fetchAllBooks()
{
    std::string query = "SELECT * FROM books";
    sqlite3_stmt *stmt;
    if (sqlite3_prepare_v2(db, query.c_str(), -1, &stmt, nullptr) != SQLITE_OK)
    {
        std::cerr << "Failed to fetch books: " << sqlite3_errmsg(db) << std::endl;
        return;
    }

    std::cout << "Books in library:\n";
    while (sqlite3_step(stmt) == SQLITE_ROW)
    {
        const char *title = (const char *)sqlite3_column_text(stmt, 1);
        const char *author = (const char *)sqlite3_column_text(stmt, 2);
        int id = sqlite3_column_int(stmt, 0);
        std::cout << "ID: " << id << ", Title: " << title << ", Author: " << author << std::endl;
    }

    sqlite3_finalize(stmt);
}

void Database::fetchUserTransactions(int userId)
{
    std::string query = "SELECT * FROM transactions WHERE user_id = " + std::to_string(userId);
    sqlite3_stmt *stmt;
    if (sqlite3_prepare_v2(db, query.c_str(), -1, &stmt, nullptr) != SQLITE_OK)
    {
        std::cerr << "Failed to fetch transactions: " << sqlite3_errmsg(db) << std::endl;
        return;
    }

    std::cout << "Transactions for user " << userId << ":\n";
    while (sqlite3_step(stmt) == SQLITE_ROW)
    {
        int transactionId = sqlite3_column_int(stmt, 0);
        int bookId = sqlite3_column_int(stmt, 1);
        const char *type = (const char *)sqlite3_column_text(stmt, 2);
        std::cout << "Transaction ID: " << transactionId << ", Book ID: " << bookId << ", Type: " << type << std::endl;
    }

    sqlite3_finalize(stmt);
}
