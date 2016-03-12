#include "DropDownList.h"

CDropDownList::CDropDownList() : CWindow() {

}

CDropDownList::CDropDownList(CApplication * pApp) : CWindow(pApp) {

}

BOOL CDropDownList::Create(LPCTSTR lpctszWindowName, const RECT & rect, HWND hWndParent, HMENU hMenu, HINSTANCE hInstance) {

	return CWindow::Create(_T("ComboBox"), lpctszWindowName, WS_CHILD | WS_VISIBLE | CBS_SORT | CBS_DROPDOWNLIST, rect, hWndParent, hMenu, hInstance, TRUE);

}

int CDropDownList::OnCreate(HWND hwnd, LPCREATESTRUCT lpCreateStruct) {

	return 0;

}

void CDropDownList::OnDestroy() {

}
