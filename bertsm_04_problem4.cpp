// Mason Bertsch


/* 
	Program Description:
		The purpose of this program is to read in double values into a dynamic array.
*/
#include <iostream>
#include <stdlib.h>
#include <time.h>
// preprocessor directives that load in libraries.
using namespace std ;
/* class description : the class is an array with members that describe its size and pointers that find values and addresses.
	constructors: default constructor that prompts the user for the size, then allocates memory for the array,
				  also fills the array with random decimal numbers.
   public functions: getmax() returns a pointer that should be pointing at the maximum value when returned.
*/
class DArr {
public:
	//pointer to the array
	double *arr ;
	//size of the array
	int size ;
	//displaus all the elements of the array, uses *operator.
	void displayElements(){
		for (int i = 0 ; i <size ; i ++){
			cout << arr[i] ;
			if (i != size)
				cout << ", " ;
		}
		cout << endl; 
		//printing out the maximum value and address of that value .
		cout << "max element: " << *getMax(arr) << " at address " << getMax(arr) << endl ;
	}
	/* fuction descritption: this function goes through the array and sets the returning pointer to point at the 
						     maximum value in the array.
		parameters: double arr[]
		return value: pointer

	*/
	double* getMax(double arr[]){
		//variable declarations.
		double maximum =0 ;
		double *maxAddress ; 
		for (int i = 0; i < size ; i ++){
			if (arr[i]>maximum)
				maximum = arr[i] ;
			maxAddress = &arr[i] ;

		}
		cout << endl ;
	return maxAddress ;
	}
// default and only constructor:
	//prompts the user for the array size, deallocates memory for this array, and fills the array with random decimals.
	DArr(){
		cout << "Enter the array size: " ;
		cin >> size ;
		arr = new double[size] ;
		cout << "Constructor: allocating " << 8*size<< " bytes of memory." << endl;
		cout << "array elements:" ;
		for (int i = 0 ; i < size ; i ++){
			
			arr[i] = (1000-0)*((double)rand()/(double)RAND_MAX ) + 0 ;
		}
		cout << endl ;
	}
	~DArr(){
		cout << "Destructor: freeing " << 8*size << " bytes of memory." << endl ;
		delete [] arr ;
	}
} ;
// declaration of objects and uses srand time to allow constuctor to make random values.
int main(){
	srand (time(NULL));
	DArr d1;
	d1.displayElements() ;

}