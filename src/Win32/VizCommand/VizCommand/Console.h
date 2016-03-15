#pragma once

#include "Edit.h"

class CConsole : public CEdit {

	public:

		HBRUSH m_hBrush;

		CConsole();
		CConsole(CApplication *pApp);
		virtual int OnCreate(HWND hwnd, LPCREATESTRUCT lpCreateStruct);
		virtual void OnDestroy();
		virtual HBRUSH OnCtlColorEdit(WPARAM wParam, LPARAM lParam);

};
