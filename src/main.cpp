#include <iostream>
#include <fstream>

#include "bookDatabase.h"

int main() {
  ofstream outFile;
  outFile.open("test.txt");

  bookDatabase bookdb;
  book book1("History of Programming", "Miles", 2012, 73481);

  book1.addBorrower("James");
  book1.addBorrower("Jeremy");
  book1.addBorrower("Jacob");

  book book2("The Battle of Varna", "Henry", 1994, 23893);
  book book3("AI for Dummies", "Smith", 2014, 91823);

  book3.addBorrower("Malaki");

  bookdb.insert(book1);
  bookdb.insert(book2);
  bookdb.insert(book3);

  bookdb.saveToFile();
}