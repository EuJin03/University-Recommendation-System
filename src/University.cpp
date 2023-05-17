#include <iostream>
#include "../include/University.h"

University::University()
{
	this->size = 0;
	this->univIndex = 0;
	this->head = nullptr;
	this->tail = nullptr;
	this->isSorted = false;
}

University::~University()
{
	// Clean up linked list
	UnivNode *current = head;
	while (current != nullptr)
	{
		UnivNode *temp = current;
		current = current->next;
		delete temp;
	}
}

void University::addUniversityAtStart(std::string rank, std::string institution, std::string locale, std::string location, std::string arCode, std::string arRank, std::string erScore, std::string erRank, std::string fsrScore, std::string fsrRank, std::string cpfScore, std::string cpfRank, std::string lfrScore, std::string lfrRank, std::string lsrScore, std::string lsrRank, std::string lrnScore, std::string lrnRank, std::string gerScore, std::string gerRank, std::string scoreScaled)
{
	UnivNode *newNode = new UnivNode;
	newNode->rank = rank;
	newNode->institution = institution;
	newNode->locale = locale;
	newNode->location = location;
	newNode->arCode = arCode;
	newNode->arRank = arRank;
	newNode->erScore = erScore;
	newNode->erRank = erRank;
	newNode->fsrScore = fsrScore;
	newNode->fsrRank = fsrRank;
	newNode->cpfScore = cpfScore;
	newNode->cpfRank = cpfRank;
	newNode->lfrScore = lfrScore;
	newNode->lfrRank = lfrRank;
	newNode->lsrScore = lsrScore;
	newNode->lsrRank = lsrRank;
	newNode->lrnScore = lrnScore;
	newNode->lrnRank = lrnRank;
	newNode->gerScore = gerScore;
	newNode->gerRank = gerRank;
	newNode->scoreScaled = scoreScaled;
	newNode->prev = nullptr;
	newNode->next = nullptr;

	if (head == nullptr)
	{
		head = newNode;
		tail = newNode;
	}
	else
	{
		newNode->next = head;
		head->prev = newNode;
		head = newNode;
	}

	size++;
}

void University::addUniversityAtEnd(std::string rank, std::string institution, std::string locale, std::string location, std::string arCode, std::string arRank, std::string erScore, std::string erRank, std::string fsrScore, std::string fsrRank, std::string cpfScore, std::string cpfRank, std::string lfrScore, std::string lfrRank, std::string lsrScore, std::string lsrRank, std::string lrnScore, std::string lrnRank, std::string gerScore, std::string gerRank, std::string scoreScaled)
{
	if (tail == nullptr)
	{
		addUniversityAtStart(rank, institution, locale, location, arCode, arRank, erScore, erRank, fsrScore, fsrRank, cpfScore, cpfRank, lfrScore, lfrRank, lsrScore, lsrRank, lrnScore, lrnRank, gerScore, gerRank, scoreScaled);
	}
	else
	{
		UnivNode *newNode = new UnivNode;
		newNode->rank = rank;
		newNode->institution = institution;
		newNode->locale = locale;
		newNode->location = location;
		newNode->arCode = arCode;
		newNode->arRank = arRank;
		newNode->erScore = erScore;
		newNode->erRank = erRank;
		newNode->fsrScore = fsrScore;
		newNode->fsrRank = fsrRank;
		newNode->cpfScore = cpfScore;
		newNode->cpfRank = cpfRank;
		newNode->lfrScore = lfrScore;
		newNode->lfrRank = lfrRank;
		newNode->lsrScore = lsrScore;
		newNode->lsrRank = lsrRank;
		newNode->lrnScore = lrnScore;
		newNode->lrnRank = lrnRank;
		newNode->gerScore = gerScore;
		newNode->gerRank = gerRank;
		newNode->scoreScaled = scoreScaled;
		newNode->prev = nullptr;
		newNode->next = nullptr;

		tail->next = newNode;
		newNode->prev = tail;
		tail = newNode;
		size++;
	}
}

int University::getSize() const
{
	return size;
}

void University::printUniversitiesInfo()
{
	UnivNode *curr = head;
	int index = 0;
	if (curr != nullptr)
	{
		while (index < 20)
		{
			std::cout << curr->rank << std::endl;
			std::cout << curr->institution << std::endl;
			curr = curr->next;
			index++;
		}
	}
	else
	{
		std::cout << "No universities to print." << std::endl;
	}
}