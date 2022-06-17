/* ========================================================================
   $File: $
   $Date: $
   $Revision: $
   $Creator: Matt Brock $
   $Notice: (C) Copyright 2022 by CronoGames, Inc. All Rights Reserved. $
   ======================================================================== */
#pragma once
#include "windows.h"
#include <optional>
#include <string>
#include "GenException.h"
#include "Keyboard.h"

class GenWindow
{
public:
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
		const char* what() const noexcept override;
		const char* GetType() const noexcept override;
		HRESULT GetErrorCode() const noexcept;
		std::string GetErrorDescription() const noexcept;
	private:
		HRESULT hr;
	};
	class NoGfxException : public Exception
	{
	public:
		using Exception::Exception;
		const char* GetType() const noexcept override;
	};
private:
	// singleton manages registration/cleanup of window class
	class WindowClass
	{
	public:
		static const char* GetName() noexcept;
		static HINSTANCE GetInstance() noexcept;
	private:
		WindowClass() noexcept;
		~WindowClass();
		WindowClass(const WindowClass&) = delete;
		WindowClass& operator=(const WindowClass&) = delete;
		static constexpr const char* wndClassName = "GenesisClass";
		static WindowClass wndClass;
		HINSTANCE hInst;
	};
public:
	GenWindow(int width, int height, const char* name);
	~GenWindow();
	GenWindow(const GenWindow&) = delete;
	GenWindow& operator=(const GenWindow&) = delete;
	void SetTitle(const std::string& title);
	static std::optional<int> ProcessMessages() noexcept;
	//Graphics& Gfx();
private:
	static LRESULT CALLBACK HandleMsgSetup(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam) noexcept;
	static LRESULT CALLBACK HandleMsgThunk(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam) noexcept;
	LRESULT HandleMsg(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam) noexcept;
public:
	Keyboard kbd;
	//Mouse mouse;
private:
	int width;
	int height;
	HWND hWnd;
	//std::unique_ptr<Graphics> pGfx;
};

// error exception helper macro
#define GENWND_EXCEPT( hr ) GenWindow::HrException( __LINE__,__FILE__,(hr) )
#define GENWND_LAST_EXCEPT() GenWindow::HrException( __LINE__,__FILE__,GetLastError() )
#define GENWND_NOGFX_EXCEPT() GenWindow::NoGfxException( __LINE__,__FILE__ )