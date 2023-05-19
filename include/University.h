#ifndef UNIVERSITY_H
#define UNIVERSITY_H

#include <iostream>
#include <string>

class University
{
public:
	// Constructor
	University(int rank, std::string institution, std::string locale, std::string location, int arScore, int arRank, int erScore, int erRank, int fsrScore, int fsrRank, int cpfScore, int cpfRank, int lfrScore, int lfrRank, int lsrScore, int lsrRank, int lrnScore, int lrnRank, int gerScore, int gerRank, int scoreScaled);
	// Copy Constructor
	University(const University &university);
	// Destructor
	~University();

	// Getters
	int getRank() {return this->rank;};
	std::string getInstitution() {return this->institution;};
	std::string getLocale() {return this->locale;};
	std::string getLocation() {return this->location;};
	int getArScore() {return this->arScore;};
	int getArRank() {return this->arRank;};
	int getErScore() {return this->erScore;};
	int getErRank() {return this->erRank;};
	int getFsrScore() {return this->fsrScore;};
	int getFsrRank() {return this->fsrRank;};
	int getCpfScore() {return this->cpfScore;};
	int getCpfRank() {return this->cpfRank;};
	int getLfrScore() {return this->lfrScore;};
	int getLfrRank() {return this->lfrRank;};
	int getLsrScore() {return this->lsrScore;};
	int getLsrRank() {return this->lsrRank;};
	int getLrnScore() {return this->lrnScore;};
	int getLrnRank() {return this->lrnRank;};
	int getGerScore() {return this->gerScore;};
	int getGerRank() {return this->gerRank;};
	int getScoreScaled() {return this->scoreScaled;};
	
	// Setters
	void setRank(int rank) {this->rank = rank;};
	void setInstitution(std::string institution) {this->institution = institution;};
	void setLocale(std::string locale) {this->locale = locale;};
	void setLocation(std::string location) {this->location = location;};
	void setArScore(int arScore) {this->arScore	= arScore;};
	void setArRank(int arRank) {this->arRank = arRank;};
	void setErScore(int erScore) {this->erScore = erScore;};
	void setErRank(int erRank) {this->erRank = erRank;};
	void setFsrScore(int fsrScore) {this->fsrScore = fsrScore;};
	void setFsrRank(int fsrRank) {this->fsrRank	= fsrRank;};
	void setCpfScore(int cpfScore) {this->cpfScore = cpfScore;};
	void setCpfRank(int cpfRank) {this->cpfRank	= cpfRank;};
	void setLfrScore(int lfrScore) {this->lfrScore = lfrScore;};
	void setLfrRank(int lfrRank) {this->lfrRank = lfrRank;};
	void setLsrScore(int lsrScore) {this->lsrScore = lsrScore;};
	void setLsrRank(int lsrRank) {this->lsrRank = lsrRank;};
	void setLrnScore(int lrnScore) {this->lrnScore = lrnScore;};
	void setLrnRank(int lrnRank) {this->lrnRank	= lrnRank;};
	void setGerScore(int gerScore) {this->gerScore = gerScore;};
	void setGerRank(int gerRank) {this->gerRank	= gerRank;};
	void setScoreScaled(int scoreScaled) {this->scoreScaled = scoreScaled;};

	void printUniversityInfo();

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
};
#endif // UNIVERSITY_H