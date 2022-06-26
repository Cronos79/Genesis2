/* ========================================================================
   $File: $
   $Date: $
   $Revision: $
   $Creator: Matt Brock $
   $Notice: (C) Copyright 2022 by CronoGames, Inc. All Rights Reserved. $
   ======================================================================== */
#pragma once
#include <vector>
#include "GenTile.h"
#include <DirectXMath.h>
#include "GenGameObject3d.h"
class GenChunk : public GenGameObject3d
{
public:
	void InitChunk(class GenLevel* currentLevel);	
	void DrawChunk();
	int32_t GetChunkWidth();
	int32_t GetChunkHeight();
private:
	void AddTile(GenTile* tile);
	void DrawTile(GenTile* tile);
	std::vector<GenTile*> tiles;
	GenLevel* currentLevel;
	int32_t chunkSize = 16;
protected:
	XMMATRIX worldMatrix = XMMatrixIdentity();
	void UpdateMatrix() override;

};

