#ifndef USER_H
#define USER_H

#include <string>
#include <vector>

class User
{
public:
    User(int id, const std::string &name);
    virtual void viewTransactions() = 0; // Pure virtual function
    int getId() const;
    std::string getName() const;

protected:
    int id;
    std::string name;
};

#endif
