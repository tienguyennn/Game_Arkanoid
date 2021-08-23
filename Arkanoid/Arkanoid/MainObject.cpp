#include "MainObject.h"

MainObject::MainObject()
{
	p_object_ = NULL;
	rect_.x = rect_.y = rect_.w = rect_.h = 0;

	x_val_ = y_val_ = 0;
}

MainObject::~MainObject()
{

}

void MainObject::HandleInputAction(SDL_Event events)
{
	if (events.type == SDL_KEYDOWN)
	{
		switch (events.key.keysym.sym)
		{
		case SDLK_LEFT:
			x_val_ = -SPEED_MAIN_OBJECT;
			break;
		case SDLK_RIGHT:
			x_val_ = SPEED_MAIN_OBJECT;
			break;

		default:
			break;
		}
	}
	else if (events.type == SDL_KEYUP)
	{
		switch (events.key.keysym.sym)
		{
		case SDLK_LEFT:
			if (x_val_ == -SPEED_MAIN_OBJECT)
				x_val_ = 0;
			break;
		case SDLK_RIGHT:
			if (x_val_ == SPEED_MAIN_OBJECT)
				x_val_ = 0;
			break;


		default:
			break;
		}
	}

}

void MainObject::HandleMove()
{
	rect_.x += x_val_;
	if (x_val_ < 0)
	{
		if (rect_.x  < FENCE_THINKNESS)
		{
			rect_.x = FENCE_THINKNESS;
		}
	}
	else if(x_val_ > 0)
	{
		if (rect_.x > SCREEN_WIDTH - FENCE_THINKNESS - rect_.w)
		{
			rect_.x = SCREEN_WIDTH - FENCE_THINKNESS - rect_.w;
		}
	}
}
