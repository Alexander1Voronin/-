#include <windows.h>
#include <locale.h>
#include <WinProc.h>
HCURSOR hCursor1;
int WINAPI WinMain(HINSTANCE hInst,HINSTANCE hpi, LPSTR cmdline,int ss) {
	(void)hpi;
	(void)cmdline;
	setlocale(LC_ALL,"");
	WNDCLASS wc; 
	wc.style=1;
	wc.lpfnWndProc=MainWinProc; 
	wc.cbClsExtra=wc.cbWndExtra=0;
	wc.hInstance=hInst;
	wc.hIcon=LoadIcon(hInst,"Ex4_Icon"); 
	hCursor1 = (HCURSOR)LoadImage(NULL,"Move.ani",IMAGE_CURSOR,0,0,LR_LOADFROMFILE);
	wc.hCursor = hCursor1;
	wc.hbrBackground=CreateSolidBrush(RGB(108, 100, 198));
	wc.lpszMenuName="Ex4_Menu";
	wc.lpszClassName="Example MainWnd Class"; 
	if (!RegisterClass(&wc))
		return FALSE;
	HWND hMainWnd = CreateWindow("Example MainWnd Class","Старые Вороны", WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT,CW_USEDEFAULT, CW_USEDEFAULT, NULL, NULL, hInst, NULL); 
	if (!hMainWnd) 
		return FALSE;
	ShowWindow(hMainWnd,ss); 
	UpdateWindow(hMainWnd); 
	MSG msg; 
	while (GetMessage(&msg,NULL,0,0)) { 
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	} 
	return msg.wParam;
}