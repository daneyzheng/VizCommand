#include "Application.h"

int WINAPI _tWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPTSTR lpCmdLine, int nShowCmd) {

	CApplication *pApp;
	int iRet;

	pApp = new CApplication();

	if (!pApp->InitInstance(hInstance, lpCmdLine, nShowCmd)) {

		pApp->ExitInstance();
		delete pApp;
		return -1;

	}

	iRet = pApp->Run();

	delete pApp;

	return 0;

}