/* ========================================================================
   $File: $
   $Date: $
   $Revision: $
   $Creator: Matt Brock $
   $Notice: (C) Copyright 2022 by CronoGames, Inc. All Rights Reserved. $
   ======================================================================== */
#include "GenLevel.h"

GenLevel::GenLevel(GenGraphics* gfx)
{
	if (!assestMngEnabled)
	{
		InitAssetMng(gfx);
	}	
}

bool GenLevel::LoadLevel(std::string name)
{
	this->levelName = name;
	world = new GenWorld(this); // #TODO: load world from name.
	return true;
}

GenWorld* GenLevel::GetWorld()
{
	return world;
}

bool GenLevel::InitAssetMng(GenGraphics* gfx)
{
	assetMng = new GenAssetMng(gfx);
	assetMng->LoadAssets();
	assestMngEnabled = true;
	return true;
}
