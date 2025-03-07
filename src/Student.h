#ifndef STUDENT_H
#define STUDENT_H

#include "User.h"
#include "Database.h"

class Student : public User
{
public:
    Student(int id, const std::string &name);
    void viewTransactions() override;
};

#endif
