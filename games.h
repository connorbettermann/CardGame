/*
Filename: games.h
Written By: Connor Bettermann
Project 2
5.5.2016

This file holds all of the function prototypes for the game, Blackjack, 
and solitaire classes. The Blackjack and Solitaire classes are sub classes
of the Game class. The Game class is purely abstract and will never have
an object of it created.
*/
#include "deck.h"
#include "adt.h"
#include <iostream>

#ifndef _GAMES_H
#define _GAMES_H


using namespace std;


class Game
{
	public:
		virtual int deal(Deck * deck, int deck_index)= 0;
		virtual int display_start_board() = 0;
		virtual int play(Deck * deck) = 0; //all pure virtual functions
							//used by both sub classes
	protected:

};


class Solitaire : public Game
{
	public:
		Solitaire();
		~Solitaire();
		int deal(Deck * deck, int deck_index);
		int display_start_board();
		int play(Deck * deck);
		int display_board(Deck * deck, int deck_index);
		char get_tail_color(int index);
		int get_tail_num(int index);
		char get_face_up_color(int index);
		int get_face_up_num(int index);
		int move_card(int orig, int dest);
		int move_from_deck(Card * orig, int dest);
	private:
		Array * s_board; //The board for solitaire
};



class Blackjack : public Game
{
	public:
		Blackjack();
		~Blackjack();
		int play(Deck * deck);
		int deal(Deck * deck, int deck_index);
		int display_start_board();
		int display_board(l_node * round, int house_index, int player_index);
		int display_draw_board(l_node * round, int house_index, int player_index);
		int display_winner();
		int check_bust();
	private:
		List * b_board; //The blackjack board
		int player_total; //total of player hand
		int house_total; //total of house hand

};


#endif
