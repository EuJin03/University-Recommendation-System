#ifndef FEEDBACK_H
#define FEEDBACK_H

#include <iostream>
#include <string>
#include <ctime>
#include <optional>

class Feedback
{
private:
	int feedbackID;
	std::string username;
	std::string feedback;
	std::time_t createdAt;
	std::string admin;
	std::string replyContent;
	std::time_t repliedAt;

public:
	// Constructor
	Feedback(int feedbackID, std::string username, std::string feedback, std::time_t createdAt, std::string admin, std::string replyContent, std::time_t repliedAt);
	// Copy constructor
	Feedback(int feedbackID, std::string username, std::string feedback, std::time_t createdAt);
	// Feedback(const Feedback &feedback);
	Feedback();

	// Getter
	int getFeedbackID() const { return this->feedbackID; }
	std::string getUsername() const { return this->username; }
	std::string getFeedback() const { return this->feedback; }
	std::time_t getCreatedAt() const { return this->createdAt; }
	std::string getAdmin() const { return this->admin; }
	std::string getReplyContent() const { return this->replyContent; }
	std::time_t getRepliedAt() const { return this->repliedAt; }

	// Setter
	void setFeedbackID(int feedbackID) { this->feedbackID = feedbackID; }
	void setUsername(std::string username) { this->username = username; }
	void setFeedback(std::string feedback) { this->feedback = feedback; }
	void setCreatedAt(std::time_t createdAt) { this->createdAt = createdAt; }
	void setAdmin(std::string admin) { this->admin = admin; }
	void setReplyContent(std::string replyContent) { this->replyContent = replyContent; }
	void setRepliedAt(std::time_t repliedAt) { this->repliedAt = repliedAt; }

	// Overriding ostream operator
	friend std::ostream &operator<<(std::ostream &os, const Feedback &feedback);
};

// Override ostream operator
std::ostream &operator<<(std::ostream &os, const Feedback &feedback);

#endif