#include "VisualConsoleWindow.h"

CVisualConsoleWindow::CVisualConsoleWindow() : CVisualConsoleView() {

	m_pMenu = NULL;

}

CVisualConsoleWindow::CVisualConsoleWindow(CApplication * pApp) : CVisualConsoleView(pApp) {

	m_pMenu = NULL;

}

CVisualConsoleWindow::~CVisualConsoleWindow() {

	if (m_pVisualConsolePanel != NULL) {
		delete m_pVisualConsolePanel;
		m_pVisualConsolePanel = NULL;
	}

	if (m_pMenu) {

		delete m_pMenu;
		m_pMenu = NULL;

	}

}

int CVisualConsoleWindow::OnCreate(HWND hwnd, LPCREATESTRUCT lpCreateStruct) {

	m_pMenu = new CMenu(lpCreateStruct->hInstance);

	m_pMenu->LoadMenu(IDR_MENU);

	m_pMenu->SetMenu(hwnd);

	RECT rc;

	GetClientRect(hwnd, &rc);

	m_pVisualConsolePanel = new CVisualConsolePanel(m_pApp);

	m_pVisualConsolePanel->Create(_T(""), rc, hwnd, (HMENU)IDC_VISUALCONSOLEPANEL1, lpCreateStruct->hInstance);

	return 0;

}

void CVisualConsoleWindow::OnDestroy() {

	if (m_pMenu) {

		delete m_pMenu;
		m_pMenu = NULL;

	}

	__super::OnDestroy();

}

BOOL CVisualConsoleWindow::OnCommand(WPARAM wParam, LPARAM lParam) {

	if (HIWORD(wParam) == 0) {

		return m_pMenu->OnCommandMenuItem(wParam, lParam);

	}
	else {

		return FALSE;

	}

}
