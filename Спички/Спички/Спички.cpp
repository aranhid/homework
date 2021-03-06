﻿#include "pch.h"
#include <iostream>
#include <ctime>
#include <locale.h>
#include <string>

using namespace std;

//int lose[] = { 1, 7, 13, 19, 25, 31, 37, 43, 49, 55, 61, 67, 73, 79, 85, 91, 97 };

const int maximumMatches = 100;
const int minimumMatches = 30;
int matches;

enum Variant { BOT, MAN};

Variant man = MAN;
Variant bot = BOT;

int MaxTake()
{
	return (matches > 5) ? 5 : matches;
}

void WriteNumberOfMatches()
{
	cout << "=====================" << endl;
	cout << "Количество спичек: " << matches << endl;
	cout << "=====================" << endl;
}

int CheckInput(istream &in)
{
	int temp;
	while (!(cin >> temp) || cin.peek() != '\n')
	{
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "Можно вводить только цифры! Введите число: ";
	}
	return temp;
}

void Step(Variant variant)
{
	int step = 0;
	switch (variant)
	{
	case BOT:
		if (matches % 6 == 1)
		{
			if(matches != 1)
				step = rand() % 4 + 1;
			else step = 1;
		}
		else
		{
			step = matches % 6 - 1;
			if (step == -1) step = 5;
		}
		cout << "Ходит бот. Он взял ";
		switch (step)
		{
		case 1:
			cout << step << " спичку." << endl;
			break;
		case 5:
			cout << step << " спичек." << endl;
			break;
		default:
			cout << step << " спички." << endl;
			break;
		}
		break;
	case MAN:
		bool checkInput = false;
		while (!checkInput)
		{
			step = CheckInput(cin);
			if (step >= 1 && step <= MaxTake())
				checkInput = true;
			else
			{
				cout << "Вы ввели число, которое не входит в указанный промежуток! Введите правильное число: ";
			}
		}
		break;
	}
	matches -= step;
}

void Game()
{
	matches = rand() % (maximumMatches - minimumMatches) + minimumMatches;
	while (matches != 0)
	{
		WriteNumberOfMatches();
		cout << "Ваш ход. Выберете количество спичек от 1 до " << MaxTake() << " включительно: ";
		Step(man);
		if (matches == 0)
		{
			cout << "=================" << endl;
			cout << "= Вы проиграли! =" << endl;
			cout << "=================" << endl;
			return;
		}
		WriteNumberOfMatches();
		Step(bot);
		if (matches == 0)
		{
			cout << "================" << endl;
			cout << "= Вы выиграли! =" << endl;
			cout << "================" << endl;
		}
	}
}

int main()
{
	setlocale(LC_ALL, "Russian");
	srand(time(0));
	cout << "Вас приветствует игра Спички! Цель игры - сделать так, чтобы ваш противник забрал последнюю спичку, иначе вы проиграете." << endl <<endl;
	while (true) 
	{
		Game();
		cout << "Хотите сыграть ещё раз? Yes/No: ";
		string answer; cin >> answer;
		if (answer == "No" || answer == "no") return 0;
	}
}
