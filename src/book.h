#ifndef BOOK_H
#define BOOK_H

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class book
{
public:
  // OPERATOR OVERLOADING
  const book& operator=(const book&); // Assignment operator
  bool operator==(const book&) const; 
  // Equality operator. Used for sorting.
  // Postcondition: Returns true if the titles are the same.
  bool operator>=(const book&) const;
  // Greater than or equal to operator. Used for sorting.
  // Postcondition: Returns true if the title of this book is greater than or
  // equal to the other book.

  // SET FUNCTIONS
  void setTitle(string t); // Function to set title
  void setAuthor(string name); // Function to set author
  void setDate(int date); // Function to set datePublished
  void setCatalogNumber(double num); // Function to set catalogNumber
  void setBorrowStatus(bool stat); // Function to set borrowed

  // GET FUNCTIONS
  string getTitle() const; // Function to get title
  string getAuthor() const; // Function to get author name
  int getDate() const; // Function to get datePublished
  bool isBorrowed() const; // Function to get if the book is borrowed or not
  double getCatalogNumber() const; // Function to get catalog number

  // PRINT FUNCTIONS
  void printTitle() const; // Function to print book title *use for selection options in search*
  void printInfo() const; // *Alyssa* Function to print book information to console
  void printInfo(ofstream outFile) const; // *Alyssa* Function to print book information to an output file

  // Constructor. Borrower always starts off as an empty string, and the book always starts off as not borrowed
  book(string newTitle = "", string name = "", int publishDate = 1990, double num);

  // Copy constructor. Makes an identical book to the book provided in the copy constructor.
  book(const book&);

private:
  string title, author, borrower; // Book title and author (Borrower will be implemented in phase 2)
  int datePublished = 1990; // Date published
  bool borrowed = false; // Boolean value to determine borrow status (implemented in phase 2)
  double catalogNumber; // Book catalog number, Dewey decimal system

  void copyBook(const book&); // Private function for copying books.
};

// OPERATOR OVERLOADING
const book& book::operator=(const book& otherBook)
{
  if (this != &otherBook) // Checks self-assignment
  {
    copyBook(otherBook);
  }
	
  return *this;
}//end assignment operator

bool book::operator==(const book& otherBook) const
{ return (title == otherBook.getTitle()); }//end equality operator

bool book::operator>=(const book& otherBook) const
{ return (title >= otherBook.getTitle()); }//end gtoe operator

// SET FUNCTIONS

void book::setTitle(string t)
{ title = t; }//end setTitle

void book::setAuthor(string name)
{ author = name; }//end setAuthor

void book::setDate(int date)
{ datePublished = date; }//end setDate

void book::setCatalogNumber(double num)
{ catalogNumber = num; }//end setCatalogNumber

void book::setBorrowStatus(bool stat)
{ borrowed = stat; }//end setBorrowStatus

// GET FUNCTIONS

string book::getTitle() const
{ return title; }//end getTitle

string book::getAuthor() const
{ return author; }//end getAuthor

int book::getDate() const
{ return datePublished; }//end getDate

bool book::isBorrowed() const
{ return borrowed; }//end isBorrowed

double book::getCatalogNumber() const
{ return catalogNumber; }//end getCatalogNumber

// PRINT FUNCTIONS
void book::printTitle() const
{ cout << title << endl; }//end printTitle

// CONSTRUCTOR

book::book(string newTitle, string name, int publishDate, double num)
{
	setTitle(newTitle);
	setAuthor(name);
	setDate(publishDate);
	setCatalogNumber(num);
}//end book

book::book(const book& otherBook) 
{ copyBook(otherBook); }//end copy constructor

// PRIVATE FUNCTIONS

void book::copyBook(const book& otherBook) {
    title = otherBook.getTitle();
    author = otherBook.getAuthor();
    borrowed = otherBook.isBorrowed();
    datePublished = otherBook.getDate();
    catalogNumber = otherBook.getCatalogNumber();
}//end copyBook

#endif
