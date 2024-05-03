#include <iostream>
#include <fstream>
#include <string>
#include <limits>
#include "bookDatabase.h"
#include "userDatabase.h"
#include "user.h"

using namespace std;

enum systemStatus{HOME, USER, ADMIN, EXIT}; // special data type to keep track of the current menu

// menu display functions
void displayPreMenu();
void displayMenuUser(string);
void displayMenuAdmin();

// special function for handling a book return
int returnLogicHandler(string, string, userDatabase&, bookDatabase&);


int main()
{
	// VARIABLES
  int choice, flag, tempDate;
  char ch;
  string username, pass, newUsername, newPass, tempTitle, tempAuth, newBorrower;
  double tempCatNum;
  bookDatabase library; // database with all books in the library
  systemStatus status = HOME;
  userDatabase userList;
  user currentUser("", "", false); // will be the current loaded user in the system
  book tempBook; //will be a temp book, for adding a book to the system
  user newUser; // used for adding a new user to the database

	// LOADING DATA
  library.loadFromFile(); // load data from book database file into library
  userList.loadFromFile(); // load data from user database file into userList

	// ENTERING MENU SYSTEM
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
            if(!userList.findUser(username))
              throw "Invalid username.";

            // load user data to validate password
            currentUser = userList.getUser(username);

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

            // if next character is a space, the user
            // incorrectly inserted a space in their username
            if(ch == ' ')
              throw "No spaces allowed in your password.";

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
            currentUser.setPassword(pass);

            // add current user to database
            userList.addUser(currentUser);

            status = USER;
          }
          catch(string str)
          {
            cout << "Error: " << str << endl;
          }
         break; // end case 2 (Register)

        // EXIT
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
			//reinitializing certain variables
			tempTitle = "";
			tempAuth = "";
			tempDate = 1900;
			tempCatNum = 000.00;
      
			//reinitializing input stream
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			
			// print user menu
      displayMenuUser(username);

      // get user selection
      cin >> choice;
      cin.get(ch);
      cout << endl;

      // process selection
      switch(choice)
      {		
          //SEARCH FOR BOOKS
          case 1:
            // input title
            cout << "Enter the title of the book to search for: ";
            getline(cin, tempTitle);
            cout << endl;

            // search for title in library
            tempBook = library.getBookFromTitle(tempTitle);
            if (tempTitle == tempBook.getTitle())
            {
              // book exists, print out book information
              cout << "This book exists in the library." << endl;
              cout << "-----     BOOK INFO     -----" << endl;
              tempBook.printInfo();
              cout << "-----------------------------" << endl;
            }
            else
            {
              // book does not exist, print relevant message
              cout << "The book does not exist in the library. ";
            }
            cout << "Press enter to return to the user menu." << endl;
          break;

          //BORROW A BOOK
          case 2:
            if(!currentUser.hasMaxBooks())
            {
              // input title
              cout << "Input the title of the book you want to borrow: ";
              getline(cin, tempTitle);
              cout << endl;

              // get book, if book exists
              tempBook = library.getBookFromTitle(tempTitle);

              // if the book exists, tempTitle will equal tempBook.getTitle()
              if(tempTitle == tempBook.getTitle())
              {
                if(!tempBook.isBorrowed()) // book is not currently borrowed
                {
                  // add to user's book list
                  currentUser.addBook(tempTitle);
                  // output relevant message
                  cout << "Book borrowed." << endl;
                }
                else // book is currently borrowed
								{
                  cout << "The book is currently on loan. We have placed a hold "
                       << "on it for you."
                       << endl;
								}
                // add username to book's borrower queue
                library.borrow(tempTitle, username);
              }
              else // book does not exist
                cout << "The book, " << tempTitle
                     << " does not exist in the library."
                     << endl;
            }
            else
              cout << "You have borrowed the maximum number of books."
                   << " You must return a book you currently have borrowed"
                   << " before borrowing any more."
                   << endl;
						cout << " Press enter to return to the user menu." << endl;
          break;

          //RETURN A BOOK - Ready for testing
          case 3:
            // print the titles of user's current loans
            cout << "Here are your current loans: " << endl;
            currentUser.printBooks();
            cout << endl;

            // prompt user for title to remove
            cout << "Enter the title of the book you want to return: ";
            getline(cin, tempTitle);
            cout << endl;

            // if the book is held by the user
            if(currentUser.hasBook(tempTitle))
            {
              // remove book from user's list of borrowed books
              currentUser.removeBook(tempTitle);

              // logic to handle passing book to next user
              if(returnLogicHandler(tempTitle, username, userList, library) > 0)
                cout << "Book returned successfully.";
              else
                cout << "Error in return handler logic.";
            }
            else
              cout << "Title is incorrect.";
            cout << " Returning to user menu." << endl;
          break;

          //VIEW BORROWED BOOKS
          case 4:
            // code to print users borrowed books
            cout << "Here are the books you have currently borrowed:" << endl;
            currentUser.printBooks();
            cout << "Press enter to return to the user menu." << endl;
          break;

          //RESET PASSWORD - Ready for testing
          case 5:
            do
            {
              // prompt user for password
              cout << "Please enter your new password: ";
              cin >> newPass;
              cout << endl;

              // if the password is different, break
              if(newPass != pass)
                break;
              else // the password is the same, repeat
                cout << "Password must be different from your last password." << endl;
            }
            while(newPass == pass);
						// change password and notify user
						currentUser.setPassword(newPass);
            cout << "Successfully changed your password. Press enter to return to the user menu." << endl;
          break;

          // LOGOUT - Ready for testing
          case 6:
            cout << "You have been successfully logged out.\n";
            status = HOME; // set status to HOME to return to home menu
          break;

          default:
            cout << "Invalid selection." << endl;
      }
    }// end while for user menu

    while (status == ADMIN) // loop for admin menu
    {
			//reinitializing certain variables
      tempTitle = "";
      tempAuth = "";
      tempDate = 1900;
      tempCatNum = 000.00;
			
			//reinitializing input stream
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			
      // print admin menu
      displayMenuAdmin();

      // get user selection
      cin >> choice;
      cin.get(ch);
      cout << endl;

      // process selection
      switch(choice)
      {
        // ADD A BOOK - Ready for testing
        case 1:
          // Prompt for title
          cout << "Enter the title of the book you want to add: ";
          getline(cin, tempTitle);
          cout << endl;

          // check to see if book already exists
          tempBook = library.getBookFromTitle(tempTitle);
          if (tempTitle == tempBook.getTitle())
          {
            // book exists, output relevant message
            cout << "The book already exists in the library. Returning to administrator menu." << endl;
            break;
          }
          else
          {
            // prompt for author
            cout << "Enter the name of the author: ";
            getline(cin, tempAuth);
            cout << endl;

            // prompt for date published
            cout << "Enter the date it was published: ";
            cin >> tempDate;
            cout << endl;

            // prompt for catalog number
            cout << "Enter the catalog number of the book: ";
            cin >> tempCatNum;
            cout << endl;

            // update tempBook
            tempBook.setTitle(tempTitle);
            tempBook.setAuthor(tempAuth);
            tempBook.setDate(tempDate);
            tempBook.setCatalogNumber(tempCatNum);

            // add tempBook to library
            library.insert(tempBook);
            cout << "Book added to library. Returning to administrator menu." << endl;
          }
        break;

        // REMOVE A BOOK - ready for Testing
        case 2:
          // Prompt for title
          cout << "Input the title of the book you want to remove: ";
          getline(cin, tempTitle);
          cout << endl;

          // get book, if book exists
          tempBook = library.getBookFromTitle(tempTitle);

          // if the titles match, the book exists
          if(tempBook.getTitle() == tempTitle)
          {
            // if the book is on loan, it must be returned first
            if(tempBook.isBorrowed())
            {
              cout << "Cannot delete a book while it is loaned out."
                   << "\nReturning to adminstrator menu." << endl;
            }

            // print information to console
            cout << "\n-----     BOOK INFO     -----";
            tempBook.printInfo();
            cout << "-----------------------------" << endl;

            // ask user for confirmation and get user input
            cout << "\nAre you sure you want to remove the book?";
            cout << "\nEnter Y to confirm, N to deny: ";
            cin.get(ch);
            cout << endl;

            switch(ch)
            {
              // admin confirms, delete book
              case 'y':
              case 'Y':
                library.deleteNode(tempBook);
                cout << "Book deleted. Returning to menu." << endl;
              break;

              // admin denies, do nothing
              case 'n':
              case 'N':
                cout << "Returning to menu." << endl;
              break;

              default:
                cout << "Invalid input. Returning to menu." << endl;
            }
          }
        break;
        // end case 2 (Remove A Book)

        // UPDATE BOOK INFORMATION - Ready for testing
        case 3:
          // Prompt for title
          cout << "Input the title of the book you want to update: ";
          getline(cin, tempTitle);
          cout << endl;

          // get book, if book exists
          tempBook = library.getBookFromTitle(tempTitle);

          // if the titles match, the book exists
          if(tempBook.getTitle() == tempTitle)
          {
            // print information to console
            cout << "\n-----     BOOK INFO     -----";
            tempBook.printInfo();
            cout << "-----------------------------" << endl;


            // Prompt for which option to update
            cout << "What would you like to update?"
                 << "1 - Title\n"
                 << "2 - Author\n"
                 << "3 - Year Published\n"
                 << "4 - Catalog Number\n"
                 << "Enter the corresponding number: ";
            cin >> choice;
            cout << endl;

            switch(choice)
            {
              // TITLE
              case 1:
                // prompt for new title
                cout << "Enter the new title: ";
                getline(cin, tempTitle);
                cout << endl;

                library.deleteNode(tempBook);
                tempBook.setTitle(tempTitle);
                library.insert(tempBook);

                cout << "Updated title successfully.";
              break;

              // AUTHOR
              case 2:
                // prompt for new author
                cout << "Enter the new author: ";
                getline(cin, tempAuth);
                cout << endl;

                library.deleteNode(tempBook);
                tempBook.setAuthor(tempAuth);
                library.insert(tempBook);

                cout << "Updated author successfully.";
              break;
              // YEAR PUBLISHED
              case 3:
                // prompt for new date
                cout << "Enter the new publishing year: ";
                cin >> tempDate;
                cout << endl;

                library.deleteNode(tempBook);
                tempBook.setDate(tempDate);
                library.insert(tempBook);

                cout << "Updated publish year successfully.";
              break;
              // CATALOG NUMBER
              case 4:
                // prompt for new catalog number
                cout << "Enter the new catalog number (in the format ###.##): ";
                cin >> tempCatNum;
                cout << endl;

                library.deleteNode(tempBook);
                tempBook.setCatalogNumber(tempCatNum);
                library.insert(tempBook);
              break;

              default:
                cout << "Invalid input." << endl;
            }
          }
          else
            cout << "Book does not exist in library.";
          cout << " Returning to administrator menu." << endl;
        break;
        // end case 3 (Update Book Information)

        // VIEW ALL LOANS - Ready for testing
        case 4:
          // print all books currently loaned out from the library
          library.printAllLoans();
        break;
        // end case 4 (View All Loans)

        // ADD/REMOVE USER - Ready for testing
        case 5:
          // prompt for username
            cout << "Enter the username of the user you wish to add or delete: ";
            cout << "Please enter the new user's username: ";
            cin >> newUsername;
            cout << endl;
            if(userList.findUser(newUsername))
            {
              // remove user and notify Admin
              userList.removeUser(newUsername);
              cout << "User deleted. Returning to administrator menu." << endl;
            }
            else
            {
              // prompt for new user's password
              cout << "Please enter the new user's password: ";
              cin >> newPass;
              cout << endl;

              cout << "Is the user a\n"
                   << "0 - Regular user, or\n"
                   << "1 - Administrator\n"
                   << "Enter the corresponding number: ";
              cin >> flag;
              cout << endl;	

              // initialize newUser
              newUser.setUsername(newUsername);
              newUser.setPassword(newPass);
              if(flag == 1)
                newUser.setAdmin();
              else
                newUser.setAdmin(false);

              // add newUser to the map
              userList.addUser(newUser);

              // notify admin
              cout << "User added. Returning to administrator menu." << endl;
            }
        break;
        // end case 5 (Add/Remove User)

        // LOGOUT - Ready for testing
        case 6:
            cout << "You have been successfully logged out.\n";
            status = HOME; // set status to HOME to return to home menu
        break;
        // end case 6 (Logout)

        default:
          cout << "Invalid selection." << endl;
      }
    }// end while for admin menu

  }// end while for UI

    library.saveToFile(); // save data from library to the data file
    userList.saveToFile(); // save data from user map to the data file
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

void displayMenuUser(string name)
{
  string username;

  cout << "Welcome " << name << ", you're logged in as a User." << endl;
  cout << endl;
  cout << "1. Search for Books" << endl;
  cout << "2. Borrow a Book" << endl;
  cout << "3. Return a Book" << endl;
  cout << "4. View Borrowed Books" << endl;
  cout << "5. Reset Password" << endl;
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

int returnLogicHandler(string title, string returningUser, userDatabase& userDat, bookDatabase& bookDat)
{
  // nodes to point to book and user
  book returnBook;
  string nextBorrowerName;
  user nextBorrowerUser;
  bool found = true;

  // we assume book is held in library
  returnBook = bookDat.getBookFromTitle(title);

  if(title == returnBook.getTitle())
  {
    // pop book borrower queue and get next borrower
    returnBook.removeBorrower();
    do
    {
      nextBorrowerName = returnBook.currentBorrower();

      // next borrower must exist
      if((userDat.findUser(nextBorrowerName)) && (nextBorrowerName != returningUser))
      {
        // user exists
        nextBorrowerUser = userDat.getUser(nextBorrowerName);
      }
      else if(nextBorrowerName == "")
      {
        // no user found to give book to
        found = false;
        break;
      }
      else
        returnBook.removeBorrower(); // borrower does not exist in userDat
    }
    while(nextBorrowerUser.hasMaxBooks()); // if next borrower does not have max books, then a suitable user has been found

    // user was found, we can now 
    if(found)
    {
      nextBorrowerUser.addBook(title);
      bookDat.deleteNode(bookDat.getBookFromTitle(title));
      bookDat.insert(returnBook);
    }
    return 1;
  }
  return -1;
}// end returnLogicHandler