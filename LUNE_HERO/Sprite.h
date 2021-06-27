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

	float scale;

	float angle;

	GLuint vertexBufferId;
	GLuint indexBufferId;

	Context* context;
	Shader* shaderProgram;


private:
	//initialize objects

	virtual void InitGraphics(Shader* shader, Context* ctx);


public:

	Sprite();

	Sprite(float xpos, float ypos, float xsize, float ysize, float scale, float angle);
	Sprite(float xpos, float ypos, float xsize, float ysize, float scale, float angle, Shader* shader, Context* ctx);

	~Sprite();

	virtual void Bind();

	virtual void Process();

	virtual void Draw();

	void SetShaderProgram(Shader* program);

};