#include "GenLight.h"
#include "GenMacros.h"

bool GenLight::Initialize(ID3D11Device* device, ID3D11DeviceContext* deviceContext, ConstantBuffer<CB_VS_vertexshader>& cb_vs_vertexshader)
{
	model = new GenModel();
	if (!model->Initialize("./Data/light.fbx", device, deviceContext, cb_vs_vertexshader))
		return false;

	this->SetPosition(0.0f, 0.0f, 0.0f);
	this->SetRotation(0.0f, 0.0f, 0.0f);
	this->UpdateMatrix();
	return true;
}

void GenLight::SetConstantBuffers(GenGraphics* gfx)
{
	assert("SetConstantBuffers must be overridden." && 0);
}
