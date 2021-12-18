CC = g++
CFLAGS = -Wall -std=c++17

INCLUDES		 	:= src/
DEPENDS			 	:= src/*.cpp
BIN_TESTER		:= bin/tester

all : $(DEPENDS) $(BIN_TESTER)
	test
	
test : $(DEPENDENCIES)
	$(CC) $(CFLAGS) -o $(BIN_TESTER) main.cpp $(DEPENDS) -I $(INCLUDES) 

run :
	./bin/tester
