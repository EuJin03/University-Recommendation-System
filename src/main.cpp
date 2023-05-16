#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

#include "../include/University.h"

int main()
{
	// define a student

	// display the results to the user
	std::cout << "Welcome to our university! " << std::endl;
	// output any other information about the university or its components

	// should move this into seeder class
	std::ifstream file("C://Users/eugen/Home/Desktop/Degree(CYB)/Sem 2/Data Structure/university_recommendation_system/resources/assets/2023_QS_World_University_Rankings.csv");

	University university;

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

	std::cout << "Size of linked list: " << university.getSize() << std::endl;
	university.printUniversitiesInfo();

	return 0;
}