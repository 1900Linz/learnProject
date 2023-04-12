
#include <iostream>
#include "subject.h"

int main()
{
	subject _s;

	auto personA = new aObserver(&_s);
	auto personB = new bObserver(&_s);
	auto personC = new cObserver(&_s);

	_s.setState(111);
	_s.setState(0);
}

