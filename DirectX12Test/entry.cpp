
#include "d3dApp.h"

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE prevInstance,
	PSTR cmdLine, int showCmd)
{
	D3DApp pApp(hInstance);
	pApp.InitMainWindow();
}