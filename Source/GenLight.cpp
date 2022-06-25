#include "GenLight.h"
#include "GenMacros.h"

bool GenLight::Initialize(ID3D11Device* device, ID3D11DeviceContext* deviceContext, ConstantBuffer<CB_VS_vertexshader>& cb_vs_vertexshader)
{
	if (!model.Initialize("./Data/light.fbx", device, deviceContext, cb_vs_vertexshader))
		return false;

	this->SetPosition(0.0f, 0.0f, 0.0f);
	this->SetRotation(0.0f, 0.0f, 0.0f);
	this->UpdateMatrix();
	return true;
}

void GenLight::SetConstantBuffers(GenGraphics* gfx)
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

	hr = this->cb_ps_ambientlight.Initialize(gfx->device.Get(), gfx->deviceContext.Get());
	GENWND_ERROR_IF_FAILED(hr, "Failed to initialize constant buffer.");
	this->cb_ps_ambientlight.data.ambientLightColor = ambientLightColor;
	this->cb_ps_ambientlight.data.ambientLightStrength = ambientLightStrength; // #TODO: make a seperate light
	cb_ps_ambientlight.ApplyChanges();
	gfx->deviceContext->PSSetConstantBuffers(1, 2, cb_ps_ambientlight.GetAddressOf());
}
