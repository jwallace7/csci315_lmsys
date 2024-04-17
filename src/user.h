#ifndef USER_H
#define USER_H

#include <iostream>
#include <string>

using namespace std;

class user
{
public:
  // GET FUNCTIONS
  int getBookIndex(string bookName) const; // Returns the index of bookName in the user's book list.
  // Postcondition: Returns the index of the book in the book array. If it doesn't exist, returns -1.

  bool hasBook(string bookName) const; // Checks to see if this user has a book of bookName.
  // Postcondition: Returns true if bookName is in the user's book list, false otherwise.

  bool isAdmin() const; // Checks to see if this user is an admin.
  // Postcondition: Returns true if this user is an admin, false otherwise.

  bool hasMaxBooks() const; // Checks to see if the user has the maximum number of books.
  // Postcondition: Returns true if the user has the maximum number of books, false otherwise.

  string getUsername() const; // Returns the username of the user.
  // Postcondition: Returns the string of the username.

  // SET FUNCTIONS

  void addBook(string bookName); // Adds a book to the user's inventory.
  void removeBook(string bookName); // Removes a book from the user's inventory if it has the book.

  // PRINT FUNCTIONS

  void printBooks() const; // Prints out the user's books.
  void printName() const; // Prints the username of the user

  user(string name, bool ad); // Basic constructor function.

private:
  bool admin; // Whether or not the user is an admin.
  string username; // Username of the user.
  string books[5]; // String array of books the user owns.
  int bookCount = 0; // Count of how many users the book has.
};

int user::getBookIndex(string bookName) const {
  for (int i = 0; i < 5; i++)
    if (books[i] == bookName)
      return i;

  return -1;
}//end getBookIndex

bool user::hasBook(string bookName) const 
{ return (getBookIndex(bookName) != -1); }//end hasBook

bool user::isAdmin() const 
{ return admin; }//end isAdmin

bool user::hasMaxBooks() const
{ return bookCount == 5; }//end hasMaxBooks

string user::getUsername() const
{ return username; }//end getUsername

void user::addBook(string bookName) {
  if (not hasBook(bookName)) // If the user doesn't have the book already
    if (not hasMaxBooks()) // If the user's book count isn't full
    {
      int i = 0;
      while(books[i] != "")
      { i++; }//end while
      books[i] = bookName;
          
      bookCount += 1; // Increment book count by 1
    } else
      cout << "You have the maximum number of books." << endl;//end else
    else
      cout << "You already have this book." << endl;//end else
}//end addBook

void user::removeBook(string bookName) {
  int index = getBookIndex(bookName);
  if (index >= 0) { // If the index is valid
    books[index] = ""; // Remove the book from the array
    bookCount -= 1;
  } else
    cout << "You do not have this book." << endl;
}//end removeBook

void user::printBooks() const {
  cout << "Books: " << endl;
  for (int i = 0; i < 5; i++)
    cout << books[i] << endl;
}//end printBooks

void user::printName() const {
  cout << username << endl;
}//end printName

user::user(string name, bool ad) {
  username = name;
  admin = ad;
}//end constructor

#endif