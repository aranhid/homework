#include "pch.h"
#include <iostream>
#include <locale.h>
#include <iomanip>

using namespace std;

int const hour = 60;
int const startJob = 7 * hour;
int const endJob = 19 * hour;
int timeFromAtoB = 0, restTime = 0, currentTime = startJob;

bool check()
{
	if (currentTime + 2 * timeFromAtoB + restTime < endJob) return true;
	return false;
}

int main()
{
	setlocale(LC_ALL, "Russian");
	cout << "Введите время в пути от A до B." << endl;
	cin >> timeFromAtoB;
	cout << "Введите время отдыха." << endl;
	cin >> restTime;
	cout << "  Расписание" << endl;
	cout << "  A      B" << endl;
	while (check())
	{
		cout << setw(2) << setfill('0') <<currentTime / hour << ":" << setw(2) << setfill('0') << currentTime % hour << " > ";
		currentTime += timeFromAtoB;
		cout << setw(2) << setfill('0') << currentTime / hour << ":" << setw(2) << setfill('0') << currentTime % hour <<endl;
		currentTime += restTime + timeFromAtoB;
		cout << setw(2) << setfill('0') << currentTime / hour << ":" << setw(2) << setfill('0') << currentTime % hour << " < ";
		currentTime -= timeFromAtoB;
		cout << setw(2) << setfill('0') << currentTime / hour << ":" << setw(2) << setfill('0') << currentTime % hour << endl;
		currentTime += timeFromAtoB + restTime;
	}
}