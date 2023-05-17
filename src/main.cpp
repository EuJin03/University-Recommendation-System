#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <filesystem>
#include <ctime>
#include <chrono>

#include "../include/University.h"

using namespace std::chrono;

int main()
{
	std::cout << "Welcome to our university! " << std::endl;

	// ******************************************************
	// should move this into seeder class
	std::filesystem::path currentPath = std::filesystem::current_path();
	std::ifstream file(currentPath.string() + "\\resources\\assets\\2023_QS_World_University_Rankings.csv");

	University university;
	auto start_load = high_resolution_clock::now();
	if (file.is_open())
	{
		std::string line, entry;
		while (std::getline(file, line))
		{
			// skip file header
			if (line == "Rank,Institution,LocationCode,Location,ArScore,ArRank,ErScore,ErRank,FsrScore,FsrRank,CpfScore,CpfRank,IfrScore,IfrRank,IsrScore,IsrRank,IrnScore,IrnRank,GerScore,GerRank,ScoreScaled")
			{
				continue;
			}
			// breaking words by comma
			std::stringstream ss(line);
			std::string rank, institution, locale, location, arCode, arRank, erScore, erRank, fsrScore, fsrRank, cpfScore, cpfRank, lfrScore, lfrRank, lsrScore, lsrRank, lrnScore, lrnRank, gerScore, gerRank, scoreScaled;

			// Extract data from each column
			std::getline(ss, rank, ',');
			std::getline(ss, institution, ',');
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
			university.addUniversityAtStart(rank, institution, locale, location, arCode, arRank, erScore, erRank, fsrScore, fsrRank, cpfScore, cpfRank, lfrScore, lfrRank, lsrScore, lsrRank, lrnScore, lrnRank, gerScore, gerRank, scoreScaled);
		}
	}
	else
	{
		std::cout << "File not found." << std::endl;
	}
	file.close();
	auto end_load = high_resolution_clock::now();

	std::cout << "Size of linked list: " << university.getSize() << std::endl;

	university.printUniversitiesInfo();

	long long durationLoad = duration_cast<microseconds>(end_load - start_load).count();

	std::cout << "Time taken to load data: " << durationLoad << " microseconds" << std::endl;

	// ******************************************************

	return 0;
}

/**
 *  system("cls");
		time_t now = time(0);
		tm* current_time = localtime(&now);
 */