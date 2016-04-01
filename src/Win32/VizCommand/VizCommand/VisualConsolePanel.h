#pragma once

#include "Window.h"
#include "VisualConsole.h"

#define IDC_VISUALCONSOLE1 WM_USER + 1201

class CVisualConsole;

class CVisualConsolePanel : public CWindow {

	public:

		HBRUSH m_hBrush;

		CVisualConsole *m_pVisualConsole;

		CVisualConsolePanel();
		CVisualConsolePanel(CApplication *pApp);
		virtual BOOL Create(LPCTSTR lpctszWindowName, const RECT &rect, HWND hWndParent, HMENU hMenu, HINSTANCE hInstance);
		virtual void Destroy();
		virtual int OnCreate(HWND hwnd, LPCREATESTRUCT lpCreateStruct);
		virtual void OnDestroy();
		virtual HBRUSH OnCtlColorEdit(WPARAM wParam, LPARAM lParam);

		static BOOL RegisterClass(HINSTANCE hInstance);

};
