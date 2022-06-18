/* ========================================================================
   $File: $
   $Date: $
   $Revision: $
   $Creator: Matt Brock $
   $Notice: (C) Copyright 2022 by CronoGames, Inc. All Rights Reserved. $
   ======================================================================== */
#include "Genesis.h"
#include "GenLogger.h"

Genesis::Genesis(GenWindow* window)
{
	_window = window;
	DeltaTime = new GenTimer();
}

void Genesis::Start()
{
	GenLogger::Info("Genesis starting");
}

void Genesis::Update()
{
	float dt = DeltaTime->Mark();

	bool aDown = false;
	if (_window->kbd.KeyIsPressed('A'))
	{
		aDown = true;
	}
	else
	{
		aDown = false;
	}
}

void Genesis::Render()
{
	_window->Gfx().RenderFrame();
}

void Genesis::UpdateSound()
{

}
