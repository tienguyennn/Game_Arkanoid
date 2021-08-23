
#include "ImpTimer.h"

ImpTimer::ImpTimer()
{
	start_tick_ = pause_tick_ = 0;
	is_paused_ = is_started_ = false;
}

ImpTimer::~ImpTimer()
{
}

void ImpTimer::Start()
{
	is_started_ = true;
	is_paused_ = false;
	
	start_tick_ = SDL_GetTicks();
}

void ImpTimer::Stop()
{
	is_started_ = false;
	is_paused_ = false;
}

void ImpTimer::Pause()
{
	if (is_started_ == true && is_paused_ == false)
	{
		is_paused_ = true;
		pause_tick_ = SDL_GetTicks() - start_tick_;
	}
}

void ImpTimer::UnPause()
{
	if (is_started_ == true && is_paused_ == true)
	{
		is_paused_ = false;
		start_tick_ = SDL_GetTicks() - pause_tick_;
		pause_tick_ = 0;
	}
}

int ImpTimer::GetTicks()
{
	if (is_started_ == true)
	{
		if (is_paused_ == true)
		{
			return pause_tick_;
		}
		else
		{
			return SDL_GetTicks() - start_tick_;
		}
	}
	return 0;
}
