﻿#include "pch.h"
#include <iostream>
#include <locale.h>

using namespace std;

int b = 0;
int temp;

int function(int xn)
{
	temp = xn - xn / 2 + b / (2 * xn);

	if (temp == xn || temp == 1) 
		return temp;

	function(temp);
}

int main()
{
	setlocale(LC_ALL, "Russian");
	cout << "Введите число, для которого нужно найти корень: ";
	cin >> b;
	if (b > 0)
	{
		int answer = function(1);
		cout << "Ответ: " << answer;
	}
	else if (b == 0)
		cout << "Ответ: 0";
	else cout << "Вы ввели отрицательное число!";
}
