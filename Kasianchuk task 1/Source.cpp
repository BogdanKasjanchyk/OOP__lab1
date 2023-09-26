#include <iostream>
#include <fstream>
#include <locale.h>
#include <string>

using namespace std;

int N;
string filename;

struct date {
	int day;
	int month;
	int year;
};

struct student {
	char name[10];
	char surname[30];
	date birthDate;
} object;

int trainNumber;
string station;

void RW(string filename) {
	int startHours, startMinutes;
	int finishHours, finishMinutes;

	if (filename == "INFO.DAT")
	{
		cout << "Students amount:";
		cin >> N;

		do
		{
			cout << "Type name: ";
			cin >> object.name;

			cout << "Type surname: ";
			cin >> object.surname;

			cout << "Birthday: ";
			cin >> object.birthDate.day;

			cout << "Birth month: ";
			cin >> object.birthDate.month;

			cout << "Birth year: ";
			cin >> object.birthDate.year;

			ofstream book_file(filename, ios::app);

			book_file << object.name << " ";
			book_file << object.surname << " ";

			book_file << object.birthDate.day << " ";
			book_file << object.birthDate.month << " ";
			book_file << object.birthDate.year << " ";

			book_file << endl;

			N--;

			book_file.close();

		} while (N != 0);
	}
	if (filename == "INFO.TXT")
	{
		cout << "Trains amount: ";
		cin >> N;
		do
		{

			cout << "Type trains number: ";
			cin >> trainNumber;

			cout << "Type destinate station: ";
			cin >> station;

			cout << "Type start time (hours): ";
			cin >> startHours;

			cout << "Type start time (minutes): ";
			cin >> startMinutes;

			cout << "Type finish time (hours): ";
			cin >> finishHours;

			cout << "Type finish time (minutes): ";
			cin >> finishMinutes;

			ofstream book_file(filename, ios::app);

			book_file << trainNumber << " ";
			book_file << station << " ";

			if (startMinutes < 10) {
				book_file << startHours << ":0" << startMinutes << " ";
			}
			else {
				book_file << startHours << ":" << startMinutes << " ";
			}

			if (finishMinutes < 10) {
				book_file << finishHours << ":0" << finishMinutes << " ";
			}
			else {
				book_file << finishHours << ":" << finishMinutes << " ";
			}

			int hours = finishHours - startHours;
			int minutes = finishMinutes - startMinutes;

			cout << hours << ":" << minutes << " time left" << endl;
			book_file << hours << ":" << minutes << " time left";

			if (hours <= 10)
			{
				cout << " Less then 10 hours" << endl;
				book_file << " Less then 10 hours" << endl;
			}
			else
			{
				cout << " More then 10 hours" << endl;
				book_file << " More then 10 hours" << endl;
			}

			N--;

			book_file.close();

		} while (N != 0);
	}

}

void RD(string filename) {
	ifstream read_file(filename);
	if (filename == "INFO.DAT")
	{
		student* array = new student[100];

		int n = 0;

		while (read_file >> array[n].name >> array[n].surname >> array[n].birthDate.day >> array[n].birthDate.month >> array[n].birthDate.year) { // Зчитуємо дату народження
			n++;
		}

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n - i - 1; j++) {
				if (array[j].birthDate.year > array[j + 1].birthDate.year) {
					student temp = array[j];
					array[j] = array[j + 1];
					array[j + 1] = temp;
				}
			}
		}

		for (int i = 0; i < n; i++) {
			cout << array[i].name << " " << array[i].surname << " " << array[i].birthDate.day << "/" << array[i].birthDate.month << "/" << array[i].birthDate.year << endl; // Виводимо дату народження
		}
	}

	string line;

	if (filename == "INFO.TXT")
	{
		while (getline(read_file, line)) { 
			if (line.find("Less then 10 hours") != string::npos) {
				cout << line << endl; 
			}
		}
	}
}

void main() {
	setlocale(LC_ALL, "Ukr");
	cout << "Choose file: INFO.DAT or INFO.TXT" << endl;

	cin >> filename;

	cout << "Edit OR Read" << endl;

	string func;
	cin >> func;

	if (func == "Edit")
	{
		RW(filename);
	}
	if (func == "Read")
	{
		RD(filename);
	}
}

