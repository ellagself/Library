/**
 * @file main.cpp
 * @author Ella Self
 * @date 2024-11-05
 * @brief main file for Library
 * 
 * user interaction, function calls
 */

#include "library.h"
#include <iostream>

using namespace std;

void menu(){
  cout<<"\nLibrary Menu\n";
  cout<<"1. Add Book\n";
  cout<<"2. Find Book by Author\n";
  cout<<"3. Find Book by Title\n";
  cout<<"4. Delete Book\n";
  cout<<"5. Display All Books\n";
  cout<<"6. Load Books from File\n";
  cout<<"7. Save Books to File\n";
  cout<<"8. Exit\n";
  cout<<"Enter Choice: ";
}

int main() {
  Library library;
  int choice, pages, year;
  string title, author, filename, isbn;
  float price;

  do {
    menu();
    cin>>choice;
    cin.ignore();

    switch (choice) {
    case 1:
      cout<<"Enter title: ";getline(cin, title);
      cout<<"Enter author: ";getline(cin, author);
      cout<<"Enter pages: ";cin>>pages;
      cout<<"Enter ISBN: ";cin>>isbn;
      cout<<"Enter price: ";cin>>price;
      cout<<"Enter year: ";cin>>year;
      library.insert_sorted(author, title);
      break;

    case 2:
      cout<<"Enter author to search for: ";
      getline(cin, author);
      library.find_author(author);
      break;

    case 3:
      cout<<"Enter title to search for: ";
      getline(cin, title);
      library.find_album(title);
      break;

    case 4:
      cout<<"Enter author of book to delete: ";
      getline(cin, author);
      cout<<"Enter title of book to delete: ";
      library.delete_book(author, title);
      break;

    case 5:
      library.find_author("");//lists books
      break;

    case 6:
      cout<<"Enter filename to load: ";
      getline(cin,filename);
      if (library.loadFromFile(filename)){
	cout<<"Library loaded successfully.\n";
      }else{
	cout<<"Error loading file.\n";
      }
      break;

    case 7:
      cout<<"Enter filename to save: ";
      getline(cin,filename);
      if (library.saveToFile(filename)){
	cout<<"Library saved successfully.\n";
      }else{
	cout<<"Error saving file.\n";
      }
      break;
    }
  }while (choice != 8);

  cout<<"Exiting the library program.\n";
  return 0;
}
