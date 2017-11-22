#include "stdafx.h"
#include "System.h"

bool System::isRunning = true;

System::System(std::string _name)
{
	system_name = _name;
}

System::~System()
{
	
}
