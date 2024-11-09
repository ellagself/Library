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



/**
 * library constructor
 *
 * @pre 
 * @post library exists
 * 
 */
Library::Library(){
  head = NULL;
}




/**
 * destructor
 *
 * @pre library exists
 * @return Library:: 
 * @post library is destructed
 * 
 */
Library:: ~Library(){
  destructHelper(head);
}



/**
 * destruct helper
 *
 * @param Entry *curr 
 * @pre library exists, destructor is called
 * @post library destructed
 * 
 */
Library::destructHelper(Entry *curr){
  if( curr == NULL) {
    return;
  }

  destructHelper(curr->next);
  cout << "Removing book: " << curr->author << " " << curr->title << endl;

  delete curr; 
}


/**
 * inserts sorted into library
 *
 * @param string author 
 * @param string title 
 * @param string isbn 
 * @param int pages 
 * @param int year 
 * @param float price 
 * @pre library exists, new values exist
 * @return void 
 * @post inserts new sort
 * 
 */
void Library::insert_sorted(string author, string title, string isbn, int pages, int year, float price){
  Entry* newEntry = new Entry;
  newEntry->book = Book(author, title, isbn, pages, year, price); 
  newEntry->next = NULL; 

  // if list is empty insert here
  if(head == NULL){
    newEntry-> next = head;
    head = newEntry;
  }
  else {
    Entry* curr = head;
    while( curr->next != NULL && curr->next->title < title){
      curr = curr->next;
    }
    newEntry->next = curr->next;
    curr->next = newEntry; 
  }
}

//lookup but its find_author

/**
 * find author
 *
 * @param string author 
 * @pre 
 * @return string 
 * @post title is found via the author
 * 
 */
string Library::find_author(string author){
    Entry* curr = head;
    while (curr != NULL){
      if (curr->author == author){
	return curr->title; 
      }
      curr = curr->next;
    }
    return ""; 
  }


// reverse lookup, find books by certain author

/**
 * find album
 *
 * @param string title 
 * @pre 
 * @return string 
 * @post author is found by title
 * 
 */
string Library::find_album(string title){
   Entry* curr = head;
   while (curr != NULL){
     if (curr->title == title){
       return curr->author; // how do i get it to return all of them
     }
     curr = curr->next; 
   }
   return "";
 }



/**
 * delete book
 *
 * @param string author 
 * @param string title 
 * @pre book exists
 * @return void 
 * @post book is removed
 * 
 */
void Library::delete_book(string author, string title){
  Entry *temp;
  Entry* eraser = NULL;

  // case 1, empty list
  if (head == NULL){
    return;
    // nothing to delete, just returns
  }
  // case 2, delete the head of the list
  if(head->author == author && head-> title == title ) {
    Entry* temp = head;
    head = head->next;
    delete temp;
    return; 
  }

  Entry* curr = head; 
  while(curr->next != NULL) {
    if(curr->next->author == author && curr->next->title == title){
      Entry* temp = curr->next;
      curr->next = curr->next->next;
      delete eraser;
      return;
    }
    curr = curr->next;
  }
}



/**
 * loads file info
 *
 * @param string fileName 
 * @pre 
 * @return void 
 * @post file info is loaded
 * 
 */
void Library::load_from_file(string fileName){
  ifstream file(fileName);

  if(!file.is_open()){
    cout << "File could not open. " << endl;
    return; 
  }

  string author, title; 
  while (getline(author, title)){
      insert_sorted(author, title);
    }
  
  cout << "File has been read." << endl; 
 
  file.close(); 
}





/**
 * stores to file
 *
 * @param string fileName 
 * @pre 
 * @return void 
 * @post new info is stored to file
 * 
 */
void Library::store_to_file(string fileName){
  ofstream file(fileName);
  if(!file.is_open()){
    return;
  }
  
  Entry* curr = head; 
  
  while( curr != NULL){
    file << curr->author<< "\n" << curr->title << "\n";
    curr = curr->next;
  }

  file.close(); 
}



/**
 * print
 *
 * @pre list exists, there is something to print
 * @return void 
 * @post list is printed
 * 
 */
void Library::print(){
  cout << "START -> ";
  printHelper(head); 
  cout << " END" << endl;
}



/**
 * print helper
 *
 * @param Entry* curr 
 * @pre list exists
 * @return void 
 * @post list is printed
 * 
 */
void Library::printHelper(Entry* curr){
  if (curr == NULL){
    cout << "Library is empty. " << endl;
    return;
  }
  
  cout << curr->author << " " << curr->title << endl; 
  
  if (curr->next != NULL){
    cout << " -> ";
  }

  printHelper(curr->next);
}



/**
 * push front
 *
 * @param string author 
 * @param string title 
 * @pre new data
 * @return void 
 * @post data is pushed to front
 * 
 */
void Library::push_front(string author, string title){
  Entry *newEntry = new Entry;
  newEntry->author = author;
  newEntry->title = title;
  
  newEntry->next = head;
  head = newEntry; 
}


/**
 * push back
 *
 * @param string author 
 * @param string title 
 * @pre new data exists
 * @return void 
 * @post data is pushed to back
 * 
 */
void Phonebook::push_back(string author, string title){
  Entry* newEntry = new Entry;
  newEntry->author = author;
  newEntry->title = title; 
  newEntry->next = NULL;
  
  // case 1, empty list
  if (head == NULL){
    head = newEntry;
  }
  // case 2, list is !empty
  else {
    Entry *tail = head;

    // get to the end
    while (tail->next != NULL) {
      tail = tail->next;
    }

    tail->next = newEntry;
  }
}
