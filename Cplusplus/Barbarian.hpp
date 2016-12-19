/***************************************
 ** Program Filename: Barbarian.hpp
 ** Author: Stephen Griffin
 ** Description: The specification file for the Barbarian class,
                 which is derived from the Creature class
 ****************************************/


#ifndef BARBARIAN_HPP
#define BARBARIAN_HPP

#include "Creature.hpp"

class Barbarian : public Creature
{
	public:
     
	Barbarian();
      	int attack();
      	int defense();
      	void damage (Creature* c);
      	void restore();
      	void awardPoints (Creature* c);
};

#endif
