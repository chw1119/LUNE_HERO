#ifndef _WINDOW

#define _WINDOW

#define STD_WINDOW_XPOS 0
#define STD_WINDOW_YPOS 0

#define STD_WINDOW_XSIZE 800
#define STD_WINDOW_YSIZE 600

#define STD_WIDNOW_REFRESH 60;



#include "Class.h"
#include "Context.h"

#include <utility>

#include <SDL.h>

class Window : public Class
{
private:

	int xPos;
	int yPos;

	int xSize;
	int ySize;

	int windowBitFlag;

	int refreshRate;

	Context context;
	

public:

	Window();
	Window(int xpos, int ypos, int xsize, int ysize); 

	~Window();


	void SetWindowSize(int xsize, int ysize);

	void SetWidnowPos(int xpos, int ypos);

	void SetWindowBitFlag(int BitFlag);

	void SetWindowRefreshRate(int rate);

	void SetContext(class Context& context);

	void SyncWindowDatas();


	std::pair<int, int> GetWindowSize();
	std::pair<int, int> GetWindowPos();

	int GetWindowBitFlag() const;
	const class Context& GetContext() const;



public:

	static int GetNumVideoDisplays();

};

#endif
