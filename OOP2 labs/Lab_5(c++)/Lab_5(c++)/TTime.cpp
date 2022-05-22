#include <iostream>
#include <ctime>
#include "Header.h"
using namespace std;

void TTime::SetTime(int h, int m, int s)
{
	hh = h;
	mm = m;
	ss = s;
	Check();
}

int TTime::DayEndTime()
{
	int TimeInSec = 0;
	TimeInSec += ss;
	TimeInSec += mm * 60;
	TimeInSec += hh * 60 * 60;
	while (TimeInSec >= 86400) {
		TimeInSec -= 86400;
	}
	return 86400 - TimeInSec;
}

void TTime::Increase(int h, int m, int s)
{
	hh += h;
	mm += m;
	ss += s;
	Check();
}

void TTime::Decrease(int h, int m, int s) {
	hh -= h;
	mm -= m;
	ss -= s;
	Check();
}

void TTime::Check()
{
	while (hh >= 24 || mm >= 60 || ss >= 60) {
		if (hh >= 24) {
			hh = hh - 24;
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
		if (hh < 0) {
			hh = hh + 24;
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

