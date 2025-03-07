//Mason Bertsch 
//5005411965
//CS 202
//Assignment 1 : Elections.

// Main Library for C++ 
#include <iostream>
// Library for filestream input/output 
#include <fstream>
// Library for strings
#include <string>
#include <stdlib.h>
// Library so we can format the printed information nicely.
#include <iomanip>
// Library includes the function needed to round numbers up.
#include <math.h>

using namespace std;

const int ARR_SIZE = 100 ;
// Struct to store a candidates full name, their number of votes, and percentage of votes.
struct Candidate {
	string first ;
	string last ;
	int votes ;
	double pScore ;

}  ;

// function prototypes 
void readFile(Candidate[], int&) ;
void displayList(Candidate[], int) ;
void sortByVotes(Candidate[], int) ;
void displayCandidate(Candidate[],int) ;
Candidate getWinner(Candidate[], int) ;
Candidate getLast(Candidate[]) ;
void calculateScores(Candidate[], int) ;
void roundScore(Candidate[], int) ;
/* function description: Main function where all other functions are called to
   parameters : none
   return value : int 
*/
int main() {
	Candidate candidates[100] ;
// int variable keeps count of how many candidates 
int candidateCount = 0 ;	
readFile(candidates, candidateCount) ;
displayList(candidates, candidateCount) ;
sortByVotes(candidates, candidateCount) ;
calculateScores(candidates, candidateCount) ;
displayList(candidates, candidateCount) ;
cout << endl ;
displayCandidate(candidates, candidateCount) ;
roundScore(candidates, candidateCount) ;
displayList(candidates, candidateCount) ;

}
/*function description : Reads in a text file and stores wanted values into
						 array of structs.
  parameters : Candidate struct defined at beginning and integer that 
  			   counts the number of candidates.
  return value : none since void.
*/
void readFile(Candidate candidates[], int& candidateCount) {
	// All of my variable declarations.
	string line;
	ifstream fin;
	// string variables to find posistions of where words start/end.
	string startFirst = "F=" ;
	string endFirst = ",L=" ;
	string startLast = "L=" ;
	string endLast = ",V" ; 
	// variavles that will store names and votes for candidates.
	string newFirst ;
	string newLast ;
	string newVotes = "";
	// integers that will hold the position of where names start and end.
	int voteNumber = 0 ;
	int firstEnd = 0;
	int firstStart = 0 ;
	int lastStart = 0 ;
	int lastEnd = 0 ;
	// temporary integer variables
	int i = 0;
	int j = 0 ;
	//opens and reads the text file
	fin.open("elections.txt") ;
	// while loop for getting the lines of text
	while (!fin.eof()) {
	/* I know i should have included some type of if statement using npos and 
	   find right here to ignore lines that are formatted incorrectly but I couldn't figure it out.
	*/
		getline(fin,line) ;
		// breaks from the loop if reaches end of file.
		if (fin.eof()){
			break ;
		}
	//in the while loop finds the positions for name ending and beginnings.
		firstStart = line.find(startFirst) ;
		firstEnd = line.find(endFirst) ;
		newFirst = line.substr(firstStart +2 , firstEnd - 2) ;
		//stores name into the array of structs.
		candidates[j].first = newFirst ;
	//in the while loop finds the positions for name ending and beginnings.
		lastStart = line.find(startLast) ;
		lastEnd = line.find(endLast) ;
		newLast = line.substr(lastStart + 2 , lastEnd - 9) ;
		//stores name into the array of structs.
		candidates[j].last = newLast ;
		// loop to find where numbers are and stores the votes in a new variable.
			for ( i = 0; i < line.length() ; i ++ ) {
				if( line[i] <= 57 && line[i] >=48 ){
					newVotes = newVotes + line[i] ;
		
				}
		
			}
		// converts the string into integers.	
		voteNumber = atoi(newVotes.c_str()) ;
		// stores the new int variable into the array for votes.
		candidates[j].votes = voteNumber ;
		// sets all of the candidates percentage scores to 0.
		candidates[j].pScore = 0 ;
		// empties the newVotes string variable.
		newVotes = "" ;
		//increments the temp int and the candidate count.
		j++ ;
		candidateCount++ ;	
	}
		// closes the text file.
		fin.close() ;
	}
/*function description : Prints out to the terminal the list of candidates
						 with their information in a orderly fashion.
parameters : Candidate struct defined at beginning and integer that counts the
			 number of candidates.
return value : none since void.
*/
void displayList(Candidate candidates[], int candidateCount) {
	int j = 0 ;
	cout << endl ;
	// code to print out all of the different info for candidates.
	cout << "ALL CANDIDATES :" << endl ;
	cout << left <<  setw(12) << "   First:" ;
	cout << left << setw(12) << "   Last:" ;
	cout << left << setw(12) << "   Votes:" ;
	cout << left << setw(12) << "   % Score:" << endl ;
	//prints out all of the elements of the array of structs (Candidates)
	for (j= 0 ; j < candidateCount ; j++){
		cout << right << setw(12) << candidates[j].first ;
		cout << right << setw(12) << candidates[j].last ;
		cout << right << setw(12) << candidates[j].votes ;
		cout << right << setw(12) <<  setprecision(4) << candidates[j].pScore << "%" ;
		cout << endl ;
		
	}
}
/*function description : Sorts out the candidats by ascending number of votes.
parameters : Candidate struct defined at beginning and integer that counts the
			 number of candidates.
return value : none since void.
*/
void sortByVotes(Candidate candidates[], int candidateCount) {
bool swapped = false ;
// bubble sort, sorts the candidates in order of ascending number of votes.
	for ( int i = 0 ; i < candidateCount-1 ; i ++){
		swapped = false ;
		for (int j = 0 ; j < candidateCount - i - 1 ; j++ ){
			if(candidates[j].votes >= candidates[j+1].votes){
			swap(candidates[j] , candidates[j+1] ) ;
			swapped = true ;
			}	
		}
		if(!swapped)
		break ;
	}
}
/*function description : Displays candidates with highest and lowest amount of votes.

parameters : Candidate struct defined at beginning and integer that counts the
			 number of candidates.
return value : none since void.
*/
void displayCandidate(Candidate candidates[], int candidateCount) {
// prints out the information of the winning candidate and lowest voted candidate.
	Candidate winner ;
	winner =  getWinner(candidates, candidateCount) ;
	cout << "WINNER : " << endl ;
	cout << " FIRST NAME: " << winner.first << endl ;
	cout << " LAST NAME : " << winner.last << endl ; 
	cout << " VOTES: " << winner.votes << endl ;
	cout << " % GAINED: " << winner.pScore << "%" << endl ;	
	cout << endl ;
	Candidate loser ;
	loser =  getLast(candidates) ;
	cout << "LOWEST SCORE : " << endl ;
	cout << " FIRST NAME: " << loser.first << endl ;
	cout << " LAST NAME : " << loser.last << endl ; 
	cout << " VOTES: " << loser.votes << endl ;
	cout << " % GAINED: " << loser.pScore << "%" << endl ;
	cout << endl ;
}
/*function description : Returns the values of the highest voted candidate.

parameters : Candidate struct defined at beginning and integer that counts the
			 number of candidates.
return value : Gives the struct of the highest voted candidate.
*/
Candidate getWinner(Candidate candidates[], int candidateCount) {
// returns the winning cnadidate, last struct in my array
return candidates[candidateCount-1] ;
}
/*function description : Returns the values of the lowest voted candidate.

parameters : Candidate struct defined at beginning.
return value : Gives the struct of the lowest voted candidate.
*/
Candidate getLast(Candidate candidates[]) {
// returns the last place candidate, first struct in my array
return candidates[0] ;
}
/*function description : Calculates the sum of all of the votes and the percent
						 of votes each candidate recieved.
parameters : Candidate struct defined at beginning and integer that counts the
			 number of candidates.
return value : No return since void.
*/
void calculateScores(Candidate candidates[], int candidateCount) {
	// keeps track of total number of votes
	double totalVotes = 0 ; 
	for (int i = 0 ; i < candidateCount; i ++ ){
		totalVotes = totalVotes + candidates[i].votes ;
	}
	// includes equation for percentage score, and stores them into the structs.
	for (int j = 0 ; j < candidateCount ; j ++) {
		candidates[j].pScore = (candidates[j].votes / totalVotes) *100 ;
	}
}
/*function description : Takes the percentage values calculated before and rounds them up.
parameters : Candidate struct defined at beginning and integer that counts the
			 number of candidates.
return value : No return since void.
*/
void roundScore(Candidate candidates[], int candidateCount){
for (int j = 0 ; j < candidateCount ; j ++) {
		candidates[j].pScore = ceil(candidates[j].pScore) ;
	}
}