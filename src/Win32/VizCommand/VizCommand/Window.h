#pragma once

#include <windows.h>
#include <tchar.h>
#include <map>

#include "Application.h"

#ifdef UNICODE
#define tstring std::wstring
#else
#define tstring std::string
#endif

class CApplication;

class CWindow {

	public:

		static std::map<HWND, CWindow *> m_mapWindowMap;
		static std::map<tstring, WNDPROC> m_mapBaseWindowClassMap;

		HWND m_hWnd;
		CApplication *m_pApp;
		tstring m_tstrClassName;
		WNDPROC m_lpfnWndProc;

		CWindow();
		CWindow(CApplication *pApp);
		virtual ~CWindow();

		static BOOL RegisterClass(HINSTANCE hInstance);

		virtual BOOL Create(LPCTSTR lpctszWindowName, const RECT &rect, HINSTANCE hInstance);
		virtual BOOL Create(LPCTSTR lpctszWindowName, const RECT &rect, HWND hWndParent, HMENU hMenu, HINSTANCE hInstance);
		virtual BOOL Create(LPCTSTR lpctszClassName, LPCTSTR lpctszWindowName, DWORD dwStyle, const RECT & rect, HWND hWndParent, HMENU hMenu, HINSTANCE hInstance, BOOL bProcChange);
		virtual void Destroy();

		virtual int OnClose();
		virtual void OnSize(UINT nType, int cx, int cy);

		virtual BOOL ShowWindow(int nCmdShow);
		virtual LRESULT DynamicWindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

		virtual int OnCreate(HWND hwnd, LPCREATESTRUCT lpCreateStruct);
		virtual void OnDestroy();
		virtual BOOL OnCommand(WPARAM wParam, LPARAM lParam);

		static LRESULT CALLBACK StaticWindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

};