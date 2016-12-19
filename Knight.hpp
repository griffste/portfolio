/***************************************
 ** Program Filename: Knight.hpp
 ** Author: Stephen Griffin
 ** Description: The specification file for the Knight class,
                 which is derived from the Creature class
****************************************/


#ifndef KNIGHT_HPP
#define KNIGHT_HPP

#include "Creature.hpp"

class Knight : public Creature
{
	public:
     
	Knight();
      	int attack();
      	int defense();
      	void damage (Creature* c);
      	void restore();
      	void awardPoints (Creature* c);
};

#endif
