// SharedPointer.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <memory>
#include "A.h"
#include "memguard.h"
#include "memGuardTemplate.hpp"
#include <crtdbg.h>
#include "Treangle.h"

using namespace std;

int main()
{
	cout << "Hello World!" << endl;
	/*
	A *pA = new A(2);
	std::shared_ptr<A> sh(pA);
	std::shared_ptr<A> sh2(sh);
	std::shared_ptr<A> sh3;

	sh3 = sh2;
	sh->Show();
	sh2->Show();
	sh3->Show();

	A *pA2 = new A(9);
	std::shared_ptr<A> sh_(pA2);
	std::shared_ptr<A> sh2_(sh_);
	std::shared_ptr<A> sh3_;
	sh3_ = sh2_;
	sh_->Show();
	sh2_->Show();
	sh3_->Show();
	*/
	{
		A *pA = new A(5);
		memGuard memG1(pA);
		memGuard memG2(memG1);
	
	    memGuard memG3;

		memG3 = memG2;
		memG1->Show();
		memG2->Show();
		memG3->Show();
		
		// test template shared pointer class
		Treangle * pTR1 = new Treangle(8, 12);
		memGuardT  <Treangle> memGT1(pTR1);
		memGuardT  <Treangle> memGT2(memGT1);
		memGuardT  <Treangle> memGT3;
	

		memGT1->Show();
		memGT2->Show();
		memGT3->Show();  // in this line we call the show function for member-pointer(Treangle) memGuardT's class,
		//whose value is zero! 
		//so... for check this situation, we must check in Show function
		//if (this == 0) then break function by return, else we show the shape
		
		memGT3 = memGT2;
		memGT3->Show();
	}
	if (_CrtDumpMemoryLeaks())
		cout << "mem LEAKS!" << endl;
	else
		cout << "mem OK!" << endl;

    return 0;
}

