/* ========================================================================
   $File: $
   $Date: $
   $Revision: $
   $Creator: Matt Brock $
   $Notice: (C) Copyright 2022 by CronoGames, Inc. All Rights Reserved. $
   ======================================================================== */
#pragma once

typedef unsigned char BYTE;

class GenColor
{
public:
	GenColor();
	GenColor(unsigned int val);
	GenColor(BYTE r, BYTE g, BYTE b);
	GenColor(BYTE r, BYTE g, BYTE b, BYTE a);
	GenColor(const GenColor& src);

	GenColor& operator=(const GenColor& src);
	bool operator==(const GenColor& rhs) const;
	bool operator!=(const GenColor& rhs) const;

	constexpr BYTE GetR() const;
	void SetR(BYTE r);

	constexpr BYTE GetG() const;
	void SetG(BYTE g);

	constexpr BYTE GetB() const;
	void SetB(BYTE b);

	constexpr BYTE GetA() const;
	void SetA(BYTE a);

private:
	union
	{
		BYTE rgba[4];
		unsigned int color;
	};
};

namespace Colors
{
	const GenColor UnloadedTextureColor(100, 100, 100);
	const GenColor UnhandledTextureColor(250, 0, 0);
}

