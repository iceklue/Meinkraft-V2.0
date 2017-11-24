#pragma once
#include "MSG.h"

class MSGObserver;

class MSGSubject
{
public:
	void Notify(MSG _msg, MSGObserver* _to = nullptr);
	void Subscribe(MSGObserver* _observer);
	~MSGSubject();
private:
	std::list<MSGObserver*> m_observers;
};

