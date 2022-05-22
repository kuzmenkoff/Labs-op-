#pragma once
#include <iostream>
#include <ctime>
using namespace std;

class TTime 
{
public:
	int hh, mm, ss;
	virtual void Check();
	void SetTime(int h, int m, int s);
	void Increase(int h, int m, int s);
	void Decrease(int h, int m, int s);
	virtual int DayEndTime();
};

class TTime12 : public TTime
{
public:
	string meridiem;
	TTime12();
	TTime12(int h, int m, int s);
	virtual void Check();
	virtual int DayEndTime();
};

class TTime24 : public TTime
{
public:
	TTime24();
	TTime24(int h, int m, int s);
};

void Print12(TTime12 time);
void Print24(TTime24 time);
void Print12TimeBeforeEnd(TTime12 time);
void Print24TimeBeforeEnd(TTime24 time);
