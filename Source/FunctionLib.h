/* ========================================================================
   $File: $
   $Date: $
   $Revision: $
   $Creator: Matt Brock $
   $Notice: (C) Copyright 2022 by CronoGames, Inc. All Rights Reserved. $
   ======================================================================== */
#pragma once
#include <string>
class FunctionLib
{
public:
	static std::wstring StringToWide(std::string str);
	static std::string GetDirectoryFromPath(const std::string& filepath);
	static std::string GetFileExtension(const std::string& filename);
};

