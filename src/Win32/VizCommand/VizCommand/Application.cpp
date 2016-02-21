#include "Application.h"

CApplication::CApplication(){

	m_hInstance = NULL;
	m_hWnd = NULL;

}

CApplication::~CApplication() {

	m_hInstance = NULL;
	if (m_hWnd != NULL) {

		m_hWnd = NULL;

	}

}

BOOL CApplication::InitInstance(HINSTANCE hInstance, LPTSTR lpCmdLine, int nShowCmd)
{

	WNDCLASS wc;

	m_hInstance = hInstance;

	wc.lpszClassName = _T("CApplication");
	wc.style = CS_HREDRAW | CS_VREDRAW;
	wc.lpfnWndProc = WindowProc;
	wc.hInstance = m_hInstance;
	wc.hIcon = LoadIcon(NULL, MAKEINTRESOURCE(IDI_APPLICATION));
	wc.hCursor = LoadCursor(NULL, IDC_ARROW);
	wc.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
	wc.lpszMenuName = NULL;
	wc.cbClsExtra = 0;
	wc.cbWndExtra = 0;

	if (!RegisterClass(&wc)) {

		MessageBox(NULL, _T("ウィンドウクラスの登録に失敗しました!(-1)"), _T("CApplication - Error"), MB_OK | MB_ICONEXCLAMATION);
		return FALSE;

	}

	m_hWnd = CreateWindow(wc.lpszClassName, _T("CApplication"), WS_OVERLAPPEDWINDOW, 0, 0, CW_USEDEFAULT, CW_USEDEFAULT, NULL, NULL, hInstance, NULL);
	if (m_hWnd == NULL) {

		MessageBox(NULL, _T("ウィンドウの生成に失敗しました!(-2)"), _T("CApplication - Error"), MB_OK | MB_ICONEXCLAMATION);
		return FALSE;

	}

	ShowWindow(m_hWnd, SW_SHOW);

	return TRUE;

}

int CApplication::Run() {

	MSG msg;
	LONG lCount = 0;

	while (TRUE) {

		if (PeekMessage(&msg, NULL, 0, 0, PM_NOREMOVE)) {

			lCount = 0;

			if (GetMessage(&msg, NULL, 0, 0) > 0) {

				TranslateMessage(&msg);
				DispatchMessage(&msg);

			}
			else {

				break;

			}

		}
		else {

			if (OnIdle(lCount)) {
				lCount++;
			}

		}

	}

	return ExitInstance();

}

int CApplication::ExitInstance() {

	if (m_hWnd != NULL) {

		m_hWnd = NULL;

	}

	return 0;

}

BOOL CApplication::OnIdle(LONG lCount) {

	return TRUE;

}

LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{

	switch (uMsg) {

		case WM_CREATE:

			return 0;

		case WM_DESTROY:

			PostQuitMessage(0);

			break;

		default:

			break;

	}

	return DefWindowProc(hwnd, uMsg, wParam, lParam);

}