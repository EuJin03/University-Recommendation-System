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
	Feedback();

	// Getter
	int getFeedbackID() const { return this->feedbackID; }
	std::string getUsername() const { return this->username; }
	std::string getFeedback() const { return this->feedback; }
	tm *getCreatedAt() const { return this->createdAt; }
	std::string getAdmin() const { return this->admin; }
	std::string getReplyContent() const { return this->replyContent; }
	tm *getRepliedAt() const { return this->repliedAt; }

	// Setter
	void setFeedbackID(int feedbackID) { this->feedbackID = feedbackID; }
	void setUsername(std::string username) { this->username = username; }	
	void setFeedback(std::string feedback) { this->feedback = feedback; }
	void setCreatedAt(tm *createdAt) { this->createdAt = createdAt; }
	void setAdmin(std::string admin) { this->admin = admin; }
	void setReplyContent(std::string replyContent) { this->replyContent = replyContent; }
	void setRepliedAt(tm *repliedAt) { this->repliedAt = repliedAt; }

	// Overriding ostream operator
	friend std::ostream &operator<<(std::ostream &os, const Feedback &feedback);
};

// Override ostream operator
std::ostream &operator<<(std::ostream &os, const Feedback &feedback);

#endif