Tournament of Creatures
=======================

To Compile:

make

or 

g++ ...

Description:

The goal of the program is to exhibit a basic undestanding of
polymorphism and linked lists containing pointers to objects. The program simulates a 
dice-based roleplaying action game that involves members of five classes, all derived
from the base Creature class. The Creatures are placed in two linked list implementations of 
a FIFO queue (called a Linuep). The two Lineups (or teams) of Creatures will combat against one another,
in which the loser of the individual fights will be placed in a linked list implementation
of a LIFO stack (called Pile). The two teams will combat as part of an automated tournament,
which will continue until one team has lost all of their Creatures to the Pile. Points are
awarded to teams based on the Creature hierarchy, which as followed: 

Goblin > Barbarian > Shadow > Knight > Dragon

The program does the following: 
-Asks user how many and which Creatures should be assigned to each team
-Puts the Creature at the front of each team's Lineup in combat against one another
-The winner of the battle will move to the back of their team's Lineup, while the loser
 will be placed on top of the Loser's Pile.
-This pattern will continue until one of the two teams has no more Creatures
-Lastly, the points of each team and the winning team will be displayed 