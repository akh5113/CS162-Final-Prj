#################################################################################
## Program Name: makefile
## Author: Anne Harris
## Date: 6/5/2017
## Description: a file that uses the source, header and object files to compile 
## then cleans the executable file
################################################################################

CXX = g++

OBJS = FinalPrjMain.o menu.o game.o space.o steerage.o hallway.o storage.o captains.o deck.o

SRCS = Project4Main.cpp menu.cpp game.cpp space.cpp steerage.cpp hallway.cpp storage.cpp captains.cpp deck.cpp

HEADERS = menu.hpp game.hpp space.hpp steerage.hpp hallway.hpp storage.hpp captains.hpp deck.hpp

FinalPrj: ${OBJS}
	${CXX} ${OBJS} -o FinalPrj

%.o : %.c
	${CXX} -c -o $@ $^

.PHONY: clean

clean:
	rm FinalPrj ${OBJS}
