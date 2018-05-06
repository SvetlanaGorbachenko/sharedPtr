#pragma once
class A;

class memGuard
{
	A * m_pA;
	int * m_pCounter;

public:
	memGuard(A *pA = 0);
	memGuard(const memGuard &R);
	~memGuard();

	A * operator ->();
	memGuard & operator= (const memGuard &R);


};
