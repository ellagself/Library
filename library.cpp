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
  delete curr; 
}

void Library::insert_sorted(string author, string title, string isbn, int pages, int year, float price){
  Entry* newEntry = new Entry;
  newEntry->book.author = author;
  newEntry->book.title = title;
  newEntry->book.isbn = isbn;
  newEntry->book.pages = pages;
  newEntry->book.year = year;
  newEntry->book.price = price;
  newEntry->next = NULL; 
  cout << "Initial head: " << head << endl;  //DEBUG
  cout << "Inserting: " << title << " by " << author << endl; //DEBUG OUTPUT

  
  // if list is empty insert here
  if(head == NULL || head->book.title > title){
    newEntry->next = head;
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
    string result;
    
    if (author.empty()) {
      while (curr != NULL){
	result += curr->book.title +" by " + curr->book.author + "\n";
	curr = curr->next;
    }
      
      cout << "Books found: " << result << endl; //DEBUG OUTPUT
    return result;
  }
     while (curr != NULL) {
        if (curr->book.author == author) {
	  return curr->book.title + " by " + curr->book.author;  // Return title if author matches
        }
        curr = curr->next;
    }
     return result.empty() ? "Author not found.": result;  // Return empty string if author not found
}


// reverse lookup, find books by certain author
string Library::find_album(string title){
   Entry* curr = head;
   string authors ="";
   
   while (curr != NULL){
     if (curr->book.title == title){
       authors += curr->book.author + ","; //add author to list
     }
     curr = curr->next; 
   }
   if (!authors.empty()) {
     authors = authors.substr(0, authors.length()-2);
   } else {
     return "No authors found for this title.";
   }
   
   return authors;
 }


void Library::delete_book(string author, string title){
  Entry *temp = head;
  Entry* eraser = NULL;

  // case 1, empty list
  if (head == NULL){
    return;
    // nothing to delete, just returns
  }
  // case 2, delete the head of the list
  if(head->book.author == author && head->book.title == title) {
    eraser = head;
    head = head->next;
    delete eraser;
    return; 
  }

  while(temp->next != NULL) {
    if(temp->next->book.author == author && temp->next->book.title == title){
      eraser = temp->next;
      temp->next = eraser->next;
      delete eraser;
      return;
    }
    temp = temp->next;
  }
}

bool Library::loadFromFile(string filename) {
    ifstream file(filename);
    if (!file.is_open()) {
        cout<< "Failed to open file: " << filename << endl;
        return false;
    }

    string author, title, isbn;
    int pages, year;
    float price;

    while (file >> author >> title >> isbn >> pages >> year >> price) {
      insert_sorted(author, title, isbn, pages, year, price);
    }

    file.close();
    cout << "Books loaded from file." << endl;
    return true;
}

bool Library::saveToFile(string filename) {
    //open file in write mode
    ofstream outFile(filename);

    if (!outFile) {
        cerr << "Error opening file for writing." << endl;
        return false;
    }

    // traverse through list and write each book detail to file
    Entry* curr = head;
    while (curr != NULL) {
        outFile << curr->book.author << "\n"
                << curr->book.title << "\n"
                << curr->book.pages << "\n"
                << curr->book.isbn << "\n"
                << curr->book.price << "\n"
                << curr->book.year << "\n";
        curr = curr->next;
    }

    //close file after writing
    outFile.close();
    cout << "Library saved to file: " << filename << std::endl;
    return true;
}
