#include "MainWindow.h"

CMainWindow::CMainWindow() : CMenuWindow() {

	m_pMenu = NULL;

}

CMainWindow::CMainWindow(CApplication *pApp) : CMenuWindow(pApp) {

	m_pMenu = NULL;

}