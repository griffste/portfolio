/***************************************
 ** Program Filename: Goblin.hpp
 ** Author: Stephen Griffin
 ** Description: The specification file for the Goblin class,
                 which is derived from the Creature class
****************************************/


#ifndef GOBLIN_HPP
#define GOBLIN_HPP

#include "Creature.hpp"

class Goblin : public Creature
{
	public:
     
	Goblin();
      	int attack();
      	int defense();
      	void damage (Creature* c);
      	void restore();
      	void awardPoints (Creature* c);
};

#endif
