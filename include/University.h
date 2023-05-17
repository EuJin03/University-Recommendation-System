#ifndef UNIVERSITY_H
#define UNIVERSITY_H

#include <iostream>
#include <string>

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
	int rank;
	std::string institution;
	std::string locale;
	std::string location;
	std::string arCode;
	int arRank;
	int erScore;
	std::string erRank;
	int fsrScore;
	std::string fsrRank;
	int cpfScore;
	std::string cpfRank;
	int lfrScore;
	std::string lfrRank;
	int lsrScore;
	std::string lsrRank;
	int lrnScore;
	std::string lrnRank;
	int gerScore;
	std::string gerRank;
	int scoreScaled;
};
#endif // UNIVERSITY_H