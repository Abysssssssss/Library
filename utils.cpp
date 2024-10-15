#include"utils.h"

void printBookInfo(const Book &book){
  std::cout<<"Название: " + book.getTitle()
            <<" Автор: " + book.getAuthor()
            <<" Дата издания: " + book.getDate()
            <<" Цена: " + std::to_string(book.getPrice())+"\n";
}

void printBooksInfo(std::vector<Book*> *books){
  if(!books)
    return;

  for(const auto& book : *books){
    printBookInfo(*book);
  }
}

void menu(){
  BookStore bookstore;
  int choose=0;
  std::string chooseBuff;
  while(choose!=6){
      choose = 0;
      system("cls");
      std::cout<<"1. Добавить новую книгу.\n"
                  "2. Удалить книгу.\n"
                  "3. Найти книгу.\n"
                  "4. Показать все книги.\n"
                  "5. Найти книгу в ценовом диапазоне.\n"
                  "6. Выйти.\n"
                  "Введите: ";
      getline(std::cin, chooseBuff);
      std::stringstream(chooseBuff) >> choose;
      switch(choose)
      {

        case 1:{
          std::string title;
          std::string titleBuff="";
          std::string author;
          std::string authorBuff="";
          std::string date;
          std::string dateBuff="";
          long int price;
          std::string priceBuff="";
          std::cout<< "Введите название книги: ";
          getline(std::cin, titleBuff);
          std::stringstream(titleBuff) >> title;
          std::cout<< "Введите автора: ";
          getline(std::cin, authorBuff);
          std::stringstream(authorBuff) >> author;
          std::cout<< "Введите год издания: ";
          getline(std::cin, dateBuff);
          std::stringstream(dateBuff) >> date;
          std::cout<< "Введите цену книги: ";
          getline(std::cin, priceBuff);
          std::stringstream(priceBuff) >> price;
          Book* book = new Book(title, author, price, date);
          bookstore.addBook(book);
          system("pause");
          break;
        }

        case 2:{
          if(bookstore.isEmpty()==false){
            std::cout<<"Список книг пуст.\n";
            system("pause");
            break;
          }
          else{
            std::string title;
            std::string titleBuff="";
            std::cout<< "Введите название книги: ";
            getline(std::cin, titleBuff);
            std::stringstream(titleBuff) >> title;
            if(bookstore.removeBook(title)){
                std::cout<<"Книга успешно удалена!\n";
                system("pause");
                break;
            }
          }
          std::cout<<"Книга не была найдена!\n";
          system("pause");
          break;
        }

        case 3:{
          if(!bookstore.isEmpty()){
            std::cout<<"Список книг пуст.\n";
            system("pause");
            break;
          }
          else{
            std::string title;
            std::string titleBuff="";
            std::cout << "Введите название книги: ";
            getline(std::cin, titleBuff);
            std::stringstream(titleBuff) >> title;
            auto book = bookstore.findBook(title);
            if(book != nullptr){
            printBookInfo(*book);
            }
            else{
            std::cout<<"Книга не была найдена!\n";
            }
          }
          system("pause");
          break;
        }

        case 4:{
          if(!bookstore.isEmpty()){
            std::cout<<"Список книг пуст.\n";
            system("pause");
            break;
          }
          else{
          int sortType=0;
          std::string buffSort;
              while(sortType!=6){
                  system("cls");
                  std::cout<<"1. Сортировка по автору.\n2. Сортировка по названию.\n3. Сортировка по дате.\n(6) Выход\nВведите: ";
                  getline(std::cin, buffSort);
                  std::stringstream(buffSort) >> sortType;

                  switch(sortType){
                    case 1:{
                        auto books = bookstore.listBooks(BookStore::SortType::Title);
                        printBooksInfo(&books);
                        system("pause");
                        break;
                    }

                    case 2:{
                        auto books = bookstore.listBooks(BookStore::SortType::Author);
                        printBooksInfo(&books);
                        system("pause");
                        break;
                    }

                    case 3:{
                        auto books = bookstore.listBooks(BookStore::SortType::Date);
                        printBooksInfo(&books);
                        system("pause");
                        break;
                    }

                    default:{
                        if(sortType != 6){
                            std::cout<<"Введено неверное значение.\n";
                            system("pause");
                        }
                    break;
                    }

                  }
              }
          }

        break;
        }

        case 5:{
            if(!bookstore.isEmpty()){
                std::cout<<"Список книг пуст.\n";
                system("pause");
                break;
            }
            int min;
            std::string minBuff;
            int max;
            std::string maxBuff;
            std::cout << "Введите минимальное значениe диапазона: ";
            getline(std::cin, minBuff);
            std::stringstream(minBuff) >> min;
            std::cout << "Введите максимальное значение диапазона: ";
            getline(std::cin, maxBuff);
            std::stringstream(maxBuff) >> max;
            for(auto& i : bookstore.findBooksInPriceRange(min, max)){
            printBookInfo(*i);
            }
            system("pause");
            break;
        }

        default:{
            if(choose != 6){
                std::cout<<"Введено неверное значение\n";
                system("pause");
            }
            break;
        }
      }
  }
}
