#pragma once
#include "Header.h"

struct Time
{
	int hour;
	int minute;
};

class UseTime
{
public:
	UseTime();
	~UseTime();
	Time getFrom();
	Time getTo();
	int getDuration();
	int getInterrupt();
	int getSum();
	void setFrom(int, int);
	void setTo(int, int);
	void setDuration(int);
	void setInterrupt(int);
	void setSum(int);
	void extractTimeInfo1(string);
	void extractTimeInfo2(string);
	void extractTimeInfo3(string);
	void extractTimeInfo4(string);
private:
	Time from;
	Time to;
	int duration;
	int interrupt;
	int sum;
};

class UseTimeList
{
public:
	UseTimeList();
	~UseTimeList();
	int readUseTimeFromFile();
	int displayUseTime();
private:
	vector<UseTime> use_time_list;
};