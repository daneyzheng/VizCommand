#include "VisualConsole.h"
#include "ListCtrl.h"
#include <vector>
#include <commctrl.h>

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
#if 1
		for (int i = 0; i < 6; i++) {
			PutString(_T("\r\n\r\n"));
		}
		CListCtrl *pList = new CListCtrl(CWindow::m_pApp);
		RECT rc;
		rc.top = 20;
		rc.left = 0;
		rc.right = 640;
		rc.bottom = 20 + 190;
		Add(_T("CListCtrl_ls_0"), pList, _T(""), rc, (HMENU)IDC_VISUALCONSOLE1 + 1, CWindow::m_pApp->m_hInstance);
		
		// �ϐ��̐錾
		HANDLE hFind;			// �����n���h��hFind.
		WIN32_FIND_DATA wfd;	// �t�@�C���������wfd.
		tstring spath;
		spath = m_tstrCurrentPath;
		spath = spath + _T("\\*");
		InitCommonControls();
		std::vector<tstring> vectstrFileList;

		// "test"�t�H���_�ȉ��̃t�@�C���̒�����ŏ��Ɍ��������t�@�C���̏����擾.
		hFind = FindFirstFile(spath.c_str(), &wfd);	// FindFirstFile��"test"�t�H���_�ȉ��̃t�@�C����T��, �ŏ��Ɍ��������t�@�C������wfd�Ɋi�[.
		if (hFind == INVALID_HANDLE_VALUE) {	// INVALID_HANDLE_VALUE�Ȃ玸�s.

												// �G���[����.
			_tprintf(_T("FindFirstFile Error!\n"));	// _tprintf��"FindFirstFile Error!"�Əo��.
			return;	// -1��Ԃ�.

		}

		LV_ITEM item;
		HIMAGELIST hImageList = ImageList_Create(32, 32, ILC_COLOR24, 24, 0);
		ListView_SetImageList(pList->m_hWnd, hImageList, LVSIL_NORMAL);

		SHFILEINFO sfi;
		int i = 0;

		// do-while����FindNextFile��2�ڈȍ~���T��.
		do {	// do�u���b�N

			tstring filename;
			tstring rpath;
			filename = wfd.cFileName;
			if (filename == _T(".") || filename == _T("..")) {
				rpath = filename;
				continue;
			}
			else {
				rpath = m_tstrCurrentPath;
				rpath = rpath + _T("\\");
				rpath = rpath + filename;
			}
				// ���������t�@�C���̃t�@�C�������o��.
			//_tprintf(_T("wfd.cFileName = %s\n"), wfd.cFileName);	// ���������t�@�C���̃t�@�C����wfd.cFileName���o��.
			/*hImageList = (HIMAGELIST)*/::SHGetFileInfo(rpath.c_str(), 0, &sfi, sizeof(SHFILEINFO), /*SHGFI_SYSICONINDEX | SHGFI_SMALLICON | */SHGFI_ICON | SHGFI_LARGEICON);

			ImageList_AddIcon(hImageList, sfi.hIcon);
			ListView_SetImageList(pList->m_hWnd, hImageList, LVSIL_NORMAL);
			

			item.mask = LVIF_TEXT | LVIF_IMAGE;
			item.pszText = wfd.cFileName;
			item.iItem = i;
			item.iSubItem = 0;
			item.iImage = i;
			ListView_InsertItem(pList->m_hWnd, &item);
			i++;
			vectstrFileList.push_back(wfd.cFileName);


		} while (FindNextFile(hFind, &wfd));	// FindNextFile�Ŗ߂�l���^�Ȃ玟�̃t�@�C�������������Ƃ������ƂȂ̂ŌJ��Ԃ�.

												// �n���h�������.
		FindClose(hFind);	// FindClose��hFind�����.

#else
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
#endif
	}
	else {
		PutString(_T("\r\n\r\n"));
	}

}
