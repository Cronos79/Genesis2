/* ========================================================================
   $File: $
   $Date: $
   $Revision: $
   $Creator: Matt Brock $
   $Notice: (C) Copyright 2022 by CronoGames, Inc. All Rights Reserved. $
   ======================================================================== */
#pragma once
#include "GenGameObject2d.h"
class GenCamera2D : public GenGameObject2d
{
public:
	GenCamera2D();
	void SetProjectionValues(float width, float height, float nearZ, float farZ);

	const XMMATRIX& GetOrthoMatrix() const;
	const XMMATRIX& GetWorldMatrix() const;
private:
	void UpdateMatrix() override;

	XMMATRIX orthoMatrix;
	XMMATRIX worldMatrix;
};

