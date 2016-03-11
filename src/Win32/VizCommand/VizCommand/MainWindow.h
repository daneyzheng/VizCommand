#pragma once

#include "MenuWindow.h"
#include "Edit.h"

#define IDC_EDIT1 WM_USER + 201

class CMainWindow : public CMenuWindow {

	public:

		CEdit *m_pEdit;

		CMainWindow();
		CMainWindow(CApplication *pApp);
		virtual ~CMainWindow();
		virtual int OnCreate(HWND hwnd, LPCREATESTRUCT lpCreateStruct);
		virtual void OnDestroy();
		virtual int OnClose();

};