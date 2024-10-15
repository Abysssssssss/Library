#ifndef UTILS_H
#define UTILS_H

#include "Book.h"
#include "BookStore.h"

void printBookInfo(const Book &Book);
void printBooksInfo(std::vector<Book*> *books);

void menu();


#endif // UTILS_H
