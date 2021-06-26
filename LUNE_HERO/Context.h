#ifndef _CONTEXT
#define _CONTEXT


#include <./SDL.h>
#include "Class.h"

class Context :public Class
{

private:

	SDL_Window* window;
	SDL_GLContext context;

public:

	Context();
	Context(SDL_Window* window, SDL_GLContext context);

	SDL_Window*   GetWindow() const;
	SDL_GLContext GetGLContext() const;

	inline void MakeCurrent() const;
};


#endif 