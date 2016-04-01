#include "ListCtrl.h"
#include <commctrl.h>

CListCtrl::CListCtrl() : CWindow() {

}

CListCtrl::CListCtrl(CApplication * pApp) : CWindow(pApp) {

}

BOOL CListCtrl::Create(LPCTSTR lpctszWindowName, const RECT & rect, HWND hWndParent, HMENU hMenu, HINSTANCE hInstance) {

	return CWindow::Create(_T("SysListView32"), lpctszWindowName, WS_CHILD | WS_VISIBLE | WS_VSCROLL | WS_HSCROLL | LVS_ICON, rect, hWndParent, hMenu, hInstance, TRUE);

}

int CListCtrl::OnCreate(HWND hwnd, LPCREATESTRUCT lpCreateStruct) {

	return 0;

}

void CListCtrl::OnDestroy() {

}
