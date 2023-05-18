#include <iostream>
#include <string>

#include "../include/FavUniList.h"

FavUnivList::FavUnivList()
{
	head = nullptr;
	tail = nullptr;
	size = 0;
	isSorted = false;
}

FavUnivList::~FavUnivList()
{
	FavUnivNode *curr = head;
	while (curr != nullptr)
	{
		FavUnivNode *temp = curr;
		curr = curr->next;
		delete temp;
	}
}

void FavUnivList::addFavUnivAtEnd(UnivNode *univ, std::string customerName)
{
	FavUnivNode *newNode = new FavUnivNode;
	newNode->univ = univ;
	newNode->customerName = customerName;
	newNode->next = nullptr;

	if (head == nullptr)
	{
		head = newNode;
		tail = newNode;
	}
	else
	{
		tail->next = newNode;
		newNode->prev = tail;
		tail = newNode;
	}

	size++;
}
