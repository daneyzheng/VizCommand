#pragma once

//#include "MenuWindow.h"
//#include "Edit.h"
//#include "Static.h"
//#include "Multi.h"
#include "MultiWindow.h"

//#define IDC_EDIT1 WM_USER + 201
//#define IDC_STATIC1 WM_USER + 301
//#define IDC_MULTI1 WM_USER + 401
#define IDC_CONSOLE1 WM_USER + 501

//class CMainWindow : public CMenuWindow {
class CMainWindow : public CMultiWindow {
	
	public:

		//CEdit *m_pEdit;
		//CStatic *m_pStatic;
		//CMulti *m_pMulti;

		CMainWindow();
		CMainWindow(CApplication *pApp);
		virtual int OnCreate(HWND hwnd, LPCREATESTRUCT lpCreateStruct);
		//virtual void OnDestroy();
		//virtual int OnClose();
		//virtual void OnSize(UINT nType, int cx, int cy);

};