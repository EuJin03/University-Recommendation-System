#ifndef FAVUNILIST_H
#define FAVUNILIST_H

#include <iostream>
#include <string>

#include "./University.h"

struct FavUnivNode
{
	UnivNode *univ;
	std::string customerName;

	FavUnivNode *prev;
	FavUnivNode *next;
};

class FavUnivList
{
public:
	FavUnivList();
	~FavUnivList();
	void addFavUnivAtEnd(UnivNode *univ, std::string customerName);
	void removeFavUniv(UnivNode *univ);
	void printFavUnivLists();
	int getSize() const;
	FavUnivNode *getHead() const;
	FavUnivNode *getTail() const;

	// Printings
	void printFavUnivsInfo();

private:
	FavUnivNode *head;
	FavUnivNode *tail;
	int size;
	bool isSorted;
};

#endif // FAVUNILIST_H