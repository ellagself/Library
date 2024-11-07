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
Library::Library() : head(nullptr) {}


//destructor
Library:: ~Library(){
  destructHelper(head);
}


//destruct helper, recursive
void Library::destructHelper(Entry *curr){
  if(curr == nullptr) {
    return;
  }

  destructHelper(curr->next);
  cout << "Removing book: " << curr->book.author << " " << curr->book.title << endl;

  delete curr; 
}

void Library::insert_sorted(string author, string title){
  Entry* newEntry = new Entry;
  newEntry->book.author = author;
  newEntry->book.title = title; 
  newEntry->next = NULL; 

  // if list is empty insert here
  if(head == NULL){
    newEntry-> next = head;
    head = newEntry;
  }
  else {
    Entry* curr = head;
    while( curr->next != NULL && curr->next->book.title < title){
      curr = curr->next;
    }
    newEntry->next = curr->next;
    curr->next = newEntry; 
  }
}

//lookup but its find_author
string Library::find_author(string author){
    Entry* curr = head;
    while (curr != NULL){
      if (curr->book.author == author){
	return curr->book.title; 
      }
      curr = curr->next;
    }
    return ""; 
  }


// reverse lookup, find books by certain author
string Library::find_album(string title){
   Entry* curr = head;
   string authors ="";
   
   while (curr != NULL){
     if (curr->book.title == title){
       authors += curr->book.author + "'"; //add author to list
     }
     curr = curr->next; 
   }
   if (!authors.empty()) {
     authors = authors.substr(0, authors.length()-2);
   }
   
   return authors;
 }


void Library::delete_book(string author, string title){
  Entry *temp;
  Entry* eraser = NULL;

  // case 1, empty list
  if (head == NULL){
    return;
    // nothing to delete, just returns
  }
  // case 2, delete the head of the list
  if(head->book.author == author) {
    eraser = head;
    head = head->next;
    delete eraser;
    return; 
  }

  while(temp->next != NULL) {
    if(temp->next->book.author == author){
      eraser = temp->next;
      temp->next = eraser->next;
      delete eraser;
      return;
    }
    temp = temp->next;
  }
}

void Library::loadFromFile(string filename) {
    ifstream file(filename);
    if (!file.is_open()) {
        cout<< "Failed to open file: " << filename << endl;
        return;
    }

    string author, title, isbn;
    int pages, year;
    float price;

    while (file >> author >> title >> isbn >> pages >> year >> price) {
        insert_sorted(author, title);
    }

    file.close();
    cout << "Books loaded from file." << endl;
}
