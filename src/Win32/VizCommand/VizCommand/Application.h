#pragma once

#include <windows.h>
#include <tchar.h>

#include "Window.h"

class CWindow;

class CApplication {

	private:

		HWND m_hWnd;

	public:

		HINSTANCE m_hInstance;
		CWindow *m_pWindow;


		CApplication();
		virtual ~CApplication();

		virtual BOOL InitInstance(HINSTANCE hInstance, LPTSTR lpCmdLine, int nShowCmd);
		virtual int Run();
		virtual int ExitInstance();
		virtual BOOL OnIdle(LONG lCount);

};

LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);