#pragma once

#include "VisualConsoleView.h"
#include "Menu.h"

#define IDC_VISUALCONSOLEPANEL1 WM_USER + 801

class CVisualConsoleWindow : public CVisualConsoleView {

	public:

		CMenu *m_pMenu;

		CVisualConsoleWindow();
		CVisualConsoleWindow(CApplication *pApp);
		~CVisualConsoleWindow();
		virtual int OnCreate(HWND hwnd, LPCREATESTRUCT lpCreateStruct);
		virtual void OnDestroy();
		virtual BOOL OnCommand(WPARAM wParam, LPARAM lParam);

};