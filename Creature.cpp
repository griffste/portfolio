/***************************************
 ** Program Filename: Creature.cpp
 ** Author: Stephen Griffin
 ** Description: Creature Class implementation file 
 ****************************************/

#include <iostream>
#include <ctime>
#include <cstdlib>
#include "Creature.hpp"


/***************************************
 ** Function: Creature()
 ** Description: Creature class construtor sets all member variables
	         as well as seeding the random number generator for the dice.
 ****************************************/
Creature::Creature(int a, int s, int adn, int ads, int ddn, int dds, std::string t)
{
	unsigned seed = time(0);
	srand(seed);

	setArmor (a);
	setStrength (s);
	setAttack_dieNum (adn);
	setAttack_dieSides (ads);
	setDefense_dieNum (ddn);
	setDefense_dieSides (dds);
	setType (t);

	setPoints(0);
	setAchilles (0);
}


/***************************************
 ** Function: setArmor()
 ** Description: Setter function for armor member variable 
 ***************************************/
void Creature::setArmor (int a)
{
	armor = a;
}


/***************************************
 ** Function: setStength()
 ** Description: Setter function for strength member variable 
 ***************************************/
void Creature::setStrength (int s)
{
	strength = s;
}


/***************************************
 ** Function: setAttack_dieNum()
 ** Description: Setter function for attack_dieNum member variable 
 ***************************************/
void Creature::setAttack_dieNum (int adn)
{
	attack_dieNum = adn;
}


/***************************************
 ** Function: setAttack_dieSides()
 ** Description: Setter function for attack_dieSides member variable 
 ***************************************/
void Creature::setAttack_dieSides (int ads)
{
	attack_dieSides = ads;
}


/***************************************
 ** Function: setDefense_dieNum()
 ** Description: Setter function for defense_dieNum member variable 
 ***************************************/
void Creature::setDefense_dieNum (int ddn)
{
	defense_dieNum = ddn;
}


/***************************************
 ** Function: setDefense_dieSides()
 ** Description: Setter function for defense_dieSides member variable 
 ***************************************/
void Creature::setDefense_dieSides (int dds)
{
	defense_dieSides = dds;
}


/***************************************
 ** Function: setType()
 ** Description: Setter function for type member variable 
 ***************************************/
void Creature::setType (std::string t)
{
	type = t;
}


/***************************************
 ** Function: setTeam()
 ** Description: Setter function for team member variable 
 ***************************************/
void Creature::setTeam (int t)
{
	team = t;
}


/***************************************
 ** Function: setAchilles()
 ** Description: Setter function for cutAchilles member variable 
 ***************************************/
void Creature::setAchilles(bool a)
{
	cutAchilles = a;
} 


/***************************************
 ** Function: setPoints()
 ** Description: Setter function for points member variable 
 ***************************************/
void Creature::setPoints(int p)
{
	points = p;
} 

/***************************************
 ** Function: getArmor()
 ** Description: Getter function for armor member variable 
 ***************************************/
int Creature::getArmor()
{
	return armor;
}


/***************************************
 ** Function: getStrength()
 ** Description: Getter function for strength member variable 
 ***************************************/
int Creature::getStrength()
{
	return strength;
}


/***************************************
 ** Function: getAttack_dieNum()
 ** Description: Getter function for attack_dieNum member variable 
 ***************************************/
int Creature::getAttack_dieNum()
{
	return attack_dieNum;
}


/***************************************
 ** Function: getAttack_dieSides()
 ** Description: Getter function for attack_dieSides member variable 
 ***************************************/
int Creature::getAttack_dieSides()
{
	return attack_dieSides;
}


/***************************************
 ** Function: getDefense_dieNum()
 ** Description: Getter function for defense_dieNum member variable 
 ***************************************/
int Creature::getDefense_dieNum()
{
	return defense_dieNum;
}


/***************************************
 ** Function: getDefense_dieSides()
 ** Description: Getter function for defense_dieSides member variable 
 ***************************************/
int Creature::getDefense_dieSides()
{
	return defense_dieSides;
}


/***************************************
 ** Function: getType()
 ** Description: Getter function for type member variable 
 ***************************************/
std::string Creature::getType()
{
	return type;
}


/***************************************
 ** Function: getTeam()
 ** Description: Getter function for team member variable 
 ***************************************/
int Creature::getTeam()
{
	return team;
}


/***************************************
 ** Function: getAchilles()
 ** Description: Getter function for cutAchilles member variable 
 ***************************************/
bool Creature::getAchilles()
{
	return cutAchilles;
}


/***************************************
 ** Function: getPoints()
 ** Description: Getter function for points member variable 
 ***************************************/
int Creature::getPoints()
{
	return points;
}
