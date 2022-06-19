/* ========================================================================
   $File: $
   $Date: $
   $Revision: $
   $Creator: Matt Brock $
   $Notice: (C) Copyright 2022 by CronoGames, Inc. All Rights Reserved. $
   ======================================================================== */
#include "GenLogger.h"
#include <comdef.h>

void GenLogger::Info(std::string str)
{
	/*std::string error_message = "Info: " + str;
	MessageBoxA(NULL, error_message.c_str(), "Info", MB_ICONERROR);*/
	OutputDebugStringW(L"********** Info **********\n");
	OutputDebugStringW(FunctionLib::StringToWide(str).c_str());
	OutputDebugStringW(L"\n");
	OutputDebugStringW(L"**************************\n");
}

void GenLogger::Info(HRESULT hr, std::string str)
{
	_com_error error(hr);
	std::wstring error_message = L"Info: " + FunctionLib::StringToWide(str) + L"\n" + error.ErrorMessage();
	//MessageBoxW(NULL, error_message.c_str(), L"Info", MB_ICONERROR);
	OutputDebugStringW(L"********** Info **********\n");
	OutputDebugStringW(error_message.c_str());
	OutputDebugStringW(L"\n");
	OutputDebugStringW(L"**************************\n");
}

void GenLogger::Error(std::string str)
{
	std::string error_message = "Error: " + str;
	MessageBoxA(NULL, error_message.c_str(), "Error", MB_ICONERROR);
}

void GenLogger::Error(HRESULT hr, std::string str)
{
	_com_error error(hr);
	std::wstring error_message = L"Error: " + FunctionLib::StringToWide(str) + L"\n" + error.ErrorMessage();
	MessageBoxW(NULL, error_message.c_str(), L"Error", MB_ICONERROR);
}

void GenLogger::Error(HRESULT hr, std::wstring str)
{
	_com_error error(hr);
	std::wstring error_message = L"Error: " + str + L"\n" + error.ErrorMessage();
	MessageBoxW(NULL, error_message.c_str(), L"Error", MB_ICONERROR);
}

void GenLogger::Error(GenException e)
{
	std::wstring error_message = FunctionLib::StringToWide(e.what());
	MessageBoxW(NULL, error_message.c_str(), L"Error", MB_ICONERROR);
}
