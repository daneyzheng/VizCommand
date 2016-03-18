#include "Multi.h"

CMulti::CMulti() : CWindow() {

}

CMulti::CMulti(CApplication * pApp) : CWindow(pApp) {

}

BOOL CMulti::Create(LPCTSTR lpctszWindowName, const RECT & rect, HWND hWndParent, HMENU hMenu, HINSTANCE hInstance) {

	return CWindow::Create(_T("CMulti"), lpctszWindowName, WS_CHILD | WS_VISIBLE/* | WS_VSCROLL | WS_HSCROLL*/, rect, hWndParent, hMenu, hInstance, FALSE);

}

#if false
BOOL CMulti::Add(CWindow * pWindow, LPCTSTR lpctszWindowName, const RECT & rect, HMENU hMenu, HINSTANCE hInstance) {

	BOOL bRet = pWindow->Create(lpctszWindowName, rect, m_hWnd, hMenu, hInstance);
	if (bRet) {

		m_vecpWindowList.push_back(pWindow);

	}

	return bRet;

}
#endif

BOOL CMulti::Add(tstring tstrWindowID, CWindow * pWindow, LPCTSTR lpctszWindowName, const RECT & rect, HMENU hMenu, HINSTANCE hInstance) {

	BOOL bRet = pWindow->Create(lpctszWindowName, rect, m_hWnd, hMenu, hInstance);
	if (bRet) {

		//m_vecpWindowList.push_back(pWindow);
		if (m_mapSubWindowMap.find(tstrWindowID) == m_mapSubWindowMap.end()) {
			m_mapSubWindowMap.insert(std::pair<tstring, CWindow *>(tstrWindowID, pWindow));
		}

	}

	return bRet;

}

void CMulti::Destroy() {

	for (auto it = m_mapSubWindowMap.begin(); it != m_mapSubWindowMap.end(); ++it) {
		it->second->Destroy();
		delete it->second;
		it->second = NULL;
	}
	m_mapSubWindowMap.clear();
#if false
	for (std::vector<CWindow *>::reverse_iterator it = m_vecpWindowList.rbegin(); it != m_vecpWindowList.rend(); ++it) {
		
		(*it)->Destroy();
		delete (*it);
		(*it) = NULL;
	
	}
	m_vecpWindowList.clear();
#endif

	DestroyWindow(m_hWnd);
	m_hWnd = NULL;

}

int CMulti::OnCreate(HWND hwnd, LPCREATESTRUCT lpCreateStruct) {

	m_hBrush = CreateSolidBrush(RGB(0x00, 0x00, 0x00));

	return 0;

}

void CMulti::OnDestroy() {

	if (m_hBrush) {
		DeleteObject(m_hBrush);
		m_hBrush = NULL;
	}

}

HBRUSH CMulti::OnCtlColorEdit(WPARAM wParam, LPARAM lParam) {

	HDC hDC = (HDC)wParam;

	SetBkMode(hDC, OPAQUE);
	SetBkColor(hDC, RGB(0x00, 0x00, 0x00));
	SetTextColor(hDC, RGB(0xFF, 0xFF, 0xFF));
	return m_hBrush;

}

int CMulti::OnChar(WPARAM wParam, LPARAM lParam) {

	if ((UINT)wParam == VK_UP) {
		return -1;
	}

	return 0;

}

BOOL CMulti::RegisterClass(HINSTANCE hInstance) {

	WNDCLASS wc;

	wc.lpszClassName = _T("CMulti");
	wc.style = CS_HREDRAW | CS_VREDRAW;
	wc.lpfnWndProc = CWindow::StaticWindowProc;
	wc.hInstance = hInstance;
	wc.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	wc.hCursor = LoadCursor(NULL, IDC_ARROW);
	wc.hbrBackground = (HBRUSH)GetStockObject(GRAY_BRUSH);
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


