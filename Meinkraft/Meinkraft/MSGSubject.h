#pragma once
#include "MSG.h"

class IMSGObserver;

class MSGSubject
{
public:
	void Notify(MSG _msg, IMSGObserver* _to = nullptr);
	void Subscribe(IMSGObserver* _observer);
	~MSGSubject();
private:
	std::list<IMSGObserver*> m_observers;
};

