#ifndef BOOK_H
#define BOOK_H

// book class or struct
#include <string>
using namespace std;

struct Book{
  string author, title, isbn;
  int pages, year;
  float price;
  Book(const string& author = "", const string& title = "", const string& isbn = "", int pages = 0, int year = 0, float price =0.0f)
    : author (author), title(title), isbn(isbn), pages(pages), year(year), price(price) {} //defines constructor for book with default initial values
}; 
#endif
