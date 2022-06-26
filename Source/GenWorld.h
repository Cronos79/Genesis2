/* ========================================================================
   $File: $
   $Date: $
   $Revision: $
   $Creator: Matt Brock $
   $Notice: (C) Copyright 2022 by CronoGames, Inc. All Rights Reserved. $
   ======================================================================== */
#pragma once
#include "GenChunk.h"
class GenWorld
{
public:
	GenWorld(class GenLevel* currentLevel);
	void InitChunks(class GenLevel* currentLevel);
	GenChunk* GetChunk(int x, int y);
	void DrawWorld(class GenWindow* wnd, class GenLevel* currentLevel);
private:
	std::vector<GenChunk*> chunks;
};

