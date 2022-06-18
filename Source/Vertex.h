/* ========================================================================
   $File: $
   $Date: $
   $Revision: $
   $Creator: Matt Brock $
   $Notice: (C) Copyright 2022 by CronoGames, Inc. All Rights Reserved. $
   ======================================================================== */
#pragma once
#include <DirectXMath.h>

struct Vertex
{
	Vertex() {}
	Vertex(float x, float y, float z, float r, float g, float b)
		: pos(x, y, z), color(r, g, b) {}

	DirectX::XMFLOAT3 pos;
	DirectX::XMFLOAT3 color;
};

