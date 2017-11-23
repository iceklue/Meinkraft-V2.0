#include "stdafx.h"
#include "Input.h"

namespace Engine
{
	const Uint8* Input::keyboardState = nullptr;
	bool Input::keyUp[SDL_NUM_SCANCODES] = { false };
	bool Input::keyDown[SDL_NUM_SCANCODES] = { false };


	Input::Input()
		:System("Input")
	{
	}


	Input::~Input()
	{
	}

	void Input::OnNotify(MSG _msg)
	{
		if (_msg.type == MSG_UPDATE)
		{
			//Update events
			SDL_Event e;
			while (SDL_PollEvent(&e))
			{
				if (e.type == SDL_QUIT || (e.type == SDL_KEYDOWN && e.key.keysym.sym == SDLK_ESCAPE)) //Exit program
					m_subject->Notify(MSG(MSG_QUIT));																					//m_engine.SendMessage(Message(1, 0 ,(void*)new bool(true)));
				if (e.window.event == SDL_WINDOWEVENT_RESIZED)
				{
					int a[] = { e.window.data1, e.window.data2 };
					m_subject->Notify(MSG(MSG_RESIZE, &a));
				}
				UpdateEventState(e);
			}
			UpdateKeyState();
		}
	}

	void Input::UpdateKeyState()
	{
		keyboardState = SDL_GetKeyboardState(nullptr);
	}
	void Input::UpdateEventState(SDL_Event& e)
	{
		if (e.key.repeat == 0)
		{
			if (e.type == SDL_KEYDOWN)
			{
				keyDown[e.key.keysym.scancode] = true;
			}
			else if (e.type == SDL_KEYUP)
			{
				keyUp[e.key.keysym.scancode] = true;
				keyDown[e.key.keysym.scancode] = false;
			}
		}
	}

	bool Input::GetKeyHold(SDL_Keycode key)
	{
		if (keyboardState[SDL_GetScancodeFromKey(key)])
			return true;
		return false;
	}
	bool Input::GetKeyDown(SDL_Keycode key)
	{
		if (keyDown[SDL_GetScancodeFromKey(key)])
		{
			keyDown[SDL_GetScancodeFromKey(key)] = false;
			return true;
		}
		return false;
	}
	bool Input::GetKeyUp(SDL_Keycode key)
	{
		if (keyUp[SDL_GetScancodeFromKey(key)])
		{
			keyUp[SDL_GetScancodeFromKey(key)] = false;
			return true;
		}
		return false;
	}


}
