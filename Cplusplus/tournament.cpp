/***************************************
 ** Program Filename: tournament.hpp
 ** Author: Stephen Griffin
 ** Description: Program allows user to create two teams of Creatures which will then
		 combat against each other until one team's Creatures have all been
		 defeated. User will select number of fighers per each team, and the types of
 		 each Creature on the two teams. The winner of each individual fight will be
		 displayed, followed by which team is declared the winner. 
 ****************************************/

#include "Creature.hpp"
#include "Barbarian.hpp"
#include "Knight.hpp"
#include "Dragon.hpp"
#include "Goblin.hpp"
#include "Shadow.hpp"
#include "Pile.hpp"
#include "Lineup.hpp"

#include <iostream>

//Function prototypes
void addTeamMember (int choice, Lineup* team);
void combat (Creature* c1, Creature* c2, int fn);

int main()
{
	Pile losers;
	Lineup team1, team2;

	//Prompt user for number of fighters on each team
	int numFighters;
	std::cout << "How many fighters are in each team?" << std::endl; 
	std::cin >> numFighters;

	//Input validation
	while (numFighters < 1)
	{
		std::cout << "There must be at least one fighter per team." 
			<< " Please enter a positive number." << std::endl;
		std::cin >> numFighters;
	}

	std::cout << std::endl;

	//Add Creatures for Team 1
	std::cout << "***Add " << numFighters << " fighters to Team 1***" << std::endl; 

	for (int count = 1; count <= numFighters; count++)
	{
		int choice;    

		std::cout << "Choose type of Creature for Fighter " << count << ":" <<std::endl;
		std::cout << "Press (1) to add a Goblin\n"
			"      (2) to add a Barbarian\n"
			"      (3) to add a Shadow\n"
			"      (4) to add a Knight\n"
			"      (5) to add a Dragon" << std::endl;   
		std::cin >> choice;
		
		//Input validation
		while (choice < 1 || choice > 5)
		{
			std::cout << "Invalid choice." 
				<< " Please enter a number 1-5." << std::endl;
			std::cin >> choice;
		}

		//Adds selected Creature to team
		addTeamMember(choice, &team1);
		team1.getBack()->setTeam(1);
		std::cout << std::endl;
	}

	//Add Creatures for Team 2 
	std::cout << "***Add " << numFighters << " fighters to Team 2**" << std::endl; 
	for (int count = 1; count <= numFighters; count++)
	{
		int choice;    

		std::cout << "Choose type of Creature for Fighter " << count << ":" <<std::endl;
		std::cout << "Press (1) to add a Goblin\n"
			"      (2) to add a Barbarian\n"
			"      (3) to add a Shadow\n"
			"      (4) to add a Knight\n"
			"      (5) to add a Dragon" << std::endl;   
		std::cin >> choice;
		
		//Input validation
		while (choice < 1 || choice > 5)
		{
			std::cout << "Invalid choice." 
				<< " Please enter a number 1-5." << std::endl;
			std::cin >> choice;
		}

		//Adds selected Creature to team
		addTeamMember(choice, &team2);
		team2.getBack()->setTeam(2);
		std::cout << std::endl;
	}


	//Display the Lineups of the two teams before the tournament begins
	std::cout << "The teams are as follows: " << std::endl;
	std::cout << "Team 1: ";
	team1.displayLineup();
	std::cout << "Team 2: "; 
	team2.displayLineup();
	std::cout << "Let the tournament begin...\n" << std::endl;


	/* 
	 * Combat function is called until one team is out of Creatures.
	 * Based on the winner and loser of each individual fight the proper points
	 * will be assigned to individual Creatures and to teams. 
	 * Then the winner will be moved to the back of their Lineup and the loser
	 * to the top of the Loser Pile.
	 */

	int fightNumber = 1;  //Counter for individual fights

	//Continue until one team is out of Creatures
	while (team1.getFront() != NULL && team2.getFront() != NULL)
	{
		combat (team1.getFront(), team2.getFront(), fightNumber);

		//If Team 1 fighter wins
		if (team2.getFront()->getStrength() == 0)
		{ 
			//Add points to fighter and team
			int tempPts1 = team1.getFront()->getPoints();
			team1.getFront()->awardPoints(team2.getFront());
			team1.setTeamPoints(team1.getTeamPoints() + 
					team1.getFront()->getPoints() - tempPts1);

			//Add loser of fight to Pile
			losers.add(team2.getFront());
			team2.remove(); 

			//Move winner to back of their Lineup
			if (team1.getFrontNext() != NULL)
			{
				team1.moveToBack();
			}
		}

		//If Team 2 fighter wins
		else
		{ 
			//Add points to fighter and team
			int tempPts2 = team2.getFront()->getPoints();
			team2.getFront()->awardPoints(team1.getFront());
			team2.setTeamPoints(team2.getTeamPoints() +
					team2.getFront()->getPoints() - tempPts2);

			//Add loser of fight to Pile
			losers.add(team1.getFront());
			team1.remove(); 

			//Move winner to back of their lineup
			if (team2.getFrontNext() != NULL)
				team2.moveToBack();
		}
		//Increase counter
		fightNumber++;
	}

	//Display the points for both teams as well as the winning team
	std::cout << std::endl;    
	std::cout << "Team 1 Points: " << team1.getTeamPoints() << std::endl;  
	std::cout << "Team 2 Points: " << team2.getTeamPoints() << std::endl;  

	if (team1.getTeamPoints() > team2.getTeamPoints())
		std::cout << "Team 1 wins the tournament!" << std::endl;
	else if (team2.getTeamPoints() > team1.getTeamPoints())
		std::cout << "Team 2 wins the tournament!" << std::endl; 
	else
		std::cout << "Team 1 and Team 2 draw" << std::endl;
	std:: cout << std::endl; 


	return 0;
}



/**************************************
 ** Function: addTeamMember()
 ** Description: Adds appropriate Creature to passed in team 
 to each team
 ***************************************/
void addTeamMember(int choice, Lineup* team)
{
	switch(choice) {
		case 1: 
			team->add(new Goblin);
			break;
		case 2: 
			team->add(new Barbarian);
			break;
		case 3: 
			team->add(new Shadow);
			break;
		case 4: 
			team->add(new Knight);
			break;
		case 5:
			team->add(new Dragon);
	}
}

/**************************************
 ** Function: combat()
 ** Description: This function accepts two Creatures and has them take alternating
 turns between attacking the other until one Creature's strength
 points reach zero.
 ****************************************/  
void combat (Creature* c1, Creature* c2, int fn)
{
	//Two creatures take turns attacking one another
	//Until one fighter's strength reaches zero 
	while (c1->getStrength() > 0 && c2->getStrength() > 0)
	{
		c1->damage(c2);
		c2->damage(c1);
	}

	//Display winner and loser of fight
	if (c2->getStrength() == 0)
	{
		std::cout << c1->getType() << "(Team " << c1->getTeam() << ")" 
		<< " defeated " << c2->getType() << "(Team " << c2->getTeam() << ") in Fight #" 
		<< fn << std::endl;
	}

	else
	{
		std::cout << c2->getType() << "(Team " << c2->getTeam() << ")" 
		<< " defeated " << c1->getType() << "(Team " << c1->getTeam() << ") in Fight #" 
		<< fn << std::endl;
	}
}


