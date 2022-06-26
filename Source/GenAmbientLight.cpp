#include "GenAmbientLight.h"
#include "GenMacros.h"

void GenAmbientLight::SetConstantBuffers(GenGraphics* gfx)
{
	HRESULT hr = this->cb_ps_ambientlight.Initialize(gfx->device.Get(), gfx->deviceContext.Get());
	GENWND_ERROR_IF_FAILED(hr, "Failed to initialize constant buffer.");
	cb_ps_ambientlight.data.ambientLightColor = ambientLightColor;
	cb_ps_ambientlight.data.ambientLightStrength = ambientLightStrength;
	cb_ps_ambientlight.ApplyChanges();
	gfx->deviceContext->PSSetConstantBuffers(1, 2, cb_ps_ambientlight.GetAddressOf());
}
