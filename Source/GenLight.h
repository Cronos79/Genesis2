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
	virtual void SetConstantBuffers(GenGraphics* gfx);


	DirectX::XMFLOAT3 ambientLightColor = DirectX::XMFLOAT3(1.0f, 1.0f, 1.0f);
	float ambientLightStrength = 1.0f;
	ConstantBuffer<CB_PS_ambientlight> cb_ps_ambientlight;
};