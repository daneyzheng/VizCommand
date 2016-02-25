#include "FileDialog.h"

CFileDialog::CFileDialog() {

	ZeroMemory(&m_ofn, sizeof(OPENFILENAME));
	ZeroMemory(m_tszFilePath, sizeof(TCHAR) * _MAX_PATH);
	ZeroMemory(m_tszFilter, sizeof(TCHAR) * 256);
	m_hWnd = NULL;

}

CFileDialog::~CFileDialog() {

	ZeroMemory(&m_ofn, sizeof(OPENFILENAME));
	ZeroMemory(m_tszFilePath, sizeof(TCHAR) * _MAX_PATH);
	ZeroMemory(m_tszFilter, sizeof(TCHAR) * 256);
	m_hWnd = NULL;

}

BOOL CFileDialog::GetOpenFileName(HWND hWnd, TCHAR *tszFilter, DWORD dwFilterLen) {

	m_hWnd = hWnd;
	wmemcpy_s(m_tszFilter, sizeof(TCHAR) * 256, tszFilter, dwFilterLen);

	m_ofn.lStructSize = sizeof(OPENFILENAME);
	m_ofn.hwndOwner = m_hWnd;
	m_ofn.lpstrFilter = m_tszFilter;
	m_ofn.lpstrFile = m_tszFilePath;
	m_ofn.nMaxFile = _MAX_PATH;
	m_ofn.Flags = OFN_FILEMUSTEXIST;

	if (!::GetOpenFileName(&m_ofn)) {

		return FALSE;

	}
	
	return TRUE;

}

BOOL CFileDialog::GetSaveFileName(HWND hWnd, TCHAR *tszFilter, DWORD dwFilterLen) {

	m_hWnd = hWnd;
	wmemcpy_s(m_tszFilter, sizeof(TCHAR) * 256, tszFilter, dwFilterLen);

	m_ofn.lStructSize = sizeof(OPENFILENAME);
	m_ofn.hwndOwner = m_hWnd;
	m_ofn.lpstrFilter = m_tszFilter;
	m_ofn.lpstrFile = m_tszFilePath;
	m_ofn.nMaxFile = _MAX_PATH;
	m_ofn.Flags = OFN_OVERWRITEPROMPT;

	if (!::GetSaveFileName(&m_ofn)) {

		return FALSE;

	}

	return TRUE;

}
