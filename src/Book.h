#ifndef BOOK_H
#define BOOK_H

#include <string>

class Book
{
public:
    Book(int id, const std::string &title, const std::string &author);
    int getId() const;
    std::string getTitle() const;
    std::string getAuthor() const;

private:
    int id;
    std::string title;
    std::string author;
};

#endif
