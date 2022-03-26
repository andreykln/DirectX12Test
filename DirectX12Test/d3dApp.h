#pragma once
#include "Utility.h"


class D3DApp
{
public:
	D3DApp(HINSTANCE hInstance);
	D3DApp(const D3DApp& rhs) = delete;
	D3DApp operator=(const D3DApp& rhs) = delete;

	bool InitMainWindow();
	LRESULT MsgProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam);
	static D3DApp* GetApp();
	int Run();
	void OnResize();
	void CalculateFrameStats();
public:
	Timer mTimer;
	static D3DApp* mApp;
	HINSTANCE mhAppInst = nullptr;
	HWND      mhMainWnd = nullptr;
	std::wstring mMainWndCaption = L"DX 12";
	LONG mClientWidth = 1280;
	LONG mClientHeight = 720;
	bool      mAppPaused = false;
	bool      mMinimized = false;
	bool      mMaximized = false;
	bool      mResizing = false;
	bool      mFullscreenState = false;
};