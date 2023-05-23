#ifndef SEEDER_H
#define SEEDER_H

#include "User.h"
#include "Customer.h"
#include "University.h"
#include "LinkedList.h"
#include "Feedback.h"
#include "DynamicArray.h"
#include <cstdlib>
#include <ctime>
#include <iostream>

class Seeder
{
public:
	void createFeedbackInstances();
	void createUnivInstances();
	void createUserInstances();
    void createDynamicArrayInstance();
	static std::time_t getRandomPastTime();
};

#endif // SEEDER_H