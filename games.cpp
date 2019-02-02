/*
Filename: games.cpp
Written By: Connor Bettermann
Project 2
5.5.2016

This file contains all of the function definitions for the Solitaire
and the Blackjack classes. These classes are used by the client program to 
play both games listed above. The classes do directly interact with the user, 
because trying to implement the functions without interacting with the user 
would complicate and distort the purpose of the program. 
*/
#include "games.h"


//This is the default constructor for the Solitaire class
Solitaire::Solitaire()
{
	s_board = NULL;
}

//This is the default destructor for the Solitaire class
Solitaire::~Solitaire()
{
	delete s_board;

}


//This function is used to start a game of solitaire and interact
//with the user. This function uses the deck passed in through the args
//to "deal" cards and then keeps track of the next card to be accessed.
int Solitaire::deal(Deck * deck, int deck_index)
{
	int rows = 7; //This represents the number of rows on the board
	char selection;
	s_board = new Array(rows);
	deck->shuffle();	//SHuffle the deck
	
	for(int i = 0; i < rows; i++) //element in array
	{
		for(int j = i; j < rows; j++) //number of nodes in list
		{
			s_board->insert(deck->get_card(deck_index), i);
			deck_index++; //Fills the board with cards
		}
	}

	display_board(deck, deck_index); //displays the board
	cin.ignore();	
	cout 	<< "1. Move Card\n"
		<< "2. Flip Next Card on Deck\n"
		<< "3. Quit\n"
		<< "Selection: ";
	cin >> selection; //First player selection for action
	
	while(selection != 3)
	{	
	switch (selection)
	{
	case '1':
	{
		int orig;
		int dest;
		cout << "Enter row to move(0 = DECK): ";
		cin >> orig;
		cout << "Enter destination row: ";
		cin >> dest;
		if ( orig == 0) //moving from the deck to a row
		{
			dest--; //This function sets the row number 
				//to the element number in the array
			move_from_deck(deck->get_card(deck_index), dest);
			deck_index++;	//Moving card from one row to another
		}
		else //moving from one row to another
		{
			orig--;
			dest--;
			move_card(orig, dest);
		}
		display_board(deck, deck_index);
		cout 	<< "1. Move Card\n"
			<< "2. Flip Next Card on Deck\n"
			<< "3. Quit\n"
			<< "Selection: ";
		cin >> selection;
		break;
	}
	case '2': //This displays the next card in the deck
	{
		deck_index++;
		display_board(deck, deck_index);
		cout 	<< "1. Move Card\n"
			<< "2. Flip Next Card on Deck\n"
			<< "3. Quit\n"
			<< "Selection: ";
		cin >> selection;
		break;
		
	}
	case '3':
		return 0;
	default:
		cout << "Invalid entry!" << endl;
		cout << "Selection: ";
		cin >> selection;
		break;
		
	};
	}

	

	return 0;
}


//This function moves a card from the top of the deck to the row
//provided in the arg
int Solitaire::move_from_deck(Card * orig, int dest)
{
	if(orig->get_color() == get_tail_color(dest)) //check if color is valid
	{
		cout << "\nIllegal move! Card to move must be different color than destination spot\n";
		return 0;
	}
	if(orig->get_num() != get_tail_num(dest) - 1) //check if num is valid
	{
		cout << "\nIllegal move! Card to move number must be one less than destination card number\n";
		return 0;
	}

	a_node * temp = s_board->get_face_up(dest); //insert card into list
	s_board->insert(orig, dest);
	s_board->set_face_up(dest, temp); //set the face up pointer
	return 0;

}


//This function moves a card from one row to another on the board
int Solitaire::move_card(int orig, int dest)
{
	if(get_face_up_color(orig) == get_tail_color(dest)) //check if color is valid
	{
		cout << "\nIllegal move! Card to move must be different color than destination spot\n";
		return 0; 
	}
	if(get_face_up_num(orig) != get_tail_num(dest) - 1) //check if num is valid
	{
		cout << "\nIllegal move! Card to move number must be one less than destination card number\n";
		return 0;
	}
	else
	{
		s_board->move(orig, dest); //execute the move
	}
	return 0;

}


//return the number of the card pointed to by the face up pointer
int Solitaire::get_face_up_num(int index)
{
	return s_board->get_face_up(index)->get_card_num();

}


//return the color of the card pointer to by the face up pointer
char Solitaire::get_face_up_color(int index)
{
	return s_board->get_face_up(index)->get_card_color();

}


//return the color of the card pointer to by the tail pointer
char Solitaire::get_tail_color(int index)
{
	return s_board->get_tail(index)->get_card_color();

}


//return the num of the card pointer to by the tail pointer
int Solitaire::get_tail_num(int index)
{
	return s_board->get_tail(index)->get_card_num();

}


//This function displays the solitaire board with cards only face up when appropriate
int Solitaire::display_board(Deck * deck, int deck_index)
{
	cout 	<< "Deck: ";
		deck->get_card(deck_index)->print_card();
	cout << endl;	
	int rows = 7;  //number of rows on the board
	for (int i = 0; i < rows; i++)
	{
		cout	<< "Row " << i + 1 << ": ";
		s_board->print_row(i);
		cout << endl;
	}
	return 0;

}

//This function serves as a template for the board format
int Solitaire::display_start_board()
{
	
	cout 	<< "Deck: \n";
	int rows = 7;
	for(int i = 0; i < rows; i++)
	{
		cout << "Row " << i + 1 << ":\t";
		for(int j = i; j < rows; j++)
		{
			cout << "??\t";
		}
		cout << endl;
	}

	return 0;
}


//This function is called by the user program using dynamic binding
//to call the function based on the object type
int Solitaire::play(Deck * deck)
{
	char selection;
	int deck_index = 0; //which element of the array of cards is next
	display_start_board();
	cout	<< "1. Deal\n"
		<< "2. Quit\n"
		<< "Selection: ";
	cin >> selection;
	if(selection == '1')
	{
		deal(deck, deck_index);
	}
	else if(selection == '2')
	{
		return 0;
	}
	return 0;
}


//This is the default constructor for the Blackjack class
Blackjack::Blackjack()
{
	b_board = NULL;
}


//This is the default destructor for the Blackjack class
Blackjack::~Blackjack()
{

	delete b_board;
}


//This function is called by the client program to play the Blackjack game
//using dynamic binding to call the proper function based on object type
int Blackjack::play(Deck * deck)
{
	char selection;
	int deck_index = 0;
	display_start_board();
	cout	<< "1. Deal\n"
		<< "2. Quit\n"
		<< "Selection: ";
	cin >> selection;
	if(selection == '1')
	{
		deal(deck, deck_index);
	}
	else if(selection == '2')
	{
		return 0;
	}
	return 0;

}


//This function serves as the way for the user to make moves and interact
//with the game.
int Blackjack::deal(Deck * deck, int deck_index)
{
	int player_index = 0; //how many cards are in the players hand
	int house_index = 0; //how many cards are in the houses hand
	int MAX_HAND = 10; //the max number of cards allowed in a hand
	l_node * round = new l_node(MAX_HAND); //a new round for the game

	for(int i = 0; i < 2; i++) //this deals the initial two cards to both parties
	{	
		round->add_player_hand(deck->get_card(deck_index), player_index);
		player_total = player_total + deck->get_card(deck_index)->get_num();
		deck_index++;
		player_index++;
		round->add_house_hand(deck->get_card(deck_index), house_index);
		house_total = house_total + deck->get_card(deck_index)->get_num();
		deck_index++;
		house_index++;
	}

	display_draw_board(round, house_index, player_index);	//This displays the first board after the deal

	check_bust(); //this checks to see if either player has bust
	char selection;
	while(selection != '2' && player_total != 0) //this checks if the player decides to stay or they have busted( total == 0)
	{
		cout 	<< "\n1. Hit\n"
			<< "2. Stay\n"
			<< "Choice: ";
		cin >> selection;
		if(selection == '1') //this adds a card to the players hand
		{
			round->add_player_hand(deck->get_card(deck_index), player_index);
			player_total = player_total + deck->get_card(deck_index)->get_num();
			deck_index++;
			player_index++;
			display_draw_board(round, house_index, player_index);
			check_bust();
		}
	}

	while(house_total < player_total && house_total != 0 && player_total != 0) //This is parameters for when the house should continue to hit
	{
		round->add_house_hand(deck->get_card(deck_index), house_index);
		house_total = house_total + deck->get_card(deck_index)->get_num();
		deck_index++;
		house_index++;
		display_board(round, house_index, player_index);
		check_bust();
	}
	if(house_index == 2)
	{
		display_board(round, house_index, player_index); //if the house never hit beyond the initial deal, display both cards
	}	
	display_winner(); //display the winner of the match
	
	
	return 0;

}


//This function displays the Blackjack board as it stands
//INPUT: l_node for the current round, two ints for the number of cards in each hand
int Blackjack::display_board(l_node * round, int house_index, int player_index)
{
	round->print_house_hand(house_index);
	cout << "\nTotal: " << house_total << endl;
	round->print_player_hand(player_index);
	cout << "\nTotal: " << player_total << endl;

	return 0;

}


//This function displays the board after initial deal, with appropriate cards
//turned face down
int Blackjack::display_draw_board(l_node * round, int house_index, int player_index)
{
	round->print_house_face_down(house_index);
	cout << "\nTotal: ??" << endl;
	round->print_player_hand(player_index);
	cout << "\nTotal: " << player_total << endl;

	return 0;


}


//This function serves as a template for the Blackjack board format
int Blackjack::display_start_board()
{
	cout	<< "\n ---------------HOUSE CARDS---------------\n\n\n\n"
		<< " ---------------PLAYER CARDS--------------\n\n\n\n";
	return 0;

}


//This function checks both hands to see if either has a total over 21
int Blackjack::check_bust()
{
	if(house_total > 21 && player_total > 21)
	{
		cout 	<< "\n!!!!!!!Both HOUSE and PLAYER Bust!!!!!!!!!\n";
		player_total = 0;
		house_total = 0;
		return 0;
	}
	if(player_total > 21)
	{
		cout	<< "\n!!!!!!!!!!PLAYER BUSTS!!!!!!!!!!!\n";
		player_total = 0; //set the player total to 0 for program to check
	}
	if(house_total > 21)
	{
		cout	<< "\n!!!!!!!!!!HOUSE BUSTS!!!!!!!!!!!\n";
		house_total = 0; //set house total to 0 for program to check
	}
	return 0;
}


//This function displays the winner of the round based on information gathered from both hands
int Blackjack::display_winner()
{
	if(house_total == 0 && player_total == 0)
	{
		cout << "\n!!!!!!!!!!!IT'S A DRAW!!!!!!!!!!!\n";
		return 0;
	}
	else if(house_total >= player_total)
	{
		cout << "\n!!!!!!!!!HOUSE WINS!!!!!!!!!!\n";
	}
	else if(player_total > house_total)
	{
		cout << "\n!!!!!!!!!YOU WIN!!!!!!!!!!!\n";
	}
	return 0;

}
