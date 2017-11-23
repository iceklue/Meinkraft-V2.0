#include "stdafx.h"
#include "Time.h"
#include <SDL.h>
using namespace Engine;

double Time::delta = 0;
double Time::time = 0;

Time::Time()
	:System("Time")
{
}

void Time::Update()
{
	const auto tick_time = SDL_GetTicks() / 1000.0;
	delta = tick_time - time;
	time = tick_time;
}

void Time::OnNotify(MSG _msg)
{
	if (_msg.type == MSG_UPDATE)
	{
		Update();
	}
}

Time::~Time()
{
}
