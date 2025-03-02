// Mason Bertsch


/* 
	Program Description:
		The purpose of this program is to read in double values into a dynamic array.
*/
#include <iostream>
// Preprocessor Directives -  Loads C++ libraries for use in your program.

using namespace std ;
// Using the std namespace saving code.


// Function Description : reads in values into a dynamic array.
// parameters: none
// return value: int
int main(){

// Variable declarations
	int iteration = 0 ;
	int asize ;
	double number ;
	double maximum = 0 ;
	double minimum = 10000 ;
	// prompting the use for the array size.
	cout << "How many numbers would you like to store?  " ;
	cin >> asize ;
	// allocating the new array
	double *array= new double[asize] ;
	//declaring new pointers
	double *p_min = NULL;
	double *p_max = NULL;
	// loop to iterate the amount of times same as size of array.
	for (int i = 0 ; i < asize ; i ++){
	cout << "Iteration Number: " << iteration << endl ;
	// prompting the user for the value in the array.
	cout << "Please enter element number " << iteration << ":" ;
	cin >> number ;
	//stores value into array.
	array[i]= number ;
	//loop that assigns maximum and minimum values
	for (int k = 0 ; k <= iteration ; k ++){
		if (array[k]>maximum){
		maximum = array[k] ;
		}
		if (array[k]<minimum){
	 	minimum = array[k] ;
		}
	}
	// assignment of pointer values and addresses to maximums
	p_min = &minimum ;
	p_max = &maximum ;
	*p_max = maximum ;
	*p_min = minimum ;
	cout << "Updating p_max to address " << p_max << ", now pointing to value: " << *p_max << endl ;
	array[i]= number ;
	// printing out the number that was read again.
	cout << "Read Number: " << number << endl ;
	// printing out the array of values
	cout << "Current array elements: " ;
	for (int j = 0 ; j < i+1 ; j++ ){
		cout << array[j] ;
		if (j!= i )
			cout << ", " ;
	}
	cout << endl;
	// printing out the maximum/minimum values and addresses.
	cout << "Current minimum = " << *p_min << " at address " << p_min << endl ;
	cout << "Current maximum = " << *p_max << " at address " << p_max << endl ;
	//incrementing the iteration variable.
		iteration++ ;
		cout << endl ;
	}
//deallocating the memory that the array used.
	delete [] array ;
}


