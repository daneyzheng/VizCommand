#pragma once

#include "Console.h"
#include "Multi.h"
#include "VisualConsolePanel.h"

class CVisualConsolePanel;

class CVisualConsole : public CConsole, public CMulti {

	public:

		CVisualConsole();
		CVisualConsole(CApplication *pApp);
		virtual BOOL Create(LPCTSTR lpctszWindowName, const RECT &rect, HWND hWndParent, HMENU hMenu, HINSTANCE hInstance);
		virtual int OnCreate(HWND hwnd, LPCREATESTRUCT lpCreateStruct);
		virtual void OnDestroy();
		virtual HBRUSH OnCtlColorEdit(WPARAM wParam, LPARAM lParam);
		virtual int OnChar(WPARAM wParam, LPARAM lParam);
		virtual void PutResponseAction();

};