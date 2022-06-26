/* ========================================================================
   $File: $
   $Date: $
   $Revision: $
   $Creator: Matt Brock $
   $Notice: (C) Copyright 2022 by CronoGames, Inc. All Rights Reserved. $
   ======================================================================== */
#pragma once
#include "GenCharacter.h"
#include "GenPointLight.h"
class GenHero : public GenCharacter
{
public:
	GenHero(class GenLevel* currentLevel);
	void DrawLight(class GenWindow* wnd, class GenLevel* currentLevel);
};

