/***************************************
 ** Program Filename: Lineup.hpp
 ** Author: Stephen Griffin
 ** Description: Lineup class specification file
***************************************/

#ifndef LINEUP_HPP
#define LINEUP_HPP

#include "Creature.hpp"

#include <cstdlib>


class Lineup
{
   private:
     
      	struct LineupNode
      	{
       	  	Creature* creature;
         	LineupNode* next;
         	LineupNode(Creature* c, LineupNode* n = NULL)
         	{
            		creature = c;
            		next = n;
         	}
        
      	};  

      	LineupNode* front;
     	LineupNode* back;
      
      	int teamPoints;


   public:

      	Lineup();
      	~Lineup();
     
      	Creature* getFront();
      	Creature* getBack();
      	Creature* getFrontNext();

      	void add (Creature* c);
     	Creature* remove();
      	void displayLineup();
      	void moveToBack();
      	void setTeamPoints (int);
      	int getTeamPoints();

};

#endif
