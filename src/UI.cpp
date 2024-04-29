#include <iostream>
#include <fstream>
#include <string>
#include "bookDatabase.h"
#include "user.h"

using namespace std;

enum systemStatus{HOME, USER, ADMIN, EXIT}; // special data type to keep track of the current menu

// menu display functions
void displayPreMenu();
void displayMenuUser();
void displayMenuAdmin();


int main()
{
  int choice;
  char ch;
  string username;
  string pass;
  bookDatabase library; // database with all books in the library
  systemStatus status = HOME;
  user* currentUser; // will be the current loaded user in the system
	book* tempBook; //will be a temp book, for adding a book to the system
	user* newUser; // used for adding a new user to the database
  // eventually create a user database of some kind

  // will eventually need code to load data from file
  // into the "library" variable, working with Alyssa for this

  while (status != EXIT) // while user does not exit, continue looping
  {
    while (status == HOME) // loop for home menu
    {
      // display home menu
      displayPreMenu();

      // get user selection
      cin >> choice;
      cin.get(ch);
      cout << endl;

      // process user selection
      switch(choice)
      {
        // LOGIN
        case 1:
          cout << "Enter your username: " << endl; //admin's username is Admin
          getline(cin, username);
          cout << "Enter your password: " << endl;
          getline(cin, pass);
          status = USER; // temporary, for testing purposes,
                               // may be changed when authentication method is developed by Trenten/Jonathan
          // code to check user is valid and output "Invalid username and password, please try again."
          // may be coded later, i.e. week 8
          break;

        // REGISTER
        case 2:
          cout << "Enter your new username: " << endl;
          getline(cin, username); //how to differentiate that it is new? - will use a search function to ensure
                                  // the user does not already exist, to be handled later
          cout << "Enter your new password: " << endl;
          getline(cin, pass);
          // need lines for other
          // go to user/admin menu
          break;

        // EXIT
        case 3:
          status = EXIT;
          break;

        default:
          cout << "Invalid selection." << endl;
      } //end switch
    }// end while for home menu

    while (status == USER) // loop for user menu
    {
      // code for user menu

      // print user menu
      // input user selection
      // process selection (below)
			
			// switch(choice)
			//{
					// SEARCH FOR BOOKS
					// case 1:
					// input title
					// search for title
					// if not present, print relevant message
					// if present, print book information
					
					// BORROW A BOOK
					// case 2:
					// input title
					// if(book exists)
						// if(book is available)
							// add to user's book list
							// output relevant message, also indicate number of books left
						// else(book is currently borrowed)
							// output relevant message saying the book is on hold for them
						// add username to books borrower queue
					// else (book does not exist)
						// output relevant message
						// maybe - show 
					
					// RETURN A BOOK
					// case 3:
					// print the titles of user's current loans, I.e.:
						// 1. Jack and the Beanstalk
						// 2. Little Women
						// etc.
					// get user choice
					// remove book from user's list of borrowed books
					// pop book borrower queue
					// while(current borrower has borrowed max books || current borrower username does not exist)
						// pop borrower queue
					
					// VIEW BORROWED BOOKS
					// case 4:
					// code to print users borrowed books
					// maybe - option to return to menu? this way user can view list as long as they wish
					
					// UPDATE PROFILE - Can reuse a lot of code between here and REGISTER
					// case 5:
						// print options for what the user can change (password, name, age, etc.)
						// get user choice
						// switch(choice)
						// {
									// PASSWORD
									// case 1:
									//	 code to change password
									// NAME
									// case 2:
									//   code to change name
									// ...
									// default:
						// }
					
					// LOGOUT
					// case 6:
					// cout << "You have been successfully logged out.\n";
					// status = HOME; // set status to HOME to return to home menu
					
					// default:	
			//}
    }// end while for user menu

    while (status == ADMIN) // loop for admin menu
    {
      // code for admin menu

      // print admin menu
      // input user selection
      // process selection
			
			// switch(choice)
			// {
					// ADD A BOOK
					// case 1:
					// Prompt for title
					// Input title
					// if (book already exists)
						// output relevant message
						// 
					// update tempBook
					// Prompt for author
					// Input author
					// Update tempBook
					// Prompt for date published
					// Input date published
					// Update tempBook
					// prompt for catalog number
					// input catalog number
					// update tempBook
					// add tempBook to library
					// break;
					
					// REMOVE A BOOK
					// case 2:
					// Prompt for title
					// If book exists
						// print book information
						// ask user for confirmation
						// if user confirms
							// delete book
					// else
						// print relevant message (i.e., "book does not exist in library")
					// break;
					
					// UPDATE BOOK INFORMATION
					// case 3:
					// prompt for title
					// if book exists
						// Output book information
						// Prompt for which option to edit (I.e., 1 - Title, 2 - Author)
						// switch(choice)
						// {
							// TITLE
							// AUTHOR
							// DATE PUBLISHED
							// CATALOG NUMBER
						// }
						// break;
						
					// VIEW ALL LOANS
					// case 4:
					// iterate through binary search tree (maybe develop as function in BST class? - Trenten/Jonathan)
					// if book is on loan, print
					
					// ADD/REMOVE USER (ADMINS)
					// case 5:
					// 
					// LOGOUT
					// case 6:
			// }
      // set status to...
          // HOME to return to the home menu
          // EXIT to exit the program
    }// end while for admin menu

  }// end while for UI

    // will eventually need code to save data from "library" variable
    // to a data file, working with Alyssa for this
}


// FUNCTION DEFINITIONS //

// menu display functions

void displayPreMenu()
{
  cout << "Welcome to the Virtual Library Management System" << endl;
  cout << "-------------------------------------" << endl;
  cout << "1. Login" << endl;
  cout << "2. Register" << endl;
  cout << "3. Exit" << endl;
}// end displayPreMenu()

void displayMenuUser()
{
  string username;

  cout << "Welcome " << username << ", you're logged in as a User." << endl;
  cout << endl;
  cout << "1. Search for Books" << endl;
  cout << "2. Borrow a Book" << endl;
  cout << "3. Return a Book" << endl;
  cout << "4. View Borrowed Books" << endl;
  cout << "5. Update profile" << endl;
  cout << "6. Logout" << endl;
  cout << "\nPlease select an option: ";
}// end displayMenuUser()

void displayMenuAdmin()
{
  cout << "Admin Dashboard," << endl;
  cout << "-------------" << endl;
  cout << "1. Add a Book" << endl;
  cout << "2. Remove a Book" << endl;
  cout << "3. Update Book Information" << endl;
  cout << "4. View All Loans" << endl;
  cout << "5. Add/Remove User (Admins)" << endl;
  cout << "6. Logout" << endl;
}// end displayMenuAdmin()