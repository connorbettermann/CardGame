/*
Filename: deck.h
Written By: Connor Bettermann
Project 2
5.5.2016

This file contains all of the function prototypes for the deck and card classes
The Card class represents a card that is in the deck. The deck class represents
an array of cards to be used in either game
*/
#include <cstring>
#include <fstream>
#include <iostream>
#include <ctime>
#include <cstdlib>

#ifndef _DECK_H
#define _DECK_H

using namespace std;

class Card
{
	public:
		Card();
		Card(char in_color, char in_suit, int in_num);
		Card(const Card *& to_copy);
		~Card();
		int print_card();
		int print_card_face_down();
		int set_card(char in_color, char in_suit, int in_num);
		Card* get_card();
		int copy_card(Card &to_copy);
		int copy_card(Card *to_copy);
		int get_num();
		char get_color();
	private:
		char color; //color of card
		char suit; //suit of card
		int num; //number of card
};


class Deck
{
	public:
		Deck();
		~Deck();
		Deck(int in_DECK_SIZE);
		int fill_deck();
		int print_deck() const;
		int print_deck(int index) const;
		int swap(int a, int b);
		int shuffle();
		Card* get_card(int deck_index);
	protected:
		Card * deck; //array of cards
		int DECK_SIZE; //size of the array of cards
};


#endif
