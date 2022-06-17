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
	wnd(800, 600, "Genesis2")
{
	wnd.SetTitle("Test");
}

int GenApp::Start()
{
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

}
