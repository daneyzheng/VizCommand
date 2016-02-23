#pragma once

#include <windows.h>
#include <tchar.h>

class CFileDialog {

	public:

		OPENFILENAME m_ofn;
		TCHAR m_tszFilePath[_MAX_PATH];
		TCHAR m_tszFilter[256];
		HWND m_hWnd;

		CFileDialog();
		~CFileDialog();

		virtual BOOL GetOpenFileName(HWND hWnd, TCHAR *tszFilter, DWORD dwFilterLen);
		virtual BOOL GetSaveFileName(HWND hWnd, TCHAR *tszFilter, DWORD dwFilterLen);

};