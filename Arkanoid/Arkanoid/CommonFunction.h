#pragma once

#include <Windows.h>
#include <string>
#include <vector>
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_mixer.h>
#include <SDL_ttf.h>

static SDL_Window* g_windows = NULL;
static SDL_Renderer* g_screen = NULL;
static SDL_Event g_event;



const int SCREEN_WIDTH = 520;
const int SCREEN_HEIGHT = 800;
const int FENCE_THINKNESS = 20;

const int FRAME_PER_SECOND = 10;

const int COLOR_KEY_R = 167;
const int COLOR_KEY_G = 175;
const int COLOR_KEY_B = 180;
const int RENDER_DRAW_COLOR = 0xff;

const int SPEED_MAIN_OBJECT = 10;

const int SPEED_BALL = 15;
const double PI = 3.14159265359;

const int MAX_MAP_X = 10;
const int MAX_MAP_Y = 15;



static char g_name_background[] = { "images/background.png" };
static char g_name_main_player[] = { "images/main_player.png" };
static char g_name_ball[] = { "images/red_ball.png" };


struct WALL
{
	int title_[MAX_MAP_Y][MAX_MAP_X];
	int type_reward_;

};

//enum COLLISION
//{
//	NON= 0,
//	LEFT = 1,
//	RIGHT = 2,
//	TOP  = 3,
//	BOTTOM = 4,
//
//};


namespace SDLCommonFunction
{
	bool CheckCollision(const SDL_Rect& object1, const SDL_Rect& object2);
}


