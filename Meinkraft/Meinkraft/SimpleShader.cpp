#include "stdafx.h"
#include "SimpleShader.h"

SimpleShader::SimpleShader(const std::string& VERTEX_FILE, const std::string& FRAGMENT_FILE)
	: Shader(VERTEX_FILE, FRAGMENT_FILE)
{
	GetUniforms();
}

void SimpleShader::BindAttributes()
{
	BindAttribute(0, "inPosition");
	BindAttribute(1, "inColor");
}

void SimpleShader::GetUniforms()
{
	UseProgram();
	uLocTime = glGetUniformLocation(m_programID, "time");
	uLocPosOffset = glGetUniformLocation(m_programID, "posOffset");
}

