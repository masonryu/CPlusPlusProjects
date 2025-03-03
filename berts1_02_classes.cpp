// Mason Bertsch


/* 
	Program Description:
		The purpose of this program is to prompt the user for account information,
		then print out the information they give us, open an account for them, then close the account.
*/

#include <iostream>
// Preprocessor Directives -  Loads C++ libraries for use in your program.
#include <iomanip>
// Responsible for correct output formattting.
#include <stdlib.h> 
// Responsible for random number generator.
#include <time.h>
// Responsible for including constantly changing number with time.

using namespace std ;

const int ARRY_SIZE = 5 ;
// Class bankAccount that contains all members of information for bank accounts.
class bankAccount {
// Members of class
	string firstName ;
	string lastName ;
	string initials ;
	int accountNumber ;
	int amount ;
	public: 
	// Function Description : reads in information for bank account from keyboard.
	// parameters: none
	// return value: none
	void readCustomer() {
		string firstInitial;
		string lastInitial ;
		int sumAmount = 0;
		//Prompting user for information
		cout << "Reading data for customer" << endl ;
		cout << "First name: " ; cin >> firstName ;
		cout << "Last name: " ; cin >> lastName ;
		cout << "Amount: " ; cin >> amount ;
		// Generating random account number
		srand (time(0)) ;
		accountNumber = rand() % 300000 + 100000 ;
		// Getting initals
		firstInitial = firstName[0] ;
		lastInitial = lastName[0] ;
		initials += firstInitial + lastInitial ;
		} ;
	//Functoin Description : displays information that we just prompted user for
	//Parameters : none
	//return value : none
	void displayCustomer() {
		cout << "Customer: " << firstName << " " << lastName << " (" << initials
			 << ")" << endl ;
		cout << "account:  " << accountNumber << " at " << interestRate << "% has amount of " << amount ;
		cout << endl ;
		cout << setw(25) << setfill('-') << " " ;
		cout << endl ;
		};
	static double interestRate ;
	// Function description : allows us to return the amount member from the pricate class.
	// Parameters : none
	// return value : none 
	int getTotal () {
		
		return amount ;

	}
// Default Constructor
	bankAccount() {
		
	};
// Deconstructor
	~bankAccount() {
		cout  << endl << "Closing the account: " << accountNumber << ", " << firstName << " "
			 << lastName << ", with the amount " << amount << endl ;
	} ;
} ;

double bankAccount::interestRate = 3.5 ;
//Function description : inserts all readvalues into the class memebers.
//parameters : none
//Return value : none
void readCustomer(bankAccount customer[]) {
	for (int i = 0 ; i <ARRY_SIZE ; i ++ )
	(customer[i].readCustomer()) ; 
}

// function description : Main function that calls other functions. 
// parameters: none
// return value: int
int main () {
	int newTotal = 0;
// Creates array of classes
bankAccount customer[ARRY_SIZE] ;
// Calls read function to read in members.
readCustomer(customer) ;
//Loop to display all customers that are read in
	for (int i = 0 ; i < ARRY_SIZE ; i ++ ) {
	customer[i].displayCustomer() ;
	}
//Loop to pass all the amounts to add them all up.
	for (int i = 0 ; i < ARRY_SIZE ; i ++ ) {
		newTotal += customer[i].getTotal() ;
		}
cout <<" SUM OF AMOUNTS : " << newTotal ; 
}

