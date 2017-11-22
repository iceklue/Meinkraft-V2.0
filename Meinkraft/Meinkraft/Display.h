#pragma once
#include "System.h"
#include "SDL.h"
class Display :
	public System
{
public:
	Display(char* title = "NONAME");
	void OnNotify(MSG _msg) override;
	~Display();

	SDL_Window& GetWindow() const;
	bool IsOpen() const;

private:
	bool Initialize();

	void Resize(int _w, int _h);
	void ToggleFullscreen() const;
	void Refresh() const;
	void Close();

	void SetOpenGLAttributes();

	int WIDTH = 1280;
	int HEIGHT = 720;
	const std::string TITLE;
	// Our SDL window
	SDL_Window* window;
	// Our SDL screen
	SDL_Surface* screen;
	// Our OpenGL context handle
	SDL_GLContext windowContext;
};

