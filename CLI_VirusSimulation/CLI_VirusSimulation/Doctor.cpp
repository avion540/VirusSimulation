/*
 * Doctor.cpp
 *
 *  Created on: Feb 24, 2017
 *      Author: nicholas.zimmerman
 */


#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <cstdlib>
#include "Person.h"
#include "Doctor.h"
using namespace std;

Doctor::Doctor(double prob, int intensity) {
	if (rand() % 101 <= prob)	//rand produces 0-100
	{
		isHealed = false;
		isAlive = false;	
	}
	else {
		isHealed = true;
		isAlive = true;
	}
}