#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void displayPreMenu()
{
    cout << "Welcome to the Virtual Library Management System" << endl;
    cout << "-------------------------------------" << endl;
    cout << "1. Login" << endl;
    cout << "2. Register" << endl;
    cout << "3. Exit" << endl;
}

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
}

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
}



int main()
{
    int choice;
    char ch;
    string username;
    string pass;

    displayPreMenu();
    cin >> choice;
    cin.get(ch);
    cout << endl;

    while (choice != 3) /*3 bc 3 is exiting*/
    {
        switch (choice)
        {
            case 1:
            cout << "Enter your username: " << endl; //admin's username is Admin
            getline(cin, username);
            cout << "Enter your password: " << endl;
            getline(cin, pass);
            //how to authenticate and open up user or admin menu?
            break; //somehow the break doesn't work

            case 2:
            cout << "Enter your new username: " << endl;
            getline(cin, username); //how to differentiate that it is new?
            cout << "Enter your new password: " << endl;
            getline(cin, pass);
            //go to user/admin menu
            break;

            default:
            cout << "Invalid selection." << endl; //write option for terminating program? (option 3)
        } //end switch
    } // end while for preMenu

    //have the while/switch structure skeleton for the other menus??
    //where do i put the other menus
}



