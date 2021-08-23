
#include "WallObject.h"
WallTitle::WallTitle()
{
}

WallTitle::~WallTitle()
{
}


WallObject::WallObject()
{
}

WallObject::~WallObject()
{
}

void WallObject::LoadWalls(const char* fileName, SDL_Renderer* screen)
{
	FILE* fp = NULL;
	fopen_s(&fp, fileName, "rb");
	if (fp == NULL)
		return;

	for (int i = 0; i < MAX_MAP_Y; i++)
	{
		for (int j = 0; j < MAX_MAP_X; j++)
		{
			fscanf_s(fp,"%d", &wall_map_.title_[i][j]);
		}

	}
	fclose(fp);

	char file_img[20];
	for (int i = 0; i < 10; i++)
	{
		sprintf_s(file_img, "wall_map/%d.png", i);
		fopen_s(&fp, file_img, "rb");
		if (fp == NULL)
			continue;
		fclose(fp);

		wall_title_[i].LoadImg(file_img, screen);
	}
}

void WallObject::RenderWalls(SDL_Renderer* des)
{
	
	for (int i = 0; i < MAX_MAP_Y; i++)
	{
		for (int j = 0; j < MAX_MAP_X; j++)
		{
			int val = wall_map_.title_[i][j];
			if (val > 0)
			{
				wall_title_[val].SetRect(20 + j * wall_title_[val].GetRect().w, 20 + i * wall_title_[val].GetRect().h);
				wall_title_[val].Render(des);
			}
		}

	}

}

