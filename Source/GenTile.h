/* ========================================================================
   $File: $
   $Date: $
   $Revision: $
   $Creator: Matt Brock $
   $Notice: (C) Copyright 2022 by CronoGames, Inc. All Rights Reserved. $
   ======================================================================== */
#pragma once
#include "GenGameObject.h"
class GenTile : public GenGameObject
{
public:
	GenTile();
	static float GetSize();
	std::string test = "default";
	float x;
	float y;
};

