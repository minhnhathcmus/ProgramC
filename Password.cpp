#include "Password.h"

PasswordManager::PasswordManager()
{
	children_password = "";
	parent1_password = "";
	parent2_password = "";
}

PasswordManager::~PasswordManager()
{

}

string PasswordManager::getChildrenPassword()
{
	return children_password;
}

string PasswordManager::getParent1Password()
{
	return parent1_password;
}

string PasswordManager::getParent2Password()
{
	return parent2_password;
}

int PasswordManager::readPasswordFromFile()
{
	FILE* f = fopen("password.txt", "r");
	if (f == NULL)
	{
		cout << "Da xay ra loi, vui long thu lai sau";
		return 1; //Loi khong the doc tap tin chua mat khau dang nhap
	}
	string line = "";
	fscanf(f, "%[^/n]", &line);
	if (line != "")
		children_password = line.substr(line.find_first_of("child=") + 7);

	fscanf(f, "%[^/n]", &line);
	if (line != "")
		parent1_password = line.substr(line.find_first_of("parent1=") + 9);

	fscanf(f, "%[^/n]", &line);
	if (line != "")
		parent2_password = line.substr(line.find_first_of("parent2=") + 9);

	fclose(f);
	return 0; //Doc mat khau thanh cong
}

bool PasswordManager::isEmpty()//Tra ve true neu chua co mat khau cho tre, nguoc lai tra ve false
{
	if (children_password == "")
		return true;
	return false;
}

int PasswordManager::createChildrenPassword()
{
	cout << "\tTAO MAT KHAU CHO TRE\n";
	cout << "\nMat khau cua tre dai 6 - 12 ky tu, chi bao gom cac chu so\n";
	string password;
	string repassword;
	do
	{
		do
		{
			cout << "\nNhap vao mat khau cua tre: ";
			cin >> password;
		} while (checkValidChildrenPassword(password) != true);
		do
		{
			cout << "\nXac nhan mat khau cua tre: ";
			cin >> repassword;
		} while (checkValidChildrenPassword(repassword) != true);
	} while (verifyPassword(password, repassword) != true);
	children_password = password;
	FILE* f = fopen("password.txt", "a");
	if (f == NULL)
	{
		cout << "Da xay ra loi, vui long thu lai sau";
		return 1;//Loi khong the mo tap tin luu mat khau
	}
	fprintf(f, "child=%s", children_password.c_str());
	fprintf(f, "\nparent1=%s", parent1_password.c_str());
	fprintf(f, "\nparent2=%s", parent2_password.c_str());
	fclose(f);
	cout << "\nTao mat khau cho tre thanh cong";
	return 0;//Tao mat khau cho tre thanh cong
}