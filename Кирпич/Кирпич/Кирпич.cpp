﻿#include "pch.h"
#include <iostream>
#include <locale.h>
#include <algorithm>

using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");
	int kirpichW, kirpichH, kirpichL, W, H;
	cout << "Введите длину, ширину и высоту кирпича через пробел: ";
	cin >> kirpichL >> kirpichW >> kirpichH;
	cout << "Введите ширину и высоту дыры в стене через пробел: ";
	cin >> W >> H;
	int minSide1 = min(kirpichL, min(kirpichH, kirpichW));
	int minSide2 = min(max(kirpichH, kirpichW), min(max(kirpichH, kirpichL), max(kirpichL, kirpichW)));
	bool check = (minSide1 <= H && minSide2 <= W) || (minSide1 <= W && minSide2 <= H);
	if (check)
		cout << "Кирпич пролезет.";
	else
		cout << "Кирпич не пролезет.";
}
