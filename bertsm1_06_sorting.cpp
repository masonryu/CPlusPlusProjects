// Mason Bertsch
// Assiognment 6 
//Preprocessor Directives. Including all these libraries for varoius funcitons and keywords.
#include<iostream>
#include<time.h>
#include<stdlib.h>
#include<ctime>
#include<fstream>
using namespace std;
//Declaration of all global constants used in program. 
const int ARR_SIZE = 1000000;
const int ID_MAX = 99999 ;
const int ID_MIN = 10000 ;
/*Class description: class is of type student and has members to hold id and gpa.
  Constructors: none excpet default one c++ assings.
  public functions: none
*/
class Student {
public:
	int id ;
	double gpa ; 
};
/*Function description: this function is used to display the test for smaller sorting numbers.
  parameters: pointer to Student
  return value: non(void)
*/
void display(Student *array){
	for(int i = 0 ; i < ARR_SIZE ; i ++){
		cout << array[i].id << " : " << array[i].gpa << " " ;
		cout << endl; 
	}
}
/*Function description: sorts the array of students using bubble sort by their gpa
  parameters: pointer to student
  return values: none(void)
*/
void sortBubble(Student *array){
	double temp ;
	bool swap = true;
	while(swap){
		swap = false ;
		for(int count = 0 ; count <(ARR_SIZE-1); count++){
			if(array[count].gpa > array[count+1].gpa)
			{
				temp = array[count].gpa;
				array[count].gpa = array[count+1].gpa ;
				array[count+1].gpa = temp ;
				swap = true ;
			}
		}
	}
}
/*Functoin description: This function is used as a qsort parameter.
  Parameters: void pointers a nd b
  reeturn values: integer
*/
int compare1(const void *a, const void *b){
	Student *ia = (Student*)a ;
	Student *ib = (Student*)b ;
	if(ia->gpa > ib->gpa) return 1;
	else if(ia->gpa < ib->gpa) return -1 ;
	else return 0;
}
/*Function description: Main function that creates objects and does all function calls.
  Parameters: none
  return values: none
*/
int main(){
//Variable declarations
int sortType;
double elapsed1 = 0  ;
double elapsed = 0 ;
//creating an array of 1 million elements.
	Student *array = new Student[ARR_SIZE];
//srand included here to randomize time.
	srand(unsigned(time(NULL))) ;
//fill with random values: id=(ID_MIN-ID_MAX)
	for(int i = 0 ; i < ARR_SIZE ; i ++){
		array[i].id = rand()%ID_MAX+ID_MIN ;
		array[i].gpa = (rand()%400)/100.0 ;
	}
	//ofstream out_time("out.txt") ;
	//display(array); 
//prompt for bubble sort or quickort.
	cout << "Bubble sort or Quick sort? :" ; cin >> sortType ;
	if(sortType == 1){
		//start measuring time
		clock_t start1 = clock() ;
		//sort by selected algorithm
		sortBubble(array);
		//stop measuring time
		clock_t stop1 = clock() ;
		//calculating time elapsed
		elapsed1 = (double)(stop1-start1)/ double(CLOCKS_PER_SEC) ;
		//dislpay sorted (only for small phase)
		//	display(array) ;
		// << setw(30) << setfill
		cout << "time taken: " <<fixed <<elapsed1 << setprecision(5) << "seconds " <<  endl ;
		//displaying time elapsed
	}
	// sorting using qsort
	if (sortType == 2){
		//start measuring time
		clock_t start = clock() ;
		qsort(array, ARR_SIZE, sizeof(Student),compare1) ;
		//stop measuring time
		clock_t stop = clock() ;
		elapsed = (double)(stop-start)/ double(CLOCKS_PER_SEC) ;
		cout << "time taken : " << fixed<<elapsed<<setprecision(5)<<"seconds" << endl ;
	//	display(array) ;
	}
//deleting the memory allocated 
delete [] array ;
//ending the program
return 0 ; 
}