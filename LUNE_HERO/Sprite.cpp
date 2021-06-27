#include "Sprite.h"

//Shader standardShader("./resource/shader/vertex/vStdShader.glsl", "./resource/shader/fragment/fStdShader.glsl");

void Sprite::InitGraphics(Shader* shader, Context* ctx)
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

	glGenBuffers(1, &vertexBufferId);

	glBindBuffer(GL_VERTEX_ARRAY, vertexBufferId);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertexData), vertexData, GL_DYNAMIC_DRAW);

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);

	glGenBuffers(1, &indexBufferId);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, indexBufferId);

	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indexData),indexData,GL_DYNAMIC_DRAW);

	shaderProgram = shader;

	context = ctx;
	
	//glBindAttribLocation(shaderProgram.ID, 0, "aPos");

}

Sprite::Sprite() : xpos(0.f), ypos(0.f), xsize(10.f), ysize(10.f), scale(1.0f), angle(0.f)
{
	InitGraphics(nullptr,nullptr);
}

Sprite::Sprite(float _xpos, float _ypos, float _xsize, float _ysize, float _scale, float _angle)
	: xpos(0.f), ypos(0.f), xsize(10.f), ysize(10.f), scale(1.0f), angle(0.f)
{
	InitGraphics(nullptr,nullptr);
}

Sprite::~Sprite()
{
	//glDeleteBuffers(2, &vertexBufferId);
}

void Sprite::Bind()
{
	glBindBuffer(GL_ARRAY_BUFFER, vertexBufferId);

	if (shaderProgram != nullptr)
	{
		shaderProgram->Use();
	}
}

void Sprite::Process()
{

}

void Sprite::Draw()
{
	Bind();

	glEnableVertexAttribArray(0);
	glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
	glDisableVertexAttribArray(0);
}

void Sprite::SetShaderProgram(Shader* program)
{
	shaderProgram = program;
}
