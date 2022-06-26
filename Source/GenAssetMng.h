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
#include "ConstantBuffer.h"
#include "GenLight.h"
#include "GenPointLight.h"
#include "GenAmbientLight.h"
#include "GenTile.h"
#include "GenHero.h"
using namespace std;

class GenAssetMng
{
public:
	GenAssetMng(GenGraphics* gfx);
	~GenAssetMng();
	bool LoadAssets();	
	GenTile* GetTile(std::string name);
	GenPointLight* GetPointLight(std::string name);
	GenAmbientLight* GetAmbientLight(std::string name);
	map<std::string, VertexShader*> vertexShaders;
	map<std::string, PixelShader*> pixelShaders;
	ConstantBuffer<CB_VS_vertexshader_2d> cb_vs_vertexshader_2d;
	ConstantBuffer<CB_VS_vertexshader> cb_vs_vertexshader;	

	// Temp
	GenCamera camera;
	GenCamera2D camera2D;
	GenSprite sprite;
	GenHero* hero;
	bool assetsLoaded = false;
private:
	bool InitializeShaders();
	bool LoadVertexShaders();
	bool LoadPixelShaders();
	bool InitializeConstantBuffers();
	bool Test();
	bool LoadTile(std::string name);
	bool LoadPointLight(std::string name);
	bool LoadAmbientLight(std::string name);

	map<std::string, GenTile*> loadedTiles;
	map<std::string, GenPointLight*> loadedPointLights;
	map<std::string, GenAmbientLight*> loadedAmbientLights;

	GenGraphics* Gfx;
	VertexShader vertexshader_2d;
	VertexShader vertexshader;
	PixelShader pixelshader_2d;
	PixelShader pixelshader;
	PixelShader pixelshader_nolight;		
};

