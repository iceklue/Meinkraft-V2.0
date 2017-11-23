#include "stdafx.h"
#include "Application.h"
#include <SDL.h>
#include "System.h"
#include "Display.h"
#include "Time.h"
#include <thread>
#include "Input.h"
#include "Renderer.h"
#include "ModelLoader.h"
#include "PrimitiveShapes.h"
#include "SimpleShader.h"

Engine::Display* dis;
Application::Application()
{
	if (!CreateSystem(new Engine::Time()))
		System::isRunning = false;
	if (!CreateSystem(new Engine::Input()))
		System::isRunning = false;
	if (!CreateSystem(new Engine::Display("Meinkraft")))
	{
		
		System::isRunning = false;
	}
		//if(!CreateSystem())
}

void Application::Loop()
{
	dis = reinterpret_cast<Engine::Display*>(m_systems[2]);
	Renderer renderer(dis->GetWindow());
	ModelLoader loader;
	RawModel model = PrimitiveShapes::Triangle(loader);
	SimpleShader shader;
	Vector3 offset(0,0,0);
	const int FPS = 244;
	//calculate the period
	double period = 1.0 / (double)FPS;
	period = period * 1000;
	int milliPeriod = (int)period;
	int sleep;
	Uint32 lastTick;
	Uint32 currentTick;
	while(System::isRunning)
	{
		lastTick = SDL_GetTicks();
		m_MSGHub.Notify(MSG(MSG_UPDATE));
		if (Engine::Input::GetKeyHold(SDLK_w))
			offset.y += 1 * Engine::Time::delta;
		if (Engine::Input::GetKeyHold(SDLK_s))
			offset.y -= 1 * Engine::Time::delta;
		if (Engine::Input::GetKeyHold(SDLK_d))
			offset.x += 1 * Engine::Time::delta;
		if (Engine::Input::GetKeyHold(SDLK_a))
			offset.x -= 1 * Engine::Time::delta;

		shader.UseProgram();
		shader.LoadVector3(shader.uLocPosOffset, offset);
		renderer.Render(model);
		shader.StopProgram();
		m_MSGHub.Notify(MSG(MSG_RENDER));
		currentTick = SDL_GetTicks();

		//wait the appropriate amount of time
		sleep = milliPeriod - (currentTick - lastTick);
		if (sleep < 0) { sleep = 0; }
		SDL_Delay(sleep);

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
