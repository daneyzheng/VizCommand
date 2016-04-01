#include "VisualConsolePanel.h"

CVisualConsolePanel::CVisualConsolePanel() : CWindow() {

}

CVisualConsolePanel::CVisualConsolePanel(CApplication * pApp) : CWindow(pApp) {

}

BOOL CVisualConsolePanel::Create(LPCTSTR lpctszWindowName, const RECT & rect, HWND hWndParent, HMENU hMenu, HINSTANCE hInstance) {
	
	return CWindow::Create(_T("CVisualConsolePanel"), lpctszWindowName, WS_CHILD | WS_VISIBLE/* | WS_VSCROLL | WS_HSCROLL*/, rect, hWndParent, hMenu, hInstance, FALSE);

}

void CVisualConsolePanel::Destroy() {

	m_pVisualConsole->CMulti::Destroy();

	DestroyWindow(m_hWnd);
	m_hWnd = NULL;

}

int CVisualConsolePanel::OnCreate(HWND hwnd, LPCREATESTRUCT lpCreateStruct) {

	m_hBrush = CreateSolidBrush(RGB(0x00, 0x00, 0x00));

	RECT rc;	// RECT rc = { 50, 50, 200, 200 };

	GetClientRect(hwnd, &rc);

	m_pVisualConsole = new CVisualConsole(m_pApp);

	m_pVisualConsole->Create(_T(""), rc, hwnd, (HMENU)IDC_VISUALCONSOLE1, lpCreateStruct->hInstance);

	return 0;

}

void CVisualConsolePanel::OnDestroy() {

	if (m_hBrush) {
		DeleteObject(m_hBrush);
		m_hBrush = NULL;
	}

}

HBRUSH CVisualConsolePanel::OnCtlColorEdit(WPARAM wParam, LPARAM lParam) {

	HDC hDC = (HDC)wParam;

	SetBkMode(hDC, OPAQUE);
	SetBkColor(hDC, RGB(0x00, 0x00, 0x00));
	SetTextColor(hDC, RGB(0xFF, 0xFF, 0xFF));
	return m_hBrush;

}

BOOL CVisualConsolePanel::RegisterClass(HINSTANCE hInstance) {

	WNDCLASS wc;

	wc.lpszClassName = _T("CVisualConsolePanel");
	wc.style = CS_HREDRAW | CS_VREDRAW;
	wc.lpfnWndProc = CWindow::StaticWindowProc;
	wc.hInstance = hInstance;
	wc.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	wc.hCursor = LoadCursor(NULL, IDC_ARROW);
	wc.hbrBackground = (HBRUSH)GetStockObject(GRAY_BRUSH);
	wc.lpszMenuName = NULL;
	wc.cbClsExtra = 0;
	wc.cbWndExtra = 0;

	if (!::RegisterClass(&wc)) {

		return FALSE;

	}

	if (CWindow::m_mapBaseWindowClassMap.find(wc.lpszClassName) == CWindow::m_mapBaseWindowClassMap.end()) {
		CWindow::m_mapBaseWindowClassMap.insert(std::pair<tstring, WNDPROC>(wc.lpszClassName, DefWindowProc));
	}

	return TRUE;

}
