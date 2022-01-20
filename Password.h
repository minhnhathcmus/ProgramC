#pragma once
#include "Header.h"

class PasswordManager
{
public:
	PasswordManager();
	~PasswordManager();
	string getChildrenPassword();
	string getParent1Password();
	string getParent2Password();
	int readPasswordFromFile();
	bool isEmpty();
	int createChildrenPassword();
private:
	string children_password;
	string parent1_password;
	string parent2_password;
};
