#include "Static.h"

CStatic::CStatic() : CWindow() {

}

CStatic::CStatic(CApplication * pApp) : CWindow(pApp) {

}

BOOL CStatic::Create(LPCTSTR lpctszWindowName, const RECT & rect, HWND hWndParent, HMENU hMenu, HINSTANCE hInstance) {

	return CWindow::Create(_T("Static"), lpctszWindowName, WS_CHILD | WS_VISIBLE | WS_VSCROLL | WS_HSCROLL, rect, hWndParent, hMenu, hInstance);

}

void CStatic::OnDestroy() {

}
