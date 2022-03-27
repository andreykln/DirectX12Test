
#include "d3dApp.h"

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE prevInstance,
	PSTR cmdLine, int showCmd)
{
	try
	{
		D3DApp pApp(hInstance);
		if(!pApp.Initialize())
		return 0;
		
		return pApp.Run();
	}
	catch (const DxException& e)
	{
		MessageBox(nullptr, e.ToString().c_str(), L"HR Failed", MB_OK);
		return 0;
	}

	
}