/* ========================================================================
   $File: $
   $Date: $
   $Revision: $
   $Creator: Matt Brock $
   $Notice: (C) Copyright 2022 by CronoGames, Inc. All Rights Reserved. $
   ======================================================================== */
#pragma once
#include "FunctionLib.h"
#include <string>
#include <windows.h>

class GenLogger
{
public:
	static void Info(std::string str);
	static void Info(HRESULT hr, std::string str);
	static void Error(std::string str);
	static void Error(HRESULT hr, std::string str);
};

