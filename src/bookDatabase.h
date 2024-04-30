#ifndef BOOKDATABASE_H
#define BOOKDATABASE_H

#include "binarySearchTree.h"
#include "book.h"

#include <string>
#include <fstream>

class bookDatabase : bSearchTreeType<book>
{
public:
    book getBookFromTitle(std::string title);
    // Function that gets a book based on the given title string.
    // Precondition: The book exists in the book database.
    // Postcondition: Returns a book if its found, returns an empty book if not.

    // LOAN FUNCTIONS
    void printAllLoans() const;

    // DATA MANAGEMENT FUNCTIONS
    void loadFromFile(ifstream inFile); // *Alyssa* Function to load the address book from a file
    void saveToFile(ofstream outFile); // *Alyssa* Function to save the address book to a file
private:
    void printLoan(nodeType<book> *b) const;
};

// Custom search function that returns a book if its found, and an empty book when its not.
book bookDatabase::getBookFromTitle(std::string title) {
    nodeType<book> *current; // Declare a node type of book.

    if (root == nullptr)
        cout << "Cannot search an empty tree." << endl;
    else
    { 
       current = root;

       while (current != nullptr)
        {
            if ((current->info).getTitle() == title)
                return current->info; // Return the book if its found.
            else if ((current->info).getTitle() > title)
                current = current->lLink; // If not, move to the next node.
            else
                current = current->rLink;
        }//end while
    }//end else

    // If the book isn't found, return an empty book.
    return book();
}//end getBookFromTitle

// Custom inorder traversal that prints all loans from books.
void bookDatabase::printAllLoans() const {
    printLoan(root);
}//end printALlLoans

// In order traversal that prints the loan of the book, then iterates to the next book.
void bookDatabase::printLoan(nodeType<book> *b) const {
    if (b != nullptr)
    {
        printLoan(b->lLink);
        if (b->info.isBorrowed())
        {
            b->info.printTitle();
            cout << "Current Borrower: " << b->info.currentBorrower() << endl;
        }
        printLoan(b->rLink);
    }
}//end printLoan

#endif