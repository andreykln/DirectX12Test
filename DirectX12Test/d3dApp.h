#pragma once
#include "Utility.h"

// Link necessary d3d12 libraries, they are linked in the linker settings
//#pragma comment(lib,"d3dcompiler.lib")
//#pragma comment(lib, "D3D12.lib")
//#pragma comment(lib, "dxgi.lib")
class D3DApp
{
public:
	D3DApp(HINSTANCE hInstance);
	D3DApp(const D3DApp& rhs) = delete;
	D3DApp operator=(const D3DApp& rhs) = delete;
	bool Initialize();
	int  Run();
	static D3DApp* GetApp();
	LRESULT MsgProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam);
private:
	bool InitMainWindow();
	bool InitD3D();
	void CreateCommandObjects();
	void CreateSwapChain();
	void CreateRtvAndDsvDescriptorHeaps();
	void Draw(Timer& timer);
	void FlushCommandQueue();
	
	void OnResize();
	void CalculateFrameStats();

	D3D12_CPU_DESCRIPTOR_HANDLE DepthStencilDescriptor()const;
	D3D12_CPU_DESCRIPTOR_HANDLE CurrentBackBufferView()const;
	D3D12_CPU_DESCRIPTOR_HANDLE DepthStencilView()const;
	ID3D12Resource* CurrentBackBuffer()const;

	Timer mTimer;
	static D3DApp* mApp;
	HINSTANCE mhAppInst{ nullptr };
	HWND      mhMainWnd{ nullptr };
	const std::wstring mMainWndCaption{ L"DX 12" };
	LONG	mClientWidth{ 1280 };
	LONG	mClientHeight{ 720 };
	bool	mAppPaused{ false };
	bool	mMinimized{ false };
	bool	mMaximized{ false };
	bool    mResizing{ false };
	bool    mFullscreenState{ false };
	bool    m4xMsaaState = false;    
	UINT    m4xMsaaQuality = 0; 


	Microsoft::WRL::ComPtr<IDXGIFactory4> mdxgiFactory;
	Microsoft::WRL::ComPtr<ID3D12Device> md3dDevice;

	static const int SwapChainBufferCount{ 2 };
	Microsoft::WRL::ComPtr<IDXGISwapChain1> mSwapChain;
	int mCurrBackBuffer = 0;
	Microsoft::WRL::ComPtr<ID3D12Resource> mSwapChainBuffer[SwapChainBufferCount];
	Microsoft::WRL::ComPtr<ID3D12Resource> mDepthStencilBuffer;

	Microsoft::WRL::ComPtr<ID3D12CommandQueue> mCommandQueue;
	Microsoft::WRL::ComPtr<ID3D12CommandAllocator> mDirectCmdListAlloc;
	Microsoft::WRL::ComPtr<ID3D12GraphicsCommandList> mCommandList;

	Microsoft::WRL::ComPtr<ID3D12DescriptorHeap> mRTVHeap;
	Microsoft::WRL::ComPtr<ID3D12DescriptorHeap> mDSVHeap;

	Microsoft::WRL::ComPtr<ID3D12Fence> mFence;
	UINT64 mCurrentFence{ 0 };

	D3D12_VIEWPORT mScreenViewport;
	D3D12_RECT mScissorRect;

	UINT mRtvDescriptorSize{ 0 };
	UINT mDsvDescriptorSize{ 0 };
	UINT mCbvSrvUavDescriptorSize{ 0 };
	const DXGI_FORMAT mBackBufferFormat = DXGI_FORMAT_R8G8B8A8_UNORM;
	const DXGI_FORMAT mDepthStencilFormat = DXGI_FORMAT_D24_UNORM_S8_UINT;

	DXGI_PRESENT_PARAMETERS presentParameters;

};