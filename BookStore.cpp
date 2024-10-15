#include "BookStore.h"

void BookStore::addBook(Book* _book){
  Books.push_back(_book);
}

Book* BookStore::findBook(const std::string &_title){
  for(const auto& i : Books){
    if(i->getTitle()==_title)
      return i;
  }
  return nullptr;
}

bool BookStore::removeBook(const std::string &_title){
  for(auto i = Books.begin(); i != Books.end(); i++){
    if((*i)->getTitle() == _title){
        Books.erase(i);
        return true;
    }
  }
  return false;
}

std::vector<Book*> BookStore::listBooks(BookStore::SortType sortType){
  std::vector<Book*> buff = Books;
  switch (sortType)
  {
  case SortType::Author:
    std::sort(buff.begin(), buff.end(), [](Book* first, Book* second){
      return first->getAuthor() > second->getAuthor();
    });
    break;

  case SortType::Title:
    std::sort(buff.begin(), buff.end(), [](Book* first, Book* second){
      return first->getTitle() > second->getTitle();
    });
    break;

  case SortType::Date:
    std::sort(buff.begin(), buff.end(), [](Book* first, Book* second){
      return first->getDate() > second->getDate();
    });
    break;

  default:
    break;
  }
  return buff;
}

std::vector<Book*> BookStore::findBooksInPriceRange(int _minPrice,int _maxPrice){
  std::vector<Book*> buff;
  for(const auto& i : Books){
    if(i->getPrice() >= _minPrice && i->getPrice() <= _maxPrice)
      buff.push_back(i);
  }
  return buff;
};

bool BookStore::isEmpty(){
  return !Books.empty();
};

BookStore::BookStore(){};
BookStore::~BookStore(){};
