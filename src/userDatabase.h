#ifndef USERDATABASE_H
#define USERDATABASE_H

#include <iostream>
#include <string>
#include <fstream>
#include <unordered_map>

#include "user.h"

class userDatabase
{
public:
  // RETRIEVAL FUNCTIONS
  bool findUser(const std::string& username) const;
  // Function that returns a boolean value based on if the user is found in the database.
  // Postcondition: Returns true if the user is found in the hashmap,
  // otherwise, returns false.
  user getUser(const std::string username) const;
  // Function that returns a user from the map based on a given username.
  // Precondition: A user of username exists within the database.
  // Postcondition: If a user is found, then this returns the user data of the user.
  // Otherwise, this returns an empty user with a warning message displayed.

  // INSERT/REMOVAL FUNCTIONS
  void registerUser(user newUser); 
  // Function that either adds or updates a user.
  // If a user doesn't exist with the username, then it creates a user.
  // If a user exists with the username, then it updates the user.
  void removeUser(const std::string username);
  // Removes a user from the hashmap based on the provided username.
  // Precondition: A user of the username provided exists in the database.

  // DATA MANAGEMENT FUNCTIONS
  void loadFromFile(std::ifstream fileName); // *Alyssa* Loads the user database from a file
  void saveToFile(std::ofstream fileName); // *Alyssa* Saves the user database to a file

  // CONSTRUCTOR
  userDatabase(); // Constructor function
private:
  std::unordered_map<std::string, user> users;
  // The hashmap that stores the users of the database.
  // The key or unique identifier of the user is its username, where
  // the value which the hashmap returns is the user data.
};

// RETRIEVAL FUNCTIONS
bool userDatabase::findUser(const std::string& username) const
{ return users.find(username) != users.end(); }//end findUser

user userDatabase::getUser(const std::string username) const
{ return users.at(username); }//end getUser



// INSERT/REMOVAL FUNCTIONS
void userDatabase::registerUser(user newUser)
{
    std::string username = newUser.getUsername();
    std::string action = (findUser(username)) ? " updated." : " created.";
    users[username] = newUser;
    std::cout << "User " << username << action << std::endl;
}

void userDatabase::removeUser(const std::string username)
{
    if (findUser(username))
        users.erase(username);
    else
        std::cout << "User " << username << " already does not exist." << std::endl;
}//end removeUser

// DATA MANAGEMENT FUNCTIONS
void userDatabase::loadFromFile(std::ifstream fileName)
{

}//end loadFromFile

void userDatabase::saveToFile(std::ofstream fileName)
{

}//end saveToFile

// CONSTRUCTOR
userDatabase::userDatabase() {}//end constructor

#endif