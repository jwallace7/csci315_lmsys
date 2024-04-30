#ifndef USER_H
#define USER_H

#include <iostream>
#include <string>

// NOTE - Need to overload = operator

class user
{
public:
  // GET FUNCTIONS
  int getBookIndex(std::string bookName) const; // Returns the index of bookName in the user's book list.
  // Postcondition: Returns the index of the book in the book array. If it doesn't exist, returns -1.
	
  std::string getUsername() const; // Returns the username of the user.
  // Postcondition: Returns the std::string of the username.
	
	// SET FUNCTIONS
	void setUsername(std::string str); // Sets the username of the user
	// Postcondition: username = str
	
	void setPassword(std::string str); // Sets the password of the user
	// Postcondition: password = str

	// VALIDATION FUNCTIONS
  bool hasBook(std::string bookName) const; // Checks to see if this user has a book of bookName.
  // Postcondition: Returns true if bookName is in the user's book list, false otherwise.

  bool isAdmin() const; // Checks to see if this user is an admin.
  // Postcondition: Returns true if this user is an admin, false otherwise.

  bool hasMaxBooks() const; // Checks to see if the user has the maximum number of books.
  // Postcondition: Returns true if the user has the maximum number of books, false otherwise.
	
	bool validate(std::string pass) const; // Checks to see if password is same as user.
	// Postcondition: Returns true if pass is the same as password.
	
	// BOOK FUNCTIONS

  void addBook(std::string bookName); // Adds a book to the user's inventory.
  void removeBook(std::string bookName); // Removes a book from the user's inventory if it has the book.

  // PRINT FUNCTIONS

  void printBooks() const; // Prints out the user's books.
  void printName() const; // Prints the username of the user

  user(std::string name, std::string pass, bool ad); // Basic constructor function.

private:
  bool admin; // Whether or not the user is an admin.
	std::string password;
  std::string username; // Username of the user.
  std::string books[5]; // String array of books the user owns.
  int bookCount = 0; // Count of how many users the book has.
};

// GET FUNCTIONS

std::string user::getUsername() const
{ return username; }//end getUsername

int user::getBookIndex(std::string bookName) const {
  for (int i = 0; i < 5; i++)
    if (books[i] == bookName)
      return i;

  return -1;
}//end getBookIndex

// SET FUNCTIONS

void setUsername(std::string str)
{ username = str; }//end setUsername

void setPassword(std::string str)
{ password = str; }//end setPassword

// VALIDATION FUNCTIONS

bool user::hasBook(std::string bookName) const 
{ return (getBookIndex(bookName) != -1); }//end hasBook

bool user::isAdmin() const 
{ return admin; }//end isAdmin

bool user::hasMaxBooks() const
{ return bookCount == 5; }//end hasMaxBooks

std::string user::validate(std::string pass) const
{ return pass == password; }//end validate

void user::addBook(std::string bookName) {
  if (!hasBook(bookName)) // If the user doesn't have the book already
    if (!hasMaxBooks()) // If the user's book count isn't full
    {
      int i = 0;
      while(books[i] != "")
      { i++; }//end while
      books[i] = bookName;
          
      bookCount += 1; // Increment book count by 1
    } else
      std::cout << "You have the maximum number of books." << std::endl;//end else
    else
      std::cout << "You already have this book." << std::endl;//end else
}//end addBook

void user::removeBook(std::string bookName) {
  int index = getBookIndex(bookName);
  if (index >= 0) { // If the index is valid
    books[index] = ""; // Remove the book from the array
    bookCount -= 1;
  } else
    std::cout << "You do not have this book." << std::endl;
}//end removeBook

void user::printBooks() const {
  std::cout << "Books: " << std::endl;
  for (int i = 0; i < 5; i++)
    if (books[i] != "")
      std::cout << books[i] << std::endl;
}//end printBooks

void user::printName() const {
  std::cout << username << std::endl;
}//end printName

user::user(std::string name, std::string pass, bool ad) {
  username = name;
	password = pass;
  admin = ad;
}//end constructor

#endif