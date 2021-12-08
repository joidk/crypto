CC = g++
CFLAGS = -Wall -std=c++17

INCLUDES		 	:= src/
DEPENDS			 	:= src/Crypto.cpp
BIN_TESTER		:= bin/tester

all : $(DEPENDS) $(BIN_TESTER)
	
test : $(DEPENDENCIES)
	$(CC) $(CFLAGS) -o $(BIN_TESTER) tester.cpp $(DEPENDS) -I $(INCLUDES) 

run :
	./bin/tester
