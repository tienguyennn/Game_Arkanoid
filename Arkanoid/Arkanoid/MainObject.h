#pragma once

#include "CommonFunction.h"
#include "BaseObject.h"

class MainObject : public BaseObject
{
public:
	MainObject();
	~MainObject();

	void HandleInputAction(SDL_Event events);
	void HandleMove();

private:
	int x_val_;
	int y_val_;

};

