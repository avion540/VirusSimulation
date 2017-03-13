//
//  Person.h
//  VirusSimulation
//
//  Created by Nick Zimmerman on 3/12/17.
//
//



#ifndef Person_h
#define Person_h

#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <cstdlib>
using namespace std;

class Person
{
public:
    int natImmunity;
    int health;
    int strain;
    bool dead = 0;
    
    //Deconstructor
    ~Person();
    
    //Default constructor
    Person();
    
    //Constructor given health probablility
    Person(double prob);
    
    //Constructor given probability and a strain intensity
    Person(double prob, int intensity);
    
    
    //Full-control constructor
    Person(int nat,int h, int s);
    
    void iterate(int popSize);
};


#endif /* Person_h */



