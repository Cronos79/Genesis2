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
#include "Vertex.h"
#include "VertexBuffer.h"
#include "IndexBuffer.h"
#include "ConstantBuffer.h"
#include "GenCamera.h"
#include "GenTimer.h"

class GenGraphics
{
public:
	GenGraphics(HWND hwnd, int width, int height);
	~GenGraphics();
public:
	bool Initialize(HWND hwnd, int width, int height);
	void RenderFrame();
	GenCamera camera;
private:
	bool InitializeDirectX(HWND hwnd);
	bool InitializeShaders();
	bool InitializeScene();

	Microsoft::WRL::ComPtr<ID3D11Device> device;
	Microsoft::WRL::ComPtr<ID3D11DeviceContext> deviceContext;
	Microsoft::WRL::ComPtr<IDXGISwapChain> swapchain;
	Microsoft::WRL::ComPtr<ID3D11RenderTargetView> renderTargetView;

	

	VertexShader vertexshader;
	PixelShader pixelshader;

	VertexBuffer<Vertex> vertexBuffer;
	IndexBuffer indicesBuffer;
	ConstantBuffer<CB_VS_vertexshader> constantBuffer;

	Microsoft::WRL::ComPtr<ID3D11DepthStencilView> depthStencilView;
	Microsoft::WRL::ComPtr<ID3D11Texture2D> depthStencilBuffer;
	Microsoft::WRL::ComPtr<ID3D11DepthStencilState> depthStencilState;

	Microsoft::WRL::ComPtr<ID3D11RasterizerState> rasterizerState;

	Microsoft::WRL::ComPtr<ID3D11SamplerState> samplerState;
	Microsoft::WRL::ComPtr<ID3D11ShaderResourceView> myTexture;

	int windowWidth = 0;
	int windowHeight = 0;	
	GenTimer fpsTimer;
};
