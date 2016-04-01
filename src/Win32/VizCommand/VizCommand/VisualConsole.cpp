#include "VisualConsole.h"

CVisualConsole::CVisualConsole(): CConsole() {

}

CVisualConsole::CVisualConsole(CApplication * pApp) : CConsole(pApp) {

}

BOOL CVisualConsole::Create(LPCTSTR lpctszWindowName, const RECT & rect, HWND hWndParent, HMENU hMenu, HINSTANCE hInstance) {

	CConsole::Create(lpctszWindowName, rect, hWndParent, hMenu, hInstance);
	HWND hwnd = this->CConsole::m_hWnd;
	HWND hwnd2 = this->CMulti::m_hWnd;
	this->CMulti::m_hWnd = CConsole::m_hWnd;
	return TRUE;
}

int CVisualConsole::OnCreate(HWND hwnd, LPCREATESTRUCT lpCreateStruct) {

	CConsole::OnCreate(hwnd, lpCreateStruct);

	CConsole::m_hBrush = CreateSolidBrush(RGB(0xFF, 0xFF, 0xFF));

	return 0;

}

void CVisualConsole::OnDestroy() {

	if (CConsole::m_hBrush) {
		DeleteObject(CConsole::m_hBrush);
		CConsole::m_hBrush = NULL;
	}

}

HBRUSH CVisualConsole::OnCtlColorEdit(WPARAM wParam, LPARAM lParam) {

	HDC hDC = (HDC)wParam;

	SetBkMode(hDC, OPAQUE);
	SetBkColor(hDC, RGB(0xFF, 0xFF, 0xFF));
	SetTextColor(hDC, RGB(0x00, 0x00, 0x00));
	return CConsole::m_hBrush;

}

int CVisualConsole::OnChar(WPARAM wParam, LPARAM lParam) {

	if ((UINT)wParam == VK_BACK) {
		long lCurrentPos = 0;
		SendMessage(CWindow::m_hWnd, EM_GETSEL, (WPARAM)&lCurrentPos, NULL);
		if (lCurrentPos <= m_lStartPos) {
			return -1;
		}
	}

	if ((UINT)wParam == VK_RETURN) {

		GetCommandLineString();
		PutResponseAction();
		PutString(m_tstrOutputForm);
		return -1;

	}

	return 0;

}

void CVisualConsole::PutResponseAction() {

	if (m_tstrCommandLineString == _T("ls")) {
		for (int i = 0; i < 6; i++) {
			PutString(_T("\r\n\r\n"));
		}
		CEdit *pEdit = new CEdit(CWindow::m_pApp);
		RECT rc;
		rc.top = 50;
		rc.left = 0;
		rc.right = 640;
		rc.bottom = 50 + 100;
		Add(_T("hoge"), pEdit, _T("foobar"), rc, (HMENU)IDC_VISUALCONSOLE1 + 1, CWindow::m_pApp->m_hInstance);
	}
	else {
		PutString(_T("\r\n\r\n"));
	}

}
