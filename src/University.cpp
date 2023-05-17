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

University::~University()
{
	// TODO: Ask Eugene how to write this Destructor
}