/***************************************
 ** Program Filename: Shadow.hpp
 ** Author: Stephen Griffin
 ** Description: The specification file for the Shadow class,
                 which is derived from the Creature class
****************************************/


#ifndef SHADOW_HPP
#define SHADOW_HPP

#include "Creature.hpp"

class Shadow : public Creature
{
	public:
     
	Shadow();
      	int attack();
      	int defense();
      	void damage (Creature* c);
      	void restore();
      	void awardPoints (Creature* c);
};

#endif
