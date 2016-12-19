/***************************************
 ** Program Filename: Pile.cpp
 ** Author: Stephen Griffin
 ** Description: Pile class implementation file
    NOTE: Pile is a linked list implementation of LIFO
 ***************************************/


#include "Pile.hpp"
#include <cstdlib>
#include <iostream>


/***************************************
 ** Function: Pile()
 ** Description: Pile class constructor initializes top to NULL
 ***************************************/
Pile::Pile ()
{
	top = NULL;
}


/***************************************
 ** Function: add()
 ** Description: Adds the most recent loser to the top of the Pile 
 ***************************************/
void Pile::add (Creature* c)
{
	PileNode* tempPtr;
	tempPtr = top; 
	top = new PileNode(c);
	top->next = tempPtr;
}


/**************************************
 ** Function: getTop()
 ** Description: Returns the Creature at the top of the Pile
 ****************************************/
Creature* Pile::getTop()
{
	if (top == NULL)
		return NULL;
	else 
		return top->creature;
}



/***************************************
 ** Function: displayPile()
 ** Description: Dispalys the contents of the Pile 
 ***************************************/
void Pile::displayPile()
{
	PileNode* nodePtr = top;

	while(nodePtr != NULL)
	{
		std::cout << nodePtr->creature->getType() 
			<< " - Team " << nodePtr->creature->getTeam() << std::endl;
		nodePtr = nodePtr->next;
	}

	std::cout << std::endl;
} 


/***************************************
 ** Function: ~Pile()
 ** Description: Pile class destructor frees dynamically allocated memory
 ***************************************/
Pile::~Pile()
{
	PileNode *nodePtr = top;

	while (nodePtr != NULL)
	{
		PileNode* garbage = nodePtr;
		Creature* trash = nodePtr->creature;
		nodePtr = nodePtr->next;
		delete garbage;
		delete trash;
	}
}  
