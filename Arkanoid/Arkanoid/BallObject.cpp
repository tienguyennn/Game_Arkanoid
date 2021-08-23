
#include "BallObject.h"
#include "WallObject.h"
#include "math.h"
#include "time.h"


BallObject::BallObject()
{
	p_object_ = NULL;
	rect_.x = rect_.y = rect_.w = rect_.h = 0;

	x_val_ = y_val_ = 0;
}

BallObject::~BallObject()
{
}

void BallObject::HandleInputAction(SDL_Event events)
{
	if (events.type == SDL_KEYDOWN)
	{
		switch (events.key.keysym.sym)
		{
		case SDLK_SPACE:
			if (is_moved_ == false)
			{
				is_moved_ = true;
				srand((int)time(0));
				int angle = 50 + rand() % 90;
				while (80 < angle && angle < 100)
				{
					angle = 50 + rand() % 90;
				}

				double deg = -angle * PI / 180;
				x_val_ = (int)(cos(deg) * SPEED_BALL);
				y_val_ = (int)(sin(deg) * SPEED_BALL);
			}
			break;
		default:
			break;
		}
	}
}

//void BallObject::HandleBall(SDL_Rect rect_main_player, WALL* wall_map)
//{
//	if (is_moved_ == false)
//		return;
//
//
//	rect_.x += x_val_;
//	rect_.y += y_val_;
//
//	if (rect_.x <= FENCE_THINKNESS)
//	{
//		x_val_ = -x_val_;
//	}
//
//	if (rect_.x >= SCREEN_WIDTH - FENCE_THINKNESS - rect_.w)
//	{
//		x_val_ = -x_val_;
//	}
//
//	if (rect_.y <= FENCE_THINKNESS)
//	{
//		y_val_ = -y_val_;
//	}
//
//	if (rect_.y >= rect_main_player.y)
//	{
//		y_val_ = -y_val_;
//	}
//
//	if (rect_.y >= SCREEN_HEIGHT)
//	{
//		//is_moved_ = false;
//	}
//
//	if (SDLCommonFunction::CheckCollision(rect_main_player, { rect_.x, rect_.y + rect_main_player.h / 2, rect_.w, rect_.h }) == true)
//	{
//		y_val_ = -y_val_;
//	}
//
//	if (x_val_ < 0 && y_val_ < 0)
//	{
//		int x_check = (rect_.x - FENCE_THINKNESS + rect_.w / 2) / 48;
//		int y_check = (rect_.y - rect_.h - FENCE_THINKNESS) / 18 + 1;
//		//if (x_check < MAX_MAP_X && y_check < MAX_MAP_Y)
//		//{
//		//	if (wall_map->title_[y_check][x_check] != 0)
//		//	{
//		//		wall_map->title_[y_check][x_check] = 0;
//		//		if (rect_.x < ((x_check + 1) * 48 + 20))
//		//			y_val_ = -y_val_;
//		//		else
//		//			x_val_ = -x_val_;
//		//	}
//		//}
//		if (x_check < MAX_MAP_X && y_check < MAX_MAP_Y && x_check >= 0 && y_check >= 0)
//		{
//			if (wall_map->title_[y_check][x_check] != 0)
//			{
//				bool isCollision = false;
//				for (int i = x_check - 1; i <= x_check + 1; i++)
//				{
//					for (int j = y_check; j <= y_check + 2; j++)
//					{
//						if (SDLCommonFunction::CheckCollision(rect_, { 20 + x_check * 48, 20 + y_check * 18, 48,18 }));
//						{
//							wall_map->title_[j][i] = 0;
//							y_val_ = -y_val_;
//							isCollision = true;
//							break;
//						}
//					}
//					if (isCollision)
//						break;
//				}
//			}
//		}
//
//
//	}
//	else if (x_val_ > 0 && y_val_ < 0)
//	{
//		int x_check = (rect_.x - FENCE_THINKNESS) / 48;
//		int y_check = (rect_.y - rect_.h - FENCE_THINKNESS) / 18;
//		if (x_check < MAX_MAP_X && y_check < MAX_MAP_Y)
//		{
//			if (wall_map->title_[y_check][x_check] != 0)
//			{
//				wall_map->title_[y_check][x_check] = 0;
//				y_val_ = -y_val_;
//			}
//		}
//	}
//	else if (x_val_ < 0 && y_val_ > 0)
//	{
//		int x_check = (rect_.x - FENCE_THINKNESS) / 48;
//		int y_check = (rect_.y - FENCE_THINKNESS) / 18;
//		if (x_check < MAX_MAP_X && y_check < MAX_MAP_Y)
//		{
//			if (wall_map->title_[y_check][x_check] != 0)
//			{
//				wall_map->title_[y_check][x_check] = 0;
//				y_val_ = -y_val_;
//			}
//		}
//	}
//	else if (x_val_ > 0 && y_val_ > 0)
//	{
//		{
//			int x_check = (rect_.x - FENCE_THINKNESS) / 48;
//			int y_check = (rect_.y - FENCE_THINKNESS) / 18;
//			if (x_check < MAX_MAP_X && y_check < MAX_MAP_Y)
//			{
//				if (wall_map->title_[y_check][x_check] != 0)
//				{
//					wall_map->title_[y_check][x_check] = 0;
//					y_val_ = -y_val_;
//				}
//			}
//		}
//
//	}
//}

void BallObject::HandleBall(SDL_Rect rect_main_player, WALL* wall_map)
{
	if (is_moved_ == false)
		return;


	rect_.x += x_val_;
	rect_.y += y_val_;

	if (rect_.x <= FENCE_THINKNESS)
	{
		x_val_ = -x_val_;
	}

	if (rect_.x >= SCREEN_WIDTH - FENCE_THINKNESS - rect_.w)
	{
		x_val_ = -x_val_;
	}

	if (rect_.y <= FENCE_THINKNESS)
	{
		y_val_ = -y_val_;
	}

	if (rect_.y >= rect_main_player.y)
	{
		y_val_ = -y_val_;
	}

	if (rect_.y >= SCREEN_HEIGHT)
	{
		//is_moved_ = false;
	}

	if (SDLCommonFunction::CheckCollision(rect_main_player, { rect_.x, rect_.y + rect_main_player.h / 2, rect_.w, rect_.h }) == true)
	{
		y_val_ = -y_val_;
	}


	bool isCollision = false;
	for (int i = 0; i < MAX_MAP_Y; i++)
	{
		for (int j = 0; j < MAX_MAP_X; j++)
		{
			if (wall_map->title_[i][j] != 0)
			{
				if (SDLCommonFunction::CheckCollision(rect_, { FENCE_THINKNESS + j * 48, FENCE_THINKNESS + i * 18 , 48, 18 }) == true)
				{
					wall_map->title_[i][j] = 0;
					isCollision = true;

					int x_before = rect_.x - x_val_;
					int y_before = rect_.y - y_val_;
					
					if (x_val_ < 0)
					{
						if (y_val_ < 0)
						{
							if (x_before < FENCE_THINKNESS + j * 48 + 48)
								y_val_ = -y_val_;
							if (y_before - rect_.h < FENCE_THINKNESS + i * 18)
								x_val_ = -x_val_;
						}
						else
						{
							if (x_before < FENCE_THINKNESS + j * 48 + 48)
								y_val_ = -y_val_;
							if (y_before > FENCE_THINKNESS + i * 18 - 18)
								x_val_ = -x_val_;
						}
						break;
					}
					else
					{
						if (y_val_ < 0)
						{
							if (x_before + rect_.w < FENCE_THINKNESS + j * 48)
								y_val_ = -y_val_;
							if (y_before - rect_.h < FENCE_THINKNESS + i * 18)
								x_val_ = -x_val_;
						}
						else
						{
							if (x_before + rect_.w > FENCE_THINKNESS + j * 48)
								y_val_ = -y_val_;
							if (y_before > FENCE_THINKNESS + i * 18 - 18)
								x_val_ = -x_val_;
						}
						break;
					}

				}
			}
		}
		if (isCollision)
			break;
	}
}
