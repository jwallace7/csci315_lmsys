#ifndef BOOKDATABASE_H
#define BOOKDATABASE_H

#include <iostream>

using namespace std;

#include "book.h"
#include "orderedLinkedList.h"

class bookDatabase : public orderedLinkedList<book>
{
public:
  void loadFromFile(ifstream inFile); // *Alyssa* Function to load the address book from a file
  void saveToFile(ofstream outFile); // *Alyssa* Function to save the address book to a file

  void addBook(book newBook);
  // Function to insert a book in the ordered linked list
  // Precondition: the book object must already exist
  // and be passed as a parameter.
  // Postcondition: newBook will be part of the ordered
  // linked list, and count will be incremented by 1.
  void removeBook(book newBook);
  // Function to remove a book from the ordered linked list.
  // Precondition: The unique identifier we use for a book
  // (i.e., the title, the dewey decimal) will be the only
  // identifier needed, because of the way the '==' and
  // '>=' operators are overloaded
  
};

#endif