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

#include <string>
using namespace std; 

class Library {
 private:
  Entry *head;
  void destructHelper(Entry *curr); 
  
 public:
  Library(); // constructor
  ~Library(); // destructor
  void insert_sorted(string author, string title);
  void find_author(string title); // lookup, finds books by same author
  void find_album(string title); // reverse lookup, finds books same name 
  void delete(string author, string title);
};

#endif
