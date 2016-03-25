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

	PutString(m_tstrOutputForm);

	return 0;

}

void CConsole::OnDestroy() {

}

HBRUSH CConsole::OnCtlColorEdit(WPARAM wParam, LPARAM lParam) {

	return HBRUSH(0);

}

int CConsole::OnChar(WPARAM wParam, LPARAM lParam) {

	if ((UINT)wParam == VK_BACK) {
		long lCurrentPos = 0;
		SendMessage(m_hWnd, EM_GETSEL, (WPARAM)&lCurrentPos, NULL);
		if (lCurrentPos <= m_lStartPos) {
			return -1;
		}
	}

	if ((UINT)wParam == VK_RETURN) {
		
		GetCommandLineString();
		PutResponseString();
		PutString(m_tstrOutputForm);
		return -1;

	}

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
	
	HideCaret(m_hWnd);	// downしたときにキャレットを隠す方法はこれしかない.

	return 0;

}

int CConsole::OnLButtonUp(WPARAM wParam, LPARAM lParam) {

	long lCurrentPos = 0;

	ShowCaret(m_hWnd);	// 下の位置更新により, 常にフォームより右に来る.

	SendMessage(m_hWnd, EM_GETSEL, (WPARAM)&lCurrentPos, NULL);
	if (lCurrentPos < m_lStartPos) {
		SendMessage(m_hWnd, EM_SETSEL, (WPARAM)m_lStartPos, (LPARAM)m_lStartPos);
		
	}

	return 0;

}

void CConsole::GetCommandLineString() {

	unsigned int uiAllTextLen;
	unsigned int uiCmdLineStrLen;
	TCHAR *ptszAllText = NULL;

	uiAllTextLen = GetWindowTextLength(m_hWnd);
	ptszAllText = new TCHAR[uiAllTextLen + 1];
	GetWindowText(m_hWnd, ptszAllText, uiAllTextLen + 1);

	uiCmdLineStrLen = uiAllTextLen - m_lStartPos;
	TCHAR *ptszCmdLineStrBuf = new TCHAR[uiCmdLineStrLen + 1];
	_tcsncpy_s(ptszCmdLineStrBuf, uiCmdLineStrLen + 1 , &ptszAllText[m_lStartPos], uiCmdLineStrLen);
	ptszCmdLineStrBuf[uiCmdLineStrLen] = _T('\0');
	m_tstrCommandLineString = ptszCmdLineStrBuf;

	delete[] ptszCmdLineStrBuf;
	delete[] ptszAllText;

}

void CConsole::PutString(tstring tstr)
{

#if 1
	::SendMessage(m_hWnd, EM_REPLACESEL, 0, (LPARAM)tstr.c_str());

	SendMessage(m_hWnd, EM_SETSEL, (WPARAM)0x7FFFFFFF, (LPARAM)0x7FFFFFFF);	// -1(0xFFFFFFFF)だと0が返ってきてしまう.
	SendMessage(m_hWnd, EM_GETSEL, (WPARAM)&m_lStartPos, NULL);

#else
	unsigned int uiLen = 0;
	unsigned int uiNewTextLen = 0;
	unsigned int uiTStrlen = 0;
	TCHAR *ptszNewText = NULL;

	uiLen = GetWindowTextLength(m_hWnd);
	uiTStrlen = tstr.length();

	uiNewTextLen = uiLen;
	uiNewTextLen = uiNewTextLen + uiTStrlen;

	ptszNewText = new TCHAR[uiNewTextLen + 1];
	ZeroMemory(ptszNewText, uiNewTextLen + 1);

	GetWindowText(m_hWnd, ptszNewText, uiNewTextLen + 1);
	ptszNewText[uiLen] = _T('\0');

	_tcscat_s(ptszNewText, uiNewTextLen + 1, tstr.c_str());
	ptszNewText[uiNewTextLen] = _T('\0');

	SetWindowText(m_hWnd, ptszNewText);

	SendMessage(m_hWnd, EM_SETSEL, (WPARAM)0x7FFFFFFF, (LPARAM)0x7FFFFFFF);	// -1(0xFFFFFFFF)だと0が返ってきてしまう.
	SendMessage(m_hWnd, EM_GETSEL, (WPARAM)&m_lStartPos, NULL);

	delete[] ptszNewText;
#endif

}

void CConsole::PutResponseString() {

	PutString(_T("\r\n"));

	m_tstrResponseString = m_tstrCommandLineString;
	m_tstrResponseString = m_tstrResponseString + _T("\r\n");

	PutString(m_tstrResponseString);

}
