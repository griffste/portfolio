Tournament of Creatures
=======================

To Compile:

make

or 

g++ -std=c++0x -Wall -pedantic-errors -g Creature.cpp Pile.cpp Lineup.cpp Goblin.cpp Barbarian.cpp Shadow.cpp Knight.cpp Dragon.cpp tournament.cpp -o tournament


Description:

The goal of the program is to exhibit a basic undestanding of
polymorphism and linked lists containing pointers to objects.

The program has five derived classes from the base Creature class, which
will battle against each other in an automated dice-based action game. The
game takes place in the form of a tournament, in which the user will select 
two teams of Creatures. These Creatures will then be placed in linked list
implementations of a FIFO queue represented by the Lineup class. The front
Creature of the two Lineups will combat in a simulated fight, where the winner
will return to the back of their Lineup, and the loser will be placed at the top
of a linked list implementation of a LIFO stack represented by the Pile class.
The tournament will continue until one team has no more Creatures left in their Lineup.
During the tournament points are awarded to each team based on the Creature hierachy, which
is as follows:

Goblin > Barbarian > Shadow > Knight > Dragon

Teams will be awarded points equal to two times the difference in class. For example, if a Shadow
defeats a Knight or a Dragon, they will receive two or four points respectively. If a Creature 
defeats an equal or lesser Creature, they will simply receive one point.

The structure of the program is as follows: 
-Asks user how many and which Creatures should be assigned to each team
-The two teams are displayed to the user
-The two Creature at the front of each team's Lineup combat against one another
-The winner of the battle will move to the back of their team's Lineup, while the loser
 will be placed on top of the Loser's Pile.
-This pattern will continue until one of the two teams has no more Creatures
-Lastly, the points of each team and the winning team will be displayed 