#ifndef UNIVERSITY_H
#define UNIVERSITY_H

#include <iostream>
#include <string>

class University
{
private:
	int rank;
	std::string institution;
	std::string locale;
	std::string location;
	int arScore;
	int arRank;
	int erScore;
	int erRank;
	int fsrScore;
	int fsrRank;
	int cpfScore;
	int cpfRank;
	int lfrScore;
	int lfrRank;
	int lsrScore;
	int lsrRank;
	int lrnScore;
	int lrnRank;
	int gerScore;
	int gerRank;
	int scoreScaled;

public:
	// Constructor
	University(int rank, std::string institution, std::string locale, std::string location, int arScore, int arRank, int erScore, int erRank, int fsrScore, int fsrRank, int cpfScore, int cpfRank, int lfrScore, int lfrRank, int lsrScore, int lsrRank, int lrnScore, int lrnRank, int gerScore, int gerRank, int scoreScaled);
	University();
	// Copy Constructor
	University(const University &university);
	// Destructor
	~University();

	// Getters
	int getRank() const {return this->rank;}
	std::string getInstitution() const {return this->institution;}
	std::string getLocale() const {return this->locale;}
	std::string getLocation() const {return this->location;}
	int getArScore() const {return this->arScore;}
	int getArRank() const {return this->arRank;}
	int getErScore() const {return this->erScore;}
	int getErRank() const {return this->erRank;}
	int getFsrScore() const {return this->fsrScore;}
	int getFsrRank() const {return this->fsrRank;}
	int getCpfScore() const {return this->cpfScore;}
	int getCpfRank() const {return this->cpfRank;}
	int getLfrScore() const {return this->lfrScore;}
	int getLfrRank() const {return this->lfrRank;}
	int getLsrScore() const {return this->lsrScore;}
	int getLsrRank() const {return this->lsrRank;}
	int getLrnScore() const {return this->lrnScore;}
	int getLrnRank() const {return this->lrnRank;}
	int getGerScore() const {return this->gerScore;}
	int getGerRank() const {return this->gerRank;}
	int getScoreScaled() const {return this->scoreScaled;}

	// Setters
	void setRank(int rank) {this->rank = rank;}
	void setInstitution(std::string institution) {this->institution = institution;}
	void setLocale(std::string locale) {this->locale = locale;}
	void setLocation(std::string location) {this->location = location;}
	void setArScore(int arScore) {this->arScore	= arScore;}
	void setArRank(int arRank) {this->arRank = arRank;}
	void setErScore(int erScore) {this->erScore = erScore;}
	void setErRank(int erRank) {this->erRank = erRank;}
	void setFsrScore(int fsrScore) {this->fsrScore = fsrScore;}
	void setFsrRank(int fsrRank) {this->fsrRank	= fsrRank;}
	void setCpfScore(int cpfScore) {this->cpfScore = cpfScore;}
	void setCpfRank(int cpfRank) {this->cpfRank	= cpfRank;}
	void setLfrScore(int lfrScore) {this->lfrScore = lfrScore;}
	void setLfrRank(int lfrRank) {this->lfrRank = lfrRank;}
	void setLsrScore(int lsrScore) {this->lsrScore = lsrScore;}
	void setLsrRank(int lsrRank) {this->lsrRank = lsrRank;}
	void setLrnScore(int lrnScore) {this->lrnScore = lrnScore;}
	void setLrnRank(int lrnRank) {this->lrnRank	= lrnRank;}
	void setGerScore(int gerScore) {this->gerScore = gerScore;}
	void setGerRank(int gerRank) {this->gerRank	= gerRank;}
	void setScoreScaled(int scoreScaled) {this->scoreScaled = scoreScaled;}

	// search
	void binarySearch(int rank);
	UnivNode *getMiddle(UnivNode *start, UnivNode *last);

	int linearSearch();

private:
	UnivNode *head;
	UnivNode *tail;
	int size;
	bool isSorted;
	int univIndex;
};

// Override ostream operator
std::ostream &operator<<(std::ostream &os, const University &university);

#endif // UNIVERSITY_H