#include "MultiView.h"
#include "Edit.h"
#include "DropDownList.h"

CMultiView::CMultiView() : CWindow() {

	m_pMulti = NULL;

}

CMultiView::CMultiView(CApplication * pApp) : CWindow(pApp) {

	m_pMulti = NULL;

}

CMultiView::~CMultiView() {

	if (m_pMulti != NULL) {
		delete m_pMulti;
		m_pMulti;
	}

}

int CMultiView::OnCreate(HWND hwnd, LPCREATESTRUCT lpCreateStruct) {

	RECT rc;

	GetClientRect(hwnd, &rc);

	m_pMulti = new CMulti(m_pApp);

	//m_pMulti = new CMulti(m_pApp);

	m_pMulti->Create(_T(""), rc, hwnd, (HMENU)IDC_MULTI1, lpCreateStruct->hInstance);

	CDropDownList *pEncodeCB = new CDropDownList(m_pApp);

	RECT rc1;
	rc1.top = 0;
	rc1.left = 0;
	rc1.right = rc.right;
	rc1.bottom = 28;

	m_pMulti->Add(_T("EncodeCB"), pEncodeCB, _T(""), rc1, (HMENU)IDC_MULTI1 + 1, lpCreateStruct->hInstance);

	CEdit *pTextEdit = new CEdit(m_pApp);

	RECT rc2;
	rc2.top = rc1.bottom;
	rc2.left = 0;
	rc2.right = rc.right;
	rc2.bottom = rc.bottom - 28;

	m_pMulti->Add(_T("TextEdit"), pTextEdit, _T(""), rc2, (HMENU)IDC_MULTI1 + 2, lpCreateStruct->hInstance);

	CDropDownList *pLineFeedCB = new CDropDownList(m_pApp);

	RECT rc3;
	rc3.top = rc2.bottom;
	rc3.left = 0;
	rc3.right = rc.right;
	rc3.bottom = rc.bottom;

	m_pMulti->Add(_T("LineFeedCB"), pLineFeedCB, _T(""), rc3, (HMENU)IDC_MULTI1 + 3, lpCreateStruct->hInstance);

	return 0;

}

void CMultiView::OnDestroy() {

	__super::OnDestroy();

}

int CMultiView::OnClose() {

	if (m_pMulti != NULL) {
		m_pMulti->Destroy();
		delete m_pMulti;
		m_pMulti = NULL;
	}

	return 0;

}

void CMultiView::OnSize(UINT nType, int cx, int cy) {

	if (m_pMulti != NULL) {
		MoveWindow(m_pMulti->m_hWnd, 0, 0, cx, cy, TRUE);
	}

}
