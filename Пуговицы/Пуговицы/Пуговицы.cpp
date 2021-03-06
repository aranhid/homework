#include "pch.h"
#include <iostream>
#include <fstream>
#include <ctime>

using namespace std;

ifstream in("in.txt");
ofstream out("in.txt");
ofstream superout("superout.txt");

struct pug
{
	int x;
	int y;
	int Pair = -1;
	bool isInPair = false;
};

pug* Square;
pug* Circle;
pug* Pair;
static pug* _Square;
static pug* _Circle;
static pug* _Pair;
double sumOfPath = 0;
double answer = INT32_MAX;

double Vector(pug* first, pug* second)
{
	return sqrt((first->x - second->x)*(first->x - second->x) + (first->y - second->y)*(first->y - second->y));
}

void recursion(int iter, int n)
{
	if (iter == n) return;
	for (int i = 0; i < n; i++)
	{
		if (iter == 0)
		{
			memcpy_s(_Square, sizeof(pug)*n, Square, sizeof(pug)*n);
			memcpy_s(_Circle, sizeof(pug)*n, Circle, sizeof(pug)*n);
			_Pair = new pug[n];
		}
		if (_Circle[i].isInPair)
			continue;
		_Square[iter].Pair = i;
		_Circle[i].Pair = iter;
		_Square[iter].isInPair = true;
		_Circle[i].isInPair = true;
		_Pair[iter].Pair = i;
		sumOfPath += Vector(&_Square[iter], &_Circle[i]);
		recursion(iter + 1, n);
		if (iter == 0)
		{
			if (sumOfPath < answer)
			{
				memcpy_s(Pair, sizeof(pug)*n, _Pair, sizeof(pug)*n);
				answer = sumOfPath;
			}
			delete[] _Pair;
			sumOfPath = 0;
		}
	}
}

void generatePonts(int n)
{
	srand(time(0));
	out << n << endl;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			out << rand() % 101 << " ";
		}
		out << endl;
	}
}

void work(int k)
{
	/*cout << "Kol-vo pugivec: ";
	cin >> k;*/
	cout << "Generate points... ";
	generatePonts(k);
	cout << "OK!" << endl;
	cout << "Input points... ";
	int n;
	in >> n;
	Square = new pug[n];
	Circle = new pug[n];
	Pair = new pug[n];
	_Square = new pug[n];
	_Circle = new pug[n];
	_Pair = new pug[n];

	for (int i = 0; i < n; i++)
	{
		in >> Square[i].x >> Square[i].y >> Circle[i].x >> Circle[i].y;
	}
	cout << "OK!" << endl;
	cout << "Start recursion.";
	time_t start, end;
	double seconds;
	time(&start);
	recursion(0, n);
	time(&end);
	seconds = difftime(end, start);
	cout << " It took " << seconds << " seconds!" << endl;
	superout << k << " " << seconds << endl;
	//cout << answer << endl;
/*
	for (int i = 0; i < n; i++)
	{
		cout << i + 1 << " ---- " << Pair[i].Pair + 1 << endl;
	}*/
}

int main()
{
	/*cout << "Kol-vo pugivec: ";
	int k;
	cin >> k;
	cout << "Generate points... ";
	generatePonts(k);
	cout << "OK!" << endl;
	cout << "Input points... ";
	int n;
	in >> n;
	Square = new pug[n];
	Circle = new pug[n];
	Pair = new pug[n];
	_Square = new pug[n];
	_Circle = new pug[n];
	_Pair = new pug[n];
	
	for (int i = 0; i < n; i++)
	{
		in >> Square[i].x >> Square[i].y >> Circle[i].x >> Circle[i].y;
	}
	cout << "OK!" << endl;
	cout << "Start recursion.";
	time_t start, end;
	double seconds;
	time(&start);
	recursion(0, n);
	time(&end);
	seconds = difftime(end, start);
	cout << " It took " << seconds << " seconds!" << endl;
	cout << answer << endl;

	for (int i = 0; i < n; i++)
	{
		cout << i + 1 << " ---- " << Pair[i].Pair + 1 << endl;
	}*/
	superout << 2500 << endl;
	for (int i = 1; i <= 3500; i += 100)
	{
		cout << i << endl;
		work(i);
	}
	//work(3500);
}
