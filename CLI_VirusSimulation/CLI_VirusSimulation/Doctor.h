/*
 * Ambulance.h
 *
 *  Created on: Feb 24, 2017
 *      Author: nicholas.zimmerman
 */

#ifndef DOCTOR_H_
#define DOCTOR_H_

#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <cstdlib>
using namespace std;

class Doctor
{
public:
	bool isHealed;
	bool isAlive;

	Doctor(double prob, int intensity);

};


#endif /* DOCTOR_H_ */
