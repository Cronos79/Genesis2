/* ========================================================================
   $File: $
   $Date: $
   $Revision: $
   $Creator: Matt Brock $
   $Notice: (C) Copyright 2022 by CronoGames, Inc. All Rights Reserved. $
   ======================================================================== */
#pragma once

#include <d3d11.h>
#include <wrl/client.h>
#include "GenColor.h"
#include <assimp/material.h>

enum class TextureStorageType
{
	Invalid,
	None,
	EmbeddedIndexCompressed,
	EmbeddedIndexNonCompressed,
	EmbeddedCompressed,
	EmbeddedNonCompressed,
	Disk
};

class GenTexture
{
public:
	GenTexture(ID3D11Device* device, const GenColor& color, aiTextureType type);
	GenTexture(ID3D11Device* device, const GenColor* colorData, UINT width, UINT height, aiTextureType type); //Generate texture of specific color data
	GenTexture(ID3D11Device* device, const std::string& filePath, aiTextureType type);
	GenTexture(ID3D11Device* device, const uint8_t* pData, size_t size, aiTextureType type);

	aiTextureType GetType();
	ID3D11ShaderResourceView* GetTextureResourceView();
	ID3D11ShaderResourceView** GetTextureResourceViewAddress();

private:
	void Initialize1x1ColorTexture(ID3D11Device* device, const GenColor& colorData, aiTextureType type);
	void InitializeColorTexture(ID3D11Device* device, const GenColor* colorData, UINT width, UINT height, aiTextureType type);
	Microsoft::WRL::ComPtr<ID3D11Resource> texture = nullptr;
	Microsoft::WRL::ComPtr<ID3D11ShaderResourceView> textureView = nullptr;
	aiTextureType type = aiTextureType::aiTextureType_UNKNOWN;
};