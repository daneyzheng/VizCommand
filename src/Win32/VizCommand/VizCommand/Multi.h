#pragma once

#include "Window.h"

class CMulti : public CWindow {

	public:

		CMulti();
		CMulti(CApplication *pApp);
		virtual BOOL Create(LPCTSTR lpctszWindowName, const RECT &rect, HWND hWndParent, HMENU hMenu, HINSTANCE hInstance);
		virtual void OnDestroy();

		static BOOL RegisterClass(HINSTANCE hInstance);

};