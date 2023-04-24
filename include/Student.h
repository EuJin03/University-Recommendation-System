#ifndef STUDENT_H
#define STUDENT_H

#include <string>

class Student
{
public:
	Student(const std::string &name)
	{
		this->name = name;
	};

	// add any other necessary member functions

	const std::string &getName() const;
	// add any other necessary member functions

private:
	std::string name;
	// add any other necessary member variables
};

#endif // STUDENT_H