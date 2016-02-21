#pragma once

#include <windows.h>
#include <tchar.h>

#include "resource.h"

class CMenu {

	public:

		HINSTANCE m_hInstance;
		HMENU m_hMenu;
		HWND m_hWnd;

		CMenu();
		CMenu(HINSTANCE hInstance);
		virtual ~CMenu();

		virtual BOOL LoadMenu(UINT nIDResource);
		virtual BOOL SetMenu(HWND hwnd);
		virtual BOOL OnCommandMenuItem(WPARAM wParam, LPARAM lParam);

};