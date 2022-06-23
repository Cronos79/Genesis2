/* ========================================================================
   $File: $
   $Date: $
   $Revision: $
   $Creator: Matt Brock $
   $Notice: (C) Copyright 2022 by CronoGames, Inc. All Rights Reserved. $
   ======================================================================== */
#pragma once
#include <DirectXMath.h>

struct Vertex2D
{
	Vertex2D() {}
	Vertex2D(float x, float y, float z, float u, float v)
		: pos(x, y, z), texCoord(u, v) {}

	DirectX::XMFLOAT3 pos;
	DirectX::XMFLOAT2 texCoord;
};


struct Vertex
{
	Vertex() {}
	Vertex(float x, float y, float z, float u, float v, float nx, float ny, float nz)
		: pos(x, y, z), texCoord(u, v), normal(nx, ny, nz) {}

	DirectX::XMFLOAT3 pos;
	DirectX::XMFLOAT2 texCoord;
	DirectX::XMFLOAT3 normal;
};

