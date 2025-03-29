#include <windows.h>
#include <locale.h>
LRESULT CALLBACK MainWinProc(HWND,UINT,WPARAM,LPARAM);
#define ID_MYBUTTON1 1    
#define ID_MYBUTTON2 13
#define ID_MYBUTTON3 14
HCURSOR hCursor1;
static HFONT hFont1,hFont2,hFont3;
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
		SendMessage(b1,WM_SETFONT,(WPARAM)hFont1,TRUE);
		SendMessage(b2,WM_SETFONT,(WPARAM)hFont2,TRUE);
		SendMessage(b3,WM_SETFONT,(WPARAM)hFont3,TRUE);
		return 0;
	
	case WM_COMMAND:
		if ((HIWORD(wp)==0) && (LOWORD(wp)==ID_MYBUTTON1)) 
			MessageBox(hw, "Неть", "MessageBox", MB_OK|MB_ICONSTOP);
		else if ((HIWORD(wp)==0) && (LOWORD(wp)==ID_MYBUTTON2)) 
			MessageBox(hw, "Спать", "MessageBox", MB_OK|MB_ICONWARNING);
		else if ((HIWORD(wp)==0) && (LOWORD(wp)==ID_MYBUTTON3)) 
			MessageBox(hw, "Дать", "MessageBox", MB_OK|MB_ICONASTERISK);
		else if (HIWORD(wp)==0){
			//char buf[256];
			switch (LOWORD(wp))
			{
			case 2:
				MessageBox(hw, "Не открою", "MessageBox", MB_OK|MB_ICONSTOP);
				break;
			case 3:
				MessageBox(hw, "Не сохраню ", "MessageBox", MB_OK|MB_ICONSTOP);
				break;
			case 4:
				MessageBox(hw, "Как?", "MessageBox", MB_OK|MB_ICONSTOP);
				break;
			case 5:
				PostQuitMessage(0);
				break;
			case 6:
				MessageBox(hw, "Коооооопииипааааастааааааа", "MessageBox", MB_OK|MB_ICONSTOP);
				break;
			case 7:
				MessageBox(hw, "Куда?", "MessageBox", MB_OK|MB_ICONSTOP);
				break;
			case 8:
				MessageBox(hw, "Мало", "MessageBox", MB_OK|MB_ICONSTOP);
				break;
			case 9:
				MessageBox(hw, "Средне", "MessageBox", MB_OK|MB_ICONSTOP);
				break;
			case 10:
				MessageBox(hw, "Много", "MessageBox", MB_OK|MB_ICONSTOP);
				break;
			case 11:
				MessageBox(hw, "Мамонт обнаружен", "MessageBox", MB_OK|MB_ICONSTOP);
				break;
			case 12:
				MessageBox(hw, "Дата основания старых ворон:1775", "MessageBox", MB_OK|MB_ICONSTOP);
				break;
			default:
				break;
			}
		}
		return 0;
	case WM_DESTROY:
		MessageBox(hw, "Goodbye", "MessageBox", MB_OK|MB_ICONINFORMATION);
		PostQuitMessage(0);
		return 0;
	case WM_SETCURSOR:
		if ((HWND)wp == GetDlgItem(hw,1)){
			hCursor1 = (HCURSOR)LoadImage(NULL,"Working.ani",IMAGE_CURSOR,0,0,LR_LOADFROMFILE);
			SetCursor(hCursor1);
			return TRUE;
		}else if ((HWND)wp == GetDlgItem(hw,13)){
			hCursor1 = (HCURSOR)LoadImage(NULL,"Alternate.ani",IMAGE_CURSOR,0,0,LR_LOADFROMFILE);
			SetCursor(hCursor1);
			return TRUE;
		}else if ((HWND)wp == GetDlgItem(hw,14)){
			hCursor1 = (HCURSOR)LoadImage(NULL,"Precision.ani",IMAGE_CURSOR,0,0,LR_LOADFROMFILE);
			SetCursor(hCursor1);
			return TRUE;
		}

	}
	
	return DefWindowProc(hw,msg,wp,lp);
}
