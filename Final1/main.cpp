/*
 * main.cpp
 *
 *  Created on: Mar 12, 2017
 *      Author: Aaron
 */

#include <iostream>
#include <ctime>
#include <Windows.h> //this is just to use the sleep function
#include "interaction.h"
#include "person.h"
using namespace std;

int main()
{
	Person Ivan ("Ivan");
	Person Veronica ("Veronica");
	Person Adam ("Adam");
	Person Beatrice ("Beatrice");
	Person Charles ("Charles");

	//To test, five people to start out with

	Ivan.setinfected(true); //Ivan starts out being infected
	Veronica.vaccinate(); //Veronica starts out vaccinated

	collide(Ivan, Veronica);
	Sleep(500); //waits for half a second; this might only be working for me in windows
	cout << "testing one" << endl;

	collide(Ivan, Adam);
	Sleep(500);
	cout << "testing two" << endl;

	collide(Ivan, Beatrice);
	Sleep(500);
	cout << "testing three" << endl;

	collide(Ivan, Charles);
	Sleep(500);
	cout << "testing four" << endl;

	collide(Veronica, Adam);
	Sleep(500);

	collide(Veronica, Beatrice);
	Sleep(500);

	collide(Veronica, Charles);
	Sleep(500);

	collide(Adam, Beatrice);
	Sleep(500);

	collide(Adam, Charles);
	Sleep(500);

	collide(Beatrice, Charles);
	Sleep(5000); //waits for 5 seconds at the end


	cout << Ivan.name;
	cout << Beatrice.isinfected();

	return 0;
}
/* Overall, I'm just having a tough time figuring out why person.h is not compiling
 * and how to get the program to sleep between interactions.
 * Should we figure out the cocos deal, the sleep function would be unneccessary,
 * but I'm unsure whether or not we can do that (I had a really hard time trying to
 * understand it).
 */
