/* ========================================================================
   $File: $
   $Date: $
   $Revision: $
   $Creator: Matt Brock $
   $Notice: (C) Copyright 2022 by CronoGames, Inc. All Rights Reserved. $
   ======================================================================== */
#pragma once
#include "GenWindow.h"
// error exception helper macro
#define GENWND_EXCEPT( hr ) GenWindow::HrException( __LINE__,__FILE__,(hr) )
#define GENWND_LAST_EXCEPT() GenWindow::HrException( __LINE__,__FILE__,GetLastError() )
#define GENWND_NOGFX_EXCEPT() GenWindow::NoGfxException( __LINE__,__FILE__ )