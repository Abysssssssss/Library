#include "Book.h"

std::string Book::getTitle() const{
  return title;
};

std::string Book::getAuthor() const{
  return author;
};

std::string Book::getDate() const{
  return date;
};

int Book::getPrice() const{
  return price;
};


Book::Book(std::string title, std::string author, long int price, std::string date)
{
  this->title=title;
  this->author=author;
  this->price=price;
  this->date=date;
};

Book::~Book(){};
