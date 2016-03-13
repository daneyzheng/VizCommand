#pragma once

#include "MultiView.h"
#include "Menu.h"

#define IDC_MULTI1 WM_USER + 401

class CMultiWindow : public CMultiView {

	public:

		CMenu *m_pMenu;

		CMultiWindow();
		CMultiWindow(CApplication *pApp);
		~CMultiWindow();
		virtual int OnCreate(HWND hwnd, LPCREATESTRUCT lpCreateStruct);
		virtual void OnDestroy();
		virtual BOOL OnCommand(WPARAM wParam, LPARAM lParam);

};