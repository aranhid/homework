#include "pch.h"
#include <iostream>
#include <locale.h>

using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");
	char src[] = "Some string";
	char dst[20];
	// Копирование через индексацию
	int i = 0;
	for (i = 0; src[i] != 0; i++)
		dst[i] = src[i];
	dst[i] = 0;
	cout << "Копирование через индексацию: " << dst << endl;
	// Копирование через указатели I
	const char* psrc = src;
	char* pdst = dst;
	while (*psrc)
		*pdst++ = *psrc++;
	*pdst = 0;
	cout << "Копирование через указатели I: " << dst << endl;
	// Копирование через указатели II
	psrc = src;
	pdst = dst;
	while (*pdst++ = *psrc++);
	cout << "Копирование через указатели II: " << dst << endl;
	return 0;
}
