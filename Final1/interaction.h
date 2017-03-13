/*
 * interaction.h
 *
 *  Created on: Mar 12, 2017
 *      Author: Aaron
 */

#ifndef INTERACTION_H_
#define INTERACTION_H_

#include "person.h"
#include <iostream>
using namespace std;

void infect(Person A, Person B)
{
	if (A.isinfected() && !(B.isinfected() || B.isvaccinated()))
		//A being infected but not B being infected or vaccinated
	{
		if ((rand() % 100 + 1) > 60) //a fourty percent chance
		{
			B.setinfected(true);
			cout << A.name << " infected " << B.name << "." << endl;
		}
	}
	if (B.isinfected)
	{
		cout << B.name << "is vaccinated." << endl;
	}
}

void collide(Person A, Person B)
{
	A.expire();
	B.expire();
	if (A.getalive() && B.getalive()) //assuming living people don't go
									  //interacting with dead people
	{
		infect(A,B);
		infect(B,A); //checking both because the infect function only goes one way
	}
}

#endif /* INTERACTION_H_ */
