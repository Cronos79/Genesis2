/* ========================================================================
   $File: $
   $Date: $
   $Revision: $
   $Creator: Matt Brock $
   $Notice: (C) Copyright 2022 by CronoGames, Inc. All Rights Reserved. $
   ======================================================================== */
#pragma once
#include "GenException.h"
// error exception helper macro
#define GENWND_EXCEPT( hr )HrException( __LINE__,__FILE__,(hr) )
#define GENWND_LAST_EXCEPT() HrException( __LINE__,__FILE__,GetLastError() )
#define GENWND_NOGFX_EXCEPT() NoGfxException( __LINE__,__FILE__ )
#define GENWND_ERROR_IF_FAILED( hr, msg ) if( FAILED( hr ) ) throw HrException( __LINE__,__FILE__,(hr) )