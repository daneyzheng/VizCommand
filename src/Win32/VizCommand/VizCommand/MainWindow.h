#pragma once

#include "Window.h"
#include "Menu.h"

class CApplication;

class CMainWindow : public CWindow {

	public:

		CMenu *m_pMenu;

		CMainWindow();
		CMainWindow(CApplication *pApp);
		virtual int OnCreate(HWND hwnd, LPCREATESTRUCT lpCreateStruct);
		virtual void OnDestroy();
		virtual BOOL OnCommand(WPARAM wParam, LPARAM lParam);

};