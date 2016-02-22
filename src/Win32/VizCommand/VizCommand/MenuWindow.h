#pragma once

#include "Window.h"
#include "Menu.h"

class CApplication;

class CMenuWindow : public CWindow {

	public:

		CMenu *m_pMenu;

		CMenuWindow();
		CMenuWindow(CApplication *pApp);
		virtual int OnCreate(HWND hwnd, LPCREATESTRUCT lpCreateStruct);
		virtual void OnDestroy();
		virtual BOOL OnCommand(WPARAM wParam, LPARAM lParam);

};
