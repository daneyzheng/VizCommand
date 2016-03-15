#include "Console.h"

CConsole::CConsole() : CEdit() {

	m_hBrush = NULL;

}

CConsole::CConsole(CApplication * pApp) : CEdit(pApp) {

	m_hBrush = NULL;
}

int CConsole::OnCreate(HWND hwnd, LPCREATESTRUCT lpCreateStruct) {

	m_hBrush = CreateSolidBrush(RGB(0x00, 0x00, 0x00));

	return 0;

}

void CConsole::OnDestroy() {

	if (m_hBrush) {
		DeleteObject(m_hBrush);
		m_hBrush = NULL;
	}

}

HBRUSH CConsole::OnCtlColorEdit(WPARAM wParam, LPARAM lParam) {

	HDC hDC = (HDC)wParam;

	SetBkMode(hDC, OPAQUE);
	SetBkColor(hDC, RGB(0x00, 0x00, 0x00));
	SetTextColor(hDC, RGB(0xFF, 0xFF, 0xFF));
	return m_hBrush;

}
