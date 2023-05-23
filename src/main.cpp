#include "../include/Seeder.h"
#include "../include/DynamicArray.h"

using namespace std::chrono;

int main()
{
	std::cout << "Welcome to our university! " << std::endl;

	// ******************************************************
	// should move this into seeder class

	auto start_load = high_resolution_clock::now();
	auto end_load = high_resolution_clock::now();
	long long durationLoad = duration_cast<std::chrono::microseconds>(end_load - start_load).count();
	std::cout << "Time taken to load data: " << durationLoad << " microseconds" << std::endl;

	// ******************************************************
	Seeder seeder;
	// seeder.createFeedbackInstances();
	// seeder.createUnivInstances();
	// seeder.createUserInstances();

	// std::cout << "======== TEST DYNAMIC ARRAY ========" << std::endl;
	seeder.createDynamicArrayInstance();

	return 0;
}

/**
 *  system("cls");
		time_t now = time(0);
		tm* current_time = localtime(&now);
 */