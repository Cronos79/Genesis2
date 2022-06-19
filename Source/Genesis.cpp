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
	float dt = DeltaTime->Mark() * 1000;

	bool aDown = false;
	if (_window->kbd.KeyIsPressed('A'))
	{
		aDown = true;
	}
	else
	{
		aDown = false;
	}

	if (_window->mouse.RightIsPressed())
	{
		_window->Gfx().camera.AdjustRotation((float)_window->mouse.GetPosY() * 0.001f, (float)_window->mouse.GetPosX() * 0.001f, 0); // #TODO: Mouse is all over the place
	}

	const float cameraSpeed = 0.006f;

	if (_window->kbd.KeyIsPressed('W'))
	{
		_window->Gfx().camera.AdjustPosition(_window->Gfx().camera.GetForwardVector() * cameraSpeed * dt);
	}
	if (_window->kbd.KeyIsPressed('S'))
	{
		_window->Gfx().camera.AdjustPosition(_window->Gfx().camera.GetBackwardVector() * cameraSpeed * dt);
	}
	if (_window->kbd.KeyIsPressed('A'))
	{
		_window->Gfx().camera.AdjustPosition(_window->Gfx().camera.GetLeftVector() * cameraSpeed * dt);
	}
	if (_window->kbd.KeyIsPressed('D'))
	{
		_window->Gfx().camera.AdjustPosition(_window->Gfx().camera.GetRightVector() * cameraSpeed * dt);
	}
	if (_window->kbd.KeyIsPressed(VK_SPACE))
	{
		_window->Gfx().camera.AdjustPosition(0.0f, cameraSpeed * dt, 0.0f);
	}
	if (_window->kbd.KeyIsPressed('Z'))
	{
		_window->Gfx().camera.AdjustPosition(0.0f, -cameraSpeed * dt, 0.0f);
	}
}

void Genesis::Render()
{
	_window->Gfx().RenderFrame();
}

void Genesis::UpdateSound()
{

}
