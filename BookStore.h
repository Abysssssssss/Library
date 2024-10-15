#ifndef BOOKSTORE_H
#define BOOKSTORE_H

#include"book.h"

class BookStore
{
public:
  BookStore();
  ~BookStore();

  enum class SortType{
    Title,
    Author,
    Date
  };

  void addBook(Book* _book);
  Book* findBook(const std::string &_title);
  bool removeBook(const std::string &_title);
  std::vector<Book*> listBooks(SortType sortType);

  std::vector<Book*> findBooksInPriceRange(int _minPrice,int _maxPrice);

  bool isEmpty();

private:
  std::vector<Book*> Books;
};

#endif // BOOKSTORE_H
