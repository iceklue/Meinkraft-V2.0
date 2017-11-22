#include "stdafx.h"
#include "Display.h"
#include "GL/glew.h"


Display::Display(char* title)
	:	TITLE("Display: " + std::string(title)), System(TITLE)
{
	if (Initialize())
		system_ready = true;
}

void Display::OnNotify(MSG _msg)
{
	switch (_msg.type)
	{
	case MSG_UPDATE:
		Refresh();
		break;
	case MSG_QUIT:
		Close();
		System::isRunning = false;
		break;
	default:
		break;
	}
}


Display::~Display()
{
}

SDL_Window& Display::GetWindow() const
{
	return *window;
}

bool Display::IsOpen() const
{
	return window != nullptr;
}


bool Display::Initialize()
{
	if (SDL_Init(SDL_INIT_EVERYTHING) < 0)
	{
		printf("SDL could not be initialized! SDL_Error: %s\n", SDL_GetError());
		return false;
	}

	// Create window
	window = SDL_CreateWindow
	(TITLE.c_str(), SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, WIDTH, HEIGHT, SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE | SDL_WINDOW_OPENGL);

	if (window == nullptr)
	{
		printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
		return false;
	}

	//Create surface
	screen = SDL_GetWindowSurface(window);

	// Create our opengl context and attach it to our window
	windowContext = SDL_GL_CreateContext(window);
	SetOpenGLAttributes();

	// Init GLEW
	GLenum error = glewInit();
	if (error == GLEW_OK)
	{
		printf("GLEW Status : %s\n", glewGetErrorString(error));
		printf("GLEW Version : %s\n", glewGetString(GLEW_VERSION));
	}
	else
	{
		printf("GLEW Status : %s\n", glewGetErrorString(error));
		return false;
	}
	glViewport(0, 0, WIDTH, HEIGHT);
	return true;
}

void Display::Resize(int _w, int _h)
{
	WIDTH = _w;
	HEIGHT = _h;
	glViewport(0, 0, _w, _h);
	SDL_SetWindowSize(window, _w, _h);
}

void Display::ToggleFullscreen() const
{
	bool IsFullscreen = SDL_GetWindowFlags(window) & SDL_WINDOW_FULLSCREEN;
	SDL_SetWindowFullscreen(window, IsFullscreen ? 0 : SDL_WINDOW_FULLSCREEN);
	SDL_ShowCursor(IsFullscreen);
}

void Display::Refresh() const
{
	SDL_GL_SwapWindow(window);
	glClearColor(0, 0, 0, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void Display::Close()
{
	SDL_GL_DeleteContext(windowContext);
	SDL_DestroyWindow(window);
	window = nullptr;
}

void Display::SetOpenGLAttributes()
{
	// SDL_GL_CONTEXT_CORE disables deprecated funtions
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);

	// 3.2 is mostly modern OpenGL, the majority of video cards is able to run this
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 2);

	// Turn on double buffering with a 24bit Z buffer.
	SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);

	// Print GL version
	int value = 0;
	SDL_GL_GetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, &value);
	std::cout << "GL Version : " << value << '.';
	SDL_GL_GetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, &value);
	std::cout << value << std::endl;
}