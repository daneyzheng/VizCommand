#pragma once

#include <vector>
#include <map>

#include "Window.h"

class CMulti : public CWindow {

	public:

		//std::vector<CWindow *> m_vecpWindowList;
		std::map<tstring, CWindow *> m_mapSubWindowMap;
		HBRUSH m_hBrush;

		CMulti();
		CMulti(CApplication *pApp);
		virtual BOOL Create(LPCTSTR lpctszWindowName, const RECT &rect, HWND hWndParent, HMENU hMenu, HINSTANCE hInstance);
		//virtual BOOL Add(CWindow *pWindow, LPCTSTR lpctszWindowName, const RECT &rect, HMENU hMenu, HINSTANCE hInstance);
		virtual BOOL Add(tstring tstrWindowID, CWindow *pWindow, LPCTSTR lpctszWindowName, const RECT &rect, HMENU hMenu, HINSTANCE hInstance);
		virtual void Destroy();
		virtual int OnCreate(HWND hwnd, LPCREATESTRUCT lpCreateStruct);
		virtual void OnDestroy();
		virtual HBRUSH OnCtlColorEdit(WPARAM wParam, LPARAM lParam);
		virtual int OnChar(WPARAM wParam, LPARAM lParam);

		static BOOL RegisterClass(HINSTANCE hInstance);

};