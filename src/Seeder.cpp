#include "../include/Seeder.h"

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

	// Generate a random number between 0 and 30 days in the past (in seconds)
	std::time_t randomOffset = std::rand() % (30 * 24 * 60 * 60);

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

	std::string username2 = "alice456";
	std::string password2 = "password2";
	std::time_t lastLogin2 = getRandomPastTime();
	User user2(username2, password2, lastLogin2);

	std::string username3 = "bob789";
	std::string password3 = "password3";
	std::time_t lastLogin3 = getRandomPastTime();
	User user3(username3, password3, lastLogin3);

	std::string username4 = "emma123";
	std::string password4 = "password4";
	std::time_t lastLogin4 = getRandomPastTime();
	User user4(username4, password4, lastLogin4);

	// Create a Customer instance
	Customer customer(10);

	// Add users to the customer
	customer.addCustomer(user1);
	customer.addCustomer(user2);
	customer.addCustomer(user3);
	customer.addCustomer(user4);

	// Verify customer credentials
	bool verified = customer.verifyCustomer("john123", "password1");
	if (verified)
		std::cout << "User verified!\n";
	else
		std::cout << "Invalid credentials!\n";

	// Update last login time
	bool updated = customer.updateLastLogin("john123");
	if (updated)
		std::cout << "Last login time updated!\n";
	else
		std::cout << "User not found!\n";

	// Print customer details
	customer.printCustomerDetails("john123");

	// Remove a customer
	customer.removeCustomer("bob789");

	// Delete inactive accounts
	bool accountsDeleted = customer.deleteInactiveAccounts();
	if (accountsDeleted)
		std::cout << "Inactive accounts deleted!\n";
	else
		std::cout << "No inactive accounts found!\n";
}