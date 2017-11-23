#include "stdafx.h"
#include "Application.h"
#include <SDL.h>
#include "System.h"
#include "Display.h"
#include "Time.h"
#include <thread>
#include "Input.h"


Application::Application()
{
	if (!CreateSystem(new Engine::Time()))
		System::isRunning = false;
	if (!CreateSystem(new Engine::Input()))
		System::isRunning = false;
	if (!CreateSystem(new Engine::Display("Meinkraft")))
		System::isRunning = false;
	//if(!CreateSystem())
}

void Application::Loop()
{
	while(System::isRunning)
	{
		m_MSGHub.Notify(MSG(MSG_UPDATE));
		m_MSGHub.Notify(MSG(MSG_RENDER));
	}
	SDL_Quit();
}


Application::~Application()
{
	for (unsigned int i = 0; i < m_systems.size(); i--)
	{
		delete m_systems.back();
		m_systems.pop_back();
	}
}

bool Application::CreateSystem(System* _system)
{
	if (_system == nullptr && !_system->system_ready)
		return false;
	m_systems.push_back(_system);
	m_MSGHub.Subscribe(_system);
	return true;
}
