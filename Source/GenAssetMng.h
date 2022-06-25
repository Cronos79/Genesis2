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
using namespace std;

class GenAssetMng
{
public:
	GenAssetMng(GenGraphics* gfx);
	~GenAssetMng();
	bool LoadAssets();	
	GenGameObject* GetGameObject(std::string name);
	map<std::string, VertexShader*> vertexShaders;
	map<std::string, PixelShader*> pixelShaders;
	ConstantBuffer<CB_VS_vertexshader_2d> cb_vs_vertexshader_2d;
	ConstantBuffer<CB_VS_vertexshader> cb_vs_vertexshader;	
	GenCamera camera;
	GenCamera2D camera2D;
	GenSprite sprite;
	//GenGameObject gameObject;
	GenLight light;
	bool assetsLoaded = false;
private:
	bool InitializeShaders();
	bool LoadVertexShaders();
	bool LoadPixelShaders();
	bool InitializeConstantBuffers();
	bool Test();
	bool LoadGameObject(std::string name);

	map<std::string, GenGameObject*> loadedGameObjects3d;

	GenGraphics* Gfx;
	VertexShader vertexshader_2d;
	VertexShader vertexshader;
	PixelShader pixelshader_2d;
	PixelShader pixelshader;
	PixelShader pixelshader_nolight;		
};

