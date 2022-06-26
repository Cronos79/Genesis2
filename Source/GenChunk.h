
/* ========================================================================
   $File: $
   $Date: $
   $Revision: $
   $Creator: Matt Brock $
   $Notice: (C) Copyright 2022 by CronoGames, Inc. All Rights Reserved. $
   ======================================================================== */#pragma once
#include "GameObject.h"
#include <vector>
#include "GenTile.h"
#include "GenLevel.h"
class GenChunk : public GameObject
{
public:
	void InitChunk(GenLevel* currentLevel);	
	void DrawChunk();
private:
	void AddTile(GenTile* tile);
	void DrawTile(GenTile* tile);
	std::vector<GenTile*> tiles;
	GenLevel* currentLevel;
};

