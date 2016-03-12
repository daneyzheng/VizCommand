#pragma once

#include <vector>

#include "Window.h"

class CMulti : public CWindow {

	public:

		std::vector<CWindow *> m_vecpWindowList;
		CMulti();
		CMulti(CApplication *pApp);
		virtual BOOL Create(LPCTSTR lpctszWindowName, const RECT &rect, HWND hWndParent, HMENU hMenu, HINSTANCE hInstance);
		virtual int OnCreate(HWND hwnd, LPCREATESTRUCT lpCreateStruct);
		virtual void OnDestroy();

		static BOOL RegisterClass(HINSTANCE hInstance);

};