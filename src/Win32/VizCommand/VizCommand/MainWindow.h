#pragma once

#include "Window.h"

class CApplication;

class CMainWindow : public CWindow {

public:

	CMainWindow();
	CMainWindow(CApplication *pApp);
	virtual int OnCreate(HWND hwnd, LPCREATESTRUCT lpCreateStruct);
	virtual void OnDestroy();

};