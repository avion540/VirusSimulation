/*
 * Person.h
 *
 *  Created on: Feb 24, 2017
 *      Author: nicholas.zimmerman
 */

#ifndef PERSON_H_
#define PERSON_H_

#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <cstdlib>
using namespace std;

class Person
{
public:
int health;
int natImmunity;
int strain;

Person(int h, int nat, int s) {
	health = h;
	natImmunity = nat;
	strain = s;
}


};



#endif /* PERSON_H_ */
