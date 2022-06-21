/* ========================================================================
   $File: $
   $Date: $
   $Revision: $
   $Creator: Matt Brock $
   $Notice: (C) Copyright 2022 by CronoGames, Inc. All Rights Reserved. $
   ======================================================================== */
#pragma once
#include "GenWindow.h"
#include "Genesis.h"

class GenApp
{
public:
	GenApp();
	// master frame / message loop
	int Start();
private:
	void DoFrame();
private:
	GenWindow wnd;
	Genesis* _game;
};

