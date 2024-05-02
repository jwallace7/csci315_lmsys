#include <iostream>
#include <fstream>
#include <string>

#include "userDatabase.h"

int main() {
    userDatabase userdb;

    userdb.loadFromFile("output.txt");

    /*
    user user1("Joseph", "donkeys841", false);
    user user2("James", "Gr@ndC4nyon444", false);
    user user3("Jeremy", "und3f1n3d123", true);

    user1.addBook("How to Program for Dummies");
    user1.addBook("The Battle of Varna");
    user2.addBook("AI for Dummies");
    user3.addBook("History of Programming");
    user3.addBook("Why Gaming is Addictive");

    userdb.addUser(user1);
    userdb.addUser(user2);
    userdb.addUser(user3);
    */

   user user5("Jarold", "MYN4MEisT3RRIBL4", true);
   userdb.addUser(user5);

    userdb.saveToFile("output.txt");
}