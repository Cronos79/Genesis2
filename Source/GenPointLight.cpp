/* ========================================================================
   $File: $
   $Date: $
   $Revision: $
   $Creator: Matt Brock $
   $Notice: (C) Copyright 2022 by CronoGames, Inc. All Rights Reserved. $
   ======================================================================== */
#include "GenPointLight.h"
#include "GenMacros.h"

void GenPointLight::SetConstantBuffers(GenGraphics* gfx)
{
	HRESULT hr = this->cb_ps_light.Initialize(gfx->device.Get(), gfx->deviceContext.Get());
	GENWND_ERROR_IF_FAILED(hr, "Failed to initialize constant buffer.");
	cb_ps_light.data.dynamicLightColor = lightColor;
	cb_ps_light.data.dynamicLightStrength = lightStrength;
	cb_ps_light.data.dynamicLightPosition = GetPositionFloat3();
	cb_ps_light.data.dynamicLightAttenuation_a = attenuation_a;
	cb_ps_light.data.dynamicLightAttenuation_b = attenuation_b;
	cb_ps_light.data.dynamicLightAttenuation_c = attenuation_c;
	cb_ps_light.ApplyChanges();
	gfx->deviceContext->PSSetConstantBuffers(0, 2, cb_ps_light.GetAddressOf());
}

void GenPointLight::UpdateMatrix()
{
	this->worldMatrix = XMMatrixRotationRollPitchYaw(this->rot.x, this->rot.y, this->rot.z) * XMMatrixTranslation(this->pos.x, this->pos.y, this->pos.z);
	this->UpdateDirectionVectors();
}
