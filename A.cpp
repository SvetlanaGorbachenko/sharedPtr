#include "stdafx.h"
#include "A.h"
#include <iostream>

using namespace std;


A::A(int a) :m_a(a)
{
	cout << "constructor A(int a)" << " this = " << this << endl;
}


A::~A()
{
	cout << "destructor ~A()" << " this = " << this << endl;
}

void A::Show()
{
	cout << "m_a = " << m_a << endl;
}
