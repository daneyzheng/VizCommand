#pragma once

#include "Application.h"
//#include "File.h"

class CMainApplication : public CApplication {

	public:

		//CFile *m_pFile;

		virtual BOOL InitInstance(HINSTANCE hInstance, LPTSTR lpCmdLine, int nShowCmd);
		virtual int ExitInstance();

};
