#pragma once

#include "Window.h"

class CListCtrl : public CWindow {

	public:

		CListCtrl();
		CListCtrl(CApplication *pApp);
		virtual BOOL Create(LPCTSTR lpctszWindowName, const RECT &rect, HWND hWndParent, HMENU hMenu, HINSTANCE hInstance);
		virtual int OnCreate(HWND hwnd, LPCREATESTRUCT lpCreateStruct);
		virtual void OnDestroy();
};
