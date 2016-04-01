#include "MainApplication.h"
#include "MainMenu.h"
#include "FileDialog.h"
#include "MultiWindow.h"
#include "Edit.h"
#include "DropDownList.h"

CMainMenu::CMainMenu() : CMenu(){

}

CMainMenu::CMainMenu(HINSTANCE hInstance) : CMenu(hInstance){

}

CMainMenu::CMainMenu(CApplication * pApp, HINSTANCE hInstance) : CMenu(pApp, hInstance) {

}

BOOL CMainMenu::OnCommandMenuItem(WPARAM wParam, LPARAM lParam) {

	switch (LOWORD(wParam)) {

		case ID_FILE_NEW:

			OnFileNew();
	
			break;

		case ID_FILE_OPEN:

			OnFileOpen();

			break;

		case ID_FILE_SAVE:

			OnFileSave();

			break;

		case ID_FILE_SAVEAS:

			OnFileSaveAs();

			break;

		case ID_APP_EXIT:

			OnAppExit();

			break;

		default:

			return FALSE;

	}

	return TRUE;

}

void CMainMenu::OnFileNew(){

	MessageBox(NULL, _T("OnFileNew"), _T("VizCommand"), MB_OK | MB_ICONASTERISK);

}

void CMainMenu::OnFileOpen(){

	MessageBox(NULL, _T("OnFileOpen"), _T("VizCommand"), MB_OK | MB_ICONASTERISK);

#if FALSE
	CFileDialog openfiledlg;

	if (openfiledlg.GetOpenFileName(m_hWnd, _T("テキストファイル(*.txt)\0*.txt\0すべてのファイル(*.*)\0*.*\0\0"), 41)) {
		
		//MessageBox(NULL, openfiledlg.m_tszFilePath, _T("ObjeqtNote"), MB_OK | MB_ICONASTERISK);
		
		CMainApplication *pMainApp = (CMainApplication *)m_pApp;
		pMainApp->m_pFile = new CFile();
		pMainApp->m_pFile->Open(openfiledlg.m_tszFilePath, OPEN_EXISTING);
		ULONGLONG ullSize = pMainApp->m_pFile->GetLength();
		BYTE *pBytes = new BYTE[ullSize + 1];
		ZeroMemory(pBytes, sizeof(BYTE) * (ullSize + 1));
		pMainApp->m_pFile->Read(pBytes, ullSize);

		CMultiWindow *pMultiWindow = (CMultiWindow *)pMainApp->m_pWindow;
		RECT rc;
		GetClientRect(m_hWnd, &rc);
		CDropDownList *pEncodeCB = new CDropDownList(m_pApp);
		RECT rc1;
		rc1.top = 0;
		rc1.left = 0;
		rc1.right = rc.right;
		rc1.bottom = 28;
		pMultiWindow->m_pMulti->Add(pEncodeCB, _T(""), rc1, (HMENU)IDC_MULTI1 + 1, m_hInstance);

		CEdit *pTextEdit = new CEdit(m_pApp);
		RECT rc2;
		rc2.top = rc1.bottom;
		rc2.left = 0;
		rc2.right = rc.right;
		rc2.bottom = rc.bottom - 28;
		int len = MultiByteToWideChar(CP_ACP, 0, (LPCSTR)pBytes, -1, NULL, 0);
		TCHAR *ptszText = new TCHAR[len];
		MultiByteToWideChar(CP_ACP, 0, (LPCSTR)pBytes, -1, ptszText, len);
		pMultiWindow->m_pMulti->Add(pTextEdit, ptszText, rc2, (HMENU)IDC_MULTI1 + 2, m_hInstance);
		//SetWindowText(pMultiWindow->m_pMulti->m_vecpWindowList[1]->m_hWnd, (LPCWSTR)pBytes);
		delete[] ptszText;

		CDropDownList *pLineFeedCB = new CDropDownList(m_pApp);
		RECT rc3;
		rc3.top = rc2.bottom;
		rc3.left = 0;
		rc3.right = rc.right;
		rc3.bottom = rc.bottom;
		pMultiWindow->m_pMulti->Add(pLineFeedCB, _T(""), rc3, (HMENU)IDC_MULTI1 + 3, m_hInstance);
		
		delete [] pBytes;
		pMainApp->m_pFile->Close();
		delete pMainApp->m_pFile;
		pMainApp->m_pFile = NULL;

	}

#endif

}

void CMainMenu::OnFileSave(){

	MessageBox(NULL, _T("OnFileSave"), _T("VizCommand"), MB_OK | MB_ICONASTERISK);

}

void CMainMenu::OnFileSaveAs(){

	CFileDialog savefiledlg;

	if (savefiledlg.GetSaveFileName(m_hWnd, _T("テキストファイル(*.txt)\0*.txt\0すべてのファイル(*.*)\0*.*\0\0"), 41)) {

		//MessageBox(NULL, savefiledlg.m_tszFilePath, _T("ObjeqtNote"), MB_OK | MB_ICONASTERISK);

	}

}

void CMainMenu::OnAppExit(){

	//MessageBox(NULL, _T("OnAppExit"), _T("VizCommand"), MB_OK | MB_ICONASTERISK);
	::SendMessage(m_hWnd, WM_CLOSE, 0, 0);

}
