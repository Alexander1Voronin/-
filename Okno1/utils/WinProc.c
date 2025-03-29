#include <windows.h>
#include <locale.h>
#include "WinProc.h"
#define ID_MYBUTTON1 1    
#define ID_MYBUTTON2 13
#define ID_MYBUTTON3 14
#define ID_EDIT1 30
HCURSOR hCursor1;
static HFONT hFont1,hFont2,hFont3;
char buf[256]= " ";
HINSTANCE h;
BOOL CALLBACK DigProc(HWND hw, UINT msg, WPARAM wp, LPARAM lp){
	(void)lp;
	switch (msg)
	{
	case WM_INITDIALOG:
		return TRUE;
	case WM_COMMAND:
		if(LOWORD(wp == 32)){
			MessageBox(hw, "Дать", "MessageBox", MB_OK|MB_ICONASTERISK);
			EndDialog(hw,0);
		}else if(LOWORD(wp == 33)){
			MessageBox(hw, "Черт", "MessageBox", MB_OK|MB_ICONSTOP);
			EndDialog(hw,0);
		}
	}
	return FALSE;
}
BOOL CALLBACK CrWs(HWND hw, UINT msg, WPARAM wp, LPARAM lp){
	(void)lp;
	switch (msg)
	{
	case WM_INITDIALOG:
		return TRUE;
	case WM_COMMAND:
		if(LOWORD(wp == 35)){
			EndDialog(hw,0);
		}else if(LOWORD(wp == 36)){
			MessageBox(hw, "Черт", "MessageBox", MB_OK|MB_ICONSTOP);
			EndDialog(hw,0);
		}
		break;
	case WM_CLOSE:
		EndDialog(hw,IDCANCEL);
		return TRUE;
	}
	return FALSE;
}
LRESULT CALLBACK MainWinProc(HWND hw, UINT msg, WPARAM wp, LPARAM lp) {
    setlocale(LC_ALL,"");
	switch (msg) {
	case WM_CREATE:
		hFont1 = CreateFont(10,10,0,0,FW_NORMAL,FALSE,FALSE,TRUE,DEFAULT_CHARSET,OUT_DEFAULT_PRECIS,CLIP_DEFAULT_PRECIS, PROOF_QUALITY,DEFAULT_PITCH | FF_DONTCARE,"Times New Roman");
		hFont2 = CreateFont(20,0,500,0,FW_NORMAL,FALSE,FALSE,FALSE,DEFAULT_CHARSET,OUT_DEFAULT_PRECIS,CLIP_DEFAULT_PRECIS,DRAFT_QUALITY,DEFAULT_PITCH | FF_DONTCARE,"Times New Roman");
		hFont3 = CreateFont(30,0,0,0,FW_NORMAL,TRUE,TRUE,FALSE,DEFAULT_CHARSET,OUT_DEFAULT_PRECIS,CLIP_DEFAULT_PRECIS,DEFAULT_QUALITY,DEFAULT_PITCH | FF_DONTCARE,"Impact");
		HWND b1 = CreateWindow("button","Работать", WS_CHILD | BS_PUSHBUTTON | WS_VISIBLE, 5, 5, 100, 100, hw, (HMENU)ID_MYBUTTON1, NULL, NULL);
		HWND b2 = CreateWindow("button", "Отдыхать", WS_CHILD | BS_PUSHBUTTON |  WS_VISIBLE, 105, 5, 200, 200, hw, (HMENU)ID_MYBUTTON2, NULL, NULL); 
		HWND b3 = CreateWindow("button", "Гладить", WS_CHILD | BS_PUSHBUTTON |  WS_VISIBLE, 305, 5, 100, 300, hw, (HMENU)ID_MYBUTTON3, NULL, NULL);
		//HWND e1 = CreateWindow("edit", "", WS_CHILD | BS_TEXT |  WS_VISIBLE, 405, 5, 100, 100, hw, (HMENU)ID_EDIT1, NULL, NULL);
		SendMessage(b1,WM_SETFONT,(WPARAM)hFont1,TRUE);
		SendMessage(b2,WM_SETFONT,(WPARAM)hFont2,TRUE);
		SendMessage(b3,WM_SETFONT,(WPARAM)hFont3,TRUE);
		return 0;
	case WM_COMMAND:
		if ((HIWORD(wp)==0) && (LOWORD(wp)==ID_MYBUTTON1)) 
			CreateDialog(GetModuleHandle(NULL),MAKEINTRESOURCE(32),hw,CrWs);
		else if ((HIWORD(wp)==0) && (LOWORD(wp)==ID_MYBUTTON2)) 
			CreateDialog(GetModuleHandle(NULL),MAKEINTRESOURCE(33),hw,CrWs);
		else if ((HIWORD(wp)==0) && (LOWORD(wp)==ID_MYBUTTON3)) 
			CreateDialog(GetModuleHandle(NULL),MAKEINTRESOURCE(34),hw,CrWs);
		else if (HIWORD(wp)==0){
			switch (LOWORD(wp))
			{
			case 2:
				CreateDialog(GetModuleHandle(NULL),MAKEINTRESOURCE(41),hw,CrWs);
				break;
			case 3:
				CreateDialog(GetModuleHandle(NULL),MAKEINTRESOURCE(35),hw,CrWs);
				break;
			case 4:
				CreateDialog(GetModuleHandle(NULL),MAKEINTRESOURCE(45),hw,CrWs);
				break;
			case 5:
				PostQuitMessage(0);
				break;
			case 6:
				CreateDialog(GetModuleHandle(NULL),MAKEINTRESOURCE(51),hw,CrWs);
				break;
			case 7:
				CreateDialog(GetModuleHandle(NULL),MAKEINTRESOURCE(55),hw,CrWs);
				break;
			case 8:
				CreateDialog(GetModuleHandle(NULL),MAKEINTRESOURCE(59),hw,CrWs);
				break;
			case 9:
				CreateDialog(GetModuleHandle(NULL),MAKEINTRESOURCE(63),hw,CrWs);
				break;
			case 10:
				CreateDialog(GetModuleHandle(NULL),MAKEINTRESOURCE(67),hw,CrWs);
				break;
			case 11:
				MessageBox(hw, "Мамонт обнаружен", "MessageBox", MB_OK|MB_ICONSTOP);
				break;
			case 12:
				DialogBox(GetModuleHandle(NULL),MAKEINTRESOURCE(31),hw,DigProc);
				break;
			default:
				break;
			}
		}
		return 0;
	case WM_DESTROY:
		PostQuitMessage(0);
		return 0;
	case WM_SETCURSOR:
		if ((HWND)wp == GetDlgItem(hw,1)){
			hCursor1 = (HCURSOR)LoadImage(NULL,"resource\\Working.ani",IMAGE_CURSOR,0,0,LR_LOADFROMFILE);
			SetCursor(hCursor1);
			return TRUE;
		}else if ((HWND)wp == GetDlgItem(hw,13)){
			hCursor1 = (HCURSOR)LoadImage(NULL,"resource\\Alternate.ani",IMAGE_CURSOR,0,0,LR_LOADFROMFILE);
			SetCursor(hCursor1);
			return TRUE;
		}else if ((HWND)wp == GetDlgItem(hw,14)){
			hCursor1 = (HCURSOR)LoadImage(NULL,"resource\\Precision.ani",IMAGE_CURSOR,0,0,LR_LOADFROMFILE);
			SetCursor(hCursor1);
			return TRUE;
		}else if ((HWND)wp == GetDlgItem(hw,30)){
			hCursor1 = (HCURSOR)LoadImage(NULL,"resource\\Text.ani",IMAGE_CURSOR,0,0,LR_LOADFROMFILE);
			SetCursor(hCursor1);
			return TRUE;
		}
	}
	return DefWindowProc(hw,msg,wp,lp);
}
