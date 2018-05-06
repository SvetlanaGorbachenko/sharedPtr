#include "stdafx.h"
#include "memGuard.h"
#include <iostream>
#include "A.h"


using namespace std;

//   memGuard(A *pA = 0);
memGuard::memGuard(A *pA) : m_pA(pA)
{
	m_pCounter = new int(0);

	cout << "memGuard(A *pA) for " << this << " m_pA = " << m_pA << " *m_pCounter = " << *m_pCounter << endl;
}

memGuard::memGuard(const memGuard &R)
{
	if (this != &R)
	{
		m_pA = R.m_pA;
		m_pCounter = R.m_pCounter;
		if (m_pA != 0)
			++(*m_pCounter);
	}
	cout << "memGuard copy constructor for " << this << " m_pA = " << m_pA << " *m_pCounter = " << *m_pCounter << endl;
}

memGuard::~memGuard()
{
	if (*m_pCounter != 0)
		--(*m_pCounter);
	else
	{
		delete m_pCounter;
		delete m_pA;

		m_pCounter = 0;
		m_pA = 0;
	}
	if(m_pCounter != 0)
		cout << "~memGuard() for " << this << " *m_pCounter = " << *m_pCounter << " m_pA = " << m_pA << endl;
	else
		cout << "~memGuard() for " << this << " m_pCounter = " << m_pCounter << " m_pA = " << m_pA << endl;
}

A * memGuard::operator ->()
{
	return m_pA;
}


memGuard & memGuard::operator= (const memGuard &R)
{
	if (this != &R)
	{
		this->~memGuard();

		m_pA = R.m_pA;
		m_pCounter = R.m_pCounter;
		if (m_pA != 0)
			(*m_pCounter)++;

		cout << "memGuard::operator= for this " << this << " and R = " << &R << endl;
	}
	return *this;
}

/*

it's a good practice to return value or error code from function by saving this value-code
in extra variable like nRet

int func()
{
	int nRet = 0;
	if (2 > 0)
	{
		................
		................
		nRet = 23;
	}
	return nRet;
}
*/

