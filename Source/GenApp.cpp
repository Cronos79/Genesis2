/* ========================================================================
   $File: $
   $Date: $
   $Revision: $
   $Creator: Matt Brock $
   $Notice: (C) Copyright 2022 by CronoGames, Inc. All Rights Reserved. $
   ======================================================================== */
#include "GenApp.h"


GenApp::GenApp()
	:
	wnd(1920, 1080, "Genesis2")
{
	wnd.SetTitle("Genesis");
	wnd.kbd.DisableAutorepeat();
	_game = new Genesis(&wnd);
}

int GenApp::Start()
{
	if (_game) { _game->Start(); }
	while (true)
	{
		// process all messages pending, but to not block for new messages
		if (const auto ecode = GenWindow::ProcessMessages())
		{
			// if return optional has value, means we're quitting so return exit code
			return *ecode;
		}
		DoFrame();
	}
}

void GenApp::DoFrame()
{
	if (!_game) { return; }
	_game->Update();
	_game->UpdateSound();
	_game->Render();
}
