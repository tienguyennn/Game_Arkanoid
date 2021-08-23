#include "CommonFunction.h"
#include "BaseObject.h"
#include "ImpTimer.h"
#include "MainObject.h"
#include "BallObject.h"
#include "WallObject.h"


#undef main

BaseObject g_background;
MainObject main_player;
ImpTimer fps_timer;
BallObject ball;




bool InitData()
{
	int ret = SDL_Init(SDL_INIT_VIDEO);
	if (ret < 0)
		return false;
	SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "1");

	g_windows = SDL_CreateWindow("ARKANOID", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
	if (g_windows == NULL)
		return false;

	g_screen = SDL_CreateRenderer(g_windows, -1, SDL_RENDERER_ACCELERATED);
	if (g_screen == NULL)
		return false;

	SDL_SetRenderDrawColor(g_screen, RENDER_DRAW_COLOR, RENDER_DRAW_COLOR, RENDER_DRAW_COLOR, RENDER_DRAW_COLOR);
	int imgFlags = IMG_INIT_PNG;
	if (!(IMG_Init(imgFlags) && imgFlags))
		return false;

	return true;
}

void Close()
{
	g_background.Free();

	SDL_DestroyRenderer(g_screen);
	g_screen = NULL;

	SDL_DestroyWindow(g_windows);
	g_windows = NULL;

	IMG_Quit();
	SDL_Quit();
}


int main(int argc, char* argv[])
{
	if (InitData() == false)
		return -1;

	if (g_background.LoadImg(g_name_background, g_screen) == false)
		return -1;

	if (main_player.LoadImg(g_name_main_player, g_screen) == false)
		return -1;
	main_player.SetRect(240, 680);

	if (ball.LoadImg(g_name_ball, g_screen) == false)
		return -1;

	WallObject walls;
	walls.LoadWalls("wall_map/wall1.dat",g_screen);

	WALL* wall_map = walls.GetWallMap();


	bool isQuit = false;
	while (!isQuit)
	{
		fps_timer.Start();
		while (SDL_PollEvent(&g_event) != 0)
		{
			if (g_event.type == SDL_QUIT)
			{
				isQuit = true;
			}
			main_player.HandleInputAction(g_event);
			ball.HandleInputAction(g_event);
		}

		SDL_SetRenderDrawColor(g_screen, RENDER_DRAW_COLOR, RENDER_DRAW_COLOR, RENDER_DRAW_COLOR, RENDER_DRAW_COLOR);
		SDL_RenderClear(g_screen);

		g_background.Render(g_screen);
		main_player.HandleMove();
		main_player.Render(g_screen);


		if (ball.GetIsMoved() == false)
			ball.SetRect(main_player.GetRect().x + main_player.GetRect().w / 2 - ball.GetRect().w / 2, main_player.GetRect().y - main_player.GetRect().h);

		ball.HandleBall(main_player.GetRect(), wall_map);
		ball.Render(g_screen);

		walls.RenderWalls(g_screen);

		SDL_RenderPresent(g_screen);

		//FPS
		int real_imp_time = fps_timer.GetTicks();
		int time_one_frame = 1000 / FRAME_PER_SECOND;
		if (real_imp_time < time_one_frame)
		{
			SDL_Delay(time_one_frame - real_imp_time);
		}

	}

		
	Close();
	return 0;
}

