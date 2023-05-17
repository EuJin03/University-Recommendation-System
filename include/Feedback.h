#ifndef FEEDBACK_H
#define FEEDBACK_H

#include <iostream>
#include <string>

struct feedbackNode
{
	int feedbackID;
	std::string username;
	std::string feedback;
	tm *createdAt;
	std::string admin;
	std::string replyContent;
	tm *repliedAt;
	feedbackNode *prev;
	feedbackNode *next;
};

class Feedback
{
private:
	int size;
	Feedback *head;
	Feedback *tail;

public:
	Feedback();
	void insertAtEnd(int feedbackID, std::string username, std::string feedback, tm *createdAt);
	void printList();
	feedbackNode *navigateTo(Feedback *current, char code);
	void replyFeedback(int feedbackID, std::string replyContent, tm *repliedAt);
};

#endif