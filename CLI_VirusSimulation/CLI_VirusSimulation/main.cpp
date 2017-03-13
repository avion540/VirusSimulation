/*
 * main.cpp
 *
 *  Created on: Feb 24, 2017
 *      Author: nicholas.zimmerman
 */


#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <thread>
#include <chrono>
#include "Person.h"
#include "Ambulance.h"
using namespace std;
using namespace this_thread;
using namespace chrono;


int main()
{
	// Check for user OS to see if we need to "pause" at end
//	bool windows;
//	char userOS;
//	cout << "Are you running this program on Windows? (y/n) ";
//	cin >> userOS;
//	if (userOS == 'y' || userOS == 'Y')
//	{
//		windows = true;
//	}
//	if (userOS == 'n' || userOS == 'N')
//	{
//		windows = false;
//	}


	int userNumPeople;	// Array size
	//int *a; // Will be array a

	cout << "Welcome to VirusSimulation." << endl;
	cout << "How many people do you want in the simulation? ";
	cin >> userNumPeople;
	// Variable a = new dynamic array of user defined size
	//a = new int[numPeople];
    vector<int> numPeople(userNumPeople);
    cout << "vector numPeople holds: " << numPeople.size() << " elements" << endl;

	// (Maybe we should use vectors to auto - resize instead of arrays)
	int infected = 0;	// When this reaches the same number as the amount of people, simulation ends
    int saved = 0;
    int died = 0;
	bool run = true;		// Used for while loop

    // Start timer
    clock_t start;
    double duration;
    start = clock();
    
    vector<Person> population;

	while (run == true)
	{
		// Your algorithm here
		for (int i = 0; i < userNumPeople; i++)
		{
        
            Person p;
            population.push_back(p);
            
            cout << population[i].natImmunity << endl;
            cout << population[i].health << endl;
            cout << population[i].strain << endl << endl;;
            
			if (infected == userNumPeople)
			{
				run = false;
			}
            run = false;
		}
	}

	duration = (clock() - start) / (double)CLOCKS_PER_SEC;
	cout << "\n\nEveryone was infected." << endl;
    cout << saved << " people were saved by the ambulance." << endl;
	cout << "It took " << duration << " seconds." << endl;


//	if (windows == true)
//	{
//		system("pause");
//		return 0;
//	}
//	else
//		return 0;
}
