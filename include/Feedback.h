/*
	created by eujin
*/
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
	// ~Feedback();

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
	// Below codes are referenced from Jason (2023)
	// APA Citation: Jason. (2023, March 8). Override output operator << inside class c++ to print std::vector. Retrieved from stackoverflow: https://stackoverflow.com/questions/75670540/override-output-operator-inside-class-c-to-print-stdvector
	friend std::ostream &operator<<(std::ostream &os, const Feedback &feedback);
	bool operator==(const Feedback &other) const
	{
		// Define what it means for two Feedback objects to be equal.
		return this->feedbackID == other.feedbackID && this->username == other.username && this->feedback == other.feedback && this->createdAt == other.createdAt && this->admin == other.admin && this->replyContent == other.replyContent && this->repliedAt == other.repliedAt;
	}
};

// Override ostream operator
std::ostream &operator<<(std::ostream &os, const Feedback &feedback);

#endif