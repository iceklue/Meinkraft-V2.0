#pragma once
#include "IMSGObserver.h"

class System
	:	public IMSGObserver
{
public:
	static bool isRunning;

	System(std::string _name);
	virtual ~System() = 0;

	std::string system_name = "NONAME";
	bool system_ready = false;
};

