#include "Password.h"
#include "UseTime.h"

int main()
{
	/*PasswordManager password_manager;
	password_manager.readPasswordFromFile();
	if (password_manager.isEmpty() == true)
		password_manager.createChildrenPassword();*/
	UseTimeList use_time_list;
	use_time_list.readUseTimeFromFile();
	use_time_list.displayUseTime();
	return 0;
}