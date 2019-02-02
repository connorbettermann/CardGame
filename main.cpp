/*
Filenmae: main.cpp
Written By: Connor Bettermann
Project 2
CS202
4.28.2016

This program plays two different card games, Blackjack and Solitaire, 
both derived from the same base class. Using dynamic binding, 
the code is able to call functions  at compile time, based on 
the data type of the object that is calling it. Upcasting is
also used to have a base class pointer, and assign it to point to a derived class object.
This pointer is then used to access the derived class functions.

*/

#include <iostream>
#include "user_functions.h"

using namespace std;


const int DECK_SIZE = 52;

int main()
{
	
	menu(DECK_SIZE);


	return 0;
}
