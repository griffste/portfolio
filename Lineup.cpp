/***************************************
 ** Program Filename: Lineup.cpp
 ** Author: Stephen Griffin
 ** Description: Lineup class implementation file
    NOTE: Lineup is linked list implemenation of FIFO
 ***************************************/

#include "Lineup.hpp"
#include <cstdlib>
#include <iostream>


/***************************************
 ** Function: Lineup()
 ** Description: Lineup class constructor initializes front and back to NULL
		 and sets Team Points to zero
 ***************************************/
Lineup::Lineup ()
{ 
	front = NULL;
	back = NULL;

	setTeamPoints(0);
}


/***************************************
 ** Function: add()
 ** Description: Adds new Creature to the back of the Lineup
 ***************************************/
void Lineup::add (Creature* c)
{
	if (front == NULL)
	{
		front = back = new LineupNode(c);
	}

	else
	{
		LineupNode *nodePtr = front;
		while(nodePtr->next != NULL)
		{
			nodePtr = nodePtr->next;
		}
		nodePtr->next = back = new LineupNode(c);
	}
}


/***************************************
 ** Function: remove()
 ** Description: Removes the Creature at the front of the Lineup
 ***************************************/
Creature* Lineup::remove()
{
	if (front == NULL)
	{
		std::cout << "Lineup is empty." <<std::endl; 
		return 0;
	}

	else
	{
		Creature* removed = front->creature;

		LineupNode* tempPtr;
		tempPtr = front;
		front = front->next;
		delete tempPtr;

		return removed;     
	}
}


/***************************************
 ** Function: displayLineup()
 ** Description: Displays the contents of the Lineup from front to back
 ***************************************/
void Lineup::displayLineup()
{
	if (front == NULL)
	{
		std::cout << "Lineup is empty." << std::endl;
	}

	else
	{
		LineupNode* nodePtr = front;

		while(nodePtr != NULL)
		{
			std::cout <<  nodePtr->creature->getType() << "  ";
			nodePtr = nodePtr->next;
		}
	}

	std::cout << std::endl;
} 

/**************************************
 ** Function: getFront()
 ** Description: Returns the Creature at the front of the Lineup
 ****************************************/
Creature* Lineup::getFront()
{
	if (front == NULL)
		return NULL;
	else 
		return front->creature;
}

/**************************************
 ** Function: getFrontNext()
 ** Description: Returns the second Creature in the lineup
 ****************************************/
Creature* Lineup::getFrontNext()
{
	if (front->next == NULL)
		return NULL;
	else 
		return front->next->creature;
}

/**************************************
 ** Function: getBack()
 ** Description: Returns the Creature at the back of the Lineup
 ****************************************/
Creature* Lineup::getBack()
{
	if (back == NULL)
		return NULL;
	else 
		return back->creature;
}


/***************************************
 ** Function: moveToBack()
 ** Description: Moves Creature at the front of the lineup to the back
 and restores their strength
 ****************************************/
void Lineup::moveToBack()
{
	Creature* tempPtr = remove(); 
	add(tempPtr);

	back->creature->restore(); 
}    


/***************************************
 ** Function: setTeamPoints()
 ** Description: Setter function for teamPoints member variable
 ****************************************/
void Lineup::setTeamPoints(int p)
{
	teamPoints = p;
}


/***************************************
 ** Function: getTeamPoints()
 ** Description: Getter function for teamPoints member variable
 ****************************************/
int Lineup::getTeamPoints()
{
	return teamPoints;
} 


/***************************************
 ** Function: ~Lineup()
 ** Description: Lineup class destructor frees dynamically allocated memory
 ** Parameters: N/A
 ** Pre-Conditions: N/A
 ** Post-Conditions: N/A
 ***************************************/
Lineup::~Lineup()
{
	LineupNode *nodePtr = front;

	while (nodePtr != NULL)
	{
		LineupNode* garbage = nodePtr;
		Creature* trash = nodePtr->creature;
		nodePtr = nodePtr->next;
		delete garbage;
		delete trash;
	}
}  

