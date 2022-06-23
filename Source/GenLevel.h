/* ========================================================================
   $File: $
   $Date: $
   $Revision: $
   $Creator: Matt Brock $
   $Notice: (C) Copyright 2022 by CronoGames, Inc. All Rights Reserved. $
   ======================================================================== */
#pragma once
#include "GenAssetMng.h"
#include <string>
class GenLevel
{
public:
	GenLevel(GenGraphics* gfx);
	bool LoadLevel(std::string name);	
	GenAssetMng* assetMng;
private:	
	bool assestMngEnabled = false;
	bool InitAssetMng(GenGraphics* gfx);
	std::string levelName;
};

