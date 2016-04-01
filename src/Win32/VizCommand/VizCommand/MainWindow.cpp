#include <vector>

#include "MainWindow.h"
#include "MainMenu.h"
#include "Edit.h"
#include "DropDownList.h"
#include "Console.h"

CMainWindow::CMainWindow() : CVisualConsoleWindow() {

}

CMainWindow::CMainWindow(CApplication *pApp) : CVisualConsoleWindow(pApp) {

}

int CMainWindow::OnCreate(HWND hwnd, LPCREATESTRUCT lpCreateStruct) {

	m_pMenu = new CMainMenu(m_pApp, lpCreateStruct->hInstance);

	m_pMenu->LoadMenu(IDR_MENU);

	m_pMenu->SetMenu(hwnd);

	RECT rc;	// RECT rc = { 50, 50, 200, 200 };

	GetClientRect(hwnd, &rc);

	//m_pEdit = new CEdit(m_pApp);

	//m_pEdit->Create(_T(""), rc, hwnd, (HMENU)IDC_EDIT1, lpCreateStruct->hInstance);

	//m_pStatic = new CStatic(m_pApp);

	//m_pStatic->Create(_T(""), rc, hwnd, (HMENU)IDC_STATIC1, lpCreateStruct->hInstance);

	m_pVisualConsolePanel = new CVisualConsolePanel(m_pApp);

	m_pVisualConsolePanel->Create(_T(""), rc, hwnd, (HMENU)IDC_VISUALCONSOLEPANEL1, lpCreateStruct->hInstance);
	
	//m_pMulti->m_vecpWindowList[0]->
#if FALSE

	CDropDownList *pEncodeCB = new CDropDownList(m_pApp);

	RECT rc1;
	rc1.top = 0;
	rc1.left = 0;
	rc1.right = rc.right;
	rc1.bottom = 28;

	m_pMulti->Add(pEncodeCB, _T(""), rc1, (HMENU)IDC_MULTI1 + 1, lpCreateStruct->hInstance);

	CEdit *pTextEdit = new CEdit(m_pApp);

	RECT rc2;
	rc2.top = rc1.bottom;
	rc2.left = 0;
	rc2.right = rc.right;
	rc2.bottom = rc.bottom - 28;

	m_pMulti->Add(pTextEdit, _T(""), rc2, (HMENU)IDC_MULTI1 + 2, lpCreateStruct->hInstance);

	CDropDownList *pLineFeedCB = new CDropDownList(m_pApp);

	RECT rc3;
	rc3.top = rc2.bottom;
	rc3.left = 0;
	rc3.right = rc.right;
	rc3.bottom = rc.bottom;

	m_pMulti->Add(pLineFeedCB, _T(""), rc3, (HMENU)IDC_MULTI1 + 3, lpCreateStruct->hInstance);

#endif

	return 0;

}

#if FALSE

void CMainWindow::OnDestroy() {

	PostQuitMessage(0);

}

#endif

#if FALSE

int CMainWindow::OnClose() {
	

	if (m_pEdit != NULL) {
		m_pEdit->Destroy();
		delete m_pEdit;
		m_pEdit = NULL;
	}

	if (m_pStatic != NULL) {
		m_pStatic->Destroy();
		delete m_pStatic;
		m_pStatic = NULL;
	}

	if (m_pMulti != NULL) {
		m_pMulti->Destroy();
		delete m_pMulti;
		m_pMulti = NULL;
	}

	return 0;

}

#endif

#if FALSE

void CMainWindow::OnSize(UINT nType, int cx, int cy) {

	if (m_pEdit != NULL) {
		MoveWindow(m_pEdit->m_hWnd, 0, 0, cx, cy, TRUE);
	}

	if (m_pStatic != NULL) {
		MoveWindow(m_pStatic->m_hWnd, 0, 0, cx, cy, TRUE);
	}

	if (m_pMulti != NULL) {
		MoveWindow(m_pMulti->m_hWnd, 0, 0, cx, cy, TRUE);
	}

}

#endif