#include "pch.h"
#include <iostream>
#include <locale.h>
#include <algorithm>

using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");
	const int sides = 3;
	const int wh = 2;
	int kirpichSides[sides];
	int WH[wh];
	cout << "Введите длину, ширину и высоту кирпича через пробел: ";
	for (int i = 0; i < sides; i++)
	{
		cin >> kirpichSides[i];
	}
	cout << "Введите ширину и высоту дыры в стене через пробел: ";
	for (int i = 0; i < wh; i++)
	{
		cin >> WH[i];
	}
	sort(kirpichSides, kirpichSides + sides);
	sort(WH, WH + wh);
	bool check = (kirpichSides[0] <= WH[0] && kirpichSides[1] <= WH[1]);
	if (check)
		cout << "Кирпич пролезет.";
	else
		cout << "Кирпич не пролезет.";
}
