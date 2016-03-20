#pragma once

#include "Edit.h"

class CConsole : public CEdit {

	public:

		HBRUSH m_hBrush;
		
		tstring m_tstrCurrentPath;
		tstring m_tstrForm;
		tstring m_tstrOutputForm;
		long m_lStartPos;

		CConsole();
		CConsole(CApplication *pApp);
		virtual int OnCreate(HWND hwnd, LPCREATESTRUCT lpCreateStruct);
		virtual void OnDestroy();
		virtual HBRUSH OnCtlColorEdit(WPARAM wParam, LPARAM lParam);
		virtual int OnChar(WPARAM wParam, LPARAM lParam);
		virtual int OnSysChar(WPARAM wParam, LPARAM lParam);
		virtual int OnKeyDown(WPARAM wParam, LPARAM lParam);
		virtual int OnLButtonDown(WPARAM wParam, LPARAM lParam);
		virtual int OnLButtonUp(WPARAM wParam, LPARAM lParam);

};
