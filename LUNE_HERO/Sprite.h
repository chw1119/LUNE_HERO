#pragma once

#include "Class.h"
#include "Shader.h"
#include "Context.h"

#include <./glew.h>

class Sprite : public Class
{
private:

	float xpos;
	float ypos;

	float xsize;
	float ysize;

	GLuint vertexBufferId;
	Shader shaderProgram;

	Context* context;


private:
	//initialize objects

	void InitGraphics();


public:

	Sprite();

	virtual void Bind();

	virtual void Process();

	virtual void Draw();

	void SetShaderProgram(Shader program);

};