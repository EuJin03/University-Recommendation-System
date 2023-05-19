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
		tail = tail->next;
	}

	size++;
}

void FavUnivList::removeFavUniv(UnivNode *univ)
{
	FavUnivNode *curr = head;
	while (curr != nullptr)
	{
		if (curr->univ == univ)
		{
			if (curr == head)
			{
				head = head->next;
				head->prev = nullptr;
			}
			else if (curr == tail)
			{
				tail = tail->prev;
				tail->next = nullptr;
			}
			else
			{
				curr->prev->next = curr->next;
				curr->next->prev = curr->prev;
			}

			delete curr;
			size--;
			return;
		}
		curr = curr->next;
	}
}

void FavUnivList::printFavUnivLists()
{
	FavUnivNode *curr = head;
	while (curr != nullptr)
	{
		std::cout << curr->univ->institution << std::endl;
		curr = curr->next;
	}
}

int FavUnivList::getSize() const
{
	return size;
}

FavUnivNode *FavUnivList::getHead() const
{
	return head;
}

FavUnivNode *FavUnivList::getTail() const
{
	return tail;
}