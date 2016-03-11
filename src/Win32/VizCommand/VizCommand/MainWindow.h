#pragma once

#include "MenuWindow.h"
#include "Edit.h"
#include "Static.h"

#define IDC_EDIT1 WM_USER + 201
#define IDC_STATIC1 WM_USER + 301

class CMainWindow : public CMenuWindow {

	public:

		CEdit *m_pEdit;
		CStatic *m_pStatic;

		CMainWindow();
		CMainWindow(CApplication *pApp);
		virtual ~CMainWindow();
		virtual int OnCreate(HWND hwnd, LPCREATESTRUCT lpCreateStruct);
		virtual void OnDestroy();
		virtual int OnClose();
		virtual void OnSize(UINT nType, int cx, int cy);

};