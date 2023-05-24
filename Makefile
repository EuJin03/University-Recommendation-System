CC=g++
CFLAGS=-I include
OBJ=bin/University.o bin/main.o bin/Feedback.o bin/HashTable.o bin/User.o bin/Seeder.o bin/UI.o bin/Algorithms.o

all: university_recommendation_system

university_recommendation_system: $(OBJ)
	$(CC) -o $@ $^

bin/%.o: src/%.cpp
	$(CC) -c -o $@ $< $(CFLAGS)

clean:
	rm -f $(OBJ) university_recommendation_system