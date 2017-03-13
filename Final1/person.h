/*
 * person.h
 *
 *  Created on: Mar 12, 2017
 *      Author: Aaron
 */

#ifndef PERSON_H_
#define PERSON_H_

#include <iostream>
#include <ctime>
#include <string>
using namespace std;

class Person
{
	private:

	string name;
	bool infected;
	bool vaccinated;
	double age; //can be considered the time of death
	bool alive;

	Person(string n = "John Doe", bool i = false, bool v = false, double a = clock(), bool b = true)
	{
		name = n;
		infected = i;
		vaccinated = v;
		age = a + (10 * CLOCKS_PER_SEC); // ten second human lifespan
		alive = b;
	}


	public:

	//deviated a bit from the standard "get" "set" naming of accessor and mutator functions
	//because "getinfected" and "getvaccinated" sounded like setting the booleans to true

	string getname() {return name;}

	bool isinfected() {return infected;} //accessor function
	void setinfected(bool A) {infected = A;} // mutator function
	//would've used the name "infect" as the name for the function, but that's used for an
	//interaction function in the other header

	bool isvaccinated() {return vaccinated;} //accessor function
	void vaccinate() {vaccinated = true;} //mutator function

	double getage() {return age;} //accessor function
	void setage() // specific mutator function (only used at time of infection)
	{
		age -= (age - clock()) * 0.40; //reduces remaining lifespan by 40%
									  //can make more dynamic or change value later
	}

	bool getalive() {return alive;}
	void expire() //can't move from dead to alive, so no bool input needed
	{
		if (clock() >= age) //checks if person is past death time
		{
			alive = false;
			cout << name << " had died." << endl;
		}
	}
};



#endif /* PERSON_H_ */
