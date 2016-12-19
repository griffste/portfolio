/***************************************
 ** Program Filename: Pile.hpp
 ** Author: Stephen Griffin
 ** Description: Pile class specification file
***************************************/

#ifndef PILE_HPP
#define PILE_HPP

#include <cstdlib>
#include "Creature.hpp"

class Pile
{
   private:
     
      	struct PileNode
      	{
       	  	Creature* creature;
       		PileNode* next;
         	PileNode(Creature* c, PileNode* n = NULL)
         	{
            		creature = c;
            		next = n;
         	}
      	};  

      	PileNode* top;

   public:

      	Pile();
      	~Pile();

      	Creature* getTop();

      	void add (Creature* c);
      	void displayPile();
};

#endif
