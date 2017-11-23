#pragma once
#include "Shader.h"
class SimpleShader :
	public Shader
{
public:
	SimpleShader(	const std::string& VERTEX_FILE = "SimpleShader",
			    	const std::string& FRAGMENT_FILE = "SimpleShader");

	GLuint uLocTime;
	GLuint uLocPosOffset;

protected:
	void BindAttributes() override;
	void GetUniforms() override;
};

