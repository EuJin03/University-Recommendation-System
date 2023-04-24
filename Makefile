CC=g++
CFLAGS=-I include
OBJ=src/Student.o src/University.o src/main.o

all: university_recommendation_system

university_recommendation_system: $(OBJ)
	$(CC) -o $@ $^

src/%.o: src/%.cpp
	$(CC) -c -o $@ $< $(CFLAGS)

clean:
	rm -f $(OBJ) university_recommendation_system