#include <Windows.h>
#include "itemProj.h"
#include "iterattor.h"


entityItem::entityItem()
{
    for (int i = 0; i < ARRAYSIZE(m_itemLst); i++) {
        m_itemLst[i] = i;
    }
}

entityItem::~entityItem()
{
}

iterattor* entityItem::createIterattor()
{
    return new entityIterattor(this);
}

int entityItem::queryListCount()
{
    return ARRAYSIZE(m_itemLst);
}

ObjectItem entityItem::getItem(const int index)
{
    if (index < ARRAYSIZE(m_itemLst)) {
        return m_itemLst[index];
    }
    else {
        return -1;
    }
}
