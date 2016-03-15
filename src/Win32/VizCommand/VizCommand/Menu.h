#pragma once

#include <windows.h>
#include <tchar.h>

#include "Application.h"
#include "resource.h"

class CMenu {

	public:

		HINSTANCE m_hInstance;
		HMENU m_hMenu;
		HWND m_hWnd;
		CApplication *m_pApp;

		CMenu();
		CMenu(HINSTANCE hInstance);
		CMenu(CApplication *pApp, HINSTANCE hInstance);
		virtual ~CMenu();

		virtual BOOL LoadMenu(UINT nIDResource);
		virtual BOOL SetMenu(HWND hwnd);
		virtual BOOL OnCommandMenuItem(WPARAM wParam, LPARAM lParam);

};