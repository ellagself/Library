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

void Library::insert_sorted(string author, string title){
  Entry* newEntry = new Entry;
  newEntry->author = authore;
  newEntry->title = title; 
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
string Library::find_author(string title){
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


void Library::delete(string author, string title){
  Entry *temp;
  Entry* eraser = NULL;

  // case 1, empty list
  if (head == NULL){
    return;
    // nothing to delete, just returns
  }
  // case 2, delete the head of the list
  if(head->author == author) {
    eraser = head;
    head = head->next;
    delete eraser;
    return; 
  }

  while(temp->next != NULL) {
    if(temp->next->author == author){
      eraser = temp->next;
      temp->next = eraser->next;
      delete eraser;
      return;
    }
    temp = temp->next;
  }
}
