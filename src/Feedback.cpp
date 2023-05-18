#include "../include/Feedback.h"

Feedback::Feedback(int feedbackID, std::string username, std::string feedback, std::string admin, std::string replyContent)
{
	this->feedbackID = feedbackID;
	this->username = username;
	this->feedback = feedback;
	this->admin = admin;
	this->replyContent = replyContent;
}

void Feedback::printFeedback()
{
	std::cout << "Feedback ID: " << feedbackID << std::endl;
	std::cout << "Username: " << username << std::endl;
	std::cout << "Feedback: " << feedback << std::endl;
	std::cout << "Admin: " << admin << std::endl;
	std::cout << "Reply content: " << replyContent << std::endl;
}