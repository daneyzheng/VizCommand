#pragma once

#include "Window.h"
#include "Multi.h"

#define IDC_MULTI1 WM_USER + 401

class CApplication;

class CMultiView : public CWindow {

	public:

		CMulti *m_pMulti;

		CMultiView();
		CMultiView(CApplication *pApp);
		~CMultiView();
		virtual int OnCreate(HWND hwnd, LPCREATESTRUCT lpCreateStruct);
		virtual void OnDestroy();
		virtual int OnClose();
		virtual void OnSize(UINT nType, int cx, int cy);

};
