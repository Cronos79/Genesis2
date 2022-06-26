#pragma once
#include "GenLight.h"
class GenAmbientLight : public GenLight
{
public:
	void SetConstantBuffers(GenGraphics* gfx) override;
	DirectX::XMFLOAT3 ambientLightColor = DirectX::XMFLOAT3(1.0f, 1.0f, 1.0f);
	float ambientLightStrength = 1.0f;
	ConstantBuffer<CB_PS_ambientlight> cb_ps_ambientlight;
};

