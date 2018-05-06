// SharedPointer.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <memory>
#include "A.h"
#include "memguard.h"
#include <crtdbg.h>

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
	}
	if (_CrtDumpMemoryLeaks())
		cout << "mem LEAKS!" << endl;
	else
		cout << "mem OK!" << endl;

    return 0;
}

