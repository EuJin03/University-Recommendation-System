#include <iostream>
#include <unordered_map>
#include <string>
#include <vector>

struct University
{
	std::unordered_map<std::string, std::string> attributes;

	University(const std::string rank, const std::string &institution, const std::string &location, const std::string arScore, const std::string erScore, const std::string fsrScore, const std::string cpfScore, const std::string ifrScore, const std::string isrScore, const std::string irnScore, const std::string gerScore)
	{
		attributes["rank"] = rank;
		attributes["institution"] = institution;
		attributes["location"] = location;
		attributes["arScore"] = arScore;
		attributes["erScore"] = erScore;
		attributes["fsrScore"] = fsrScore;
		attributes["cpfScore"] = cpfScore;
		attributes["ifrScore"] = ifrScore;
		attributes["isrScore"] = isrScore;
		attributes["irnScore"] = irnScore;
		attributes["gerScore"] = gerScore;
	}
};

// class UniversityList
// {
// private:
// 	int tableSize;
// 	std::vector<std::vector<University *>> hashTable;

// 	int Hash(int rank)
// 	{
// 		return rank % tableSize;
// 	}

// public:
// 	UniversityList(int size) : tableSize(size)
// 	{
// 		hashTable.resize(tableSize);
// 	}

// 	void AddUniversity(int rank, std::string institution, std::string location, int arScore, int erScore, int fsrScore, int cpfScore, int ifrScore, int isrScore, int irnScore, int gerScore)
// 	{
// 		int index = Hash(rank);
// 		University *newUniversity = new University(rank, institution, location, arScore, erScore, fsrScore, cpfScore, ifrScore, isrScore, irnScore, gerScore);

// 		hashTable[index].push_back(newUniversity);
// 	}

// 	University *FindUniversityByRank(int rank)
// 	{
// 		int index = Hash(rank);

// 		for (University *university : hashTable[index])
// 		{
// 		}

// 		return nullptr; // University not found
// 	}

// 	void UpdateUniversityAttributes(int rank, const std::unordered_map<std::string, int> &newAttributes)
// 	{
// 		University *university = FindUniversityByRank(rank);
// 		if (university != nullptr)
// 		{
// 			university->attributes = newAttributes;
// 		}
// 		else
// 		{
// 			std::cout << "University not found." << std::endl;
// 		}
// 	}

// 	void DeleteUniversity(int rank)
// 	{
// 		int index = Hash(rank);

// 		for (auto it = hashTable[index].begin(); it != hashTable[index].end(); ++it)
// 		{
// 		}

// 		std::cout << "University not found." << std::endl;
// 	}
// };

// #include "../include/University.h"
// #include <iostream>

// // Constructor
// University::University(int rank, std::string institution, std::string location, int arScore, int erScore, int fsrScore, int cpfScore, int ifrScore, int isrScore, int irnScore, int gerScore)
// {
// 	this->rank = rank;
// 	this->institution = institution;
// 	this->location = location;
// 	this->arScore = arScore;
// 	this->erScore = erScore;
// 	this->fsrScore = fsrScore;
// 	this->cpfScore = cpfScore;
// 	this->ifrScore = ifrScore;
// 	this->isrScore = isrScore;
// 	this->irnScore = irnScore;
// 	this->gerScore = gerScore;
// 	this->head = nullptr; // Initialize head of linked list
// }

// // Copy constructor
// University::University(const University &other)
// {
// 	this->rank = other.rank;
// 	this->institution = other.institution;
// 	this->location = other.location;
// 	this->arScore = other.arScore;
// 	this->erScore = other.erScore;
// 	this->fsrScore = other.fsrScore;
// 	this->cpfScore = other.cpfScore;
// 	this->ifrScore = other.ifrScore;
// 	this->isrScore = other.isrScore;
// 	this->irnScore = other.irnScore;
// 	this->gerScore = other.gerScore;
// 	this->head = nullptr; // Initialize head of linked list (will be populated separately)
// }

// // Destructor
// University::~University()
// {
// 	// Clean up linked list
// 	Node *current = head;
// 	while (current != nullptr)
// 	{
// 		Node *temp = current;
// 		current = current->next;
// 		delete temp;
// 	}
// }

// // Getters
// int University::getRank() const
// {
// 	return rank;
// }

// std::string University::getInstitution() const
// {
// 	return institution;
// }

// std::string University::getLocation() const
// {
// 	return location;
// }

// int University::getArScore() const
// {
// 	return arScore;
// }

// int University::getErScore() const
// {
// 	return erScore;
// }

// int University::getFsrScore() const
// {
// 	return fsrScore;
// }

// int University::getCpfScore() const
// {
// 	return cpfScore;
// }

// int University::getIfrScore() const
// {
// 	return ifrScore;
// }

// int University::getIsrScore() const
// {
// 	return isrScore;
// }

// int University::getIrnScore() const
// {
// 	return irnScore;
// }

// int University::getGerScore() const
// {
// 	return gerScore;
// }

// // Setters
// void University::setRank(int rank)
// {
// 	this->rank = rank;
// }

// void University::setInstitution(const std::string &institution)
// {
// 	this->institution = institution;
// }

// void University::setLocation(const std::string &location)
// {
// 	this->location = location;
// }

// void University::setArScore(int arScore)
// {
// 	this->arScore = arScore;
// }

// void University::setErScore(int erScore)
// {
// 	this->erScore = erScore;
// }

// void University::setFsrScore(int fsrScore)
// {
// 	this->fsrScore = fsrScore;
// }

// void University::setCpfScore(int cpfScore)
// {
// 	this->cpfScore = cpfScore;
// }

// void University::setIfrScore(int ifrScore)
// {
// 	this->ifrScore = ifrScore;
// }

// void University::setIsrScore(int isrScore)
// {
// 	this->isrScore = isrScore;
// }

// void University::setIrnScore(int irnScore)
// {
// 	this->irnScore = irnScore;
// }

// void University::setGerScore(int gerScore)
// {
// 	this->gerScore = gerScore;
// }

// // Linked List Operations
// void University::addToLinkedList(const std::string &data)
// {
// 	Node *newNode = new Node;
// 	newNode->data = data;
// 	newNode->next = nullptr;

// 	if (head == nullptr)
// 	{
// 		head = newNode;
// 	}
// 	else
// 	{
// 		Node *current = head;
// 		while (current->next != nullptr)
// 		{
// 			current = current->next;
// 		}
// 		current->next = newNode;
// 	}
// }
