#ifndef UNIVERSITY_H
#define UNIVERSITY_H

#include <iostream>
#include <string>

struct UnivNode
{
	std::string rank;
	std::string institution;
	std::string locale;
	std::string location;
	std::string arCode;
	std::string arRank;
	std::string erScore;
	std::string erRank;
	std::string fsrScore;
	std::string fsrRank;
	std::string cpfScore;
	std::string cpfRank;
	std::string lfrScore;
	std::string lfrRank;
	std::string lsrScore;
	std::string lsrRank;
	std::string lrnScore;
	std::string lrnRank;
	std::string gerScore;
	std::string gerRank;
	std::string scoreScaled;

	UnivNode *prev;
	UnivNode *next;
};

class University
{
public:
	University();
	~University();
	void addUniversityAtStart(std::string rank, std::string institution, std::string locale, std::string location, std::string arCode, std::string arRank, std::string erScore, std::string erRank, std::string fsrScore, std::string fsrRank, std::string cpfScore, std::string cpfRank, std::string lfrScore, std::string lfrRank, std::string lsrScore, std::string lsrRank, std::string lrnScore, std::string lrnRank, std::string gerScore, std::string gerRank, std::string scoreScaled);
	void addUniversityAtEnd(std::string rank, std::string institution, std::string locale, std::string location, std::string arCode, std::string arRank, std::string erScore, std::string erRank, std::string fsrScore, std::string fsrRank, std::string cpfScore, std::string cpfRank, std::string lfrScore, std::string lfrRank, std::string lsrScore, std::string lsrRank, std::string lrnScore, std::string lrnRank, std::string gerScore, std::string gerRank, std::string scoreScaled);
	int getSize() const;

	// Printings
	void printUniversitiesInfo();

	// TODO: all functions should display 20 units at a time, could use index to keep track on next 20 units.
	// sort
	void sortUniversitiesByRank();
	void sortUniversitiesByInstitution();

	// search
	int binarySearch();
	int linearSearch();

private:
	UnivNode *head;
	UnivNode *tail;
	int size;
	bool isSorted;
	int univIndex;
};
#endif // UNIVERSITY_H