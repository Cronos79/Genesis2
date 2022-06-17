/* ========================================================================
   $File: $
   $Date: $
   $Revision: $
   $Creator: Matt Brock $
   $Notice: (C) Copyright 2022 by CronoGames, Inc. All Rights Reserved. $
   ======================================================================== */
#include "GenApp.h"
#include <exception>
#include "GenLogger.h"

int CALLBACK WinMain(HINSTANCE instance, HINSTANCE, LPSTR, int)
{
	try
	{
		return GenApp{}.Start();
	}
	catch (const GenException& e)
	{
		GenLogger::Error(e.what());
	}
	catch (const std::exception& e)
	{
		GenLogger::Error(e.what());
	}
	catch (...)
	{
		GenLogger::Error("No details available");
	}
	return -1;
}
