/* ========================================================================
   $File: $
   $Date: $
   $Revision: $
   $Creator: Matt Brock $
   $Notice: (C) Copyright 2022 by CronoGames, Inc. All Rights Reserved. $
   ======================================================================== */
#include "GenAssetMng.h"

GenAssetMng::GenAssetMng(GenGraphics* gfx)
	: Gfx(gfx)
{
	InitializeShaders();
}

GenAssetMng::~GenAssetMng()
{

}

bool GenAssetMng::LoadAssets()
{
	if (!LoadVertexShaders())
		return false;

	if (!LoadPixelShaders())
		return false;

	GenLogger::Info("Shaders loaded");
	return true;
}

bool GenAssetMng::InitializeShaders()
{
	std::wstring shaderfolder = L"";
#pragma region DetermineShaderPath
	if (IsDebuggerPresent() == TRUE)
	{
#ifdef _DEBUG //Debug Mode
#ifdef _WIN64 //x64
		shaderfolder = L".\\x64\\Debug\\";
#else  //x86 (Win32)
		shaderfolder = L".\\Debug\\";
#endif
#else //Release Mode
#ifdef _WIN64 //x64
		shaderfolder = L".\\x64\\Release\\";
#else  //x86 (Win32)
		shaderfolder = L".\\Release\\";
#endif
#endif
	}
	//2d shaders
	D3D11_INPUT_ELEMENT_DESC layout2D[] =
	{
		{"POSITION", 0, DXGI_FORMAT::DXGI_FORMAT_R32G32B32_FLOAT, 0, 0, D3D11_INPUT_CLASSIFICATION::D3D11_INPUT_PER_VERTEX_DATA, 0  },
		{"TEXCOORD", 0, DXGI_FORMAT::DXGI_FORMAT_R32G32_FLOAT, 0, D3D11_APPEND_ALIGNED_ELEMENT, D3D11_INPUT_CLASSIFICATION::D3D11_INPUT_PER_VERTEX_DATA, 0  },
	};

	UINT numElements2D = ARRAYSIZE(layout2D);

	if (!vertexshader_2d.Initialize(Gfx->device, shaderfolder + L"VertexShader_2d.cso", layout2D, numElements2D))
		return false;

	if (!pixelshader_2d.Initialize(Gfx->device, shaderfolder + L"PixelShader_2d.cso"))
		return false;

	// 3D shaders
	D3D11_INPUT_ELEMENT_DESC layout[] =
	{
		{"POSITION", 0, DXGI_FORMAT::DXGI_FORMAT_R32G32B32_FLOAT, 0, 0, D3D11_INPUT_CLASSIFICATION::D3D11_INPUT_PER_VERTEX_DATA, 0  },
		{"TEXCOORD", 0, DXGI_FORMAT::DXGI_FORMAT_R32G32_FLOAT, 0, D3D11_APPEND_ALIGNED_ELEMENT, D3D11_INPUT_CLASSIFICATION::D3D11_INPUT_PER_VERTEX_DATA, 0  },
		{"NORMAL", 0, DXGI_FORMAT::DXGI_FORMAT_R32G32B32_FLOAT, 0, D3D11_APPEND_ALIGNED_ELEMENT, D3D11_INPUT_CLASSIFICATION::D3D11_INPUT_PER_VERTEX_DATA, 0  },
	};

	UINT numElements = ARRAYSIZE(layout);


	if (!vertexshader.Initialize(Gfx->device, shaderfolder + L"VertexShader.cso", layout, numElements))
		return false;

	if (!pixelshader.Initialize(Gfx->device, shaderfolder + L"PixelShader.cso"))
		return false;

	if (!pixelshader_nolight.Initialize(Gfx->device, shaderfolder + L"PixelShader_nolight.cso"))
		return false;
	
	return true;
}

bool GenAssetMng::LoadVertexShaders()
{
	vertexShaders["vs_default"] = &vertexshader;
	vertexShaders["vs_2d"] = &vertexshader_2d;
	return true;
}

bool GenAssetMng::LoadPixelShaders()
{
	pixelShaders["ps_default"] = &pixelshader;
	pixelShaders["ps_2d"] = &pixelshader_2d;
	pixelShaders["ps_nolight"] = &pixelshader_nolight;
	return true;
}
