#pragma once
#include "itemProj.h"

class iterattor
{
public:
    iterattor(){}
    virtual ~iterattor(){}
    virtual void First() = 0;
    virtual void Next() = 0;
    virtual bool IsDone() = 0;
    virtual ObjectItem CurrentItem() = 0;
};

class entityIterattor :public iterattor {
public:
    entityIterattor(entityItem* _item);

    void First();
    void Next();
    bool IsDone();
    ObjectItem CurrentItem();
private:
    entityItem* m_item;
    int m_index;
};