#pragma once
#include <list>

typedef unsigned int ObjectItem;

class iterattor;
class item
{
public:
	~item() {}
	virtual iterattor* createIterattor() = 0;
	virtual ObjectItem getItem(const int index) = 0;
	virtual int queryListCount() = 0;
};

class entityItem
{
public:
	entityItem();
	~entityItem();

	iterattor* createIterattor();

	ObjectItem getItem(const int index);
	int queryListCount();

private:
	ObjectItem m_itemLst[4];
};
