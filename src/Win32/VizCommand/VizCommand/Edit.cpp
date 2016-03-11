#include "Edit.h"

CEdit::CEdit() : CWindow() {

}

CEdit::CEdit(CApplication * pApp) : CWindow(pApp) {

}

BOOL CEdit::Create(LPCTSTR lpctszWindowName, const RECT & rect, HWND hWndParent, HMENU hMenu, HINSTANCE hInstance) {

	return CWindow::Create(_T("Edit"), lpctszWindowName, WS_CHILD | WS_VISIBLE | ES_WANTRETURN | ES_MULTILINE | ES_AUTOVSCROLL | WS_VSCROLL | ES_AUTOHSCROLL | WS_HSCROLL, rect, hWndParent, hMenu, hInstance);

}

void CEdit::OnDestroy() {
	
}
