/*
Filename: adt.h
Written By: Connor Bettermann
Project 2
5.5.2016

This file contains all of the function definitions for the data structures
used by the game classes. These data structures are only influenced and
altered by the game classes
*/
#include <cstring>
#include "deck.h"

#ifndef _ADT_H
#define _ADT_H

using namespace std;

//node for the array class
class a_node
{
	public:
		a_node();
		a_node(Card * to_add);
		~a_node();
		int set_next(a_node * new_next);
		int set_prev(a_node * new_prev);
		a_node * get_next();
		a_node * get_prev();
		int print_card();
		char get_card_color();
		int get_card_num();
		int move(a_node * dest);

	private:
		Card * card;
		class a_node * next;
		class a_node * prev;
};

//
class Array
{
	public:
		Array();
		Array(int rows);
		~Array();
		int insert(Card * to_add, int cards_in_row);
		int insert_as_first(Card * to_add, int cards_in_row);
		a_node * get_head(int index);
		a_node * get_tail(int index);
		a_node * get_face_up(int index);
		int set_face_up(int index, a_node * new_face_up);
		int print_row(int row);
		int move(int orig, int dest);

	private:
		a_node ** head; //array of head pointers to a_nodes
		a_node ** tail; //array of tail pointers to a_nodes
		a_node ** face_up; //array of pointers representing
					//the first card in the list
					//to be displayed face up
};

//Node for the List class
class l_node
{
	public:
		l_node();
		l_node(int MAX_HAND);
		~l_node();
		l_node * get_next();
		int set_next(l_node * new_next);
		int add_player_hand(Card * to_copy, int player_index);
		int add_house_hand(Card * to_copy, int house_index);
		int print_player_hand(int player_index);
		int print_house_hand(int house_index);
		int print_house_face_down(int house_index);
	private:
		class l_node * next;
		Card * player_hand; //array of cards for player hand
		Card * house_hand; //array of cards for house hand
		

};



class List
{
	public:
		List();
		~List();
		l_node * get_head();
		int set_head(l_node * new_head);
	private:
		l_node * head; //haed pointer

};


#endif
