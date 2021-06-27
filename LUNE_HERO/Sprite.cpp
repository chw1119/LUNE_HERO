#include "Sprite.h"

void Sprite::InitGraphics()
{
	const GLfloat vertexData[3 * 4] =
	{
		0.f,   ysize, 0.f,
		xsize, ysize, 0.f,
		xsize, 0.f,   0.f,
		0.f,   0.f,   0.f
	};

	const GLuint indexData[6] =
	{
		0,1,2,0,2,3
	};

	glGenBuffers(1, &this->vertexBufferId);
	glBindBuffer(GL_VERTEX_ARRAY, this->vertexBufferId);

	const GLuint indexData[6] =
	{
		0,1,2,0,2,3
	};

	glGenBuffers(1, &this->vertexBufferId);
	glBindBuffer(GL_ARRAY_BUFFER, this->vertexBufferId);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertexData), vertexData, GL_STATIC_DRAW);

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);
	glEnableVertexAttribArray(0);

	glGenBuffers(1, &indexBufferId);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, indexBufferId);

	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indexData),indexData,GL_STATIC_DRAW);

	shaderProgram = Shader("./resource/shader/vertex/vStdShader.glsl","./resource/shader/fragment/fStdShader.glsl");


}

Sprite::Sprite() : xpos(0.f), ypos(0.f), xsize(10.f), ysize(10.f), scale(1.0f), angle(0.f)
{
	InitGraphics();
}

Sprite::Sprite(float _xpos, float _ypos, float _xsize, float _ysize, float _scale, float _angle)
	: xpos(0.f), ypos(0.f), xsize(10.f), ysize(10.f), scale(1.0f), angle(0.f)
{
	InitGraphics();
}

void Sprite::Bind()
{
	glBindBuffer(GL_ARRAY_BUFFER, this->vertexBufferId);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, indexBufferId);

	shaderProgram.Use();
}

void Sprite::Process()
{

}

void Sprite::Draw()
{
	Bind();

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, indexBufferId);
}

void Sprite::SetShaderProgram(Shader program)
{
	shaderProgram = program;
}
