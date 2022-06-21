/* ========================================================================
   $File: $
   $Date: $
   $Revision: $
   $Creator: Matt Brock $
   $Notice: (C) Copyright 2022 by CronoGames, Inc. All Rights Reserved. $
   ======================================================================== */
#pragma once
#include <exception>
#include <string>
#include <windows.h>

class GenException : public std::exception
{
public:
	GenException(int line, const char* file) noexcept;
	const char* what() const noexcept override;
	virtual const char* GetType() const noexcept;
	int GetLine() const noexcept;
	const std::string& GetFile() const noexcept;
	std::string GetOriginString() const noexcept;
private:
	int line;
	std::string file;
protected:
	mutable std::string whatBuffer;

};
class Exception : public GenException
{
	using GenException::GenException;
public:
	static std::string TranslateErrorCode(HRESULT hr) noexcept;
};
class HrException : public Exception
{
public:
	HrException(int line, const char* file, HRESULT hr) noexcept;
	HrException(int line, const char* file, HRESULT hr, const char* msg) noexcept;
	const char* what() const noexcept override;
	const char* GetType() const noexcept override;
	HRESULT GetErrorCode() const noexcept;
	const char* GetMsg() const noexcept;
	std::string GetErrorDescription() const noexcept;
private:
	HRESULT hr;
	const char* msg;
};
class NoGfxException : public Exception
{
public:
	using Exception::Exception;
	const char* GetType() const noexcept override;
};