#include "stdafx.h"
#include "Treangle.h"
#include <iostream>

using namespace std;

Treangle::Treangle(int width, int height):mnWidth(width), mnHeight(height)
{
	cout << "Treangle(int width, int height) for " << this << " width = " << mnWidth << " height = " << mnHeight << endl;
}


Treangle::~Treangle()
{
	cout << "Treangle(int width, int height) for " << this << endl;
}

void Treangle::Show()
{
	if (this == 0)
		return;

	for (int i = 0; i < mnHeight; ++i)
	{
		for (int j = 0; j < mnWidth; ++j)
			cout << "*";

		cout << endl;
	}

	cout << endl;
}

