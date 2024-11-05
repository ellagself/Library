/**
 * @file libary.cpp
 * @author Mangos: Cameron Tucker and Ella Self
 * @date 2024-11-05
 * @brief libary methods
 * 
 * library functions 
 */

#include "library.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;


// constructor
Library::Library(){
  head = NULL;
}


//destructor
Library:: ~Library(){
  destructHelper(head);
}


//destruct helper
Library::destructHleper(Entry *curr){
  if( curr == NULL) {
    return;
  }

  destructHelper(curr->next);
  cout << "Removing book: " << curr->author << " " << curr->title << endl;

  delete curr; 
}
