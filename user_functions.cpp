/*
Filename: user_functions.cpp
Written By: Connor Bettermann
Project 2
5.5.2016

This file contains all of the function definitions used in the temporary
client program. All of these functions represent how a client program would
interact with the other classes in the program
*/
#include "user_functions.h"



//This function represents an initial menu from which the user can
//select which game they would like to play 
int menu(int DECK_SIZE)
{
	Deck * deck = new Deck(DECK_SIZE);
	Game * game;
	deck->fill_deck(); //This fills the deck that has just been created with cards
	
	char selection;
	cout << "\n-----Welcome to the Ultimate Card Game Experience v1.0-----\n";

	while (selection != 'q')
	{
		deck->shuffle();
		cout 	<< "\nPlease select from one of the following options:\n"
			<< "1. Print Card Format Instructions\n"
			<< "2. Play Solitaire\n"
			<< "3. Play Blackjack\n"
			<< "q. Quit \n"
			<< "\nSelection: ";
		cin >> selection;

		switch (selection)
		{
		case '1':
		{
			print_format();	//This prints the card format	
			break;
		}
		case '2':
		{
			Solitaire * solitaire = new Solitaire();
			game = (&*solitaire); //upcasting to an appropriate class object
			game->play(deck); //call proper function through dynamic binding
					
			break;
		}
		case '3':
		{
			Blackjack * blackjack = new Blackjack();
			game = (&*blackjack); //upcast to appropriate object
			game->play(deck); //call correct function through dynamic binding
			break;
		}
		case 'q':
		{
			break;
		}
		default:
		{
			break;
		}
		};

	}
	return 0;
}


//This function prints the format of the cards to be displayed
int print_format()
{

	cout	<< "\n----Card Format----\n"
		<< "\n----Color----"
		<< "\nr = RED  \tb = BLACK"
		<< "\n\n----Suit----"
		<< "\nc = CLUBS\ts = SPADES\td = DIAMONDS\th = HEARTS\n\n";
	return 0;
}
