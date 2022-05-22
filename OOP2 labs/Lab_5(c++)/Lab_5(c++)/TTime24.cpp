#include <iostream>
#include <ctime>
#include "Header.h"
using namespace std;

TTime24::TTime24()
{
	hh = 0;
	mm = 0;
	ss = 0;
}

TTime24::TTime24(int h, int m, int s)
{
	hh = h;
	mm = m;
	ss = s;
	Check();
}

void Print24(TTime24 time)
{
	cout << time.hh << ':' << time.mm << ':' << time.ss;
}

void Print24TimeBeforeEnd(TTime24 time)
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