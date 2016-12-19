/***************************************
 ** Program Filename: Goblin.cpp
 ** Author: Stephen Griffin
 ** Description: The implementation file for the Goblin class  
 ****************************************/

#include "Goblin.hpp"

/**********************************
 ** Function: Goblin() 
 ** Description: The Goblin class constructor sets all its member 
 	         variables to the appropriate values.
**********************************/   
Goblin::Goblin() : Creature (3, 8, 2, 6, 1, 6, "Goblin")
{ }      


/*********************************
 ** Function: attack()
 ** Description: Returns an int value for the Creature's attack roll
                 based on the number and sides of their die.  
 *********************************/     
int Goblin::attack()
{
	int attack = 0;

	for (int roll = 0; roll < getAttack_dieNum(); roll++) 
	{
		attack += (rand() % getAttack_dieSides() + 1);
	}

	return attack;
}


/*********************************
 ** Function: defense()
 ** Description: Returns an int value for the Creature's defense roll
                 based on the number and sides of their die.
    *NOTE: cutAchilles does not effect other Goblins
 *********************************/ 
int Goblin::defense()
{
	int defense = 0;

	for (int roll = 0; roll < getDefense_dieNum(); roll++) 
	{
		defense += (rand() % getDefense_dieSides() + 1);
	}    

	return defense;
}   


/*********************************
 ** Function: damage()
 ** Description: Calls one Creature's attack() and another's defense()
                 and calculates the loss of strength points from the
                 target. 
    *NOTE: If Goblin rolls a 12 for its attack it will
	   cut the Achilles of its target.
 *********************************/     
void Goblin::damage (Creature* c)
{
	int damage = 0;
	damage = attack() - c->defense();

	//Cuts target's Achilles unless the Shadow uses its special defense     
	if (attack() == 12 && c->getType() != "Shadow" && c->defense() != 20)
	{
		c->setAchilles(true); 
	}

	int finalDamage = 0;
	finalDamage = damage - c->getArmor();
	if (finalDamage < 0)
	{finalDamage = 0;}   

	int newStrength;
	newStrength = c->getStrength() - finalDamage;
	if (newStrength < 0)
	{newStrength = 0;}

	c->setStrength(newStrength);    
}


/*********************************
 ** Function: restore()
 ** Description: Restores Creature's health to full capacity
 *********************************/
void Goblin::restore()
{
	setStrength(8);
}


/*********************************
 ** Function: awardPoints()
 ** Description: Awards points to winning Creature dependent on the
                 Creature they competed against
 ********************************/ 
void Goblin::awardPoints(Creature* c)
{
	if (c->getType() == "Dragon")
		setPoints(getPoints() + 8);
	else if (c->getType() == "Knight")
		setPoints(getPoints() + 6); 
	else if (c->getType() == "Shadow")
		setPoints(getPoints() + 4);
	else if (c->getType() == "Barbarian")
		setPoints(getPoints() + 2);
	else
		setPoints(getPoints() + 1);
}



