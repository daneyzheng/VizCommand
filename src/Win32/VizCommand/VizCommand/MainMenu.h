#pragma once

#include "Menu.h"

class CMainMenu : public CMenu {

	public:

		CMainMenu();
		CMainMenu(HINSTANCE hInstance);
		CMainMenu(CApplication *pApp, HINSTANCE hInstance);
		virtual BOOL OnCommandMenuItem(WPARAM wParam, LPARAM lParam);

		void OnFileNew();
		void OnFileOpen();
		void OnFileSave();
		void OnFileSaveAs();

		void OnAppExit();

};
