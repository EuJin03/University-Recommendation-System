#include <iostream>
#include "../include/University.h"

University::University(int rank, std::string institution, std::string locale, std::string location, int arScore, int arRank, int erScore, int erRank, int fsrScore, int fsrRank, int cpfScore, int cpfRank, int lfrScore, int lfrRank, int lsrScore, int lsrRank, int lrnScore, int lrnRank, int gerScore, int gerRank, int scoreScaled)
{
	this->rank = rank;
	this->institution = institution;
	this->locale = locale;
	this->location = location;
	this->arScore = arScore;
	this->arRank = arRank;
	this->erScore = erScore;
	this->erRank = erRank;
	this->fsrScore = fsrScore;
	this->fsrRank = fsrRank;
	this->cpfScore = cpfScore;
	this->cpfRank = cpfRank;
	this->lfrScore = lfrScore;
	this->lfrRank = lfrRank;
	this->lsrScore = lsrScore;
	this->lsrRank = lsrRank;
	this->lrnScore = lrnScore;
	this->lrnRank = lrnRank;
	this->gerScore = gerScore;
	this->gerRank = gerRank;
	this->scoreScaled = scoreScaled;
}

University::University(const University &university) {
	this->rank = university.rank;
	this->institution = university.institution;
	this->locale = university.locale;
	this->location = university.location;
	this->arScore = university.arScore;
	this->arRank = university.arRank;
	this->erScore = university.erScore;
	this->erRank = university.erRank;
	this->fsrScore = university.fsrScore;
	this->fsrRank = university.fsrRank;
	this->cpfScore = university.cpfScore;
	this->cpfRank = university.cpfRank;
	this->lfrScore = university.lfrScore;
	this->lfrRank = university.lfrRank;
	this->lsrScore = university.lsrScore;
	this->lsrRank = university.lsrRank;
	this->lrnScore = university.lrnScore;
	this->lrnRank = university.lrnRank;
	this->gerScore = university.gerScore;
	this->gerRank = university.gerRank;
	this->scoreScaled = university.scoreScaled;
}

University::~University()
{
	// TODO: Ask Eugene how to write this Destructor
}

void University::printUniversityInfo()
{
	std::cout << "Rank: " << this->rank << std::endl;
	std::cout << "Institution: " << this->institution << std::endl;
	std::cout << "Locale: " << this->locale << std::endl;
	std::cout << "Location: " << this->location << std::endl;
	std::cout << "Academic Reputation Score: " << this->arScore << std::endl;
	std::cout << "Academic Reputation Rank: " << this->arRank << std::endl;
	std::cout << "Employer Reputation Score: " << this->erScore << std::endl;
	std::cout << "Employer Reputation Rank: " << this->erRank << std::endl;
	std::cout << "Faculty Student Score: " << this->fsrScore << std::endl;
	std::cout << "Faculty Student Rank: " << this->fsrRank << std::endl;
	std::cout << "Citations Per Faculty Score: " << this->cpfScore << std::endl;
	std::cout << "Citations Per Faculty Rank: " << this->cpfRank << std::endl;
	std::cout << "International Faculty Score: " << this->lfrScore << std::endl;
	std::cout << "International Faculty Rank: " << this->lfrRank << std::endl;
	std::cout << "International Students Score: " << this->lsrScore << std::endl;
	std::cout << "International Students Rank: " << this->lsrRank << std::endl;
	std::cout << "International Research Score: " << this->lrnRank << std::endl;
	std::cout << "International Research Rank: " << this->lrnRank << std::endl;
	std::cout << "Employment Outcome Score: " << this->gerScore << std::endl; // "ger" stands for "Graduate Employment Rate
	std::cout << "Employment Outcome Rank: " << this->gerRank << std::endl;
	std::cout << "Overall score: " << this->scoreScaled << std::endl;
}
