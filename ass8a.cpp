//Mason Bertsch
/* Function Description: This function allows somebody to manage a single link list that keeps track of Car information
*/
// Preprocessor Directives -  Loads C++ libraries for use in your program.
#include<iostream>
using namespace std ;
//Class/struct description: holds information for type Car includes id, make, price, and year mostly taken from user input.
	//public functions : none

struct Car{
	int id ;
	string make ;
	int price;
	int year;
	Car *next ;
} ;

/*Function Description: This function gets called  when the user wants to add a car at the end of the linked list.
		Parameters: The pointer to the first car, last car, and the integer that keeps track of the id numbers already used.
		Rerturn value: none
*/
void addCar(Car *&first, Car *&last, int &id){
	//Creating a new car in the list.
	//Setting the car id using id variable
	Car *newCar = new Car ;
	newCar->id = id;
	id ++ ;
	//Prompting user for other car information.
	cout << "Enter Make: " ;
	cin >> newCar->make ;
	cout << "Enter Price: " ;
	cin >> newCar->price ;
	cout << "Enter year: " ;
	cin >> newCar->year ;
	newCar->next= NULL ;
	if (first==NULL){
		first= newCar ;
		last= newCar;
	} else {
		last->next= newCar ;
		last = newCar ;
	}

}
/*Function Description: This function is called when the user would like to remove a car from the single linked list.
		Parameters: Pointers to first and last nodes of the list
	Return value: none (void)
*/
void removeCar(Car *&first, Car *&last){
	//Variable and pointer declarations.
	int carRemove ;
	Car *current ;
	Car *previous ;
	current = first ;
	previous = NULL ;
	//prompting user for which car to remove.
	cout << "Enter id of car to remove: "  ;
	cin >> carRemove ;
	while(current!=NULL){
		if(current->id==carRemove){
			break ;
		}
		previous = current ;
		current = current->next ;
	}
	//If statement for if deleting the first node in the list
	if (current==first){
		first = current->next ;
		if(first==NULL){
			last=NULL ;
		}
		delete current ;
	//If statement for if deleting the last node in the list
	}else if(current==last){
		last = previous ;
		previous->next =NULL ;
		delete current ;

	//if statement for if deleting an element other than the first or last.
	}else {
		previous->next = current->next ;
		delete current ;
	}
	cout << endl ;
}

/*Function description: This displays the current list to the user.
	Parameters: The pointer to the first car in the list.
	Return Value: none(void)
*/
void display(Car *firstCar){
	Car *current ;
	current = firstCar ;
	while (current!=NULL){
		cout << current->id << "\t" << current->make << "\t" << current->price << "\t" << current->year << endl;
		current = current->next ;	
	}
	cout << endl ;

}
/*Function Description: main function that calls other functions and displays the options menu to the user.
	Parameters: none
	Return value: int
*/
int main(){

	//variable and pointers declarations
	int id = 100 ;
	int option ;
	string manage = "y" ;
	Car *first= NULL ;
	Car *last= NULL ;

// prompting user for which action to do to the list
	while(manage=="y") {
		cout << "CAR MANAGEMENT" << endl ;
		cout << "Car list: " << endl ;
		cout << "---------------------"<< endl ;
		display(first);
		cout << "1. add car"<< endl ; 
		cout << "2. remove car" << endl;
		cout << "5. exit" << endl ;
		cout << "Enter: " ;
		cin >> option ;

		if(option==1){

			addCar(first,last,id) ;
		}
		if(option==2){
			cout << "remove car code execution "  << endl ;
			removeCar(first, last) ;
		}
		if(option==5){
			return 0;
		}
		if(cin.fail()){
			cout << "thats wrong" << endl ;
		}

	}
	
	//Deallocating the memory of the list
	Car *current = first ;
	while(current!=NULL){
		first=first->next ;
		delete current ;
		current = first ;

	}

}