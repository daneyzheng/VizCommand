#include "MainWindow.h"

CMainWindow::CMainWindow() : CWindow() {

	m_pMenu = NULL;

}

CMainWindow::CMainWindow(CApplication *pApp) : CWindow(pApp) {

	if (m_pMenu != NULL) {

		delete m_pMenu;
		m_pMenu = NULL;

	}

}

int CMainWindow::OnCreate(HWND hwnd, LPCREATESTRUCT lpCreateStruct) {

	m_pMenu = new CMenu(lpCreateStruct->hInstance);

	m_pMenu->LoadMenu(IDR_MENU);

	m_pMenu->SetMenu(hwnd);

	return 0;

}

void CMainWindow::OnDestroy() {

	if (m_pMenu) {

		delete m_pMenu;
		m_pMenu = NULL;

	}

	PostQuitMessage(0);

}

BOOL CMainWindow::OnCommand(WPARAM wParam, LPARAM lParam)
{
	if (HIWORD(wParam) == 0) {

		return m_pMenu->OnCommandMenuItem(wParam, lParam);

	}
	else {

		return FALSE;

	}

}
