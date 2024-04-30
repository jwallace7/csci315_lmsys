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

// 4-30-24
// Note to Samantha:
// I've worked to get the home menu to a test-ready state.
// Please work on options 1, 4 and 6 for the user menu.

int main()
{
  int choice;
  char ch;
  string username;
  string pass;
  bookDatabase library; // database with all books in the library
  systemStatus status = HOME;
	userDatabase userList;
  user currentUser("", "", false); // will be the current loaded user in the system
	book* tempBook; //will be a temp book, for adding a book to the system
	user* newUser; // used for adding a new user to the database
  // eventually create a user database of some kind

  // code to load data from booko database file into library
	// code to load data from user database file into userList

  while (status != EXIT) // while user does not exit, continue looping
  {
		//***HOME MENU***//
    while (status == HOME) // while loop for home menu
    {
			// reinitialize variables
			username = "";
			pass = "";
			
      // display home menu
      displayPreMenu();

      // get user selection
      cin >> choice;
      cin.get(ch);
      cout << endl;

      // process user selection
      switch(choice)
      {
        // LOGIN - Ready for testing, but need to overload = operator in user.h first
        case 1:
					try
					{
						// get username input from user
						cout << "Enter your username: "; // admin's username is Admin
						cin >> username;
						cout << endl;
						
						// get password input from user
						cout << "Enter your password: ";
						cin >> pass;
						cout << endl;
						
						// if the username does not exist, throw exception
						if(!userList.findUser(userName))
							throw "Invalid username.";
						
						// load user data to validate password
						currentUser = userList.getUser(userName);
						
						// if passwords do not match, throw exception
						if(!currentUser.validate(pass))
							throw "Invalid password.";
						// if the user is admin, go to admin menu
						else if(currentUser.isAdmin())
							status = ADMIN;
						// if the user is a regular user, go to user menu
						else
							status = USER;
					}
					catch(string str)
					{
						// code for handling exceptions
						cout << "Error: " << str << " Try again." << endl;
					}
         break; //end case 1 (Login)

        // REGISTER - Ready for testing
        case 2:
					try
					{
						// code for new username
						cout << "Enter a unique username (no spaces allowed): " << endl;
						cin >> username;
						cout << endl;
						
						// if user exists, throw exception
						if(userList.findUser(username))
							throw "User already exists.";
						
						// code to get password for new user
						cout << "Enter a password (no spaces allowed): ";
						cin >> pass;
						cin.get(ch); // gets next character
						cout << endl;
						
						// if the next character was a space, user incorrectly entered
						// their password, throw exception
						if(ch == ' ')
							throw "No spaces allowed in your password.";
						
						//set current user data
						currentUser.setUsername(username);
						currentUser.setPassword(password);
						
						// add current user to database
						userList.addUser(currentUser);
						
						status = USER;
					}
					catch(string str)
					{
						cout << "Error: " << str << endl;
					}
         break; // end case 2 (Register)

        // EXIT - Ready for testing
        case 3:
          status = EXIT;
          break; // end case 3 (Exit)

        default:
          cout << "Invalid selection." << endl;
      } //end switch
    }// end while loop for home menu

		//***USER MENU***//
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
					// search for title in library
					// if not present, print relevant message
					// if present, print book information
					// break;
					
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
					// break;
					
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
					// break;
					
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
					
					// UPDATE BOOK INFORMATION // either change one or prompt for new information
					// case 3:
					// prompt for title
					// if book exists
						// Output book information //
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
					// prompt for new user information
					// add to newUser
					// add newUser to the map
					
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