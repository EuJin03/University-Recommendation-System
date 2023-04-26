#ifndef UNIVERSITY_H
#define UNIVERSITY_H

#include <string>
#include <vector>
#include "Student.h" // assume Department class is defined in Department.h

class University
{
public:
	// constructor
	University(int rank, std::string institution, std::string location, int arScore, int erScore, int fsrScore, int cpfScore, int ifrScore, int isrScore, int irnScore, int gerScore) {
		this->rank = rank;
		this->institution = institution;
		this->location = location;
		this->arScore = arScore;
		this->erScore = erScore;
		this->fsrScore = fsrScore;
		this->cpfScore = cpfScore;
		this->ifrScore = ifrScore;
		this->isrScore = isrScore;
		this->irnScore = irnScore;
		this->gerScore = gerScore;
	};

	// copy constructor
	University(const University &other) {
		this->rank = other.rank;
		this->institution = other.institution;
		this->location = other.location;
		this->arScore = other.arScore;
		this->erScore = other.erScore;
		this->fsrScore = other.fsrScore;
		this->cpfScore = other.cpfScore;
		this->ifrScore = other.ifrScore;
		this->isrScore = other.isrScore;
		this->irnScore = other.irnScore;
		this->gerScore = other.gerScore;
	};

	// destructor
	~University() {};

	// getters
	int getRank() const { return rank; };
	std::string getInstitution() const { return institution; };
	std::string getLocation() const { return location; };
	int getArScore() const { return arScore; };
	int getErScore() const { return erScore; };
	int getFsrScore() const { return fsrScore; };
	int getCpfScore() const { return cpfScore; };
	int getIfrScore() const { return ifrScore; };
	int getIsrScore() const { return isrScore; };
	int getIrnScore() const { return irnScore; };

	// setters
	void setRank(int rank) { this->rank = rank; };
	void setInstitution(std::string institution) { this->institution = institution; };
	void setLocation(std::string location) { this->location = location; };
	void setArScore(int arScore) { this->arScore = arScore; };
	void setErScore(int erScore) { this->erScore = erScore; };
	void setFsrScore(int fsrScore) { this->fsrScore = fsrScore; };
	void setCpfScore(int cpfScore) { this->cpfScore = cpfScore; };
	void setIfrScore(int ifrScore) { this->ifrScore = ifrScore; };
	void setIsrScore(int isrScore) { this->isrScore = isrScore; };
	void setIrnScore(int irnScore) { this->irnScore = irnScore; };
	void setGerScore(int gerScore) { this->gerScore = gerScore; };

private:
	int rank;
	std::string institution;
	std::string location;
	int arScore;	// Academic Reputation
	int erScore;	// Employer Reputation
	int fsrScore;	// Faculty/Student ratio
	int cpfScore;	// Citations per faculty ratio
	int ifrScore;	// Interation Faculty score
	int isrScore;	// International Students ratio
	int irnScore;	// International Research Network
	int gerScore;	// Employment outcome
};

#endif // UNIVERSITY_H