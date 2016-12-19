##########################################
## Author: Stephen Griffin
## Date: November 22, 2015
## Description: Makefile for Assignment 4
##########################################
 
CXX = g++
CXXFLAGS = -std=c++0x
CXXFLAGS += -Wall
CXXFLAGS += -pedantic-errors
CXXFLAGS += -g

OBJS = 

SRCS = Creature.cpp Pile.cpp Lineup.cpp Goblin.cpp Barbarian.cpp Shadow.cpp Knight.cpp Dragon.cpp tournament.cpp  

HEADERS = Creature.hpp Goblin.hpp Barbarian.hpp Shadow.hpp Knight.hpp Dragon.hpp Pile.hpp Lineup.hpp

DOCS = README.txt

PROGS = tournament 

all: ${HEADERS} ${SRCS} 
	${CXX} ${CXXFLAGS} ${SRCS} -o ${PROGS} 

clean:
	rm -f ${PROGS} *.o *.out 

