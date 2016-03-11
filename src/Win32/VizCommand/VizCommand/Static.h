#pragma once

#include "Window.h"

class CStatic : public CWindow {

	public:

		CStatic();
		CStatic(CApplication *pApp);
		virtual BOOL Create(LPCTSTR lpctszWindowName, const RECT &rect, HWND hWndParent, HMENU hMenu, HINSTANCE hInstance);
		virtual void OnDestroy();
};