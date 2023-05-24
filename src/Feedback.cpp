#include "../include/Feedback.h"

Feedback::Feedback(std::string username, std::string feedback, std::string admin, std::string replyContent)
{
	this->feedbackID++;
	this->username = username;
	this->feedback = feedback;
	this->admin = admin;
	this->replyContent = replyContent;
}

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
	this->feedbackID++;
	this->username = "";
	this->feedback = "";
	this->admin = "";
	this->replyContent = "";
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