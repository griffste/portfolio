/***************************************
 ** Program Filename: Shadow.cpp
 ** Author: Stephen Griffin
 ** Description: The implementation file for the Shadow class  
 ****************************************/

#include "Shadow.hpp"


/**********************************
 ** Function: Shadow() 
 ** Description: The Shadow class constructor sets all its member 
		 variables to the appropriate values.
 **********************************/   
Shadow::Shadow() : Creature (0, 12, 2, 10, 1, 6, "Shadow")
{ }      


/*********************************
 ** Function: attack()
 ** Description: Returns an int value for the Creature's attack roll
	         based on the number and sides of their die. If 
	         the member variable cutAchilles is true the roll is
	         divided in half. 
 *********************************/     
int Shadow::attack()
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
    *NOTE: Fifty percent of the time the Shadow will not take any 
           damage due to its special condition. 
 *********************************/     
int Shadow::defense()
{
	int defense = 0;

	if(rand() % 2 + 1 == 1)
	{
		for (int roll = 0; roll < getDefense_dieNum(); roll++) 
		{
			defense += (rand() % getDefense_dieSides() + 1);
		}
	}

	else
	{
		defense = 20; //Highest possible attack from any other creature
			      ///Therefore, represents "missed attack"
	}

	return defense;
}   


/*********************************
 ** Function: damage()
 ** Description: Calls one Creature's attack() and another's defense()
                 and calculates the loss of strength points from the target.
 *********************************/     
void Shadow::damage (Creature* c)
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
void Shadow::restore()
{
	setStrength(12);
}


/*********************************
 ** Function: awardPoints()
 ** Description: Awards points to winning Creature dependent on the
                 Creature they competed against
 ********************************/ 
void Shadow::awardPoints(Creature* c)
{
	if (c->getType() == "Dragon")
		setPoints(getPoints() + 4);
	else if (c->getType() == "Knight")
		setPoints(getPoints() + 2); 
	else
		setPoints(getPoints() + 1);
}
