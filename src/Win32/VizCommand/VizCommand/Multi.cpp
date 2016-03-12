#include "Multi.h"

CMulti::CMulti() : CWindow() {

}

CMulti::CMulti(CApplication * pApp) : CWindow(pApp) {

}

BOOL CMulti::Create(LPCTSTR lpctszWindowName, const RECT & rect, HWND hWndParent, HMENU hMenu, HINSTANCE hInstance) {

	return CWindow::Create(_T("CMulti"), lpctszWindowName, WS_CHILD | WS_VISIBLE/* | WS_VSCROLL | WS_HSCROLL*/, rect, hWndParent, hMenu, hInstance, FALSE);

}

int CMulti::OnCreate(HWND hwnd, LPCREATESTRUCT lpCreateStruct) {

	return 0;

}

void CMulti::OnDestroy() {

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


