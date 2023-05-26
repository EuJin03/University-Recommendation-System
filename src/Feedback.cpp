#include "../include/Feedback.h"

Feedback::Feedback(int feedbackID, std::string username, std::string feedback, std::time_t createdAt, std::string admin, std::string replyContent, std::time_t repliedAt)
{
	this->feedbackID = feedbackID;
	this->username = username;
	this->feedback = feedback;
	this->createdAt = createdAt;
	this->admin = admin;
	this->replyContent = replyContent;
	this->repliedAt = repliedAt;
}

Feedback::Feedback(int feedbackID, std::string username, std::string feedback, std::time_t createdAt)
{
	this->feedbackID = feedbackID;
	this->username = username;
	this->feedback = feedback;
	this->createdAt = createdAt;
	this->admin = "";
	this->replyContent = "";
	this->repliedAt = -1;
}

// Feedback::Feedback(const Feedback &feedback)
// {
// 	this->feedbackID = feedback.feedbackID;
// 	this->username = feedback.username;
// 	this->feedback = feedback.feedback;
// 	this->createdAt = feedback.createdAt;
// 	this->admin = feedback.admin;
// 	this->replyContent = feedback.replyContent;
// 	this->repliedAt = feedback.repliedAt;
// }

Feedback::Feedback()
{
	this->feedbackID = 0;
	this->username = "";
	this->feedback = "";
	this->createdAt = -1;
	this->admin = "";
	this->replyContent = "";
	this->repliedAt = -1;
}

// Override ostream operator
std::ostream &operator<<(std::ostream &os, const Feedback &feedback)
{
	std::time_t createdAt = feedback.getCreatedAt();
	std::tm *createdStruct = std::localtime(&createdAt);
	char CAbuffer[80];
	std::strftime(CAbuffer, sizeof(CAbuffer), "%Y-%m-%d %H:%M:%S", createdStruct);

	std::time_t repliedAt = feedback.getRepliedAt();
	std::tm *repliedStruct = std::localtime(&repliedAt);
	char RAbuffer[80];
	std::strftime(RAbuffer, sizeof(RAbuffer), "%Y-%m-%d %H:%M:%S", repliedStruct);
	os << "\nFeedback ID: " << feedback.getFeedbackID() << std::endl;
	os << "Username: " << feedback.getUsername() << std::endl;
	os << "Feedback: " << feedback.getFeedback() << std::endl;
	os << "Created At: " << CAbuffer << std::endl;
	os << "Admin: " << feedback.getAdmin() << std::endl;
	os << "Reply content: " << feedback.getReplyContent() << std::endl;
	os << "Replied At: " << RAbuffer << std::endl;
	return os;
}