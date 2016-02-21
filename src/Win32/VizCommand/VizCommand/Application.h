#pragma once

#include <windows.h>
#include <tchar.h>

class CApplication {

	public:

		HINSTANCE m_hInstance;
		HWND m_hWnd;

		CApplication();
		virtual ~CApplication();

		virtual BOOL InitInstance(HINSTANCE hInstance, LPTSTR lpCmdLine, int nShowCmd);
		virtual int Run();
		virtual int ExitInstance();
		virtual BOOL OnIdle(LONG lCount);

};

LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);