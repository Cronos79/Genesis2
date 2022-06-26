/* ========================================================================
   $File: $
   $Date: $
   $Revision: $
   $Creator: Matt Brock $
   $Notice: (C) Copyright 2022 by CronoGames, Inc. All Rights Reserved. $
   ======================================================================== */
#pragma once
#include "GenGameObject3d.h"
class GenGameObject : public GenGameObject3d
{
public:
	bool Initialize(const std::string name, const std::string& filePath, ID3D11Device* device, ID3D11DeviceContext* deviceContext, ConstantBuffer<CB_VS_vertexshader>& cb_vs_vertexshader);
	void SetModel(GenModel* model);
	GenModel* GetModel();
	void Draw(const XMMATRIX& viewProjectionMatrix);
	bool modelLoaded = false;
protected:
	GenModel* model;
	
	void UpdateMatrix() override;

	XMMATRIX worldMatrix = XMMatrixIdentity();
};

