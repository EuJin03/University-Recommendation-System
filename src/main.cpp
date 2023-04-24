#include <iostream>
#include "../include/Student.h"

int main()
{
	// define a student
	Student student("John Doe");

	// display the results to the user
	std::cout << "Welcome to our university! " << student.getName() << "!" << std::endl;
	// output any other information about the university or its components

	return 0;
}