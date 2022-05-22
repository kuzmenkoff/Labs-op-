#include <iostream>
#include <ctime>
#include "Header.h"
using namespace std;

int main()
{
	int N, M;
	cout << "n = ";
	cin >> N;
	cout << "m = ";
	cin >> M;
	TTime12* time12 = new TTime12[N];
	TTime24* time24 = new TTime24[M];
	srand((unsigned int)time(NULL));
	int h, m, s;
	cout << "Time12:\n";
	for (int i = 0; i < N; i++) {
		h = rand() % 23 + 1;
		m = rand() % 59 + 1;
		s = rand() % 59 + 1;
		time12[i].SetTime(h, m, s);
		cout << i + 1 << ": ";
		Print12(time12[i]); cout << endl;
	}
	cout << "Time12 decreased:\n";
	for (int i = 0; i < N; i++) {
		time12[i].Decrease(0, 0, 5);
		cout << i + 1 << ": ";
		Print12(time12[i]);
		Print12TimeBeforeEnd(time12[i]);
	}
	cout << "Time24:\n";
	for (int i = 0; i < M; i++) {
		h = rand() % 23 + 1;
		m = rand() % 59 + 1;
		s = rand() % 59 + 1;
		time24[i].SetTime(h, m, s);
		cout << i + 1 << ": ";
		Print24(time24[i]); cout << endl;
		
	}
	cout << "Time24 increased:\n";
	for (int i = 0; i < M; i++) {
		time24[i].Increase(0, 15, 0);
		cout << i + 1 << ": ";
		Print24(time24[i]);
		Print24TimeBeforeEnd(time24[i]);
	}
	int smallest12time = 86400, smallest12timei = 0, smallest24time = 86400, smallest24timei = 0;
	for (int i = 0; i < N; i++) {
		if (time12[i].DayEndTime() < smallest12time) {
			smallest12time = time12[i].DayEndTime();
			smallest12timei = i;
		}
	}
	for (int i = 0; i < M; i++) {
		if (time24[i].DayEndTime() < smallest24time) {
			smallest24time = time24[i].DayEndTime();
			smallest24timei = i;
		}
	}
	cout << "\nSmallest time before end of the day:\n\n";
	if (smallest24time < smallest12time) {
		cout << smallest24timei + 1 << ": "; Print24(time24[smallest24timei]);
		Print24TimeBeforeEnd(time24[smallest24timei]);
	}
	else {
		cout << smallest12timei + 1 << ": "; Print12(time12[smallest12timei]);
		Print12TimeBeforeEnd(time12[smallest12timei]);
	}
}

