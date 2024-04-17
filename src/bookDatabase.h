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
};

#endif