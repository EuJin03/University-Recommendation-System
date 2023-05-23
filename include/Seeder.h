#ifndef SEEDER_H
#define SEEDER_H

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <ctime>
#include <chrono>
#include <filesystem>
#include <regex>
#include <algorithm>
#include <cctype>

#include "User.h"
#include "HashTable.h"
#include "University.h"
#include "LinkedList.h"
#include "Feedback.h"
#include "DynamicArray.h"

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