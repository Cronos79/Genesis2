/* ========================================================================
   $File: $
   $Date: $
   $Revision: $
   $Creator: Matt Brock $
   $Notice: (C) Copyright 2022 by CronoGames, Inc. All Rights Reserved. $
   ======================================================================== */
#include "GenColor.h"

GenColor::GenColor()
	:color(0)
{}

GenColor::GenColor(unsigned int val)
	: color(val)
{}

GenColor::GenColor(BYTE r, BYTE g, BYTE b)
	: GenColor(r, g, b, 255)
{
}

GenColor::GenColor(BYTE r, BYTE g, BYTE b, BYTE a)
{
	rgba[0] = r;
	rgba[1] = g;
	rgba[2] = b;
	rgba[3] = a;
}

GenColor::GenColor(const GenColor& src)
	:color(src.color)
{}

GenColor& GenColor::operator=(const GenColor& src)
{
	this->color = src.color;
	return *this;
}

bool GenColor::operator==(const GenColor& rhs) const
{
	return (this->color == rhs.color);
}

bool GenColor::operator!=(const GenColor& rhs) const
{
	return !(*this == rhs);
}

constexpr BYTE GenColor::GetR() const
{
	return this->rgba[0];
}
void GenColor::SetR(BYTE r)
{
	this->rgba[0] = r;
}

constexpr BYTE GenColor::GetG() const
{
	return this->rgba[1];
}
void GenColor::SetG(BYTE g)
{
	this->rgba[1] = g;
}

constexpr BYTE GenColor::GetB() const
{
	return this->rgba[2];
}
void GenColor::SetB(BYTE b)
{
	this->rgba[2] = b;
}

constexpr BYTE GenColor::GetA() const
{
	return this->rgba[3];
}
void GenColor::SetA(BYTE a)
{
	this->rgba[3] = a;
}
