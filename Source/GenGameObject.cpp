/* ========================================================================
   $File: $
   $Date: $
   $Revision: $
   $Creator: Matt Brock $
   $Notice: (C) Copyright 2022 by CronoGames, Inc. All Rights Reserved. $
   ======================================================================== */
#include "GenGameObject.h"
bool GenGameObject::Initialize(const std::string name, const std::string& filePath, ID3D11Device* device, ID3D11DeviceContext* deviceContext, ConstantBuffer<CB_VS_vertexshader>& cb_vs_vertexshader)
{
	
	if (model == nullptr)
	{	
		model = new GenModel();
		model->Initialize(filePath, device, deviceContext, cb_vs_vertexshader);
	}

	this->SetName(name);
	this->SetPosition(0.0f, 0.0f, 0.0f);
	this->SetRotation(0.0f, 0.0f, 0.0f);
	this->UpdateMatrix();
	return true;
}

void GenGameObject::SetModel(GenModel* model)
{
	this->model = model;
}

GenModel* GenGameObject::GetModel()
{
	return model;
}

void GenGameObject::Draw(const XMMATRIX& viewProjectionMatrix)
{
	model->Draw(this->worldMatrix, viewProjectionMatrix);
}

void GenGameObject::UpdateMatrix()
{
	this->worldMatrix = XMMatrixRotationRollPitchYaw(this->rot.x, this->rot.y, this->rot.z) * XMMatrixTranslation(this->pos.x, this->pos.y, this->pos.z);
	this->UpdateDirectionVectors();
}