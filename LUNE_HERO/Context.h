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

	void SetWindow(SDL_Window* window);
	void SetGLContext(SDL_GLContext context);

	inline void MakeCurrent() const;
};


#endif 