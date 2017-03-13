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
//#include "Ambulance.h"
using namespace std;
using namespace this_thread;
using namespace chrono;


int main()
{
	int numPeople;	// Array size
	//int *a; // Will be array a

	cout << "Welcome to VirusSimulation." << endl;
	cout << "How many people do you want in the simulation? ";
	cin >> numPeople;
	// Variable a = new dynamic array of user defined size
	//a = new int[numPeople];

	// (Maybe we should use vectors to auto - resize instead of arrays)
	int infected = 0;	// When this reaches the same number as the amount of people, simulation ends
    int saved = 0;
    int died = 0;
	bool run = true;		// Used for while loop
    int prob = 50;      //should be a user entry
    // Start timer
    clock_t start;
    double duration;
    start = clock();
    
    vector<Person> population;
    vector<Person> temp;
	while (run == true)
	{
		// Your algorithm here
		for (int i = 0; i < numPeople; i++)
		{
            Person p;
            population.push_back(p);
            
            cout << population[i].natImmunity << ", " << population[i].health << ", " << population[i].strain << endl;
            
            
            
			if (infected == numPeople)
			{
				run = false;
			}
            run = false;
		}
        
        for(int i = 0; i < numPeople; i++) //transfer checker
            for(int a = (i+1); a < numPeople; a++)
            {
                if((population[i].health = 1) && (population[a].health = 0))
                    if((prob / population[i].natImmunity) < (rand() % 100))
                        population[i].health = 0;
                if((population[i].health = 0) && (population[a].health = 1))
                    if((prob / population[a].natImmunity) < (rand() % 100))
                        population[a].health = 0;
            }
        
        temp = population;
        population.clear();
        for(int i = 0; i < numPeople; i++) //death checker
        {
            if((population[i].strain * 4) < (rand() % 100))
            {
                population[i].dead = 1;
                died++;
            }
            else
            { temp.push_back(population[i]); }
        }
        numPeople = static_cast<int>(population.size());
        temp.clear();
    }
    

    
	duration = (clock() - start) / (double)CLOCKS_PER_SEC;
	cout << "\n\nEveryone was infected." << endl;
    cout << saved << " people were saved by the ambulance." << endl;
	cout << "It took " << duration << " seconds." << endl;

	system("pause");
}
    
    
