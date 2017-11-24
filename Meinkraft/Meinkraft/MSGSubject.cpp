#include "stdafx.h"
#include "MSGSubject.h"
#include "MSGObserver.h"
#include "ListHelper.h"


void MSGSubject::Notify(MSG _msg, MSGObserver* _to)
{
	if (_to == nullptr)
	{
		for (unsigned int i = 0; i < m_observers.size(); i++)
		{
			ListHelper::GetElementAtIndex(m_observers, i)->OnNotify(_msg);
		}
	}
	else
	{
		if (!ListHelper::Contains(m_observers, _to))
			return;
		_to->OnNotify(_msg);
	}
	
}

void MSGSubject::Subscribe(MSGObserver* _observer)
{
	_observer->m_subject = this;
	m_observers.push_back(_observer);
}


MSGSubject::~MSGSubject()
{
}
