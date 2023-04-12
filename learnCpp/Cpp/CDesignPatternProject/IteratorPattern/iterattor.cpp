#include "iterattor.h"

entityIterattor::entityIterattor(entityItem* _item)
{
	m_item = _item;
	m_index = 0;
}

void entityIterattor::First()
{
	m_index = 0;
}

void entityIterattor::Next()
{
	m_index++;
	m_index %= 4;
}

bool entityIterattor::IsDone()
{
	return (m_index == m_item->queryListCount());
}

ObjectItem entityIterattor::CurrentItem()
{
	return m_item->getItem(m_index);
}
