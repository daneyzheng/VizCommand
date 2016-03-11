#pragma once

#include "Window.h"

class CEdit : public CWindow {

	public:

		CEdit();
		CEdit(CApplication *pApp);
		virtual BOOL Create(LPCTSTR lpctszWindowName, const RECT &rect, HWND hWndParent, HMENU hMenu, HINSTANCE hInstance);
		virtual int OnClose();
		virtual void OnDestroy();

};