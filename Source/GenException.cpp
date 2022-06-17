/* ========================================================================
   $File: $
   $Date: $
   $Revision: $
   $Creator: Matt Brock $
   $Notice: (C) Copyright 2022 by CronoGames, Inc. All Rights Reserved. $
   ======================================================================== */
#include "GenException.h"
#include <sstream>

GenException::GenException(int line, const char* file) noexcept
	: line(line), file(file)
{
	//
}

const char* GenException::what() const noexcept
{
	std::ostringstream oss;
	oss << GetType() << std::endl
		<< GetOriginString();
	whatBuffer = oss.str();
	return whatBuffer.c_str();
}

const char* GenException::GetType() const noexcept
{
	return "Gen Exception";
}

int GenException::GetLine() const noexcept
{
	return line;
}

const std::string& GenException::GetFile() const noexcept
{
	return file;
}

std::string GenException::GetOriginString() const noexcept
{
	std::ostringstream oss;
	oss << "[File] " << file << std::endl
		<< "[Line] " << line;
	return oss.str();
}
