#include <fstream>
#include <iostream>
#include <string>
#include "Header.h"
using namespace std;

class personnel {
public:
	string name, date, num, sex;
};

void CreateFile(int n)
{
	if (n == 2) {
		//Відкриття файлу для запису даних в кінець, вважаючи його бінарним
		ofstream fout("File.bin", ios::binary | ios::app);
		string s = "yes", name, date, num, sex;
		while (s == "yes") {
			cout << "Name: ";
			cin >> name;
			cout << "Date: ";
			cin >> date;
			//Перевіряємо вік, чи не більше він 60, або менше 20
			if (CheckAge(date) == false) {
				cout << "Bad age!\n";
				cout << "Continue?\n";
				cin >> s;
				continue;
			}
			fout << name << " ";
			fout << date << " ";
			cout << "Registration number: ";
			cin >> num;
			fout << num << " ";
			cout << "Sex: ";
			cin >> sex;
			fout << sex << "\n";
			cout << "Continue?\n";
			cin >> s;
		}
		fout.close();
	}
	else if (n == 1) {
		//Відкриття файлу для запису, вважаючи його бінарним
		ofstream fout("File.bin", ios::binary | ios::out);
		string s = "yes", name, date, num, sex;
		while (s == "yes") {
			cout << "Name: ";
			cin >> name;
			cout << "Date: ";
			cin >> date;
			if (CheckAge(date) == false) {
				cout << "Bad age!\n";
				cout << "Continue?\n";
				cin >> s;
				continue;
			}
			fout << name << " ";
			fout << date << " ";
			cout << "Registration number: ";
			cin >> num;
			fout << num << " ";
			cout << "Sex: ";
			cin >> sex;
			fout << sex << "\n";
			cout << "Continue?\n";
			cin >> s;

		}
		fout.close();
	}
}

bool CheckAge(string date)
{
	string s = date.substr(1, 2);
	int days = stoi(s);
	s = date.substr(3, 2);
	days += stoi(s) * 30;
	s = date.substr(6, 4);
	days += stoi(s) * 365;
	int newdays = 9 + 3 * 30 + 2022 * 365;
	int age = newdays - days;
	if (age > 7304 && age < 21914) {
		return true;
	}
	else {
		return false;
	}
}

int FindSize() {
	char s;
	int size = 0;
	ifstream read;
	read.open("File.bin");
	while (read.get(s)) {
		if (s == '\n') {
			size++;
		}
	}
	read.close();
	return size;
}

personnel* ReadInfo(int size)
{
	ifstream read;
	read.open("File.bin");
	personnel* workers = new personnel[size];
	for (int i = 0; i < size; i++) {
		read >> workers[i].name >> workers[i].date >> workers[i].num >> workers[i].sex;
	}
	read.close();
	return workers;
}

void FileOutput1(personnel* workers, int size)
{
	char s;
	ifstream read;
	cout << "\nFile we've got:\n";
	read.open("File.bin");
	//Посимвольний вивід файлу
	for (int i = 0; i < size; i++) {
		cout << workers[i].name << " " << workers[i].date << " " << workers[i].num << " " << workers[i].sex << endl;
	}
	read.close();
}

void Sort(personnel* workers, int size)
{
	ofstream fout1, fout2;
	fout1.open("1.bin", ios::binary);
	fout2.open("2.bin", ios::binary);
	for (int i = 0; i < size; i++) {
		if (CheckAge2(workers[i].date) == true) {
			fout1 << workers[i].name << " " << workers[i].date << " " << workers[i].num << " " << workers[i].sex << '\n';
		}
		else {
			fout2 << workers[i].name << " " << workers[i].date << " " << workers[i].num << " " << workers[i].sex << '\n';
		}
	}
	fout2.close();
	fout1.close();
}

bool CheckAge2(string date)
{
	string s = date.substr(0, 2);
	int days = stoi(s);
	s = date.substr(3, 2);
	days += stoi(s) * 30;
	s = date.substr(6, 4);
	days += stoi(s) * 365;
	int newdays = 11 + 3 * 30 + 2022 * 365;
	int age = newdays - days;
	if (age < 14609) {
		return true;
	}
	else {
		return false;
	}
}

void FileOutput2()
{
	char s;
	ifstream read1, read2;
	cout << "\n1st file:\n";
	read1.open("1.bin");
	while (read1.get(s)) {
		cout << s;
	}
	read1.close();
	cout << "\n2nd file:\n";
	read2.open("2.bin");
	while (read2.get(s)) {
		cout << s;
	}
	read2.close();
}