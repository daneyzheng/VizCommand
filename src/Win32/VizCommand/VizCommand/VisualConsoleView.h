#pragma once

#include "Window.h"
#include "VisualConsolePanel.h"

#define IDC_VISUALCONSOLEPANEL1 WM_USER + 801

class CApplication;

class CVisualConsoleView : public CWindow {

	public:

		CVisualConsolePanel *m_pVisualConsolePanel;

		CVisualConsoleView();
		CVisualConsoleView(CApplication *pApp);
		~CVisualConsoleView();
		virtual int OnCreate(HWND hwnd, LPCREATESTRUCT lpCreateStruct);
		virtual void OnDestroy();
		virtual int OnClose();
		virtual void OnSize(UINT nType, int cx, int cy);

};
