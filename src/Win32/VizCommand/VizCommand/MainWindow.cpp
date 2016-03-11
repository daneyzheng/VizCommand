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

	if (m_pStatic != NULL) {
		delete m_pStatic;
		m_pStatic = NULL;
	}

}

int CMainWindow::OnCreate(HWND hwnd, LPCREATESTRUCT lpCreateStruct) {

	m_pMenu = new CMainMenu(lpCreateStruct->hInstance);

	m_pMenu->LoadMenu(IDR_MENU);

	m_pMenu->SetMenu(hwnd);

	RECT rc;	// RECT rc = { 50, 50, 200, 200 };

	GetClientRect(hwnd, &rc);

	//m_pEdit = new CEdit(m_pApp);

	//m_pEdit->Create(_T(""), rc, hwnd, (HMENU)IDC_EDIT1, lpCreateStruct->hInstance);

	m_pStatic = new CStatic(m_pApp);

	m_pStatic->Create(_T(""), rc, hwnd, (HMENU)IDC_STATIC1, lpCreateStruct->hInstance);


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

	if (m_pStatic != NULL) {
		DestroyWindow(m_pStatic->m_hWnd);
		delete m_pStatic;
		m_pStatic = NULL;
	}

	return 0;

}

void CMainWindow::OnSize(UINT nType, int cx, int cy) {

	if (m_pEdit != NULL) {
		MoveWindow(m_pEdit->m_hWnd, 0, 0, cx, cy, TRUE);
	}

	if (m_pStatic != NULL) {
		MoveWindow(m_pStatic->m_hWnd, 0, 0, cx, cy, TRUE);
	}

}
