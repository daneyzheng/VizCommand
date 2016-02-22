#include "MenuWindow.h"

CMenuWindow::CMenuWindow() : CWindow() {

	m_pMenu = NULL;

}

CMenuWindow::CMenuWindow(CApplication *pApp) : CWindow(pApp) {

	m_pMenu = NULL;

}

int CMenuWindow::OnCreate(HWND hwnd, LPCREATESTRUCT lpCreateStruct) {

	m_pMenu = new CMenu(lpCreateStruct->hInstance);

	m_pMenu->LoadMenu(IDR_MENU);

	m_pMenu->SetMenu(hwnd);

	return 0;

}

void CMenuWindow::OnDestroy() {

	if (m_pMenu) {

		delete m_pMenu;
		m_pMenu = NULL;

	}

	PostQuitMessage(0);

}

BOOL CMenuWindow::OnCommand(WPARAM wParam, LPARAM lParam)
{
	if (HIWORD(wParam) == 0) {

		return m_pMenu->OnCommandMenuItem(wParam, lParam);

	}
	else {

		return FALSE;

	}

}