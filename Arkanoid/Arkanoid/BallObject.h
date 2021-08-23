#pragma once

#include "BaseObject.h"

class BallObject : public BaseObject
{
public:
	BallObject();
	~BallObject();
		
	void HandleInputAction(SDL_Event events);
	void HandleBall(SDL_Rect rect_main_player, WALL* wall_map);

	void SetIsMoved(bool isMoved) { is_moved_ = isMoved; }
	bool GetIsMoved() const { return is_moved_; }

private:
	int x_val_;
	int y_val_;

	bool is_moved_;
};

