#include <iostream>
#include <cstdlib>
#include <string>
#include <conio.h>

using namespace std;
class Book {
private:
	string isbn, title, author, edition, publication;
public:
	void setIsbn(string a) { isbn = a; }
	void setTitle(string b) { title = b; }
	void setAuthor(string c) { author = c; }
	void setEdition(string d) { edition = d; }
	void setPublication(string e) { publication = e; }

	string getIsbn() { return isbn; }
	string getTitle() { return title; }
	string getAuthor() { return author; }
	string getEdition() { return edition; }
	string getPublication() { return publication; }
};

void addBook(int counter);
void deleteBook(int counter);
void searchBook(int counter);
void viewAllBooks(int counter);
void quit();

int counter = 0;

void increment(int a) {
	a++;
	counter = a;
}

void decrement(int a) {
	a--;
	counter = a;
}

Book books[10];

int main() {
	string choice;
	//Main Menu
	system("CLS");
	cout << "LIBRARY MANAGEMENT SYSTEM\n\n";
	cout << "[1]ADD BOOK\n";
	cout << "[2]DELETE BOOK\n";
	cout << "[4]SEARCH BOOK\n";
	cout << "[5]VIEW ALL BOOKS\n";
	cout << "[6]QUIT\n\n";
	cout << "ENTER CHOICE: ";
	getline(cin, choice);
	system("CLS");
	if (choice == "1") {
		addBook(counter); //function call
	}
	else if (choice == "2") {
		deleteBook(counter); //function call
	}
	else if (choice == "4") {
		searchBook(counter); //function call	
	}
	else if (choice == "5") {
		viewAllBooks(counter); //function call	
	}
	else if (choice == "6") {
		quit();	 //function call
	}
	else {
		main();  //function call to self(main)
	}
	_getch();
	return 0;
}

void addBook(int counter) {
	string isbn, title, author, edition, publication;
	cout << "ADD BOOK\n\n";
	if (counter < 10) {
		cout << "Enter ISBN: ";
		getline(cin, isbn);
		cout << "Enter Title: ";
		getline(cin, title);
		cout << "Enter Author: ";
		getline(cin, author);
		cout << "Enter Edition: ";
		getline(cin, edition);
		cout << "Enter Publication: ";
		getline(cin, publication);
		books[counter].setIsbn(isbn);
		books[counter].setTitle(title);
		books[counter].setAuthor(author);
		books[counter].setEdition(edition);
		books[counter].setPublication(publication);
		increment(counter);
		cout << "\nBOOK ADDED SUCCESSFULLY!\n\nPress any key to continue...";
		_getch();
		main();
	}
	else {
		cout << "YOU HAVE REACHED THE MAXIMUM NUMBER OF BOOKS TOBE ADDED!\n\nPress any key to continue...";
		_getch();
		main();
	}
}

void deleteBook(int counter) {
	string isbn;
	int choice;
	cout << "DELETE BOOK\n\n";
	if (counter == 0) {
		cout << "THERE IS NO BOOK TO DELETE!\n\nPress any key to continue...";
		_getch();
		main();
	}
	cout << "Enter ISBN: ";
	getline(cin, isbn);

	for (int i = 0; i < counter; i++) {
		if (books[i].getIsbn() == isbn) {
			cout << "\nBOOK FOUND\n\n";
			cout << "Do you want to delete?\n[1]Yes\n[2]No\n\nEnter choice: ";
			cin >> choice;
			if (choice == 1) {
				books[i].setIsbn("");
				books[i].setTitle("");
				books[i].setAuthor("");
				books[i].setEdition("");
				books[i].setPublication("");
				for (int a = i; a < counter; a++) {
					books[a] = books[a + 1];
				}
				books[9].setIsbn("");
				books[9].setTitle("");
				books[9].setAuthor("");
				books[9].setEdition("");
				books[9].setPublication("");
				decrement(counter);
				cout << "\nBOOK SUCCESSFULLY DELETED!\n\nPress any key to continue...";
				_getch();
				main();
			}
			else {
				main();
			}
		}
	}
	cout << "\nBOOK NOT FOUND!\n\nPress any key to continue...";
	_getch();
	main();
}


void searchBook(int counter) {
	string isbn;
	int choice;
	bool print = false;
	cout << "SEARCH BOOK\n\n";
	if (counter == 0) {
		cout << "THERE IS NO BOOK TO SEARCH!\n\nPress any key to continue...";
		_getch();
		main();
	}
	cout << "Entar ISBN: ";
	getline(cin, isbn);
	for (int i = 0; i < counter; i++) {
		if (books[i].getIsbn() == isbn) {
			cout << "\nBOOK FOUND!\n\n";
			cout << "ISBN: " << books[i].getIsbn() << endl;
			cout << "TITLE: " << books[i].getTitle() << endl;
			cout << "AUTHOR: " << books[i].getAuthor() << endl;
			cout << "EDITION: " << books[i].getEdition() << endl;
			cout << "PUBLICATION: " << books[i].getPublication() << endl;
			print = true;
		}
	}
	if (print) {
		cout << "\n\nPress any key to continue...";
		_getch();
		main();
	}
	else {
		cout << "\nBOOK NOT FOUND!\n\nPress any key to continue...";
		_getch();
		main;
	}
}

void viewAllBooks(int counter) {
	cout << "VIEW ALL BOOKS\n\n";
	for (int i = 0; i < counter; i++) {
		cout << "BOOK DETAILS\n\n";
		cout << "ISBN: " << books[i].getIsbn() << endl;
		cout << "TITLE: " << books[i].getTitle() << endl;
		cout << "AUTHOR: " << books[i].getAuthor() << endl;
		cout << "EDITION: " << books[i].getEdition() << endl;
		cout << "PUBLICATION: " << books[i].getPublication() << endl << endl;
	}
	cout << "Press any key to continue...";
	_getch();
	main();
}

void quit() {
	//quit function
	_exit(1);
}