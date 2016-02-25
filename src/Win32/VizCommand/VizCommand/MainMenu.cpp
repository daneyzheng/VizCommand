#include "MainMenu.h"
#include "FileDialog.h"

CMainMenu::CMainMenu() : CMenu(){

}

CMainMenu::CMainMenu(HINSTANCE hInstance) : CMenu(hInstance){

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

	CFileDialog openfiledlg;

	if (openfiledlg.GetOpenFileName(m_hWnd, _T("テキストファイル(*.txt)\0*.txt\0すべてのファイル(*.*)\0*.*\0\0"), 41)) {
		
		MessageBox(NULL, openfiledlg.m_tszFilePath, _T("VizCommand"), MB_OK | MB_ICONASTERISK);

	}

}

void CMainMenu::OnFileSave(){

	MessageBox(NULL, _T("OnFileSave"), _T("VizCommand"), MB_OK | MB_ICONASTERISK);

}

void CMainMenu::OnFileSaveAs(){

	CFileDialog savefiledlg;

	if (savefiledlg.GetSaveFileName(m_hWnd, _T("テキストファイル(*.txt)\0*.txt\0すべてのファイル(*.*)\0*.*\0\0"), 41)) {

		MessageBox(NULL, savefiledlg.m_tszFilePath, _T("VizCommand"), MB_OK | MB_ICONASTERISK);

	}

}

void CMainMenu::OnAppExit(){

	MessageBox(NULL, _T("OnAppExit"), _T("VizCommand"), MB_OK | MB_ICONASTERISK);

}
