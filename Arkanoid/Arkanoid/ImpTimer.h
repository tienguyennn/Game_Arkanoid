#pragma once

#include "CommonFunction.h"

class ImpTimer
{
public:
	ImpTimer();
	~ImpTimer();

	void Start();
	void Stop();
	void Pause();
	void UnPause();

	int GetTicks();
	
	bool IsStarted() const { return is_started_; }
	bool IsPaused() const { return is_paused_; }

private:
	int start_tick_;
	int pause_tick_;

	bool is_paused_;
	bool is_started_;

};



