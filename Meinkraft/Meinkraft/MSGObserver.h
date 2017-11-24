#pragma once
#include "MSG.h"
#include "MSGSubject.h"


class MSGObserver
{
public:
	virtual void OnNotify(MSG _msg) = 0;
	MSGSubject* m_subject = nullptr;
};

