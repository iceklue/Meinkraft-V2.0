#pragma once
#include "MSG.h"

class MSGSubject;

class IMSGObserver
{
public:
	virtual void OnNotify(MSG _msg) = 0;
	MSGSubject* m_subject = nullptr;
};

