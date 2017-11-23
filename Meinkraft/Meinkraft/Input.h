#pragma once
#include "System.h"
#include <SDL.h>

namespace Engine
{
	class Input :
		public System
	{
	public:
		Input();
		~Input();
		void OnNotify(MSG _msg) override;

		static bool exit;

		static void UpdateKeyState();
		static void UpdateEventState(SDL_Event& e);
		static bool GetKeyHold(SDL_Keycode key);
		static bool GetKeyDown(SDL_Keycode key);
		static bool GetKeyDown();
		static bool GetKeyUp(SDL_Keycode key);
		static bool GetKeyUp();
	private:

		static const Uint8* keyboardState;
		static bool keyUp[SDL_NUM_SCANCODES];
		static bool keyDown[SDL_NUM_SCANCODES];
	};
}
