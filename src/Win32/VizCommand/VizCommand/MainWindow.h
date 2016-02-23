#pragma once

#include "MenuWindow.h"

class CMainWindow : public CMenuWindow {

	public:

		CMainWindow();
		CMainWindow(CApplication *pApp);
		virtual int OnCreate(HWND hwnd, LPCREATESTRUCT lpCreateStruct);

};