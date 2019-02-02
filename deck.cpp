/*
Filename: deck.cpp
Written By: Connor Bettermann
Project 2
5.5.2016

This file holds all of the function definitions for the deck and card classes.
The card class holds 2 chars and a num for the information on the face of the card.
The Deck class holds an array of cards set to size 52 for every card in the deck.
The deck also deals with the shuffle function, that shuffles all elements
in the array of cards.
*/
#include "deck.h"


//Default constructor for Card class
Card::Card()
{

}


//Default destructor for Card class
Card::~Card()
{

}


//This constructor for the Card class takes in args to set the members of the Card object.
Card::Card(char in_color, char in_suit, int in_num)
{
	color = in_color;
	suit = in_suit;
	num = in_num;
}


//This is the copy constructor for the Card class using a pointer as arg
Card::Card(const Card *& to_copy)
{
	color = to_copy->color;
	suit = to_copy->suit;
	num = to_copy->num;
}


//This function prints a Card object
int Card::print_card()
{
	cout 	<<" -"
		<< color
		<< suit
	 	<< num
		<< "- ";
	return 0;
}


//This function is used to print a card without revealing the data of the card.
int Card::print_card_face_down()
{
	cout	<<" -"
		<<"?"
		<<"?"
		<<"??"
		<<"- ";
	return 0;


}


//This function sets the data of a card to the args
int Card::set_card(char in_color, char in_suit, int in_num)
{
	color = in_color;
	suit = in_suit;
	num = in_num;

}


//This function returns a pointer to this Card object
Card* Card::get_card()
{

	return this;
}


//This is a copy function for Card class using a Card object
int Card::copy_card(Card &to_copy)
{
	color = to_copy.color;
	suit = to_copy.suit;
	num = to_copy.num;
	return 0;
}


//This is a copy function for the Card class using a pointer for arg
int Card::copy_card(Card *to_copy)
{
	color = to_copy->color;
	suit = to_copy->suit;
	num = to_copy->num;
	return 0;
}


//This function returns a Card num member
int Card::get_num()
{
	return num;
}


//This function returns a Card color member
char Card::get_color()
{
	return color;

}

//This is the default constructor for the Deck class
Deck::Deck()
{
	deck = NULL;
}


//This is the default destructor for the Deck class
Deck::~Deck()
{
	delete []deck;
}



//This constructor for the Deck class allocates an array of cards
//sized to the input arg
Deck::Deck(int in_DECK_SIZE)
{
	DECK_SIZE = in_DECK_SIZE;
	deck = new Card[DECK_SIZE];	
}


//This function fills the deck array with data from the external data file
int Deck::fill_deck()
{
	ifstream infile;
	infile.open("cards.txt");
	for (int i = 0; i < DECK_SIZE; i++)
	{
		char color;
		char suit;
		int num;
		infile >> color >> suit >> num;
		infile.ignore(DECK_SIZE, '\n');
		deck[i].set_card(color, suit, num);
	}
	infile.close();	
	return 0;
}


//This function prints all of the cards in the deck
int Deck::print_deck() const
{
	print_deck(0);
	return 0;	
}


//This function is called by the other print deck function
int Deck::print_deck(int index) const
{
	if(index == DECK_SIZE)
		return 0;
	else
	{
		deck[index].print_card();
		index++;
		return print_deck(index);
	}
	return 0;
}


//This function is used by the shuffle function to swap two card objects in the array
int Deck::swap(int a, int b)
{
	Card * temp = new Card;
	temp->copy_card(deck[a]);
	deck[a].copy_card(deck[b]);
	deck[b].copy_card(temp);
	return 0;
}


//This function shuffles the array of cards
int Deck::shuffle()
{
	srand(time(NULL));
	for (int i = (DECK_SIZE - 1); i > 0; i--)
	{
		int j = rand() % (i + 1);
		swap(j, i);
				
	}
	return 0;
}


//This function returns a pointer to a card located at the input index
Card* Deck::get_card(int deck_index)
{
	Card * temp = deck[deck_index].get_card();
	return temp;

}
