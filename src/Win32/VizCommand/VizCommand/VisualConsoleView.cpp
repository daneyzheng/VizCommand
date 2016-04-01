#include "VisualConsoleView.h"

CVisualConsoleView::CVisualConsoleView() : CWindow() {

	m_pVisualConsolePanel = NULL;

}

CVisualConsoleView::CVisualConsoleView(CApplication * pApp) : CWindow(pApp) {

	m_pVisualConsolePanel = NULL;

}

CVisualConsoleView::~CVisualConsoleView() {

	if (m_pVisualConsolePanel != NULL) {
		delete m_pVisualConsolePanel;
		m_pVisualConsolePanel = NULL;
	}

}

int CVisualConsoleView::OnCreate(HWND hwnd, LPCREATESTRUCT lpCreateStruct) {

	RECT rc;

	GetClientRect(hwnd, &rc);

	m_pVisualConsolePanel = new CVisualConsolePanel(m_pApp);

	m_pVisualConsolePanel->Create(_T(""), rc, hwnd, (HMENU)IDC_VISUALCONSOLEPANEL1, lpCreateStruct->hInstance);

	return 0;

}

void CVisualConsoleView::OnDestroy() {

	__super::OnDestroy();

}

int CVisualConsoleView::OnClose() {

	if (m_pVisualConsolePanel != NULL) {
		m_pVisualConsolePanel->Destroy();
		delete m_pVisualConsolePanel;
		m_pVisualConsolePanel = NULL;
	}

	return 0;

}

void CVisualConsoleView::OnSize(UINT nType, int cx, int cy) {

	if (m_pVisualConsolePanel != NULL) {

		MoveWindow(m_pVisualConsolePanel->m_hWnd, 0, 0, cx, cy, TRUE);

	}

}
