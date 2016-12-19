/***************************************
 ** Program Filename: Dragon.hpp
 ** Author: Stephen Griffin
 ** Description: The specification file for the Dragon class,
                 which is derived from the Creature class
****************************************/


#ifndef DRAGON_HPP
#define DRAGON_HPP

#include "Creature.hpp"

class Dragon : public Creature
{
	public:
     
	Dragon();
      	int attack();
      	int defense();
      	void damage (Creature* c);
      	void restore();
      	void awardPoints (Creature* c);
};

#endif
