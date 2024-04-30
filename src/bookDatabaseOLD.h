#ifndef BOOKDATABASEOLD_H
#define BOOKDATABASEOLD_H

#include <iostream>
#include <string.h>

#include "book.h"
#include "orderedLinkedList.h"

class bookDatabase : public orderedLinkedList<book>
{
public:
  book getBookFromTitle(std::string title);
  // Function that gets a book based on the given title string.
  // Precondition: The book exists in the book database.
  // Postcondition: Returns a book if its found, returns an empty book if not.

  // LOAN FUNCTIONS
  void printAllLoans();

  // DATA MANAGEMENT FUNCTIONS
  void loadFromFile(ifstream inFile); // *Alyssa* Function to load the address book from a file
  void saveToFile(ofstream outFile); // *Alyssa* Function to save the address book to a file
};

book bookDatabase::getBookFromTitle(std::string title) {
  nodeType<book> *current; // pointer to traverse the linked list
  current = first;

  while (current != nullptr) // While loop
    if (current->info.getTitle() == title) // If the title matches
      return current->info; // Return the book
    else // Otherwise, iterate through the next book
      current = current->link;

  return book(); // If no book is found, return an empty book
}//end getBookFromTitle

void bookDatabase::printAllLoans()
{
    nodeType<book>* current; // pointer to traverse the linked list
    current = first;

    while (current != nullptr)
    {
      if (current->info.isBorrowed())
      {
        current->info.printTitle();
        cout << "Current Borrower: " << current->info.currentBorrower() << endl;
      }
      current = current->link;
      cout << endl;
    }
}// end printAllLoans


#endif