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
#include "GenMacros.h"

int CALLBACK WinMain(HINSTANCE instance, HINSTANCE, LPSTR, int)
{	
	HRESULT hr = CoInitialize(NULL);
	if (FAILED(hr))
	{
		GenLogger::Error(hr, "Failed to call CoInitialize.");
		return -1;
	}

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
