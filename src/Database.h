#ifndef DATABASE_H
#define DATABASE_H

#include <sqlite3.h>
#include <string>

class Database
{
public:
    Database(const std::string &dbName);
    ~Database();
    bool executeQuery(const std::string &query);
    bool executeInsertQuery(const std::string &query);
    void fetchAllBooks();
    void fetchUserTransactions(int userId);

private:
    sqlite3 *db;
    bool openDatabase(const std::string &dbName);
};

#endif
