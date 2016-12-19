/***************************************
 ** Program Filename: Barbarian.cpp
 ** Author: Stephen Griffin
 ** Description: The implementation file for the Barbarian class  
 ****************************************/

#include "Barbarian.hpp"

/**********************************
 ** Function: Barbarian() 
 ** Description: The Barbarian class constructor sets all its member 
                 variables to the appropriate values.
 **********************************/   
Barbarian::Barbarian() : Creature (0, 12, 2, 6, 2, 6, "Barbarian")
{ } 


/*********************************
 ** Function: attack()
 ** Description: Returns an int value for the Creature's attack roll
		 based on the number and sides of their die. If 
		 the member variable cutAchilles is true the roll is
		 divided in half. 
 *********************************/     
int Barbarian::attack()
{
	int attack = 0;

	for (int roll = 0; roll < getAttack_dieNum(); roll++) 
	{
		attack += (rand() % getAttack_dieSides() + 1);
	}
	
	if(cutAchilles)
		attack /= 2;

	return attack;
}


/*********************************
 ** Function: defense()
 ** Description: Returns an int value for the Creature's defense roll
                 based on the number and sides of their die.
 *********************************/ 
int Barbarian::defense()
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
                 and calculates the loss of strength points from the target.
 *********************************/     
void Barbarian::damage (Creature* c)
{
	int damage = 0;
	damage = attack() - c->defense();

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
void Barbarian::restore()
{
	setStrength(12);
}


/*********************************
 ** Function: awardPoints()
 ** Description: Awards points to winning Creature dependent on the
 		 Creature they competed against
 ********************************/ 
void Barbarian::awardPoints(Creature* c)
{
	if (c->getType() == "Dragon")
		setPoints(getPoints() + 6);
	else if (c->getType() == "Knight")
		setPoints(getPoints() + 4); 
	else if (c->getType() == "Shadow")
		setPoints(getPoints() + 2);
	else
		setPoints(getPoints() + 1);
}
