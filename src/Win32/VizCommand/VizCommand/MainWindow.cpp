#include "MainWindow.h"

CMainWindow::CMainWindow() : CWindow() {

}

CMainWindow::CMainWindow(CApplication *pApp) : CWindow(pApp) {

}

int CMainWindow::OnCreate(HWND hwnd, LPCREATESTRUCT lpCreateStruct) {

	return 0;

}

void CMainWindow::OnDestroy() {

	PostQuitMessage(0);

}