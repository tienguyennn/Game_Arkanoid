#pragma once

#include "CommonFunction.h"
#include "BallObject.h"

class WallTitle : public BaseObject
{
public:
	WallTitle();
	~WallTitle();

private:

};




class WallObject : public BaseObject
{
public:
	WallObject();
	~WallObject();

	void LoadWalls(const char* fileName, SDL_Renderer* screen);
	void RenderWalls(SDL_Renderer* des);

	WALL* GetWallMap() { return &wall_map_; }
	void SetWallMap(const int& x, const int& y) { wall_map_.title_[y][x] = 0; }

private:

	WALL wall_map_;
	WallTitle wall_title_[10];

};
