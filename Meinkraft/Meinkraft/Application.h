#pragma once
#include "System.h"
#include "MSGSubject.h"
class Application
{
public:
	Application();

	void Loop();

	~Application();
private:
	std::vector<System*> m_systems;
	MSGSubject m_MSGHub;
	bool CreateSystem(System* _system);

};

