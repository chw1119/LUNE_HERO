#pragma once

#include <SDL.h>
#include "Context.h"

namespace Init 
{

	int SdlInit(Context& context)
	{
		bool success = true;
		char errorLogBuffer[512];

		if (SDL_Init(SDL_INIT_EVERYTHING) < 0)
		{
			std::cout << "에러 발생";

			SDL_LogError(0 ,errorLogBuffer);
			

			return -1;

		}

		auto window = SDL_CreateWindow("LUNE HEROS", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 800,600, SDL_WINDOW_SHOWN | SDL_WINDOW_OPENGL | SDL_WINDOW_RESIZABLE);

		auto gl = SDL_GL_CreateContext(window);

		auto renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

		context.SetWindow(window);

		context.SetGLContext(gl);

		SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
		SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 3);

		SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);

		SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
	
		if (renderer == NULL)
		{
			printf("OpenGL context could not be created! SDL Error: %s\n", SDL_GetError());
			success = false;
		}
		else
		{
			//Initialize GLEW
			glewExperimental = GL_TRUE;
			GLenum glewError = glewInit();
			if (glewError != GLEW_OK)
			{
				printf("Error initializing GLEW! %s\n", glewGetErrorString(glewError));
			}

			//Use Vsync
			if (SDL_GL_SetSwapInterval(1) < 0)
			{
				printf("Warning: Unable to set VSync! SDL Error: %s\n", SDL_GetError());
			}

			//Initialize OpenGL

		}


	}

	int GluInit()
	{
		bool success = true;
		GLenum error = GL_NO_ERROR;

		//Initialize Projection Matrix
		glMatrixMode(GL_PROJECTION);
		glLoadIdentity();

		//Check for error
		error = glGetError();
		if (error != GL_NO_ERROR)
		{
			printf("Error initializing OpenGL! %s\n", gluErrorString(error));
			success = false;
			return -1;
		}

		//Initialize Modelview Matrix
		glMatrixMode(GL_MODELVIEW);
		glLoadIdentity();

		//Check for error
		error = glGetError();
		if (error != GL_NO_ERROR)
		{
			printf("Error initializing OpenGL! %s\n", gluErrorString(error));
			success = false;

			return -1;
		}

		glClearColor(0.f, 0.f, 0.f, 1.f);
	}


	void Init(Context& context)
	{
		int r1 = SdlInit(context);

		if (r1 < 0)
		{
			std::cout << "SDL INITIALIZE FAILURE";

			exit(1);
		}

		int r2 = GluInit();

		if (r2 < 0)
		{
			std::cout << "GL INITIALIZE FAILURE";

			exit(1);
		}

	}

}

