﻿#include "pch.h"
#include <iostream>
#include <ctime>
#include <fstream>
#include <math.h>
#include <locale.h>

using namespace std;

struct point
{
	double x, y;
};

const int n = 100;
point points[n + 1];

int main()
{
	setlocale(LC_ALL, "Russian");
	double xStart = 2, yStart = 5, xEnd = 10, yEnd = 20;
	cout << "Введите начальную точку (x, y): ";
	cin >> xStart >> yStart;
	cout << "Введите конечную точку (x, y): ";
	cin >> xEnd >> yEnd;

	double k = (yEnd - yStart) / (xEnd - xStart),
		   b = yStart - k * xStart;
	cout << "Оригинальное значение k = " << k << endl;
	cout << "Оригинальное значение b = " << b << endl;

	cout << "Создание шума..." << endl;

	double sumKS = 0, sumBS = 0, sumKSKS = 0, sumBSBS = 0;
	const double howManyTimes = 1000;
	srand(time(0));
	for (int j = 0; j < howManyTimes; j++)
	{
		double currentX = xStart;
		double sumX = 0, sumY = 0, sumXY = 0, sumXX = 0;
		for (int i = 0; i <= n; i++)
		{
			points[i].x = currentX;
			points[i].y = k * currentX + b;
			double r = (rand()*1.0 / RAND_MAX - 0.5) * 3;
			points[i].y += r;

			sumX += points[i].x;
			sumY += points[i].y;
			sumXY += points[i].x * points[i].y;
			sumXX += points[i].x * points[i].x;

			currentX += (xEnd - xStart) / n;
		}
		double KS = (n*sumXY - sumX * sumY) / (n*sumXX - sumX * sumX);
		double BS = (sumY - KS * sumX) / n;
		sumKS += KS;
		sumBS += BS;
		sumKSKS += KS * KS;
		sumBSBS += BS * BS;
	}

	cout << "Вычисление значений k и b при помощи МНК..." << endl;

	double averageKS = sumKS / howManyTimes;
	double averageKSKS = sumKSKS / howManyTimes;
	double aKSaKS = averageKS * averageKS;
	double averageBS = sumBS / howManyTimes;
	double averageBSBS = sumBSBS / howManyTimes;
	double aBSaBS = averageBS * averageBS;

	cout << "Значение k, полученное через МНК = " << averageKS << endl;
	cout << "Среднее квадратичное отклонение для k = " << sqrt(averageKSKS - aKSaKS) << endl;
	cout<< "Значение b, полученное через МНК = " << averageBS << endl;
	cout << "Среднее квадратичное отклонение для b = " << sqrt(averageBSBS - aBSaBS) << endl;
}