#ifndef FEEDBACK_H
#define FEEDBACK_H

#include <iostream>
#include <string>

class Feedback
{
private:
	int feedbackID;
	std::string username;
	std::string feedback;
	tm *createdAt;
	std::string admin;
	std::string replyContent;
	tm *repliedAt;

public:
	// Constructor
	Feedback(int feedbackID, std::string username, std::string feedback, std::string admin, std::string replyContent);
	// Copy constructor
	Feedback(const Feedback &feedback);
	void printFeedback();
	// FeedbackNode *navigateTo(FeedbackNode *current, char code);
	// void replyFeedback(FeedbackNode *current, std::string admin, std::string replyContent);
};

#endif