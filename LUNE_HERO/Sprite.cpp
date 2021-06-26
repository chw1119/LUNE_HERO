#include "Sprite.h"

void Sprite::InitGraphics()
{
	glGenBuffers(1, &this->vertexBufferId);

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
