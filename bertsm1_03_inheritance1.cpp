/*Program Description: The purpose of this program is to keep track of how much water, coffee, and milk are in a 
					  coffee machine and to determine whether it has enough resources to complete an order made by a customer.
					  Also to display the information about the resources before and after orders.*/

#include <iostream>
// Preprocessor Directives -  Loads C++ libraries for use in your program.
using namespace std ;
// specifying the right namespace so we do not have to clarify everytime std.

//Global constant declaration
const int DEFAULT_CAPACITY = 10 ;
/*Class description: This is the base class named CoffeeMachine. It has public, protected, and private members.
				All information about the coffee machine and its resources, as well as the funcitons to create cups of coffee are contained in here. 
  Constructors: Parameterless: Initializes all variables to default settings. Prints out to display that the coffee machine object has been created.
				Parameter(string name): Initializes all the variables to default settings and the name to DECAF.
										Prints out to display that the decaf coffee machine object has been created.
				Parameter(name,water_capacity0,coffee_capacity0): Initializes all of the variables to default settings.
															      Names the coffee machine and sets the capacities as values given.
															      Also prints out the creation of the coffee machine and its capacities to display.
  Public Functions: makeCups: Returns 0 if there is not enough resources to create the number of cups ordered.
  							  Returns 1 if there is enough resources for the order and makes the cups of coffee.
					addWater: No return value. Fills the water to a value passed to it from a function
					addCoffee:No return value. Fills the coffee to a value passed to it from a funciton.
					setCoffeeSpoonsPerCup: No return value. Sets the strength of coffee passed to it from a function.
					displayCM: displays the current state of all the resources to the display.
  */	
class CoffeeMachine{
public: 
// Variable declarations.
	string name;
	int cupsOrdered ;
/*Function: checks if there is enough resources to create cups ordered.
  parameters: int cups
  return value: int
  */
	int makeCups(int cups){
		if (curr_coffee < cups*coffee_spoons_per_cup || curr_water < cups ) {
			cout << "ordered " << cups << " cups of coffee of strength "<< coffee_spoons_per_cup << endl ;
			cout << "NOT ENOUGH RESOURCES! "<< endl ;
			return 0 ;
		}
		else if (curr_coffee >= cups && curr_water >= cups ) {
			cout << "ordered " << cups << " cups of coffee of strength " << coffee_spoons_per_cup ;
			cout << endl ;
			for (int i = cups ; i > 0 ; i --){
				makeSingleCup(name) ;
			}
			cout << endl ;
			return 1 ;
		}
	} 
	/*Function: adds water to the coffeemachine. Fills to full if over the capacity.
	  parameters: int cups
	  return value: none
	  */
	void addWater(int cups){
		if(cups>=water_capacity){
			curr_water = water_capacity ;
		}
		if(cups<water_capacity){
			curr_water = curr_water + cups ;
		}
	} 
	/*Function: adds coffee to the coffeemachine. Fills to full if over the capacity.
	  parameters: int cups
	  return value: none
	  */
	void addCoffee(int cups){
		if(cups>=coffee_capacity){
			curr_coffee = coffee_capacity ;
		}
		if(cups<coffee_capacity){
			curr_coffee = curr_coffee + cups ;
		}
	} 
	/*Function: sets the strength of the coffee.
	  parameters: int newStrength
	  return value: none
	  */
	void setCoffeeSpoonsPerCup(int newStrength) {
		coffee_spoons_per_cup = newStrength ;
	} 
	/*Function: Displays the status of all the resources to the display.
	  parameters: string name
	  return value: none
	  */
	void displayCM(){
		cout << "Current state of CM: " << name << endl ;
		cout << "  WATER:  " << curr_water << " / " << water_capacity << " (cups)" << endl; 
		cout << "  COFFEE: " << curr_coffee << " / " << coffee_capacity << " (spoons)" << endl; 
		cout << "  STRENGTH: " << coffee_spoons_per_cup << " coffee spoons per cup" << endl ;
	} 
	//Constructors and Destructors
	CoffeeMachine() ;
	CoffeeMachine(string) ;
	CoffeeMachine(string,int,int) ;
	~CoffeeMachine() ;
private:
	/*Function: makes a single cup of coffee. Uses a certain amount of coffee and water from the machine.
	  parameters: string name
	  return value: none
	  */
	void makeSingleCup(string name){
		curr_water-- ;
		curr_coffee= curr_coffee -coffee_spoons_per_cup ;
		cout << "...made cup of coffee " << name << " ..." << endl ;
	} 
	// Variable Declarations
	int water_capacity ;
	int coffee_capacity ;
	int curr_water ;
	int curr_coffee ;
protected:
	int coffee_spoons_per_cup = 1;
} ;

//Default Constructor
CoffeeMachine::CoffeeMachine() {
	curr_water = 0 ;
	cout << "called" << endl;
	curr_coffee = 0 ;
	water_capacity = DEFAULT_CAPACITY ;
	coffee_capacity = DEFAULT_CAPACITY ;
	coffee_spoons_per_cup = 1 ;
	name = "UNTITLED" ;
	cout << "Created Coffee Machine " << name << " with empty resources." << endl ;
} 
//Constructor with parameter string name
CoffeeMachine::CoffeeMachine(string name0) {
	curr_water = 0 ;
	curr_coffee = 0 ;
	water_capacity = DEFAULT_CAPACITY ;
	coffee_capacity = DEFAULT_CAPACITY ;
	coffee_spoons_per_cup = 1 ;
	name = name0 ;
	cout << "Created Coffee Machine " << name << " with empty resources." << endl ;
} 
//Constructor with parameters name, water_capacity0, and coffe_capacity0 
CoffeeMachine::CoffeeMachine(string name0, int water_capacityO, int coffee_capacityO){
	curr_water = 0 ;
	curr_coffee = 0 ; 
	coffee_spoons_per_cup = 1 ; 
	water_capacity = water_capacityO ;
	coffee_capacity = coffee_capacityO ;
	name = name0 ;
	cout << "Starting up Coffee Machine " << name << " with empty resources and capacities: " ;
	cout << endl ; 
	cout << "water_capacity=" << water_capacity << endl ;
	cout << "coffee_capacity=" << coffee_capacity << endl ;
} 
//Destructor
CoffeeMachine::~CoffeeMachine() {
	cout << "Shutting down Coffee Machine " << name << " with the following resources: " << endl ;
	cout << " water: " << curr_water << endl ;
	cout << " coffee: " << curr_coffee << endl ; 
} ;

/*Function: Main function responsible for the creation of the objects, and the setting of values like the name, 
			capacity, and amount of resources available.
  parameters: none
  return value: int
 */
int main() {

	CoffeeMachine cm1 ;
	cm1.addWater(8) ;
	cm1.addCoffee(8) ;
	cm1.displayCM() ;
	cm1.makeCups(5) ;
	cm1.displayCM() ;

	CoffeeMachine cm2("DECAF") ;
	cm2.addWater(1000) ;
	cm2.addCoffee(1000) ;
	cm2.displayCM() ;
	cm2.makeCups(14) ;

	CoffeeMachine cm3("BLEND", 15, 20) ;
	cm3.addWater(14) ;
	cm3.addCoffee(20) ;
	cm3.displayCM() ;
	cm3.makeCups(12) ;
	cm3.displayCM() ;
	cm3.makeCups(5) ;
}





