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

inline void Context::MakeCurrent() const
{
	SDL_GL_MakeCurrent(window, context);
}
