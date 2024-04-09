#ifndef BOOK_H
#define BOOK_H

#include <iostream>
#include <string>

using namespace std;

class book
{
public:
  // Operator overloaders
  const book& operator=(const book&);
  bool operator==(const book&) const;
  bool operator>=(const book&) const;
  
  void setTitle(string t); // Function to set title
  void setAuthor(string name); // Function to set author
  void setDate(int date); // Function to set datePublished
  void setCatalogNumber(double num); // Function to set catalogNumber
  void setBorrowStatus(bool stat); // Function to set borrowed

  string getTitle(); // Function to get title
  string getAuthor(); // Function to get author name
  int getDate(); // Function to get datePublished
  bool isBorrowed(); // Function to get if the book is borrowed or not
  double getCatalogNumber(); // Function to get catalog number

  void printTitle(); // Function to print book title *use for selection options in search*
  void printInfo(); // Function to print book information

  // Constructor. Borrower always starts off as an empty string, and the book always starts off as not borrowed
  book(string newTitle = "", string fName = "", string lName = "", int publishDate = 1990);

private:
  // Book title and author
  string title, author, borrower;

  // Date published
  int datePublished = 1990;

  // Boolean value to determine borrow status
  bool borrowed = false;
  // Book catalog number
  double catalogNumber;
};



#endif
