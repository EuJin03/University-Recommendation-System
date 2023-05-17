#ifndef FEEDBACK_H
#define FEEDBACK_H

#include <iostream>
#include <string>

struct FeedbackNode
{
	int feedbackID;
	std::string username;
	std::string feedback;
	tm *createdAt;
	std::string admin;
	std::string replyContent;
	tm *repliedAt;
	FeedbackNode *prev;
	FeedbackNode *next;
};

class Feedback
{
private:
	int size;
	FeedbackNode *head;
	FeedbackNode *tail;

public:
	Feedback();
	void insertAtEnd(std::string username, std::string feedback, tm *createdAt);
	void printList();
	FeedbackNode *navigateTo(FeedbackNode *current, char code);
	void replyFeedback(FeedbackNode *current, std::string replyContent);
};

#endif