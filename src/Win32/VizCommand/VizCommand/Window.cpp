#include "Window.h"

std::map<HWND, CWindow *> CWindow::m_mapWindowMap;

CWindow::CWindow() {

	m_hWnd = NULL;
	m_pApp = NULL;

}

CWindow::CWindow(CApplication *pApp) {

	m_hWnd = NULL;
	m_pApp = pApp;

}

CWindow::~CWindow() {

	m_hWnd = NULL;
	m_pApp = NULL;

}

BOOL CWindow::RegisterClass(HINSTANCE hInstance) {

	WNDCLASS wc;

	wc.lpszClassName = _T("CWindow");
	wc.style = CS_HREDRAW | CS_VREDRAW;
	wc.lpfnWndProc = CWindow::StaticWindowProc;
	wc.hInstance = hInstance;
	wc.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	wc.hCursor = LoadCursor(NULL, IDC_ARROW);
	wc.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
	wc.lpszMenuName = NULL;
	wc.cbClsExtra = 0;
	wc.cbWndExtra = 0;

	if (!::RegisterClass(&wc)) {

		return FALSE;

	}

	return TRUE;

}

BOOL CWindow::Create(LPCTSTR lpctszWindowName, const RECT &rect, HINSTANCE hInstance) {

	m_hWnd = CreateWindow(_T("CWindow"), lpctszWindowName, WS_OVERLAPPEDWINDOW, rect.left, rect.top, rect.right - rect.left, rect.bottom - rect.top, NULL, NULL, hInstance, (LPVOID)this);
	if (m_hWnd == NULL) {

		return FALSE;

	}

	return TRUE;

}

BOOL CWindow::ShowWindow(int nCmdShow) {

	return ::ShowWindow(m_hWnd, nCmdShow);

}

LRESULT CWindow::DynamicWindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {	// ウィンドウオブジェクトごとのウィンドウプロシージャ.

	switch (uMsg) {

		case WM_CREATE:

			{

				return OnCreate(hwnd, (LPCREATESTRUCT)lParam);

			}

			break;

		case WM_DESTROY:

			{

				OnDestroy();

			}

			break;

		case WM_COMMAND:

			{

				return OnCommand(wParam, lParam) ? 0 : 1;

			}

			break;

		default:

			break;

	}

	return DefWindowProc(hwnd, uMsg, wParam, lParam);

}

int CWindow::OnCreate(HWND hwnd, LPCREATESTRUCT lpCreateStruct) {

	return 0;

}

void CWindow::OnDestroy() {

	PostQuitMessage(0);

}

BOOL CWindow::OnCommand(WPARAM wParam, LPARAM lParam)
{
	
	return FALSE;

}

LRESULT CALLBACK CWindow::StaticWindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {

	CWindow *pWindow = NULL;

	switch (uMsg) {

		case WM_CREATE:

			{

				LPCREATESTRUCT lpCreateStruct = NULL;

				lpCreateStruct = (LPCREATESTRUCT)lParam;
				if (lpCreateStruct->lpCreateParams != NULL) {
					pWindow = (CWindow *)lpCreateStruct->lpCreateParams;
					CWindow::m_mapWindowMap.insert(std::pair<HWND, CWindow *>(hwnd, pWindow));
				}

			}

			break;

		default:

			{

				if (CWindow::m_mapWindowMap.find(hwnd) != CWindow::m_mapWindowMap.end()) {
					pWindow = CWindow::m_mapWindowMap[hwnd];
				}

			}

			break;

	}

	if (pWindow == NULL) {

		return DefWindowProc(hwnd, uMsg, wParam, lParam);

	}
	else {

		return pWindow->DynamicWindowProc(hwnd, uMsg, wParam, lParam);

	}

}