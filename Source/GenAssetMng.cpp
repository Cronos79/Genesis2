/* ========================================================================
   $File: $
   $Date: $
   $Revision: $
   $Creator: Matt Brock $
   $Notice: (C) Copyright 2022 by CronoGames, Inc. All Rights Reserved. $
   ======================================================================== */
#include "GenAssetMng.h"
#include "GenMacros.h"
#include "GenPointLight.h"

GenAssetMng::GenAssetMng(GenGraphics* gfx)
	: Gfx(gfx)
{
	InitializeShaders();
	LoadAssets();
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
	
	if (!InitializeConstantBuffers())
		return false;

	Test();

	GenLogger::Info("Shaders loaded");
	assetsLoaded = true;
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

bool GenAssetMng::InitializeConstantBuffers()
{
	try
	{
		//Initialize Constant Buffer(s)
		HRESULT hr = this->cb_vs_vertexshader_2d.Initialize(Gfx->device.Get(), Gfx->deviceContext.Get());
		GENWND_ERROR_IF_FAILED(hr, "Failed to initialize 2d constant buffer.");

		hr = this->cb_vs_vertexshader.Initialize(Gfx->device.Get(), Gfx->deviceContext.Get());
		GENWND_ERROR_IF_FAILED(hr, "Failed to initialize constant buffer.");			
	}
	catch (GenException& exception)
	{
		//ErrorLogger::Log(exception);
		return false;
	}
	return true;
}

bool GenAssetMng::Test()
{
	if (!light.Initialize(Gfx->device.Get(), Gfx->deviceContext.Get(), this->cb_vs_vertexshader))
		return false;

	if (!sprite.Initialize(Gfx->device.Get(), Gfx->deviceContext.Get(), 256, 256, "./Data/sprite_256x256.png", cb_vs_vertexshader_2d))
		return false;

	sprite.SetPosition(XMFLOAT3(Gfx->windowWidth / 2 - sprite.GetWidth() / 2, Gfx->windowHeight / 2 - sprite.GetHeight() / 2, 0.0f));

	camera2D.SetProjectionValues(Gfx->windowWidth, Gfx->windowHeight, 0.0f, 1.0f);

	camera.SetPosition(500.0f, 400.0f, -30.0f);
	camera.SetRotation(45.0f, 0.0f, 0.0f);
	camera.SetProjectionValues(90.0f, static_cast<float>(Gfx->windowWidth) / static_cast<float>(Gfx->windowHeight), 0.1f, 1000.0f);
}

bool GenAssetMng::LoadGameObject(std::string name)
{
	if (Gfx)
	{		
		loadedGameObjects3d[name] = new GenGameObject();
		std::string delimiter = "_";
		std::string token = name.substr(0, name.find(delimiter));
		std::string path = ".\\Data\\" + token + ".fbx";
		if (!loadedGameObjects3d[name]->Initialize(path, Gfx->device.Get(), Gfx->deviceContext.Get(), this->cb_vs_vertexshader))
			return false;
	}
	else
	{
		return false;
	}
	return true;
}

GenGameObject* GenAssetMng::GetGameObject(std::string name)
{
	GenGameObject* temp = loadedGameObjects3d[name];
	if (!temp)
	{
		LoadGameObject(name);
		temp = loadedGameObjects3d[name];

	}
	return temp;
}


bool GenAssetMng::LoadPointLight(std::string name)
{
	if (Gfx)
	{
		loadedPointLights[name] = new GenPointLight();;
		if (!loadedPointLights[name]->Initialize(Gfx->device.Get(), Gfx->deviceContext.Get(), this->cb_vs_vertexshader))
			return false;
	}
	else
	{
		return false;
	}
	return true;
}

GenPointLight* GenAssetMng::GetPointLight(std::string name)
{
	GenPointLight* temp = loadedPointLights[name];
	if (!temp)
	{
		LoadPointLight(name);
		temp = loadedPointLights[name];
	}
	return temp;
}

