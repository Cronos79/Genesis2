/* ========================================================================
   $File: $
   $Date: $
   $Revision: $
   $Creator: Matt Brock $
   $Notice: (C) Copyright 2022 by CronoGames, Inc. All Rights Reserved. $
   ======================================================================== */
#pragma once

#include <map> // Header file to include map in the code
#include <string>
#include "Shaders.h"
#include "GenGraphics.h"
using namespace std;

class GenAssetMng
{
public:
	GenAssetMng(GenGraphics* gfx);
	~GenAssetMng();
	bool LoadAssets();
	map<std::string, VertexShader*> vertexShaders;
	map<std::string, PixelShader*> pixelShaders;
private:
	bool InitializeShaders();
	bool LoadVertexShaders();
	bool LoadPixelShaders();

	GenGraphics* Gfx;
	VertexShader vertexshader_2d;
	VertexShader vertexshader;
	PixelShader pixelshader_2d;
	PixelShader pixelshader;
	PixelShader pixelshader_nolight;
	
};

