CC=g++
CFLAGS=-I include
OBJ=bin/University.o bin/main.o bin/Feedback.o bin/HashTable.o bin/User.o bin/Seeder.o bin/UI.o bin/Algorithms.o bin/Controller.o

all: university_recommendation_system

university_recommendation_system: $(OBJ)
	$(CC) -o $@ $^

bin/%.o: src/%.cpp
	$(CC) -c -o $@ $< $(CFLAGS)

clean:
	rm -f $(OBJ) university_recommendation_system

# CC = g++
# CFLAGS = -I include
# SRC_DIR = src
# OBJ_DIR = bin
# SOURCES = $(wildcard $(SRC_DIR)/*.cpp)
# OBJECTS = $(patsubst $(SRC_DIR)/%.cpp, $(OBJ_DIR)/%.o, $(SOURCES))
# EXECUTABLE = university_recommendation_system

# all: $(EXECUTABLE)

# $(EXECUTABLE): $(OBJECTS)
# 	$(CC) -o $@ $^

# $(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
# 	$(CC) -c -o $@ $< $(CFLAGS)

# clean:
# 	rm -f $(OBJECTS) $(EXECUTABLE)