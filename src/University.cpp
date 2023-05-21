// #include <iostream>
#include "../include/University.h"
#include "University.h"

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

University::University()
{
	this->rank = 0;
	this->institution = "";
	this->locale = "";
	this->location = "";
	this->arScore = 0;
	this->arRank = 0;
	this->erScore = 0;
	this->erRank = 0;
	this->fsrScore = 0;
	this->fsrRank = 0;
	this->cpfScore = 0;
	this->cpfRank = 0;
	this->lfrScore = 0;
	this->lfrRank = 0;
	this->lsrScore = 0;
	this->lsrRank = 0;
	this->lrnScore = 0;
	this->lrnRank = 0;
	this->gerScore = 0;
	this->gerRank = 0;
	this->scoreScaled = 0;
}

University::~University()
{
	// TODO: Ask Eugene how to write this Destructor
}

// Overriding the ostream operator
std::ostream &operator<<(std::ostream &os, const University &university)
{
	os << "University Rank: " << university.getRank() << std::endl;
	os << "University Name: " << university.getInstitution() << std::endl;
	os << "University Locale: " << university.getLocale() << std::endl;
	os << "University Location: " << university.getLocation() << std::endl;
	os << "Academic Reputation Score: " << university.getArScore() << std::endl;
	os << "Academic Reputation Rank: " << university.getArRank() << std::endl;
	os << "Employer Reputation Score: " << university.getErScore() << std::endl;
	os << "Employer Reputation Rank: " << university.getErRank() << std::endl;
	os << "Faculty Student Score: " << university.getFsrScore() << std::endl;
	os << "Faculty Student Rank: " << university.getFsrRank() << std::endl;
	os << "Citation Per Faculty Score: " << university.getCpfScore() << std::endl;
	os << "Citation Per Faculty Rank: " << university.getCpfRank() << std::endl;
	os << "International Faculty Score: " << university.getLfrScore() << std::endl;
	os << "International Faculty Rank: " << university.getLfrRank() << std::endl;
	os << "International Student Score: " << university.getLsrScore() << std::endl;
	os << "International Student Rank: " << university.getLsrRank() << std::endl;
	os << "International Research Score: " << university.getLrnScore() << std::endl;
	os << "International Research Rank: " << university.getLrnRank() << std::endl;
	os << "Graduate Employment Score: " << university.getGerScore() << std::endl;
	os << "Graduate Employment Rank: " << university.getGerRank() << std::endl;
	os << "Overall Score: " << university.getScoreScaled() << std::endl;
	return os;
}