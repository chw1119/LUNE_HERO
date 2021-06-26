#pragma once


#define GAME_SETTING_VERTION_MAJOR 0
#define GAME_SETTING_VERTION_MINOR 1


#define SDL_MAIN_HANDLED

#include <glew.h>

#include <SDL.h>
#include <SDL_opengl.h>

#include <windows.h>

#include <iostream>
#include <chrono>
#include <future>

#include "Class.h"
#include "Sprite.h"

#pragma comment(lib, "Opengl32.lib")
#pragma comment(lib, "glu32.lib")
#pragma comment(lib, "glew32.lib")
#pragma comment(lib, "SDL2.lib")