#ifndef ADMIN_H
#define ADMIN_H

#include <string>

class Admin
{
public:
	Admin(const std::string &name)
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

#endif // ADMIN_H