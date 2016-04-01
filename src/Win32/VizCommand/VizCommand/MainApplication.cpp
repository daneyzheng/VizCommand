#include "MainApplication.h"
#include "MainWindow.h"
#include "VisualConsoleWindow.h"

BOOL CMainApplication::InitInstance(HINSTANCE hInstance, LPTSTR lpCmdLine, int nShowCmd) {

	RECT rc;

	m_hInstance = hInstance;

	if (!CWindow::RegisterClass(hInstance)) {

		MessageBox(NULL, _T("ウィンドウクラスの登録に失敗しました!(-1)"), _T("VizCommand - Error"), MB_OK | MB_ICONEXCLAMATION);
		return FALSE;

	}

	if (!CMulti::RegisterClass(hInstance)) {

		MessageBox(NULL, _T("ウィンドウクラスの登録に失敗しました!(-2)"), _T("VizCommand - Error"), MB_OK | MB_ICONEXCLAMATION);
		return FALSE;

	}

	if (!CVisualConsolePanel::RegisterClass(hInstance)) {

		MessageBox(NULL, _T("ウィンドウクラスの登録に失敗しました!(-3)"), _T("VizCommand - Error"), MB_OK | MB_ICONEXCLAMATION);
		return FALSE;

	}

	m_pWindow = new CMainWindow(this);

	rc.left = 0;
	rc.top = 0;
	rc.right = 640;
	rc.bottom = 480;

	if (!m_pWindow->Create(_T("VizCommand"), rc, m_hInstance)) {

		MessageBox(NULL, _T("ウィンドウの生成に失敗しました!(-4)"), _T("VizCommand - Error"), MB_OK | MB_ICONEXCLAMATION);
		return FALSE;

	}

	m_pWindow->ShowWindow(SW_SHOW);

	return TRUE;

}

int CMainApplication::ExitInstance() {

#if FALSE
	if (m_pFile) {
		m_pFile->Close();
		delete m_pFile;
		m_pFile = NULL;
	}
#endif

	return __super::ExitInstance();
	
}
