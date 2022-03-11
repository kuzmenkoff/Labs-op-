#include <fstream>
#include <iostream>
#include <string>
#include "Header.h"
using namespace std;

void CreateFile(int n)
{
	if (n == 2) {
		ofstream fout("File.dat", ios::binary | ios::app);
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
			fout << name << "  ";
			fout << "[" << date << "]  ";
			cout << "Registration number: ";
			cin >> num;
			fout << num << "  ";
			cout << "Sex: ";
			cin >> sex;
			fout << sex << "\n";
			cout << "Continue?\n";
			cin >> s;
		}
		fout.close();
	}
	else if (n == 1) {
		ofstream fout("File.dat", ios::binary);
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
			fout << name << "  ";
			fout << "[" << date << "]  ";
			cout << "Registration number: ";
			cin >> num;
			fout << num << "  ";
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

void FileOutput1()
{
	char s;
	ifstream read;
	cout << "\nFile we've got:\n";
	read.open("File.dat");
	while (read.get(s)) {
		cout << s;
	}
	read.close();
}

void Sort()
{
	int pos = 0;
	char ch;
	string buf = "", date;
	ifstream fin;
	ofstream fout1, fout2;
	fin.open("File.dat", ios::binary);
	fout1.open("1.dat", ios::binary);
	fout2.open("2.dat", ios::binary);
	while (fin.get(ch)) {
		buf.push_back(ch);
		if (ch == '\n') {
			for (int i = 0; i < buf.size(); i++) {
				if (buf[i] == '[') {
					pos = i + 2;
					break;
				}
			}
			
			date = buf.substr(pos, 9);
			if (CheckAge2(date) == true) {
				fout1 << buf;
			}
			else if (CheckAge2(date) == false) {
				fout2 << buf;
			}
			buf = "";
		}
	}
	fout2.close();
	fout1.close();
	fin.close();
}

bool CheckAge2(string date)
{
	string s = date.substr(0, 2);
	int days = stoi(s);
	s = date.substr(2, 2);
	days += stoi(s) * 30;
	s = date.substr(5, 4);
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
	read1.open("1.dat");
	while (read1.get(s)) {
		cout << s;
	}
	read1.close();
	cout << "\n2nd file:\n";
	read2.open("2.dat");
	while (read2.get(s)) {
		cout << s;
	}
	read2.close();
}