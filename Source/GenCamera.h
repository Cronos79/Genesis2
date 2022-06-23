/* ========================================================================
   $File: $
   $Date: $
   $Revision: $
   $Creator: Matt Brock $
   $Notice: (C) Copyright 2022 by CronoGames, Inc. All Rights Reserved. $
   ======================================================================== */
#pragma once
#include <DirectXMath.h>
#include "GenGameObject3d.h"
using namespace DirectX;

class GenCamera : public GenGameObject3d
{
public:
	GenCamera();
	void SetProjectionValues(float fovDegrees, float aspectRatio, float nearZ, float farZ);

	const XMMATRIX& GetViewMatrix() const;
	const XMMATRIX& GetProjectionMatrix() const;

private:
	void UpdateMatrix() override;

	XMMATRIX viewMatrix;
	XMMATRIX projectionMatrix;
};
