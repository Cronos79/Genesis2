/* ========================================================================
   $File: $
   $Date: $
   $Revision: $
   $Creator: Matt Brock $
   $Notice: (C) Copyright 2022 by CronoGames, Inc. All Rights Reserved. $
   ======================================================================== */
#pragma once

#include "GenGameObject.h"
#include "ConstantBuffer.h"
#include "GenGraphics.h"

class GenLight : public GenGameObject
{
public:
	bool Initialize(ID3D11Device* device, ID3D11DeviceContext* deviceContext, ConstantBuffer<CB_VS_vertexshader>& cb_vs_vertexshader);
	void SetConstantBuffers(GenGraphics* gfx);
	DirectX::XMFLOAT3 lightColor = DirectX::XMFLOAT3(1.0f, 1.0f, 1.0f);
	float lightStrength = 1.0f;
	float attenuation_a = 1.0f;
	float attenuation_b = 0.1f;
	float attenuation_c = 0.1f;
	ConstantBuffer<CB_PS_light> cb_ps_light;

	DirectX::XMFLOAT3 ambientLightColor = DirectX::XMFLOAT3(1.0f, 1.0f, 1.0f);
	float ambientLightStrength = 1.0f;
	ConstantBuffer<CB_PS_ambientlight> cb_ps_ambientlight;
};