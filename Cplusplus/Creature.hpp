/***************************************
 ** Program Filename: Creature.hpp
 ** Author: Stephen Griffin
 ** Description: Creature Class specification file 
 ****************************************/

#ifndef CREATURE_HPP
#define CREATURE_HPP

#include <string>

class Creature
{
	protected:

		int armor;
		int strength;
		int attack_dieNum;
		int attack_dieSides;
		int defense_dieNum;
		int defense_dieSides;
		std::string type;
		std::string name;
		bool cutAchilles;
		int team; 
		int points;

	public:

		Creature(int a, int s, int adn, int ads, int ddn, int dds, std::string t);
		virtual ~Creature() {};

		void setArmor (int a);
		void setStrength (int s);
		void setAttack_dieNum (int adn);
		void setAttack_dieSides (int ads);
		void setDefense_dieNum (int ddn);
		void setDefense_dieSides (int dds);
		void setType (std::string);
		void setName (std::string);
		void setTeam (int);
		void setAchilles (bool); 
		void setPoints (int); 


		int getArmor();
		int getStrength();
		int getAttack_dieNum();
		int getAttack_dieSides();
		int getDefense_dieNum(); 
		int getDefense_dieSides();
		std::string getType();
		std::string getName();
		int getTeam(); 
		bool getAchilles();
		int getPoints();

		virtual int attack() = 0;
		virtual int defense() = 0;
		virtual void damage (Creature* c) = 0;
		virtual void restore() = 0;
		virtual void  awardPoints (Creature* c) = 0;
};

#endif 

