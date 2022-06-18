/* ========================================================================
   $File: $
   $Date: $
   $Revision: $
   $Creator: Matt Brock $
   $Notice: (C) Copyright 2022 by CronoGames, Inc. All Rights Reserved. $
   ======================================================================== */
#pragma once
#include "GenWin.h"
#include "d3d11.h"
#pragma comment(lib, "d3d11.lib")

#include <wrl/client.h>
#include "Shaders.h"

class GenGraphics
{
public:
	GenGraphics(HWND hwnd, int width, int height);
	~GenGraphics();
public:
	bool Initialize(HWND hwnd, int width, int height);
	void RenderFrame();
private:
	bool InitializeDirectX(HWND hwnd, int width, int height);
	bool InitializeShaders();

	Microsoft::WRL::ComPtr<ID3D11Device> device;
	Microsoft::WRL::ComPtr<ID3D11DeviceContext> deviceContext;
	Microsoft::WRL::ComPtr<IDXGISwapChain> swapchain;
	Microsoft::WRL::ComPtr<ID3D11RenderTargetView> renderTargetView;

	

	VertexShader vertexshader;
	PixelShader pixelshader;
};
