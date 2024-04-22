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
  user* tempCurrentUser; // TEMPORARY, for testing
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
          systemStatus = USER; // temporary, for testing purposes,
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
      // process selection
      // set status to...
          // HOME to return to the home menu
          // EXIT to exit the program
    }// end while for user menu

    while (status == ADMIN) // loop for admin menu
    {
      // code for admin menu

      // print admin menu
      // input user selection
      // process selection
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