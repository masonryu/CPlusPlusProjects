// Mason Bertsc

/* 
	Program Description:
		The purpose of this program is to read in double values into a dynamic array.
*/
#include <iostream>
// Preprocessor Directives -  Loads C++ libraries for use in your program.


using namespace std; 
// Function Description : creates array of numbers for a function given, then tracks values and addresses with pointers.
	// parameters: none
	// return value: int
int main() {
// variable declarations
	int relativePosition ;
	int asize ;
	int position = 0 ;
	//prompting user for array size.
	cout << "enter array size: " ;
	cin >> asize ;
	// allocating new memory for array.
	int *DArr =  new int[asize] ;
	//filling the array with numbers from the given function [nth element= n*(n+1)]
	for (int i = 0 ; i < asize ; i++){
		DArr[i] = i * (i+1) ;
		cout << DArr[i] << ", " ;
	}
	cout << endl ;
	//new int pointer called current.
	int *current ;
	// setting the pointer address to the beginning of the array.
	current = &DArr[0] ;
	// creating the infinite loop to allow user to go to different posiitions in the array.
	while (true == true){
		//prompting the user for the relative position.
		cout << "enter relatiove pos: " ;
		cin >> relativePosition ;
		position += relativePosition ;
		//code to terminate the program if the user enters '-1111'
		if (relativePosition==-1111)
			break ;
		//code to set the position back to 0 if they try to go over the array size.
		if (position>asize){
			cout << "Position set to 0." << endl ;
			position = 0 ;
			continue ; 
		}
		// printing out the current position the user is at using pointers and calculations.
		current = &DArr[position] ;
		cout << "DArr = " << DArr << " current= " << current <<" last=" << &DArr[asize-1] << endl; 
		cout << "current value=" << *current<<", current position =" << current-DArr << "/"<< asize-1 << endl ;

		
		
	}
	return 0 ;






}