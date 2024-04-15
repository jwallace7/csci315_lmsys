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
  const book& operator=(const book&);
  bool operator==(const book&) const;
  bool operator>=(const book&) const;

  // SET FUNCTIONS
  void setTitle(string t); // Function to set title
  void setAuthor(string name); // Function to set author
  void setDate(int date); // Function to set datePublished
  void setCatalogNumber(double num); // Function to set catalogNumber
  void setBorrowStatus(bool stat); // Function to set borrowed

  // GET FUNCTIONS
  const string getTitle(); // Function to get title
  const string getAuthor(); // Function to get author name
  const int getDate(); // Function to get datePublished
  const bool isBorrowed(); // Function to get if the book is borrowed or not
  const double getCatalogNumber(); // Function to get catalog number

  const void printTitle(); // Function to print book title *use for selection options in search*
  const void printInfo(); // *Alyssa* Function to print book information to console
  const void printInfo(ofstream outFile); // *Alyssa* Function to print book information to an output file

  // Constructor. Borrower always starts off as an empty string, and the book always starts off as not borrowed
  book(string newTitle = "", string name = "", int publishDate = 1990);

private:
  string title, author, borrower; // Book title and author (Borrower will be implemented in phase 2)
  int datePublished = 1990; // Date published
  bool borrowed = false; // Boolean value to determine borrow status (implemented in phase 2)
  double catalogNumber; // Book catalog number, Dewey decimal system
};

// OPERATOR OVERLOADING
const book& operator=(const book& otherBook)
{
	title = otherBook.getTitle();
	author = otherBook.getAuthor();
	borrowed = otherBook.isBorrowed();
	datePublished = otherBook.getDate();
	catalogNumber = otherBook.getCatalogNumber();
}

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

const string book::getTitle()
{ return title; }//end getTitle

const string book::getAuthor()
{ return author; }//end getAuthor

const int book::getDate()
{ return datePublished; }//end getDate

const bool book::isBorrowed()
{ return borrowed; }//end isBorrowed

const double book::getCatalogNumber()
{ return catalogNumber; }//end getCatalogNumber

// CONSTRUCTOR

book::book(string newTitle, string name, int publishDate, double num)
{
	setTitle(newTitle);
	setAuthor(name);
	setDate(publishDate);
	setCatalogNumber(num);
}//end book

#endif
