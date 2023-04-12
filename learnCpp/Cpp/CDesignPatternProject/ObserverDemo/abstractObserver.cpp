#include "abstractObserver.h"
#include "subject.h"


aObserver::aObserver(subject* val)
{
	mSubject = val;
	mSubject->attach(this);
}

void aObserver::update()
{
	std::cout << "A " << mSubject->getState();
	std::cout << std::endl;
}


bObserver::bObserver(subject* val)
{
	mSubject = val;
	mSubject->attach(this);
}

void bObserver::update()
{
	std::cout << "B " << mSubject->getState();
	std::cout << std::endl;
}


cObserver::cObserver(subject* val)
{
	mSubject = val;
	mSubject->attach(this);
}

void cObserver::update()
{
	std::cout << "C " << mSubject->getState();
	std::cout << std::endl;
}
