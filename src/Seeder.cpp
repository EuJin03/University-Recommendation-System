#include "../include/Seeder.h"

using namespace std::chrono;

void Seeder::createFeedbackInstances(LinkedList<Feedback> *feedbackList)
{
	int feedbackCount = 3; // Number of feedback instances to create

	for (int i = 1; i <= feedbackCount; i++)
	{
		std::string customerName = "Customer " + std::to_string(i);
		std::string feedbackText = "Testing Feedback " + std::to_string(i);
		std::string adminName = "Admin " + std::to_string(i);
		std::string replyText = "Testing Reply " + std::to_string(i);

		Feedback feedback(i, customerName, feedbackText, adminName, replyText);
		feedbackList->insertAtBeginning(feedback);
	}
}

std::time_t Seeder::getRandomPastTime()
{
	// Get the current time
	std::time_t currentTime = std::time(nullptr);

	// Generate a random number between 0 and 90 days in the past (in seconds)
	std::time_t randomOffset = std::rand() % (90 * 24 * 60 * 60);

	// Calculate the past time
	std::time_t pastTime = currentTime - randomOffset;

	return pastTime;
}

void Seeder::createUserInstances(HashTable *customer)
{
	std::string username1 = "john123";
	std::string password1 = "password1";
	std::time_t lastLogin1 = getRandomPastTime();
	bool isAdmin1 = false;
	User user1(username1, password1, lastLogin1, isAdmin1);
	user1.setAsAdmin();

	std::string username2 = "eugene";
	std::string password2 = "password2";
	std::time_t lastLogin2 = getRandomPastTime();
	bool isAdmin2 = false;
	User user2(username2, password2, lastLogin2, isAdmin2);

	std::string username3 = "bryan";
	std::string password3 = "password3";
	std::time_t lastLogin3 = getRandomPastTime();
	bool isAdmin3 = false;
	User user3(username3, password3, lastLogin3, isAdmin3);

	std::string username4 = "pclai";
	std::string password4 = "password4";
	std::time_t lastLogin4 = getRandomPastTime();
	bool isAdmin4 = false;
	User user4(username4, password4, lastLogin4, isAdmin4);

	// Add users to the customer
	customer->addUser(user1);
	customer->addUser(user2);
	customer->addUser(user3);
	customer->addUser(user4);

	bool valid = user1.getIsAdmin();
	if (valid)
	{
		std::cout << "User is admin" << std::endl;
	}
	else
	{
		std::cout << "User is not admin" << std::endl;
	}

	bool valid2 = user3.getIsAdmin();
	if (valid2)
	{
		std::cout << "User is admin" << std::endl;
	}
	else
	{
		std::cout << "User is not admin" << std::endl;
	}
}

void Seeder::createUnivInstances(University uniArr[])
{
	auto start_load = high_resolution_clock::now();

	std::filesystem::path currentPath = std::filesystem::current_path();
	std::ifstream file(currentPath.string() + "\\resources\\assets\\2023_QS_World_University_Rankings.csv");
	int index = 0;

	if (!file.is_open())
	{
		std::cout << "File not found." << std::endl;
		return;
	}

	std::string line;
	std::regex unwantedRegex("[^0-9]"); // Matches any character that is not a digit

	auto cleanString = [](std::string str)
	{
		str.erase(std::remove_if(str.begin(), str.end(), [](unsigned char c)
														 { return !std::isalnum(c) && !std::isspace(c); }),
							str.end());
		return std::regex_replace(str, std::regex("^ +| +$|( +)+"), " "); // Trim leading, trailing and multiple whitespaces
	};

	auto sanitizeField = [&](std::string &field)
	{
		field = std::regex_replace(field, unwantedRegex, ""); // Remove unwanted characters
		if (field.empty())
			field = "0";
	};

	auto trim = [](std::string &str, int maxLength = 10)
	{
		str = str.substr(0, maxLength);
		size_t first = str.find_first_not_of(' ');
		if (first == std::string::npos)
		{ // check if the string is all spaces
			str = "";
		}
		else
		{
			size_t last = str.find_last_not_of(' ');
			str = str.substr(first, (last - first + 1));
		}
	};

	while (std::getline(file, line))
	{
		std::stringstream ss(line);
		std::string rank, institution, locale, location, arCode, arRank, erScore, erRank, fsrScore, fsrRank, cpfScore, cpfRank, lfrScore, lfrRank, lsrScore, lsrRank, lrnScore, lrnRank, gerScore, gerRank, scoreScaled;

		std::getline(ss, rank, ',');
		trim(rank);
		std::getline(ss, institution, ',');
		trim(institution, 60);
		if (institution == "Institution")
			continue;

		std::getline(ss, locale, ',');
		trim(locale, 10);
		std::getline(ss, location, ',');
		trim(location, 15);
		std::getline(ss, arCode, ',');
		trim(arCode);
		std::getline(ss, arRank, ',');
		trim(arRank);
		std::getline(ss, erScore, ',');
		trim(erScore);
		std::getline(ss, erRank, ',');
		trim(erRank);
		std::getline(ss, fsrScore, ',');
		trim(fsrScore);
		std::getline(ss, fsrRank, ',');
		trim(fsrRank);
		std::getline(ss, cpfScore, ',');
		trim(cpfScore);
		std::getline(ss, cpfRank, ',');
		trim(cpfRank);
		std::getline(ss, lfrScore, ',');
		trim(lfrScore);
		std::getline(ss, lfrRank, ',');
		trim(lfrRank);
		std::getline(ss, lsrScore, ',');
		trim(lsrScore);
		std::getline(ss, lsrRank, ',');
		trim(lsrRank);
		std::getline(ss, lrnScore, ',');
		trim(lrnScore);
		std::getline(ss, lrnRank, ',');
		trim(lrnRank);
		std::getline(ss, gerScore, ',');
		trim(gerScore);
		std::getline(ss, gerRank, ',');
		trim(gerRank);
		std::getline(ss, scoreScaled, ',');
		trim(scoreScaled);

		institution = cleanString(institution);
		location = cleanString(location);
		locale = cleanString(locale);

		sanitizeField(rank);
		sanitizeField(arCode);
		sanitizeField(arRank);
		sanitizeField(erScore);
		sanitizeField(erRank);
		sanitizeField(fsrScore);
		sanitizeField(fsrRank);
		sanitizeField(cpfScore);
		sanitizeField(cpfRank);
		sanitizeField(lfrScore);
		sanitizeField(lfrRank);
		sanitizeField(lsrScore);
		sanitizeField(lsrRank);
		sanitizeField(lrnScore);
		sanitizeField(lrnRank);
		sanitizeField(gerScore);
		sanitizeField(gerRank);
		sanitizeField(scoreScaled);

		// Insert into array
		University university(std::stoi(rank), institution, locale, location, std::stoi(arCode), std::stoi(arRank), std::stoi(erScore), std::stoi(erRank), std::stoi(fsrScore), std::stoi(fsrRank), std::stoi(cpfScore), std::stoi(cpfRank), std::stoi(lfrScore), std::stoi(lfrRank), std::stoi(lsrScore), std::stoi(lsrRank), std::stoi(lrnScore), std::stoi(lrnRank), std::stoi(gerScore), std::stoi(gerRank), std::stoi(scoreScaled));
		uniArr[index] = university;
		index++;
	}

	file.close();

	std::cout << "\n";
}
