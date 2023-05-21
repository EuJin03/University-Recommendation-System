#ifndef SEEDER_H
#define SEEDER_H

#include "../include/User.h"
#include "../include/Customer.h"
#include "../include/Admin.h"
#include <cstdlib>
#include <ctime>
#include <iostream>

class Seeder
{
public:
	void createUserInstances();
	static std::time_t getRandomPastTime();
};

#endif // SEEDER_H