
#include "BaseObject.h"

BaseObject::BaseObject()
{
	p_object_ = NULL;
	rect_.x = rect_.y = rect_.w = rect_. h= 0;
}

BaseObject::~BaseObject()
{
	Free();
}

bool BaseObject::LoadImg(std::string path, SDL_Renderer* screen)
{
	SDL_Texture* texture = NULL;
	SDL_Surface* surface = IMG_Load(path.c_str());
	if (surface == NULL)
		return false;
	

	//COLOR_KEY
	//SDL_SetColorKey(surface, SDL_TRUE, SDL_MapRGB(surface->format, COLOR_KEY_R, COLOR_KEY_G, COLOR_KEY_B));
	//


	texture = SDL_CreateTextureFromSurface(screen, surface);
	if (texture == NULL)
		return false;
	
	rect_.w = surface->w;
	rect_.h = surface->h;
	SDL_FreeSurface(surface);
	p_object_ = texture;

	return p_object_ != NULL;
}

void BaseObject::Render(SDL_Renderer* des, SDL_Rect* clip)
{
	SDL_Rect renderQuad = { rect_.x, rect_.y, rect_.w,rect_.h }; 
	SDL_RenderCopy(des, p_object_, clip, &renderQuad);
}

void BaseObject::Free()
{
	if (p_object_ == NULL)
		return;
	SDL_DestroyTexture(p_object_);
	p_object_ = NULL;
	rect_.w = rect_.h = 0;
}
