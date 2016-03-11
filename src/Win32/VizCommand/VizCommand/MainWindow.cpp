#include "MainWindow.h"
#include "MainMenu.h"

CMainWindow::CMainWindow() : CMenuWindow() {

	m_pMenu = NULL;

}

CMainWindow::CMainWindow(CApplication *pApp) : CMenuWindow(pApp) {

	m_pMenu = NULL;

}

CMainWindow::~CMainWindow() {

	m_pMenu = NULL;

	if (m_pEdit != NULL) {
		delete m_pEdit;
		m_pEdit = NULL;
	}

}

int CMainWindow::OnCreate(HWND hwnd, LPCREATESTRUCT lpCreateStruct) {

	m_pMenu = new CMainMenu(lpCreateStruct->hInstance);

	m_pMenu->LoadMenu(IDR_MENU);

	m_pMenu->SetMenu(hwnd);

	RECT rc = { 50, 50, 200, 200 };

	m_pEdit = new CEdit(m_pApp);

	m_pEdit->Create(_T(""), rc, hwnd, (HMENU)IDC_EDIT1, lpCreateStruct->hInstance);

	return 0;

}

void CMainWindow::OnDestroy() {

	PostQuitMessage(0);

}

int CMainWindow::OnClose() {


	if (m_pEdit != NULL) {
		DestroyWindow(m_pEdit->m_hWnd);
		delete m_pEdit;
		m_pEdit = NULL;
	}

	return 0;

}
