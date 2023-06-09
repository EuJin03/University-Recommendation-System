#include "../include/Seeder.h"

using namespace std::chrono;

void Seeder::createFeedbackInstances(LinkedList<Feedback> *feedbackList)
{
	std::string username1 = "eugene1";
	std::string feedback10 = "Testing Feedback";
	std::time_t createdAt1 = getRandomPastTime();
	std::string admin1 = "Admin 1";
	std::string reply1 = "Testing Reply";
	std::time_t repliedAt1 = getRandomPastTime();

	std::string username2 = "eugene2";
	std::string feedback20 = "Testing Feedback";
	std::time_t createdAt2 = getRandomPastTime();
	std::string admin2 = "Admin 2";
	std::string reply2 = "Testing Reply";
	std::time_t repliedAt2 = getRandomPastTime();

	std::string username3 = "eugene3";
	std::string feedback30 = "Testing Feedback";
	std::time_t createdAt3 = getRandomPastTime();
	std::string admin3 = "Admin 3";
	std::string reply3 = "Testing Reply";
	std::time_t repliedAt3 = getRandomPastTime();

	std::string username4 = "eugene4";
	std::string feedback40 = "Testing Feedback";
	std::time_t createdAt4 = getRandomPastTime();
	std::string admin4 = "Admin 4";
	std::string reply4 = "Testing Reply";
	std::time_t repliedAt4 = getRandomPastTime();

	Feedback feedback1(0, username1, feedback10, createdAt1, admin1, reply1, repliedAt1);
	Feedback feedback2(1, username2, feedback20, createdAt2, admin2, reply2, repliedAt2);
	Feedback feedback3(2, username3, feedback30, createdAt3, admin3, reply3, repliedAt3);
	Feedback feedback4(3, username4, feedback40, createdAt4, admin4, reply4, repliedAt4);
	feedbackList->pushAndPointEnd(feedback1);
	feedbackList->pushAndPointEnd(feedback2);
	feedbackList->pushAndPointEnd(feedback3);
	feedbackList->pushAndPointEnd(feedback4);
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
	std::string username1 = "admin";
	std::string password1 = "admin";
	std::time_t lastLogin1 = getRandomPastTime();
	bool isAdmin1 = true;
	User user1(username1, password1, lastLogin1, isAdmin1);

	std::string username2 = "eugene";
	std::string password2 = "user";
	std::time_t lastLogin2 = std::time(nullptr) - (60 * 60 * 24 * 31);
	bool isAdmin2 = false;
	LinkedList<University> eugeneList;
	User user2(username2, password2, lastLogin2, isAdmin2, eugeneList);

	std::string username3 = "bryan";
	std::string password3 = "bryan";
	std::time_t lastLogin3 = std::time(nullptr) - (60 * 60 * 24 * 29);
	bool isAdmin3 = false;
	LinkedList<University> bryanList;
	User user3(username3, password3, lastLogin3, isAdmin3, bryanList);

	std::string username4 = "pclai";
	std::string password4 = "pclai";
	std::time_t lastLogin4 = std::time(nullptr) - (60 * 60 * 24 * 30);
	bool isAdmin4 = false;
	LinkedList<University> pclaiList;
	User user4(username4, password4, lastLogin4, isAdmin4, pclaiList);

	// Add users to the customer
	customer->addUser(user1);
	customer->addUser(user2);
	customer->addUser(user3);
	customer->addUser(user4);

	User test2 = User();
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
	std::getline(file, line);
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
