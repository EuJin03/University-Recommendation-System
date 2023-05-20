#ifndef FEEDBACK_H
#define FEEDBACK_H

#include <iostream>
#include <string>
#include <ctime>
#include <optional>

struct FeedbackNode
{
	int feedbackID;
	std::string username;
	std::string feedback;
	struct tm createdAt;
	std::string admin;
	std::string replyContent;
	std::optional<tm> repliedAt;
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
	void insertAtEnd(std::string username, std::string feedback, struct tm *createdAt);
	void printList();
	FeedbackNode *navigateTo(FeedbackNode *current, char code);
	void replyFeedback(FeedbackNode *current, std::string admin, std::string replyContent);
	FeedbackNode *getTail() const;
};

#endif