#ifndef BOOK_H
#define BOOK_H

#include<vector>
#include<stdlib.h>
#include<sstream>
#include<iostream>
#include<cstdlib>
#include<windows.h>
#include<string>
#include<algorithm>
#include<iterator>

class Book
{
public:
  Book(std::string title, std::string author, long int price, std::string date);
  ~Book();

  std::string getTitle() const;
  std::string getAuthor() const;
  std::string getDate() const;
  int getPrice() const;

private:
  std::string title;
  std::string author;
  std::string date;
  long int price;
};

#endif // BOOK_H
