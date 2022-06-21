/* ========================================================================
   $File: $
   $Date: $
   $Revision: $
   $Creator: Matt Brock $
   $Notice: (C) Copyright 2022 by CronoGames, Inc. All Rights Reserved. $
   ======================================================================== */
#include "GenTexture.h"
#include "GenMacros.h"
#include "FunctionLib.h"
#include <WICTextureLoader.h>
#include <DDSTextureLoader.h>

GenTexture::GenTexture(ID3D11Device* device, const GenColor& color, aiTextureType type)
{
	this->Initialize1x1ColorTexture(device, color, type);
}

GenTexture::GenTexture(ID3D11Device* device, const GenColor* colorData, UINT width, UINT height, aiTextureType type)
{
	this->InitializeColorTexture(device, colorData, width, height, type);
}

GenTexture::GenTexture(ID3D11Device* device, const std::string& filePath, aiTextureType type)
{
	this->type = type;
	if (FunctionLib::GetFileExtension(filePath) == ".dds")
	{
		HRESULT hr = DirectX::CreateDDSTextureFromFile(device, FunctionLib::StringToWide(filePath).c_str(), texture.GetAddressOf(), this->textureView.GetAddressOf());
		if (FAILED(hr))
		{
			this->Initialize1x1ColorTexture(device, Colors::UnloadedTextureColor, type);
		}
		return;
	}
	else
	{
		HRESULT hr = DirectX::CreateWICTextureFromFile(device, FunctionLib::StringToWide(filePath).c_str(), texture.GetAddressOf(), this->textureView.GetAddressOf());
		if (FAILED(hr))
		{
			this->Initialize1x1ColorTexture(device, Colors::UnloadedTextureColor, type);
		}
		return;
	}
}

aiTextureType GenTexture::GetType()
{
	return this->type;
}

ID3D11ShaderResourceView* GenTexture::GetTextureResourceView()
{
	return this->textureView.Get();
}

ID3D11ShaderResourceView** GenTexture::GetTextureResourceViewAddress()
{
	return this->textureView.GetAddressOf();
}

void GenTexture::Initialize1x1ColorTexture(ID3D11Device* device, const GenColor& colorData, aiTextureType type)
{
	InitializeColorTexture(device, &colorData, 1, 1, type);
}

void GenTexture::InitializeColorTexture(ID3D11Device* device, const GenColor* colorData, UINT width, UINT height, aiTextureType type)
{
	this->type = type;
	CD3D11_TEXTURE2D_DESC textureDesc(DXGI_FORMAT_R8G8B8A8_UNORM, width, height);
	ID3D11Texture2D* p2DTexture = nullptr;
	D3D11_SUBRESOURCE_DATA initialData{};
	initialData.pSysMem = colorData;
	initialData.SysMemPitch = width * sizeof(GenColor);
	HRESULT hr = device->CreateTexture2D(&textureDesc, &initialData, &p2DTexture);
	GENWND_ERROR_IF_FAILED(hr, "Failed to initialize texture from color data.");
	texture = static_cast<ID3D11Texture2D*>(p2DTexture);
	CD3D11_SHADER_RESOURCE_VIEW_DESC srvDesc(D3D11_SRV_DIMENSION_TEXTURE2D, textureDesc.Format);
	hr = device->CreateShaderResourceView(texture.Get(), &srvDesc, textureView.GetAddressOf());
	GENWND_ERROR_IF_FAILED(hr, "Failed to create shader resource view from texture generated from color data.");
}
