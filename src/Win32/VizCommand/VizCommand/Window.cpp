#include "Window.h"

std::map<HWND, CWindow *> CWindow::m_mapWindowMap;
std::map<tstring, WNDPROC> CWindow::m_mapBaseWindowClassMap;

CWindow::CWindow() {

	m_hWnd = NULL;
	m_pApp = NULL;
	m_tstrClassName = _T("");
	m_lpfnWndProc = NULL;

}

CWindow::CWindow(CApplication *pApp) {

	m_hWnd = NULL;
	m_pApp = pApp;
	m_tstrClassName = _T("");
	m_lpfnWndProc = NULL;

}

CWindow::~CWindow() {

	m_hWnd = NULL;
	m_pApp = NULL;
	m_tstrClassName = _T("");
	m_lpfnWndProc = NULL;

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

	if (CWindow::m_mapBaseWindowClassMap.find(wc.lpszClassName) == CWindow::m_mapBaseWindowClassMap.end()) {
		CWindow::m_mapBaseWindowClassMap.insert(std::pair<tstring, WNDPROC>(wc.lpszClassName, DefWindowProc));
	}

	return TRUE;

}

BOOL CWindow::Create(LPCTSTR lpctszWindowName, const RECT &rect, HINSTANCE hInstance) {

	m_tstrClassName = _T("CWindow");

	m_hWnd = CreateWindow(m_tstrClassName.c_str(), lpctszWindowName, WS_OVERLAPPEDWINDOW, rect.left, rect.top, rect.right - rect.left, rect.bottom - rect.top, NULL, NULL, hInstance, (LPVOID)this);
	if (m_hWnd == NULL) {

		return FALSE;

	}

	return TRUE;

}

BOOL CWindow::Create(LPCTSTR lpctszWindowName, const RECT & rect, HWND hWndParent, HMENU hMenu, HINSTANCE hInstance) {
	
	m_tstrClassName = _T("CWindow");

	return Create(m_tstrClassName.c_str(), lpctszWindowName, WS_CHILD | WS_VISIBLE, rect, hWndParent, hMenu, hInstance, FALSE);

}

BOOL CWindow::Create(LPCTSTR lpctszClassName, LPCTSTR lpctszWindowName, DWORD dwStyle, const RECT & rect, HWND hWndParent, HMENU hMenu, HINSTANCE hInstance, BOOL bProcChange) {

	m_tstrClassName = lpctszClassName;

	m_hWnd = CreateWindow(m_tstrClassName.c_str(), lpctszWindowName, dwStyle, rect.left, rect.top, rect.right - rect.left, rect.bottom - rect.top, hWndParent, hMenu, hInstance, (LPVOID)this);
	if (m_hWnd == NULL) {

		return FALSE;

	}

	if (bProcChange) {

		if (OnCreate(m_hWnd, NULL) != 0) {
			DestroyWindow(m_hWnd);
			m_hWnd = NULL;
			return FALSE;
		}

		m_lpfnWndProc = (WNDPROC)GetWindowLong(m_hWnd, GWL_WNDPROC);
		SetWindowLong(m_hWnd, GWL_WNDPROC, (LONG)CWindow::StaticWindowProc);

		if (CWindow::m_mapBaseWindowClassMap.find(m_tstrClassName) == CWindow::m_mapBaseWindowClassMap.end()) {
			CWindow::m_mapBaseWindowClassMap.insert(std::pair<tstring, WNDPROC>(m_tstrClassName, m_lpfnWndProc));
		}

	}

	if (CWindow::m_mapWindowMap.find(m_hWnd) == CWindow::m_mapWindowMap.end()) {
		CWindow::m_mapWindowMap.insert(std::pair<HWND, CWindow *>(m_hWnd, this));
	}

	return TRUE;

}

void CWindow::Destroy() {

	DestroyWindow(m_hWnd);
	m_hWnd = NULL;

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

		case WM_PAINT:

			{

				OnPaint();

			}

			break;

		case WM_CLOSE:

			{

				int r;

				r = OnClose();
				if (r == 1) {
					return 0;
				}

				break;

			}

			break;

		case WM_COMMAND:

			{

				return OnCommand(wParam, lParam) ? 0 : 1;

			}

			break;

		case WM_SIZE:

			{

				UINT nType = (UINT)wParam;
				int iWidth = LOWORD(lParam);
				int iHeight = HIWORD(lParam);
				
				OnSize(nType, iWidth, iHeight);

			}

			break;


		case WM_CTLCOLOREDIT:

			{

				return (LRESULT)OnCtlColorEdit(wParam, lParam);

			}

			break;

		case WM_CHAR:

			{

				if (OnChar(wParam, lParam) == -1) {
					return 0;
				}

			}

			break;

		case WM_SYSCHAR:

			{

				if (OnSysChar(wParam, lParam) == -1) {
					return 0;
				}

			}

			break;

		case WM_KEYDOWN:

			{

				if (OnKeyDown(wParam, lParam) == -1) {
					return 0;
				}

			}

		default:

			break;

	}

	if (CWindow::m_mapBaseWindowClassMap.find(m_tstrClassName) != CWindow::m_mapBaseWindowClassMap.end()) {
		return CallWindowProc(CWindow::m_mapBaseWindowClassMap[m_tstrClassName], hwnd, uMsg, wParam, lParam);
	}
	else {
		return DefWindowProc(hwnd, uMsg, wParam, lParam);
	}


}

int CWindow::OnCreate(HWND hwnd, LPCREATESTRUCT lpCreateStruct) {

	return 0;

}

void CWindow::OnDestroy() {

	PostQuitMessage(0);

}

BOOL CWindow::OnCommand(WPARAM wParam, LPARAM lParam) {
	
	return FALSE;

}

void CWindow::OnPaint() {

}

HBRUSH CWindow::OnCtlColorEdit(WPARAM wParam, LPARAM lParam) {

	return HBRUSH(0);

}

int CWindow::OnChar(WPARAM wParam, LPARAM lParam) {
	
	return 0;

}

int CWindow::OnSysChar(WPARAM wParam, LPARAM lParam) {

	return 0;

}

int CWindow::OnKeyDown(WPARAM wParam, LPARAM lParam) {

	return 0;

}

int CWindow::OnClose() {

	return 0;

}

void CWindow::OnSize(UINT nType, int cx, int cy) {

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

		TCHAR tszClassName[256];

		::GetClassName(hwnd, tszClassName, 256);

		if (CWindow::m_mapBaseWindowClassMap.find(tszClassName) != CWindow::m_mapBaseWindowClassMap.end()) {
			return CallWindowProc(CWindow::m_mapBaseWindowClassMap[tszClassName], hwnd, uMsg, wParam, lParam);
		}
		else {
			return DefWindowProc(hwnd, uMsg, wParam, lParam);
		}

	}
	else {

		return pWindow->DynamicWindowProc(hwnd, uMsg, wParam, lParam);

	}

}