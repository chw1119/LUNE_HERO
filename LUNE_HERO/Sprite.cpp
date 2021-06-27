#include "Sprite.h"

void Sprite::InitGraphics()
{
	glGenBuffers(1, &this->vertexBufferId);
	glBindBuffer(GL_VERTEX_ARRAY, this->vertexBufferId);

	const GLfloat vertexData[3 * 6] = 
	{
	
	};


	const GLuint indexData[4]       = 
	{
	
	};

}

Sprite::Sprite() : xpos(0.f), ypos(0.f), xsize(10.f), ysize(10.f)
{

}

void Sprite::Bind()
{
}

void Sprite::Process()
{
}

void Sprite::Draw()
{
}

void Sprite::SetShaderProgram(Shader program)
{
	shaderProgram = program;
}
