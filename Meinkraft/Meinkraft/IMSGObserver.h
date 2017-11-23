#pragma once
#include "MSG.h"
#include "MSGSubject.h"


class IMSGObserver
{
public:
	virtual void OnNotify(MSG _msg) = 0;
	MSGSubject* m_subject = nullptr;
};

