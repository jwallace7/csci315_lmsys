#include "bookDatabaseOLD.h" 

// implement the loadFromFile function
void bookDatabase::loadFromFile(ifstream inFile) {
    // implementation to load the address book from a file
    // this is to read data from the input file stream 'inFile' and populate the book database?

}

// implement the saveToFile function
void bookDatabase::saveToFile(ofstream outFile) {
	// output number of books in library
	
	// if library is empty
		// output relevant message
	// if not empty, use logic to iterate through BST for each book (decide on order: preorder, inorder, postorder)
		// store title
		// store author
		// store date published
		// store catalog number
		// store borrower queue (includes number of borrowers and their names)
		
}
    // implementation to save the address book to a file
    // write data from the book database to the output file stream 'outFile'
    // implementation details depend on the file format and data structure used