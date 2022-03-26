#pragma once
#include "Utility.h"

class D3DApp
{
public:
	D3DApp(HINSTANCE hInstance)
		: mhAppInst(hInstance)
	{
		assert(mApp == nullptr);
		mApp = this;
	}
	D3DApp(const D3DApp& rhs) = delete;
	D3DApp operator=(const D3DApp& rhs) = delete;

	bool InitMainWindow();
	LRESULT MsgProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam);
	static D3DApp* GetApp();
public:
	static D3DApp* mApp;
	HINSTANCE mhAppInst = nullptr;
	HWND      mhMainWnd = nullptr;
	std::wstring mMainWndCaption = L"d3d App";
	const LONG mClientWidth = 1280;
	const LONG mClientHeight = 720;
};