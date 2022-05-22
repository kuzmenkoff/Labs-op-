#include <iostream>
#include <ctime>
#include "Header.h"
using namespace std;

TTime12::TTime12()
{
	hh = 0;
	mm = 0;
	ss = 0;
	meridiem = "a.m.";
}

TTime12::TTime12(int h, int m, int s)
{
	hh = h;
	mm = m;
	ss = s;
	Check();
}

void TTime12::Check()
{
	while (hh >= 12 || mm >= 60 || ss >= 60) {
		if (hh >= 12 && meridiem == "a.m.") {
			hh = hh - 12;
			meridiem = "p.m";
		}
		if (hh >= 12 && meridiem == "p.m.") {
			hh = hh - 12;
			meridiem = "a.m.";
		}
		if (mm >= 60) {
			mm = mm - 60;
			hh++;
		}
		if (ss >= 60) {
			ss = ss - 60;
			mm++;
		}
	}
	while (hh < 0 || mm < 0 || ss < 0) {
		if (hh < 0 && meridiem == "a.m.") {
			hh = hh + 12;
			meridiem = "p.m.";
		}
		if (hh < 0 && meridiem == "p.m.") {
			hh = hh + 12;
			meridiem = "a.m.";
		}
		if (mm < 0) {
			mm = mm + 60;
			hh--;
		}
		if (ss < 0) {
			ss = ss + 60;
			mm--;
		}
	}
}

int TTime12::DayEndTime()
{
	int TimeInSec = 0;
	TimeInSec += ss;
	TimeInSec += mm * 60;
	TimeInSec += hh * 60 * 60;
	if (meridiem == "p.m.") {
		TimeInSec += 12 * 60 * 60;
	}
	while (TimeInSec >= 86400) {
		TimeInSec -= 86400;
	}
	return 86400 - TimeInSec;
}

void Print12(TTime12 time)
{
	cout << time.hh << ':' << time.mm << ':' << time.ss << " " << time.meridiem;
}

void Print12TimeBeforeEnd(TTime12 time)
{
	int TimeInSec = time.DayEndTime();
	int h = 0, m = 0, s = 0;
	while (TimeInSec >= 3600) {
		h++;
		TimeInSec -= 3600;
	}
	while (TimeInSec >= 60) {
		m++;
		TimeInSec -= 60;
	}
	s = TimeInSec;
	cout << "   Time before end of the day: " << h << ':' << m << ':' << s << endl;
}
