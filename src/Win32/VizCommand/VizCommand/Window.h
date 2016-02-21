#pragma once

#include <windows.h>
#include <tchar.h>
#include <map>

#include "Application.h"

class CApplication;

class CWindow {

	public:

		static std::map<HWND, CWindow *>m_mapWindowMap;

		HWND m_hWnd;
		CApplication *m_pApp;

		CWindow();
		CWindow(CApplication *pApp);
		virtual ~CWindow();

		static BOOL RegisterClass(HINSTANCE hInstance);

		virtual BOOL Create(LPCTSTR lpctszWindowName, const RECT &rect, HINSTANCE hInstance);
		virtual BOOL ShowWindow(int nCmdShow);
		virtual LRESULT DynamicWindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

		virtual int OnCreate(HWND hwnd, LPCREATESTRUCT lpCreateStruct);
		virtual void OnDestroy();

		static LRESULT CALLBACK StaticWindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

};