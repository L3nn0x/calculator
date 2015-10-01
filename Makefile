EXE = a.out
CC = g++
CFLAGS = -g -Wall -Werror -std=c++11
INC = ./include
MAIN ?= src/main.cpp
SRCS = $(wildcard src/*.cpp)
SRC = $(filter-out src/main.cpp, $(SRCS))
SRC += $(MAIN)
OBJ = $(subst src, obj, $(SRC:.cpp=.o))
OBJ := $(subst tests, obj, $(OBJ))

all: $(EXE)

.PHONY: tests

tests:
	@sh tests/test.sh

$(EXE): $(OBJ)
	$(CC) $(CFLAGS) -I$(INC) $(OBJ) -o $(EXE)

obj/%.o: src/%.cpp
	$(CC) $(CFLAGS) -c -I$(INC) $< -o $@

obj/%.o: tests/%.cpp
	$(CC) $(CFLAGS) -c -I$(INC) $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(EXE)
