/*
Filename: adt.cpp
Written By: Connor Bettermann
Project 2
5.3.2016

This file holds all of the function definitions for the data structure
classes used in this program. With all of the functions listed here, the program
can store information regarding the two games that can be played by the user.
*/


#include "adt.h"



//Default Constructor for a_node class
a_node::a_node()
{
	next = NULL;
	prev = NULL;
	card = NULL;
}


//Constructor for a_node class that takes a card pointer as an argument
//and sets its own card pointer to point to that input
a_node::a_node(Card * to_add)
{
	
	card = to_add;

}


//Default destructor for a_node class
a_node::~a_node()
{
	delete next;
	delete prev;
	delete card;

}


//This function sets the next pointer of an a_node object to the input
int a_node::set_next(a_node * new_next)
{
	next = new_next;
	return 0;
}


//This function sets the previous pointer to the input
int a_node::set_prev(a_node * new_prev)
{
	prev = new_prev;
	return 0;

}


//This function returns a pointer to the next a_node in the list
a_node * a_node::get_next()
{
	return next;
}


//This function returns an a_node pointer that points to the previous
//node in the list
a_node * a_node::get_prev()
{
	return prev;
}


//This function prints the contents of the card that the card pointer
//is pointing to
int a_node::print_card()
{
	card->print_card();
	return 0;

}


//This function returns the color of the card that the card pointer
//is pointing to
char a_node::get_card_color()
{
	return card->get_color();

}



//This function returns the number of the card that the card pointer
//is pointing to
int a_node::get_card_num()
{
	return card->get_num();
}


//This function sets all of the pointers of an a_node object so that
//they link up with a new spot in a new list
int a_node::move(a_node * dest)
{
	prev->next = NULL;
	prev = dest;
	dest->next = this;
	next = NULL;
	return 0;

}


//This is the default constructor for the Array class
Array::Array()
{
	head = NULL;
	tail = NULL;
	face_up = NULL; //This is an array of a_node pointers that represents the first card that
			//should appear face up when displaying the cards.
}


//This is a constructor for the Array class that initializes all members to be
//a_node arrays of pointers. These arrays are each initializes to the size of the input
Array::Array(int rows)
{
	head = new a_node * [rows];
	tail = new a_node * [rows];
	face_up = new a_node * [rows];
	
}


//This is the default destructor for the Array class
Array::~Array()
{
	delete []head;
	delete []tail;
	delete []face_up;

}



//This function inserts a card onto the end of a list in a specific element of the array
//INPUT: Card pointer to the card to add, int for the element in the array to add to
int Array::insert(Card * to_add, int cards_in_row)
{
	if(head[cards_in_row] == NULL)
	{
		insert_as_first(to_add, cards_in_row); //If nothing in the list add as first
	}
	else
	{
		a_node * temp = new a_node(to_add);
		temp->set_prev(tail[cards_in_row]);
		tail[cards_in_row]->set_next(temp);
		tail[cards_in_row] = temp;
		face_up[cards_in_row] = temp; //Setting the last card to be the only one face up
	}
	return 0;
}



//This function is used by the insert function to insert a new node into a list in an element of the array
//INPUT: Card pointer, int for element in which to add to
int Array::insert_as_first(Card * to_add, int cards_in_row)
{
	a_node * temp = new a_node(to_add);
	head[cards_in_row] = temp;
	tail[cards_in_row] = temp;
	face_up[cards_in_row] = temp;
	return 0;

}


//This function moves the card at face up in the element of the orig value to
//the tail of the dest value element. Once moved, the tail of the destination will
//be set to the new node and the orig list will be updated as well
int Array::move(int orig, int dest)
{
	if(tail[orig] == head[orig]) //If last card in list
	{
		face_up[orig]->move(tail[dest]);
		tail[dest] = face_up[orig];
		face_up[orig] = NULL;
		tail[orig] = NULL;
		head[orig] = NULL;
	}
	else
	{
		a_node * temp = face_up[orig]->get_prev();
		face_up[orig]->move(tail[dest]);
		tail[dest] = face_up[orig];
		face_up[orig] = temp;
		tail[orig] = temp;
	}
		
	return 0;
}


//This function prints a list of one of the elements in the array depending on the arg
int Array::print_row(int row)
{
	a_node * temp = head[row];
	while(temp != NULL)
	{
		if(temp == face_up[row])
		{
			while(temp != NULL)
			{
				temp->print_card();
				temp = temp->get_next();
			}
			return 0;
		}
		else
		{
			cout << " ??\t";
			temp = temp->get_next();
		}	
	}
	return 0;

}


//This function returns an a_node pointer for the head of a list in the element
//defined in the arg
a_node * Array::get_head(int index)
{
	return head[index];

}


//This function returns an a_node pointer to the tail of the element in the array
//defined by the arg
a_node * Array::get_tail(int index)
{
	return tail[index];
	
}


//This function returns an a_node pointer of the face up member of a list in the element
//of the array defined by the arg
a_node * Array::get_face_up(int index)
{
	return face_up[index];
}



//This function sets the face up member to a new a_node passed in through the args
//INPUT: int for the element in the array to modify, a_node pointer for new face up
int Array::set_face_up(int index, a_node * new_face_up)
{
	face_up[index] = new_face_up;

}


//This is the default constructor for the l_node class
l_node::l_node()
{
	next = NULL;
	player_hand = NULL;
	house_hand = NULL;
}

//This is a constructor for the l_node class that initializes each players hand to
//the size plus 1 of the input arg
//INPUT: int for max player hand size
l_node::l_node(int MAX_HAND)
{
	player_hand = new Card[MAX_HAND + 1];
	house_hand = new Card[MAX_HAND + 1];
	next = NULL;
}


//default deconstrucotr for the l_node class
l_node::~l_node()
{
	delete []player_hand;
	delete []house_hand;
	delete next;

}


//This function returns the next pointer of a l_node object
l_node * l_node::get_next()
{
	return next;

}


//This functions sets the next pointer of a l_node object to the input arg
int l_node::set_next(l_node * new_next)
{

	next = new_next;
	return 0;

}



//This function adds a card to the players hand through the args
//INPUT: Card pointer of card to insert and int for the element of the player array to add to
int l_node::add_player_hand(Card * to_copy, int player_index)
{
	player_hand[player_index].copy_card(to_copy);
	return 0;
}


//This function adds a card the the house hand array
//INPUT: Card pointer to the card to add, int for the element of the array to add to
int l_node::add_house_hand(Card * to_copy, int house_index)
{
	house_hand[house_index].copy_card(to_copy);
	return 0;
}


//This function prints all of the elements in the players hand that contain cards
int l_node::print_player_hand(int player_index)
{
	cout 	<< "\n\n ---------------PLAYER CARDS--------------\n";	
	for(int i = 0; i < player_index; i++)
	{
		player_hand[i].print_card();
	}
	return 0;
}


//This function prints all of the elements in the houses hand that contain cards
int l_node::print_house_hand(int house_index)
{
	cout  	<< "\n\n ---------------HOUSE CARDS---------------\n";

	for(int i = 0; i < house_index; i++)
	{
		house_hand[i].print_card();
	}
	return 0;
}


//This function displays the first two cards at initial draw time, the first being face down
int l_node::print_house_face_down(int house_index)
{
	cout	<< "\n\n ---------------HOUSE CADRS---------------\n";
	house_hand[0].print_card();
	house_hand[1].print_card_face_down();

	return 0;
}


//This is the default constructor for the List class
List::List()
{
	head = NULL;
}



//This is the default destructor for the List class
List::~List()
{
	delete head;

}


//This function returns a l_node pointer for the head member
l_node * List::get_head()
{
	return head;
}


//This function sets the head member to the input arg
int List::set_head(l_node * new_head)
{
	head = new_head;
	return 0;
}
