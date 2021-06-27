#include "Context.h"

Context::Context() : window(nullptr), context(nullptr)
{

}

Context::Context(SDL_Window* _window, SDL_GLContext _context) : window(_window), context(_context)
{

}

SDL_Window* Context::GetWindow() const
{
	return window;
}

SDL_GLContext Context::GetGLContext() const
{
	return context;
}

void Context::SetWindow(SDL_Window* window)
{
	this->window = window;
}

void Context::SetGLContext(SDL_GLContext context)
{
	this->context = context;

	MakeCurrent();
}

inline void Context::MakeCurrent() const
{
	SDL_GL_MakeCurrent(window, context);

}
