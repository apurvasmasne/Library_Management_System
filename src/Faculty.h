#ifndef FACULTY_H
#define FACULTY_H

#include "User.h"
#include "Database.h"

class Faculty : public User
{
public:
    Faculty(int id, const std::string &name);
    void viewTransactions() override;
};

#endif
