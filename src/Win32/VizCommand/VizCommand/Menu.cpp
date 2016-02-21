#include "Menu.h"

CMenu::CMenu() {

	m_hInstance = NULL;
	m_hMenu = NULL;
	m_hWnd = NULL;

}

CMenu::CMenu(HINSTANCE hInstance) {

	m_hInstance = hInstance;
	m_hMenu = NULL;
	m_hWnd = NULL;

}

CMenu::~CMenu() {

	m_hInstance = NULL;
	m_hMenu = NULL;
	m_hWnd = NULL;

}

BOOL CMenu::LoadMenu(UINT nIDResource) {

	m_hMenu = ::LoadMenu(m_hInstance, MAKEINTRESOURCE(nIDResource));
	if (m_hMenu == NULL) {

		return FALSE;

	}

	return TRUE;

}

BOOL CMenu::SetMenu(HWND hwnd) {

	m_hWnd = hwnd;

	return ::SetMenu(m_hWnd, m_hMenu);

}

BOOL CMenu::OnCommandMenuItem(WPARAM wParam, LPARAM lParam) {

	MessageBox(NULL, _T("OnCommandMenuItem"), _T("CMenu"), MB_OK | MB_ICONASTERISK);

	return TRUE;

}