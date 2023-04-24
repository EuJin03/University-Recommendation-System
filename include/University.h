#ifndef UNIVERSITY_H
#define UNIVERSITY_H

#include <string>
#include <vector>
#include "Student.h" // assume Department class is defined in Department.h

class University
{
public:
	University(const std::string &name)
	{
		this->name = name;
	};

	const std::vector<Student> &getStudents() const;
	// add any other necessary member functions

private:
	std::string name;
	std::vector<Student> students;
};

#endif // UNIVERSITY_H