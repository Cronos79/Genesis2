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


	
};