#include "MainApplication.h"
#include "MultiView.h"	//#include "MainWindow.h"

BOOL CMainApplication::InitInstance(HINSTANCE hInstance, LPTSTR lpCmdLine, int nShowCmd) {

	RECT rc;

	m_hInstance = hInstance;

	if (!CWindow::RegisterClass(hInstance)) {

		MessageBox(NULL, _T("�E�B���h�E�N���X�̓o�^�Ɏ��s���܂���!(-1)"), _T("VizCommand - Error"), MB_OK | MB_ICONEXCLAMATION);
		return FALSE;

	}

	if (!CMulti::RegisterClass(hInstance)) {

		MessageBox(NULL, _T("�E�B���h�E�N���X�̓o�^�Ɏ��s���܂���!(-2)"), _T("VizCommand - Error"), MB_OK | MB_ICONEXCLAMATION);
		return FALSE;

	}

	m_pWindow = new CMultiView(this);	//new CMainWindow(this);

	rc.left = 0;
	rc.top = 0;
	rc.right = 640;
	rc.bottom = 480;

	if (!m_pWindow->Create(_T("VizCommand"), rc, m_hInstance)) {

		MessageBox(NULL, _T("�E�B���h�E�̐����Ɏ��s���܂���!(-3)"), _T("VizCommand - Error"), MB_OK | MB_ICONEXCLAMATION);
		return FALSE;

	}

	m_pWindow->ShowWindow(SW_SHOW);

	return TRUE;

}