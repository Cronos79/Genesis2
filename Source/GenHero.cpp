/* ========================================================================
   $File: $
   $Date: $
   $Revision: $
   $Creator: Matt Brock $
   $Notice: (C) Copyright 2022 by CronoGames, Inc. All Rights Reserved. $
   ======================================================================== */
#include "GenHero.h"
#include "GenLevel.h"
#include "GenWindow.h"

GenHero::GenHero(GenLevel* currentLevel)
{
	currentLevel->assetMng->GetPointLight("HeroLight");
}

void GenHero::DrawLight(GenWindow* wnd, GenLevel* currentLevel)
{
	// PointLight
	{		
		//currentLevel->assetMng->GetPointLight("HeroLight")->SetPosition(GetPositionFloat3().x + 100.0f, GetPositionFloat3().y + 300.0f,GetPositionFloat3().z);
		currentLevel->assetMng->GetPointLight("HeroLight")->Draw(currentLevel->assetMng->camera.GetViewMatrix() * currentLevel->assetMng->camera.GetProjectionMatrix());
	}
}
