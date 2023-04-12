#pragma once
#include <vector>
#include <iostream>
#include "abstractObserver.h"

class subject
{
public:
	int getState(){ return mState;}

	void setState(int);
	
	void attach(abstractObserver*);

	void notifyAllObersever();
private:
	int mState;
	std::vector<abstractObserver*> mObservers;
};

