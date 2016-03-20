#include <shlobj.h>

#include "Console.h"

CConsole::CConsole() : CEdit() {

	m_hBrush = NULL;

}

CConsole::CConsole(CApplication * pApp) : CEdit(pApp) {

	m_hBrush = NULL;
}

int CConsole::OnCreate(HWND hwnd, LPCREATESTRUCT lpCreateStruct) {

	TCHAR tszPath[1024];

	::SHGetSpecialFolderPath(hwnd, tszPath, CSIDL_PROFILE, FALSE);

	m_tstrCurrentPath = tszPath;
	m_tstrForm = _T(">");
	m_tstrOutputForm = m_tstrCurrentPath;
	m_tstrOutputForm = m_tstrOutputForm + m_tstrForm;

	::SetWindowText(hwnd, m_tstrOutputForm.c_str());

	SetFocus(hwnd);
	SendMessage(hwnd, EM_SETSEL, (WPARAM)0x7FFFFFFF, (LPARAM)0x7FFFFFFF);	// -1(0xFFFFFFFF)����0���Ԃ��Ă��Ă��܂�.
	SendMessage(hwnd, EM_GETSEL, (WPARAM)&m_lStartPos, NULL);

	return 0;

}

void CConsole::OnDestroy() {

}

HBRUSH CConsole::OnCtlColorEdit(WPARAM wParam, LPARAM lParam) {

	return HBRUSH(0);

}

int CConsole::OnChar(WPARAM wParam, LPARAM lParam) {

	return 0;

}

int CConsole::OnSysChar(WPARAM wParam, LPARAM lParam) {

	return 0;

}

int CConsole::OnKeyDown(WPARAM wParam, LPARAM lParam) {

	if ((UINT)wParam == VK_UP) {
		return -1;
	}

	if ((UINT)wParam == VK_LEFT) {
		long lCurrentPos = 0;
		SendMessage(m_hWnd, EM_GETSEL, (WPARAM)&lCurrentPos, NULL);
		if (lCurrentPos <= m_lStartPos) {
			return -1;
		}
	}

	return 0;

}

int CConsole::OnLButtonDown(WPARAM wParam, LPARAM lParam) {
	
	HideCaret(m_hWnd);	// down�����Ƃ��ɃL�����b�g���B�����@�͂��ꂵ���Ȃ�.

	return 0;

}

int CConsole::OnLButtonUp(WPARAM wParam, LPARAM lParam) {

	long lCurrentPos = 0;

	ShowCaret(m_hWnd);	// ���̈ʒu�X�V�ɂ��, ��Ƀt�H�[�����E�ɗ���.

	SendMessage(m_hWnd, EM_GETSEL, (WPARAM)&lCurrentPos, NULL);
	if (lCurrentPos < m_lStartPos) {
		SendMessage(m_hWnd, EM_SETSEL, (WPARAM)m_lStartPos, (LPARAM)m_lStartPos);
		
	}

	return 0;

}
