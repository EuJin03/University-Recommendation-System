#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <filesystem>
#include <ctime>
#include <chrono>

#include "../include/University.h"
#include "../include/Customer.h"

using namespace std::filesystem;


using namespace std::chrono;

int main()
{
	std::cout << "Welcome to our university! " << std::endl;

	// ******************************************************
	// should move this into seeder class
	path currentPath = current_path();
	std::ifstream file(currentPath.string() + "\\resources\\assets\\2023_QS_World_University_Rankings.csv");

	University university;
	auto start_load = high_resolution_clock::now();
	if (file.is_open())
	{
		std::string line, entry;
		while (std::getline(file, line))
		{
			// breaking words by comma
			std::stringstream ss(line);
			std::string rank, institution, locale, location, arCode, arRank, erScore, erRank, fsrScore, fsrRank, cpfScore, cpfRank, lfrScore, lfrRank, lsrScore, lsrRank, lrnScore, lrnRank, gerScore, gerRank, scoreScaled;

			// Extract data from each column
			std::getline(ss, rank, ',');
			std::getline(ss, institution, ',');
			if (institution == "Institution")
				continue;
			std::getline(ss, locale, ',');
			std::getline(ss, location, ',');
			std::getline(ss, arCode, ',');
			std::getline(ss, arRank, ',');
			std::getline(ss, erScore, ',');
			std::getline(ss, erRank, ',');
			std::getline(ss, fsrScore, ',');
			std::getline(ss, fsrRank, ',');
			std::getline(ss, cpfScore, ',');
			std::getline(ss, cpfRank, ',');
			std::getline(ss, lfrScore, ',');
			std::getline(ss, lfrRank, ',');
			std::getline(ss, lsrScore, ',');
			std::getline(ss, lsrRank, ',');
			std::getline(ss, lrnScore, ',');
			std::getline(ss, lrnRank, ',');
			std::getline(ss, gerScore, ',');
			std::getline(ss, gerRank, ',');
			std::getline(ss, scoreScaled, ',');

			// Insert into linked list
			university.addUniversityAtEnd(rank, institution, locale, location, arCode, arRank, erScore, erRank, fsrScore, fsrRank, cpfScore, cpfRank, lfrScore, lfrRank, lsrScore, lsrRank, lrnScore, lrnRank, gerScore, gerRank, scoreScaled);
		}
	}
	else
	{
		std::cout << "File not found." << std::endl;
	}
	file.close();
	auto end_load = high_resolution_clock::now();

	std::cout << "Size of linked list: " << university.getSize() << std::endl;

	// university.printUniversitiesInfo();

	long long durationLoad = duration_cast<std::chrono::microseconds>(end_load - start_load).count();

	std::cout << "Time taken to load data: " << durationLoad << " microseconds" << std::endl;

	// ******************************************************

	// Feedback
	Feedback feedback;
	time_t now = time(0);
	feedback.insertAtEnd("user1", "This is a feedback", localtime(&now));
	feedback.replyFeedback(feedback.getTail(), "admin1", "This is a reply");

	time_t yesterday = now - (24 * 60 * 60);
	feedback.insertAtEnd("user2", "this is another feedback", localtime(&yesterday));
	feedback.printList();
	// ******************************************************
	// Testing for Customer Class

	Customer customer;
	customer.addCustomerAtEnd("user1", "password1", "user1@mail.com", "0123456789", "01/01/2001");
	customer.addCustomerAtEnd("user2", "password2", "user2@mail.com", "0123456789", "01/01/2001");
	customer.addCustomerAtEnd("user3", "password3", "user3@mail.com", "0123456789", "01/01/2001");
	customer.addCustomerAtEnd("user4", "password4", "user4@mail.com", "0123456789", "01/01/2001");
	customer.addCustomerAtEnd("user5", "password5", "user5@mail.com", "0123456789", "01/01/2001");
	customer.addCustomerAtEnd("user6", "password6", "user6@mail.com", "0123456789", "01/01/2001");

	// customer.printCustomersInfo();
	std::cout << std::endl;
	university.binarySearch(1234);
	return 0;
}

/**
 *  system("cls");
		time_t now = time(0);
		tm* current_time = localtime(&now);
 */