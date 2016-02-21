#include <windows.h>
#include <tchar.h>

int WINAPI _tWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPTSTR lpCmdLine, int nShowCmd) {

	MessageBox(NULL, _T("Hello, world!"), _T("ObjeqtNote"), MB_ICONASTERISK);

	return 0;

}