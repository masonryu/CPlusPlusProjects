#include <iostream>
// Includes Libraries
using namespace std ;
/*Class description: The class is for objects that hold an array of doubles.
	constructors: default constructor: makes the size 0 for a new array.
					one parameter(&copied): is the copy constructor that makes a deep copy of the array.
					one parameter(size): makes an array of "size" that we pass to it.
					public functions: int length : returns the length of the array.
									All of these below for overloading operators.
									  ostream operator<< , istream operator>>, bool operator==,  bool operator!=, double& operator[],
									  smartArray& operator+,smartArray& operator-,smartArray& operator*,smartArray& operator/
*/
class smartArray{
public: 
	// declaration of pointer of type double
	double *elements ;
	//function that returns length of the array
	int length() ;
	//default constructor
	smartArray();
	//copy constructor
	smartArray(const smartArray &copied){
		this->elements = copied.elements ;
		*this = copied ;
	} ;
	// constructor that gets the size passed to it. 
	smartArray(int size) ;
	// deconstructor
	~smartArray() ;
	// overloading the >> and << operators
	friend ostream& operator<<(ostream &out, smartArray&) ;
	friend istream& operator>>(istream &in, smartArray&) ;
	// overloading == operator
	// parameters: arr2
	//return value: boolean
	bool operator==(const smartArray& arr2){
		bool equal = true ;
		if(size != arr2.size){
			equal = false ;
		}
		else{
			for(int i = 0 ; i < size ; i ++){
				if(elements[i] != arr2.elements[i]){
					equal = false ;
					break ;	
					// code to check if the arrays are diffferent in value at all.
				}
			}
		}
		return equal ;
	} 
	// overloading the != operator , calls the == function and returns the opposite 
	bool operator!=(const smartArray& arr2){
		return !(*this == arr2) ;
	} 
	//overloading the [] operator to access elements directly
	// parameters : int index
	//return value : pointer
	double& operator[](int index){
		if(index >= size){
			cout << "Array index out of bound" ;
			exit(0) ;
		}
		return elements[index] ;
	}
	// resizing the array
	//parameters: new size
	//return value : none
	void resize(int newsize){
	
			double *newArray = new double[newsize] ;
			//allocates new memory for the new array
		if (size == newsize){
			for(int i = 0 ; i < size ; i ++){
				*&newArray[i] = *&elements[i] ;
			}
		}
		if (newsize > size){
			for(int i = 0; i < size ; i ++){
				*&newArray[i] = *&elements[i] ;
			}
			for(int i = size; i < newsize ; i ++){
				*&newArray[i] = 0 ;
			}
		}
		if (newsize < size){
			for(int i = 0 ; i <newsize ; i ++){
				*&newArray[i] = *&elements[i] ;
			}
		}
		delete [] elements ;
		//deletes allocated memory
		elements = newArray ;
		size = newsize ;
	} ;
	//operator overloading for the + operator
	//parameters: &arr
	//return value: an object smartArray&
	smartArray& operator+(const smartArray &arr){
		smartArray temp ;
		if (size <arr.size){
			temp.elements = new double[arr.size];
			for (int i = size ; i <size ; i ++){
				arr.elements[i] = 0 ;
			}
			for (int i = 0 ; i < arr.size; i ++){
				temp.elements[i] = elements[i] + arr.elements[i] ;
			}
		}
		if (size >arr.size){
			temp.elements = new double[size];
			for(int i = arr.size;i <size;  i ++){
				elements[i] = 0 ;
			}
			for(int i = 0 ; i <size; i ++){
				temp.elements[i] = elements[i] + arr.elements[i] ;
			}
		}
		if (size == arr.size){
			temp.elements = new double[size] ;
			for(int i = 0 ; i <size ; i ++){
				temp.elements[i] = elements[i] + arr.elements[i] ;
			}

		}
		return temp ;
	}
//operator overloading for the - operator
	//parameters: &arr
	//return value: an object smartArray&
	smartArray& operator-(const smartArray &arr){
		smartArray temp ;
		if (size <arr.size){
			temp.elements = new double[arr.size];
			for (int i = size ; i <size ; i ++){
				arr.elements[i] = 0 ;
			}
			for (int i = 0 ; i < arr.size; i ++){
				temp.elements[i] = elements[i] - arr.elements[i] ;
			}
		}
		if (size >arr.size){
			temp.elements = new double[size];
			for(int i = arr.size;i <size;  i ++){
				elements[i] = 0 ;
			}
			for(int i = 0 ; i <size; i ++){
				temp.elements[i] = elements[i] - arr.elements[i] ;
			}
		}
		if (size == arr.size){
			temp.elements = new double[size] ;
			for(int i = 0 ; i <size ; i ++){
				temp.elements[i] = elements[i] - arr.elements[i] ;
			}

		}
		return temp ;
	}
	//operator overloading for the * operator
	//parameters: &arr
	//return value: an object smartArray&
		smartArray& operator*(const smartArray &arr){
		smartArray temp ;
		if (size <arr.size){
			temp.elements = new double[arr.size];
			for (int i = size ; i <size ; i ++){
				arr.elements[i] = 0 ;
			}
			for (int i = 0 ; i < arr.size; i ++){
				temp.elements[i] = elements[i] * arr.elements[i] ;
			}
		}
		if (size >arr.size){
			temp.elements = new double[size];
			for(int i = arr.size;i <size;  i ++){
				elements[i] = 0 ;
			}
			for(int i = 0 ; i <size; i ++){
				temp.elements[i] = elements[i] * arr.elements[i] ;
			}
		}
		if (size == arr.size){
			temp.elements = new double[size] ;
			for(int i = 0 ; i <size ; i ++){
				temp.elements[i] = elements[i] * arr.elements[i] ;
			}

		}
		return temp ;
	}
	//operator overloading for the / operator
	//parameters: &arr
	//return value: an object smartArray&
	smartArray& operator/(const smartArray &arr){
		smartArray temp ;
		if (size <arr.size){
			temp.elements = new double[arr.size];
			for (int i = size ; i <size ; i ++){
				arr.elements[i] = 0 ;
			}
			for (int i = 0 ; i < arr.size; i ++){
				temp.elements[i] = elements[i] / arr.elements[i] ;
			}
		}
		if (size >arr.size){
			temp.elements = new double[size];
			for(int i = arr.size;i <size;  i ++){
				elements[i] = 0 ;
			}
			for(int i = 0 ; i <size; i ++){
				temp.elements[i] = elements[i] / arr.elements[i] ;
			}
		}
		if (size == arr.size){
			temp.elements = new double[size] ;
			for(int i = 0 ; i <size ; i ++){
				temp.elements[i] = elements[i] / arr.elements[i] ;
			}

		}
		return temp ;
	}
	//operator overloading for the & operator
	//parameters: &arr2
	//return value: an object smartArray&
	smartArray& operator&(smartArray& arr2){
		int temp ;
		temp = size + arr2.size ;
		smartArray s0(temp) ;
		for(int i = 0 ; i < size ; i ++){
			s0[i] = elements[i] ;
		}
		for(int i = 0 ; i < arr2.size ; i ++){
			s0[i+size] = arr2.elements[i] ;
		}
		return *this;
		// how do i return 
	}
	//operator overloading for the = operator
	//parameters: &arr
	//return value: an object smartArray&
	smartArray& operator=(const smartArray& arr){
		for (int i = 0; i<size; i++){
			elements[i]=arr.elements[i] ;
		}
		return *this ;
		//is this whole thing right
	}
private:
	int size ; 
};
//operator overloading for the << operator
	//parameters: &out , &arr
	//return value: an ostream&
ostream& operator<<(ostream &out, smartArray& arr){
	out << "[" ;
	for (int i = 0 ; i < arr.size ; i ++)
		out << arr.elements[i] << "," ;
	out << "\b" ;
	out << "]" << endl ;
	return out;
}
//operator overloading for the >> operator
	//parameters: &arr
	//return value: an object smartArray&
istream& operator>>(istream &in, smartArray& arr){
	for (int i = 0; i < arr.size ; i ++){
		cout << "enter element " << i + 1 << ": " ;
		in >> arr.elements[i] ;
	}
	return in;
}
//default constructor
smartArray::smartArray(){
	size = 0 ;
	elements = new double[size] ;
}
//constructor with one parameter size
smartArray::smartArray(int size){
	this->size =size;
	elements = new double[size];
}
//deconstructor de allocagtes memory.
smartArray::~smartArray(){
	delete [] elements ;
}
// int main with all the tests for overloaded operators.
int main(){
	smartArray s1(3) ;
	cin >> s1;
	cout << s1;
	smartArray s2(3) ;
	cin >> s2 ;
	cout << s2 ;
	if (s1==s2)
		cout << "they are equal" ;
	if (s1!=s2)
		cout << "they are not equal" ;
	smartArray s3 ;
	s3 =s1+s2 ;
	cout << s3 ;
	return 0;
}

