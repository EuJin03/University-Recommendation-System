#include "../include/Seeder.h"

using namespace std::chrono;

void Seeder::createFeedbackInstances()
{
	Feedback feedback(1, "Customer 1", "Testing Feedback 1", "Admin 1", "Testing Reply 1");
	LinkedList<Feedback> feedbackList;
	feedbackList.insertAtBeginning(feedback);
	feedbackList.show();
}

void Seeder::createUnivInstances()
{
	University university(1, "Test University", "Test Locale", "Test Location", 20, 5, 23, 5, 39, 2, 100, 3, 100, 4, 50, 4, 53, 5, 20, 133, 97);
	LinkedList<University> universityList;
	universityList.insertAtBeginning(university);
	universityList.show();
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

void Seeder::createUserInstances()
{
	std::string username1 = "john123";
	std::string password1 = "password1";
	std::time_t lastLogin1 = getRandomPastTime();
	User user1(username1, password1, lastLogin1);

	std::string username2 = "eugene";
	std::string password2 = "password2";
	std::time_t lastLogin2 = getRandomPastTime();
	User user2(username2, password2, lastLogin2);

	std::string username3 = "bryan";
	std::string password3 = "password3";
	std::time_t lastLogin3 = getRandomPastTime();
	User user3(username3, password3, lastLogin3);

	std::string username4 = "pclai";
	std::string password4 = "password4";
	std::time_t lastLogin4 = getRandomPastTime();
	User user4(username4, password4, lastLogin4);

	// Create a Customer instance
	HashTable customer(10);

	// Add users to the customer
	customer.addUser(user1);
	customer.addUser(user2);
	customer.addUser(user3);
	customer.addUser(user4);

	// Verify customer credentials
	bool verified = customer.verifyUser("john123", "password1");
	if (verified)
		std::cout << "User verified!\n";
	else
		std::cout << "Invalid credentials!\n";

	// Update last login time
	bool updated = customer.updateLastLogin("john1234");
	if (updated)
		std::cout << "Last login time updated!\n";
	else
		std::cout << "User not found!\n";

	// Delete inactive accounts
	bool accountsDeleted = customer.deleteInactiveAccounts();
	if (accountsDeleted)
		std::cout << "Inactive accounts deleted!\n";
	else
		std::cout << "No inactive accounts found!\n";

	// print all users
	customer.printAllUsersDetails();

	// validate if user already existed
	bool valid = customer.validateUsername("john123");
	if (valid)
		std::cout << "User already existed!\n";
	else
		std::cout << "User not found!\n";
}

void Seeder::createDynamicArrayInstance()
{
	auto start_load = high_resolution_clock::now();

	DynamicArray<University> dynamicArray;

	std::filesystem::path currentPath = std::filesystem::current_path();
	std::ifstream file(currentPath.string() + "\\resources\\assets\\2023_QS_World_University_Rankings.csv");

	if (file.is_open())
	{
		std::string line, entry;
		while (std::getline(file, line))
		{
			// skip file header
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

			// Clean and sanitize the institution, location, and locale fields
			std::string cleanInstitution = institution;
			cleanInstitution.erase(std::remove_if(cleanInstitution.begin(), cleanInstitution.end(), [](unsigned char c)
																						{ return !std::isalnum(c) && !std::isspace(c); }),
														 cleanInstitution.end());
			cleanInstitution = std::regex_replace(cleanInstitution, std::regex("^ +| +$"), ""); // Trim leading and trailing whitespaces

			std::string cleanLocation = location;
			cleanLocation.erase(std::remove_if(cleanLocation.begin(), cleanLocation.end(), [](unsigned char c)
																				 { return !std::isalnum(c) && !std::isspace(c); }),
													cleanLocation.end());
			cleanLocation = std::regex_replace(cleanLocation, std::regex("^ +| +$"), ""); // Trim leading and trailing whitespaces

			std::string cleanLocale = locale;
			cleanLocale.erase(std::remove_if(cleanLocale.begin(), cleanLocale.end(), [](unsigned char c)
																			 { return !std::isalnum(c) && !std::isspace(c); }),
												cleanLocale.end());
			cleanLocale = std::regex_replace(cleanLocale, std::regex("^ +| +$"), ""); // Trim leading and trailing whitespaces

			// Clean and sanitize specific fields using regex
			std::regex unwantedRegex("[^0-9]"); // Matches any character that is not a digit

			rank = std::regex_replace(rank, unwantedRegex, "");								// Remove unwanted characters
			arCode = std::regex_replace(arCode, unwantedRegex, "");						// Remove unwanted characters
			arRank = std::regex_replace(arRank, unwantedRegex, "");						// Remove unwanted characters
			erScore = std::regex_replace(erScore, unwantedRegex, "");					// Remove unwanted characters
			erRank = std::regex_replace(erRank, unwantedRegex, "");						// Remove unwanted characters
			fsrScore = std::regex_replace(fsrScore, unwantedRegex, "");				// Remove unwanted characters
			fsrRank = std::regex_replace(fsrRank, unwantedRegex, "");					// Remove unwanted characters
			cpfScore = std::regex_replace(cpfScore, unwantedRegex, "");				// Remove unwanted characters
			cpfRank = std::regex_replace(cpfRank, unwantedRegex, "");					// Remove unwanted characters
			lfrScore = std::regex_replace(lfrScore, unwantedRegex, "");				// Remove unwanted characters
			lfrRank = std::regex_replace(lfrRank, unwantedRegex, "");					// Remove unwanted characters
			lsrScore = std::regex_replace(lsrScore, unwantedRegex, "");				// Remove unwanted characters
			lsrRank = std::regex_replace(lsrRank, unwantedRegex, "");					// Remove unwanted characters
			lrnScore = std::regex_replace(lrnScore, unwantedRegex, "");				// Remove unwanted characters
			lrnRank = std::regex_replace(lrnRank, unwantedRegex, "");					// Remove unwanted characters
			gerScore = std::regex_replace(gerScore, unwantedRegex, "");				// Remove unwanted characters
			gerRank = std::regex_replace(gerRank, unwantedRegex, "");					// Remove unwanted characters
			scoreScaled = std::regex_replace(scoreScaled, unwantedRegex, ""); // Remove unwanted characters

			// Convert empty fields to "0"
			if (rank.empty())
				rank = "0";
			if (arCode.empty())
				arCode = "0";
			if (arRank.empty())
				arRank = "0";
			if (erScore.empty())
				erScore = "0";
			if (erRank.empty())
				erRank = "0";
			if (fsrScore.empty())
				fsrScore = "0";
			if (fsrRank.empty())
				fsrRank = "0";
			if (cpfScore.empty())
				cpfScore = "0";
			if (cpfRank.empty())
				cpfRank = "0";
			if (lfrScore.empty())
				lfrScore = "0";
			if (lfrRank.empty())
				lfrRank = "0";
			if (lsrScore.empty())
				lsrScore = "0";
			if (lsrRank.empty())
				lsrRank = "0";
			if (lrnScore.empty())
				lrnScore = "0";
			if (lrnRank.empty())
				lrnRank = "0";
			if (gerScore.empty())
				gerScore = "0";
			if (gerRank.empty())
				gerRank = "0";
			if (scoreScaled.empty())
				scoreScaled = "0";

			// Insert into array
			University university(std::stoi(rank), institution, locale, location, std::stoi(arCode), std::stoi(arRank), std::stoi(erScore), std::stoi(erRank), std::stoi(fsrScore), std::stoi(fsrRank), std::stoi(cpfScore), std::stoi(cpfRank), std::stoi(lfrScore), std::stoi(lfrRank), std::stoi(lsrScore), std::stoi(lsrRank), std::stoi(lrnScore), std::stoi(lrnRank), std::stoi(gerScore), std::stoi(gerRank), std::stoi(scoreScaled));
			dynamicArray.append(university);
		}
	}
	else
	{
		std::cout << "File not found." << std::endl;
	}
	file.close();
	auto end_load = high_resolution_clock::now();
	long long durationLoad = duration_cast<std::chrono::microseconds>(end_load - start_load).count();
	std::cout << "Time taken to load data: " << durationLoad << " microseconds" << std::endl;

	std::cout << "\n";

	std::cout << std::left << std::setw(5) << "Rank";
	std::cout << std::left << std::setw(75) << "Institution";
	std::cout << std::left << std::setw(20) << "Locale";
	std::cout << std::left << std::setw(20) << "Location";
	std::cout << std::left << std::setw(8) << "Ar Score";
	std::cout << std::left << std::setw(8) << "Ar Rank";
	std::cout << std::left << std::setw(8) << "Er Score";
	std::cout << std::left << std::setw(8) << "Er Rank";
	std::cout << std::left << std::setw(8) << "Fsr Score";
	std::cout << std::left << std::setw(8) << "Fsr Rank";
	std::cout << std::left << std::setw(8) << "Cpf Score";
	std::cout << std::left << std::setw(8) << "Cpf Rank";
	std::cout << std::left << std::setw(8) << "Lfr Score";
	std::cout << std::left << std::setw(8) << "Lfr Rank";
	std::cout << std::left << std::setw(8) << "Lsr Score";
	std::cout << std::left << std::setw(8) << "Lsr Rank";
	std::cout << std::left << std::setw(8) << "Lrn Score";
	std::cout << std::left << std::setw(8) << "Lrn Rank";
	std::cout << std::left << std::setw(8) << "Ger Score";
	std::cout << std::left << std::setw(8) << "Ger Rank";
	std::cout << std::left << std::setw(8) << "Score Scaled";
	std::cout << "\n";
	dynamicArray.show();
}