#include "Window.h"

Window::Window() : xPos(STD_WINDOW_XPOS), yPos(STD_WINDOW_YPOS), xSize(STD_WINDOW_XSIZE), ySize(STD_WINDOW_YSIZE), windowBitFlag(SDL_WINDOW_SHOWN | SDL_WINDOW_OPENGL | SDL_WINDOW_RESIZABLE)
{
	


}

Window::Window(int xpos, int ypos, int xsize, int ysize) : xPos(xpos), yPos(ypos), xSize(xsize), ySize(ysize), windowBitFlag(SDL_WINDOW_SHOWN | SDL_WINDOW_OPENGL | SDL_WINDOW_RESIZABLE)
{

}

Window::~Window()
{
	
}

void Window::SetWindowSize(int xsize, int ysize)
{
	xSize = xsize;
	ySize = ysize;

	SyncWindowDatas();
}

void Window::SetWidnowPos(int xpos, int ypos)
{
	xPos = xpos;
	yPos = ypos;

	SyncWindowDatas();
}

void Window::SetWindowBitFlag(int bitFlag)
{
	windowBitFlag = bitFlag;

	SyncWindowDatas();
}

void Window::SetWindowRefreshRate(int rate)
{
	refreshRate = rate;
}

void Window::SetContext(Context& context)
{
	this->context = context;

	SyncWindowDatas();
}

void Window::SyncWindowDatas()
{
	auto temp = SDL_DisplayMode();

	temp.w = xSize;
	temp.h = ySize;

	temp.refresh_rate = refreshRate;

	SDL_SetWindowDisplayMode(context.GetWindow(), &temp);

	SDL_SetWindowFullscreen(context.GetWindow(), windowBitFlag);

}

std::pair<int, int> Window::GetWindowSize()
{
	auto temp = std::pair<int, int>();

	temp.first = xSize;
	temp.second = ySize;

	return temp;
}

std::pair<int, int> Window::GetWindowPos()
{
	auto temp = std::pair<int, int>();

	temp.first = xPos;
	temp.second = yPos;

	return temp;
}

int Window::GetWindowBitFlag() const
{
	return windowBitFlag;

}

const Context& Window::GetContext() const
{
	return context;
}

int Window::GetNumVideoDisplays()
{
	return 0;
}
