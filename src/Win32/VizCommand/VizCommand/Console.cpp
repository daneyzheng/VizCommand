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

	return 0;

}
