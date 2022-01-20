#include "Header.h"

bool checkValidChildrenPassword(string password)
{
	int length = password.length();
	if (length < 6 || length > 12)
	{
		cout << "\nMat khau cho tre dai 6 - 12 ky tu, vui long nhap lai";
		return false;
	}
	for (int i = 0; i < length; i++)
	{
		if (!isdigit(password[i]))
		{
			cout << "\nMat khau cho tre chi bao gom cac chu so, vui long nhap lai";
			return false;
		}
	}
	return true;
}

bool verifyPassword(string password, string repassword)
{
	if (password != repassword)
	{
		cout << "\nMat khau xac nhan khong trung khop, vui long nhap lai";
		return false;
	}
	return true;
}

int countSpaces(string s) {
	int count = 0;

	for (int i = 0; i < s.size(); i++)
		if (s[i] == ' ')
			count++;

	return count;
}