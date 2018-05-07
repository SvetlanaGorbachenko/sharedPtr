#pragma once

#include <iostream>
using namespace std;


template <class T>
class memGuardT
{
	T * m_pA;
	int * m_pCounter;

public:
	memGuardT(T *pA = 0):m_pA(pA)
	{
		m_pCounter = new int(0);
		cout << "memGuardT(T *pA) for " << this << " m_pA = " << m_pA << " *m_pCounter = " << *m_pCounter << endl;
	}
	memGuardT(const memGuardT &R)
	{
		if (this != &R)
		{
			m_pA = R.m_pA;
			m_pCounter = R.m_pCounter;
			if (m_pA != 0)
				++(*m_pCounter);
		}
		cout << "memGuardT copy constructor for " << this << " m_pA = " << m_pA << " *m_pCounter = " << *m_pCounter << endl;
	}
	~memGuardT()
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
		if (m_pCounter != 0)
			cout << "~memGuardT() for " << this << " *m_pCounter = " << *m_pCounter << " m_pA = " << m_pA << endl;
		else
			cout << "~memGuardT() for " << this << " m_pCounter = " << m_pCounter << " m_pA = " << m_pA << endl;
	}

	T * operator ->()
	{
		return m_pA;
	}
	memGuardT & operator= (const memGuardT &R)
	{
		if (this != &R)
		{
			this->~memGuardT();

			m_pA = R.m_pA;
			m_pCounter = R.m_pCounter;
			if (m_pA != 0)
				(*m_pCounter)++;

			cout << "memGuardT::operator= for this " << this << " and R = " << &R << endl;
		}
		return *this;
	}


};



