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

	const float cameraSpeed = 0.006f;	

	_window->mouse.EnableRaw();
	if (_window->mouse.RightIsPressed())
	{
		auto raw = _window->mouse.ReadRawDelta();
		if (_window->mouse.RawEnabled() && raw)
		{
			_window->Gfx().camera.AdjustRotation((float)raw->y * 0.01f, (float)raw->x * 0.01f, 0);
		}
		else
		{
			float mposX = (float)_window->mouse.GetPosX() - 400.0f;
			float mposY = (float)_window->mouse.GetPosY() - 300.0f;
			float x = 0.0f;
			float y = 0.0f;
			x = -(float)(mposX * cameraSpeed * dt) / 8.0f;
			y = -(float)(mposY * cameraSpeed * dt) / 8.0f;
			_window->Gfx().camera.AdjustRotation(y * 0.01f, x * 0.01f, 0); // #TODO: Mouse is all over the place	
		}
	}

	_window->Gfx().gameObject.AdjustRotation(0.0f, 0.001f * dt, 0.0f);

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
	if (_window->kbd.KeyIsPressed('C'))
	{
		XMVECTOR lightPosition = _window->Gfx().camera.GetPositionVector();
		lightPosition += _window->Gfx().camera.GetForwardVector();
		_window->Gfx().light.SetPosition(lightPosition);
		_window->Gfx().light.SetRotation(_window->Gfx().camera.GetRotationFloat3());
	}
}

void Genesis::Render()
{
	_window->Gfx().RenderFrame();
}

void Genesis::UpdateSound()
{

}
