#pragma once
#include <SDL.h>

class RawModel;

class Renderer
{
public:
	Renderer(SDL_Window& window);
	void Render(RawModel model);
private:
	SDL_Window& boundWindow;
};

