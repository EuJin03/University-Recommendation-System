#include "../include/Feedback.h"

Feedback::Feedback()
{
	head = nullptr;
	tail = nullptr;
	size = 0;
}

void Feedback::insertAtEnd(std::string username, std::string feedback, tm *createdAt)
{
	FeedbackNode *newNode = new FeedbackNode;
	newNode->feedbackID = size + 1;
	newNode->username = username;
	newNode->feedback = feedback;
	newNode->createdAt = createdAt;
	newNode->admin = "";
	newNode->replyContent = "";
	newNode->repliedAt = nullptr;
	newNode->prev = nullptr;
	newNode->next = nullptr;

	if (head == nullptr)
	{
		head = newNode;
		tail = newNode;
	}
	else
	{
		newNode->prev = tail;
		tail->next = newNode;
		tail = newNode;
	}

	size++;
}

void Feedback::printList()
{
	if (head == nullptr)
	{
		std::cout << "No feedbacks available." << std::endl;
		return;
	}

	int i = 0;
	FeedbackNode *current = head;
	while (current != nullptr)
	{
		std::cout << "Feedback ID: " << current->feedbackID << std::endl;
		std::cout << "Content: " << current->feedback << std::endl;
		std::cout << "By user: " << current->username << std::endl;
		current = current->next;
		i++;
	}
}

FeedbackNode *Feedback::navigateTo(FeedbackNode *current, char code)
{
	if (code == 'n')
	{
		if (current->next == nullptr)
		{
			std::cout << "No more feedbacks." << std::endl;
			return current;
		}
		else
		{
			current = current->next;
			return current;
		}
	}
	else if (code == 'p')
	{
		if (current->prev == nullptr)
		{
			std::cout << "No more feedbacks." << std::endl;
			return current;
		}
		else
		{
			current = current->prev;
			return current;
		}
	}
	else
	{
		std::cout << "Invalid input." << std::endl;
		return current;
	}
<<<<<<< HEAD
=======
}

void Feedback::replyFeedback(FeedbackNode *current, std::string admin, std::string replyContent)
{
	current->admin = "admin";
	current->replyContent = replyContent;
	time_t now = time(0);
	current->repliedAt = localtime(&now);

	char buffer[80];
	strftime(buffer, sizeof(buffer), "%y::%m::%d %H::%M::%S", current->repliedAt);
	std::cout << "repliedAt: " << buffer << std::endl;
>>>>>>> 1b2b35669d5d6e66b9b4006681ad08482e1946a6
}