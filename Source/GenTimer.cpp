/* ========================================================================
   $File: $
   $Date: $
   $Revision: $
   $Creator: Matt Brock $
   $Notice: (C) Copyright 2022 by CronoGames, Inc. All Rights Reserved. $
   ======================================================================== */
#include "GenTimer.h"

using namespace std::chrono;

GenTimer::GenTimer() noexcept
{
	last = steady_clock::now();
}

float GenTimer::Mark() noexcept
{
	const auto old = last;
	last = steady_clock::now();
	const duration<float> frameTime = last - old;
	return frameTime.count();
}

float GenTimer::Peek() const noexcept
{
	return duration<float>(steady_clock::now() - last).count();
}
