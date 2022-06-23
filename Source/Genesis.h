/* ========================================================================
   $File: $
   $Date: $
   $Revision: $
   $Creator: Matt Brock $
   $Notice: (C) Copyright 2022 by CronoGames, Inc. All Rights Reserved. $
   ======================================================================== */
#pragma once
#include "GenTimer.h"
#include "GenWindow.h"
#include "GenLevel.h"
class Genesis
{
public:
	Genesis(GenWindow* window);
	void Start();
	void Update();
	void Render();
	void UpdateSound();	
private:
	void InputHandler(float dt);
	void ImGuiHandler();
	GenTimer* DeltaTime;
	GenWindow* _window;
	GenLevel* currentLevel;
};

