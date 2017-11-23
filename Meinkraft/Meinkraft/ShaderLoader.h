#pragma once
#include <GL/glew.h>
#include <string>
namespace Loader
{
	GLuint LoadShaders(const std::string& vertexShader, const std::string& fragmentShader);
}

