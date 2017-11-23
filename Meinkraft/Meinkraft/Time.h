#pragma once
#include "System.h"

namespace Engine
{
	class Time
		:	public System
	{
	public:
		Time();
		static double time;
		static double delta;
		void OnNotify(MSG _msg) override;
		void Update();
		~Time();
	};
}

