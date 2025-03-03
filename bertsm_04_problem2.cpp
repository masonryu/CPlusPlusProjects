
// Mason Bertsch

/* 
	Program Description:
		The purpose of this program is to read in double values into a dynamic array.
*/
#include <iostream> 
// Preprocessor Directives -  Loads C++ libraries for use in your program.
using namespace std ;
/* class description : this class holds the name, id , and gpa of an object type student.
	constructors: none
	public functions: none
*/
class Student {
	public :
	string name ;
	int id ;
	double gpa ;
} ;
// Function Description : creates array of numbers for a function given, then tracks values and addresses with pointers.
// parameters: none
// return value: int
int main() {
	//variable declarations
    int asize = 0 ;
    //prompting the user for the size of the array.
    cout << "Please input the size of the array: " ;
	cin >> asize ;
	//allocating the memory for our array of students.
	Student *sArr = new Student[asize] ;
	// new pointer declaration
	Student *current ;
	//reading in values for each student in the array using pointers.
	for (int i = 0 ; i < asize ; i ++){
		current = &sArr[i] ;
		cout << "Enter student " << i + 1 << " name: " ;
		cin >> current->name ;
		cout << "Enter student " << i + 1 << " id: " ;
		cin >> current->id ;
		cout << "Enter student " << i + 1 << " gpa: " ;
		cin >> current->gpa ; 
	}	

// creation of new students Best/worst Gpa.
Student *BestGpaOfSemester = new Student ;
Student *LowestGpaOfSemester = new Student ;
//varriable declarations
double bestGpa = 0;
double worstGpa = 1000 ; 
// goes through the values of the array and copies the best/worst gpa students into new student objects.
// also sets the address of these students.
for (int i = 0 ; i <asize ; i ++){
	if (sArr[i].gpa>bestGpa){
		bestGpa = sArr[i].gpa ;
		BestGpaOfSemester = &sArr[i] ;
		*BestGpaOfSemester = sArr[i] ;
	}
	if (sArr[i].gpa<worstGpa){
		worstGpa = sArr[i].gpa ;
		LowestGpaOfSemester = &sArr[i] ;
		*LowestGpaOfSemester = sArr[i] ;
	}
}
	cout << endl ;
	//printing out the students list with all of their information on one line.
	cout << "Student List: (array address: "<< sArr << ")" << endl; 
	for (int i = 0 ; i <asize ; i ++){
		current = &sArr[i] ;
		cout << "Student " << i+1<< ": " << sArr[i].name << ", "<< sArr[i].id << ", " <<
		sArr[i].gpa << " (at address " << current << ")" << endl; 
	}
// deallocating the array sArr
delete [] sArr ;
cout << "Array deleted." << endl << endl ;
// Printint the student with the highest gpa
cout << "Student with highest GPA:" << endl;
cout << BestGpaOfSemester->name << ", " << BestGpaOfSemester->id << ", " << BestGpaOfSemester->gpa <<",   " <<
"(at address " << BestGpaOfSemester << ")" << endl ;
// Printing the student with the lowest gpa
cout << "Student with lowest GPA:" << endl;
cout << LowestGpaOfSemester->name << ", " << LowestGpaOfSemester->id << ", " << LowestGpaOfSemester->gpa <<",   " <<
"(at address " << LowestGpaOfSemester << ")" << endl ;
//deallocating the memory used by the new students.
delete BestGpaOfSemester ;
delete LowestGpaOfSemester ;
}











