#include "subject.h"

void subject::setState(int val)
{
	mState = val;
	notifyAllObersever();
}

void subject::attach(abstractObserver* p)
{
	mObservers.push_back(p);
}

void subject::notifyAllObersever()
{
	for(auto oBegin = mObservers.begin(); oBegin != mObservers.end(); oBegin++)
	{
		(*oBegin)->update();
	}
}
