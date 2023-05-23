// #include <iostream>
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

University::University(const University &university)
{
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

University::~University() = default;

// Overriding the ostream operator
std::ostream &operator<<(std::ostream &os, const University &university)
{
	if (university.getRank() != 1)
	{
		os << "\n";
	}
	else
	{
		os << "\n";
	}
	os << std::left << std::setw(5) << std::to_string(university.getRank());
	os << std::left << std::setw(60) << university.getInstitution();
	os << std::left << std::setw(10) << university.getLocale();
	os << std::left << std::setw(15) << university.getLocation();
	os << std::left << std::setw(5) << university.getArScore();
	os << std::left << std::setw(5) << university.getArRank();
	os << std::left << std::setw(5) << university.getErScore();
	os << std::left << std::setw(5) << university.getErRank();
	os << std::left << std::setw(5) << university.getFsrScore();
	os << std::left << std::setw(5) << university.getFsrRank();
	os << std::left << std::setw(5) << university.getCpfScore();
	os << std::left << std::setw(5) << university.getCpfRank();
	os << std::left << std::setw(5) << university.getLfrScore();
	os << std::left << std::setw(5) << university.getLfrRank();
	os << std::left << std::setw(5) << university.getLsrScore();
	os << std::left << std::setw(5) << university.getLsrRank();
	os << std::left << std::setw(5) << university.getLrnScore();
	os << std::left << std::setw(5) << university.getLrnRank();
	os << std::left << std::setw(5) << university.getGerScore();
	os << std::left << std::setw(5) << university.getGerRank();
	os << std::left << std::setw(5) << university.getScoreScaled();
	return os;
}