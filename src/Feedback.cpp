#include "../include/Feedback.h"
#include "Feedback.h"

Feedback::Feedback(int feedbackID, std::string username, std::string feedback, std::string admin, std::string replyContent)
{
	this->feedbackID = feedbackID;
	this->username = username;
	this->feedback = feedback;
	this->admin = admin;
	this->replyContent = replyContent;
};

Feedback::Feedback(const Feedback &feedback)
{
	this->feedbackID = feedback.feedbackID;
	this->username = feedback.username;
	this->feedback = feedback.feedback;
	this->admin = feedback.admin;
	this->replyContent = feedback.replyContent;
}

Feedback::Feedback()
{
	this->feedbackID = 0;
	this->username = "";
	this->feedback = "";
	this->admin = "";
	this->replyContent = "";
}

void Feedback::printFeedback()
{
	std::cout << "Feedback ID: " << this->feedbackID << std::endl;
	std::cout << "Username: " << this->username << std::endl;
	std::cout << "Feedback: " << this->feedback << std::endl;
	std::cout << "Admin: " << this->admin << std::endl;
	std::cout << "Reply content: " << this->replyContent << std::endl;
}

// Override ostream operator
std::ostream &operator<<(std::ostream &os, const Feedback &feedback)
{
	os << "Feedback ID: " << feedback.getFeedbackID() << std::endl;
	os << "Username: " << feedback.getUsername() << std::endl;
	os << "Feedback: " << feedback.getFeedback() << std::endl;
	os << "Admin: " << feedback.getAdmin() << std::endl;
	os << "Reply content: " << feedback.getReplyContent() << std::endl;
	return os;
}