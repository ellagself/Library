/**
 * @file library.h
 * @author Mangos: Cameron Tucker and Ella Self
 * @date 2024-11-05
 * @brief library class
 * 
 * class definitions for library
 */

#ifndef LIBRARY_H
#define LIBRARY_H

#include "book.h"
#include <string>
using namespace std; 

struct Entry {
  Book book;
  Entry* next;

  Entry () : book(), next(nullptr) {}
};

class Library {
 private:
  Entry *head;
  void destructHelper(Entry *curr); 
  
 public:
  Library(); // constructor
  ~Library(); // destructor
  
  void insert_sorted(string author, string title);
  string find_author(string title); // lookup, finds books by same author
  string find_album(string title); // reverse lookup, finds books same name 
  void delete_book(string author, string title); //having problems with the name of this, changed it to delete_book
  bool loadFromFile(string filename);
  bool saveToFile(string filename);
};

#endif
