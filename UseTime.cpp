#include "UseTime.h"

UseTime::UseTime()
{
	from.hour = 0;
	from.minute = 0;
	to.hour = 0;
	to.minute = 0;
	duration = 0;
	interrupt = 0;
	sum = 0;
}

UseTime::~UseTime()
{

}

void UseTime::extractTimeInfo1(string line)
{//Danh cho truong hop chi co From va To
	string temp_string;
	int pos;
	int hour;
	int minute;

	pos = line.find(' ');
	temp_string = line.substr(1, pos - 1);
	line.erase(0, pos + 2);

	hour = stoi(temp_string.substr(0, 2));
	minute = stoi(temp_string.substr(3));
	this->from.hour = hour;
	this->from.minute = minute;

	temp_string = line;
	hour = stoi(temp_string.substr(0, 2));
	minute = stoi(temp_string.substr(3));
	this->to.hour = hour;
	this->to.minute = minute;
}

void UseTime::extractTimeInfo2(string line)
{//Danh cho truong hop chi co From, To va Sum
	string temp_string;
	int pos;
	int hour;
	int minute;

	pos = line.find(' ');
	temp_string = line.substr(1, pos - 1);
	line.erase(0, pos + 2);

	hour = stoi(temp_string.substr(0, 2));
	minute = stoi(temp_string.substr(3));
	this->from.hour = hour;
	this->from.minute = minute;

	pos = line.find(' ');
	temp_string = line.substr(0, pos);
	line.erase(0, pos + 2);

	hour = stoi(temp_string.substr(0, 2));
	minute = stoi(temp_string.substr(3));
	this->to.hour = hour;
	this->to.minute = minute;

	this->sum = stoi(line);
}

void UseTime::extractTimeInfo3(string line)
{//Danh cho truong hop chi co From, To, Duration va Interrupt
	string temp_string;
	int pos;
	int hour;
	int minute;

	pos = line.find(' ');
	temp_string = line.substr(1, pos - 1);
	line.erase(0, pos + 2);

	hour = stoi(temp_string.substr(0, 2));
	minute = stoi(temp_string.substr(3));
	this->from.hour = hour;
	this->from.minute = minute;

	pos = line.find(' ');
	temp_string = line.substr(0, pos);
	line.erase(0, pos + 2);

	hour = stoi(temp_string.substr(0, 2));
	minute = stoi(temp_string.substr(3));
	this->to.hour = hour;
	this->to.minute = minute;

	pos = line.find(' ');
	temp_string = line.substr(0, pos);
	line.erase(0, pos + 2);

	this->duration = stoi(temp_string);
	this->interrupt = stoi(line);
}

void UseTime::extractTimeInfo4(string line)
{//Danh cho truong hop co day du From, To, Duration, Interrupt, Sum
	string temp_string;
	int pos;
	int hour;
	int minute;

	pos = line.find(' ');
	temp_string = line.substr(1, pos - 1);
	line.erase(0, pos + 2);

	hour = stoi(temp_string.substr(0, 2));
	minute = stoi(temp_string.substr(3));
	this->from.hour = hour;
	this->from.minute = minute;

	pos = line.find(' ');
	temp_string = line.substr(0, pos);
	line.erase(0, pos + 2);

	hour = stoi(temp_string.substr(0, 2));
	minute = stoi(temp_string.substr(3));
	this->to.hour = hour;
	this->to.minute = minute;

	pos = line.find(' ');
	temp_string = line.substr(0, pos);
	line.erase(0, pos + 2);

	this->duration = stoi(temp_string);

	pos = line.find(' ');
	temp_string = line.substr(0, pos);
	line.erase(0, pos + 2);

	this->interrupt = stoi(temp_string);
	this->sum = stoi(line);
}

Time UseTime::getFrom()
{
	return from;
}

Time UseTime::getTo()
{
	return to;
}

int UseTime::getDuration()
{
	return duration;
}

int UseTime::getInterrupt()
{
	return interrupt;
}

int UseTime::getSum()
{
	return sum;
}

void UseTime::setFrom(int _hour, int _minute)
{
	from.hour = _hour;
	from.minute = _minute;
}

void UseTime::setTo(int _hour, int _minute)
{
	to.hour = _hour;
	to.minute = _minute;
}

void UseTime::setDuration(int _duration)
{
	duration = _duration;
}

void UseTime::setInterrupt(int _interrupt)
{
	interrupt = _interrupt;
}

void UseTime::setSum(int _sum)
{
	sum = _sum;
}

UseTimeList::UseTimeList()
{
	
}

UseTimeList::~UseTimeList()
{

}

int UseTimeList::readUseTimeFromFile()
{
	FILE* f = fopen("use_time.txt", "r");
	if (f == NULL)
	{
		system("error.vbs");
		return 1;//Loi khong doc duoc tap tin chua khung gio duoc dung
	}
	string line = "";
	string temp_string;
	int pos;
	int hour;
	int minute;
	int number_of_space;
	while (true)
	{
		UseTime temp;
		char* buffer = new char[100];
		fscanf(f, "%[^\n]", buffer);
		line = buffer;
		number_of_space = countSpaces(line);
		switch (number_of_space)
		{
		case 1:
		{
			temp.extractTimeInfo1(line);
			break;
		}
		case 2:
		{
			temp.extractTimeInfo2(line);
			break;
		}
		case 3:
		{
			temp.extractTimeInfo3(line);
			break;
		}
		case 4:
		{
			temp.extractTimeInfo4(line);
			break;
		}
		default:
			break;
		}
		use_time_list.push_back(temp);
		delete[]buffer;
		if (feof(f))
			break;
		fseek(f, 2, SEEK_CUR);
	}
	fclose(f);
	cout << "Doc thong tin khung gio su dung thanh cong";
	return 0;//Doc thong tin thanh cong
}

int UseTimeList::displayUseTime()
{
	FILE* f = fopen("notification.vbs", "w");
	if (f == NULL)
	{
		system("error.vbs");
		return 1;//Loi khong the xuat thong bao ra man hinh
	}
	UseTime temp;
	string content = "x=msgbox(\"Khung gio duoc dung may la:\" & Chr(13) & Chr(13) ";
	for (int i = 0; i < use_time_list.size(); i++)
	{
		temp = use_time_list[i];
		content = content + "& \"Tu " + to_string(temp.getFrom().hour) + " gio "
			+ to_string(temp.getFrom().minute) + " phut den ";
		content = content + to_string(temp.getTo().hour) + " gio "
			+ to_string(temp.getTo().minute) + " phut";

		if (temp.getDuration() != 0)
			content = content + ", moi dot duoc dung " + to_string(temp.getDuration()) + " phut";

		if (temp.getInterrupt() != 0)
			content = content + ", nghi giai lao " + to_string(temp.getInterrupt()) + " phut";

		if (temp.getSum() != 0)
			content = content + ", tong thoi gian duoc dung la " + to_string(temp.getSum()) + " phut";

		content += "\" & Chr(13) & Chr(13) ";
	}
	content += ", 0, \"Thong bao\")";
	fprintf(f, "%s", content.c_str());
	fclose(f);
	system("notification.vbs");
	return 0;//Hien thi thong bao thanh cong
}