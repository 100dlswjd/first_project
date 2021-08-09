#include<windows.h>

LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);
HINSTANCE g_hInst;
HWND hWndMain;
LPCTSTR lpszClass = TEXT("macro_project");
LPPOINT mousePos;
BOOL GetCursorPos(mousePos);


int x = GetSystemMetrics(SM_CXSCREEN) / 2;
int y = GetSystemMetrics(SM_CYSCREEN) / 2;

int APIENTRY WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpszCmdParam, int nCmdShow) {
	HWND hWnd;
	MSG Message;
	WNDCLASS WndClass;
	g_hInst = hInstance;

	WndClass.cbClsExtra = 0;
	WndClass.cbWndExtra = 0;
	WndClass.hbrBackground = (HBRUSH)GetStockObject(COLOR_WINDOW + 1);
	WndClass.hCursor = LoadCursor(NULL, IDC_ARROW);
	WndClass.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	WndClass.hInstance = hInstance;
	WndClass.lpfnWndProc = WndProc;
	WndClass.lpszClassName = lpszClass;
	WndClass.lpszMenuName = NULL;
	WndClass.style = CS_HREDRAW | CS_VREDRAW;
	RegisterClass(&WndClass);

	hWnd = CreateWindow(lpszClass, lpszClass, WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, NULL, (HMENU)NULL, hInstance, NULL);

	ShowWindow(hWnd, nCmdShow);

	while (GetMessage(&Message, NULL, 0, 0)) {
		TranslateMessage(&Message);
		DispatchMessage(&Message);
	}
	return (int)Message.wParam;
}

LRESULT CALLBACK WndProc(HWND hWnd, UINT iMessage, WPARAM wParam, LPARAM lParam) {
	HDC hdc;
	PAINTSTRUCT ps;

	switch (iMessage) {
	case WM_CREATE:
		SetCursorPos(x, y);
		return 0;
	case WM_KEYDOWN:
		switch (wParam) {
		case VK_LEFT:
			SetCursorPos(x-5,y);
			x = x - 5;
			if (x < 0) {
				x = 0;
			}
			//MessageBox(hWnd, ,TEXT("screen size"), MB_OK)
			return 0;
		case VK_UP:
			SetCursorPos(x, y-5);
			y = y - 5;
			if (y < 0) {
				y = 0;
			}
			//MessageBox(hWnd, TEXT("措面 郴侩"), TEXT("措面 力格"), MB_OKCANCEL);
			return 0;
		case VK_RIGHT:
			SetCursorPos(x+5, y);
			x = x + 5;
			if (x > GetSystemMetrics(SM_CXVIRTUALSCREEN)) {
				x = GetSystemMetrics(SM_CXVIRTUALSCREEN);
			}
			return 0;
		case VK_DOWN:
			SetCursorPos(x, y+5);
			y = y + 5;
			if (y > GetSystemMetrics(SM_CYVIRTUALSCREEN)) {
				y = GetSystemMetrics(SM_CYVIRTUALSCREEN);
			}
			return 0;
		}
	case WM_DESTROY:
		PostQuitMessage(0);
		return 0;
	}
	return(DefWindowProc(hWnd, iMessage, wParam, lParam));
}

