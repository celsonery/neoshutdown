/*
	Programa "Neo Shutdown" criado por Celso Nery, objetivo e desligar remotamente
	as maquinas da lan house.

 */
#include <windows.h>
#include <commctrl.h>
#include "resource.h"

#pragma comment(lib, "comctl32.lib")

#define WIN32_LEAN_AND_MEAN

BOOL CALLBACK ProcDLG(HWND, UINT, WPARAM, LPARAM);

// Variaveis Globais
//HINSTANCE hInst;

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nShowCmd)
{
//	hInst = hInstance;

	InitCommonControls();

	return DialogBox(NULL, MAKEINTRESOURCE(idd_Dialog), NULL, DLGPROC(ProcDLG));
}


BOOL CALLBACK ProcDLG(HWND hDlg, UINT msg, WPARAM wParam, LPARAM lParam)
{
	switch(msg)
	{
		case WM_INITDIALOG:
			{
				//HBITMAP hBmp2;
				//hBmp2 = LoadBitmap(hInst,"idBmpShutdown");
				//HWND btn_shutdown = GetDlgItem(hDlg, idShutdown);
				// setando o checkbox todas as maquinas
				CheckDlgButton(hDlg, idTodas, BST_CHECKED); 
				
				// Carregando o icone da janela.
				SendMessage(hDlg, WM_SETICON, (WPARAM)NULL, (LPARAM)LoadIcon(GetModuleHandle(NULL), MAKEINTRESOURCE(idIconApp)));
				SendMessage(GetDlgItem(hDlg, idList), LB_ADDSTRING, 0, (LPARAM)"10.0.1.1");
				SendMessage(GetDlgItem(hDlg, idList), LB_ADDSTRING, 0, (LPARAM)"10.0.1.2");
				
				//SendMessage(GetDlgItem(hDlg, idShutdown), BM_SETIMAGE, IMAGE_BITMAP, (LPARAM)LoadBitmap(GetModuleHandle(NULL), MAKEINTRESOURCE(idBmpShutdown)));
				//SendMessage(btn_shutdown, BM_SETIMAGE, IMAGE_BITMAP, (LPARAM)(HBITMAP)hBmp2);

			}break;

		case WM_COMMAND:
			switch(LOWORD(wParam))
			{
				case idSair:
					EndDialog(hDlg, 0);
					break;

				case idShutdown:
					{
						//ShellExecute(NULL, NULL, "cmd.exe","/c dir /s c:",NULL, SW_SHOW);
					}
					/*
					MessageBeep(MB_ICONWARNING);
					if(MessageBox(NULL, "Deseja desligar todas as maquinas?", "Neo Shutdown", MB_YESNO | MB_ICONWARNING) == IDYES)
					{
							WinExec("cmd.exe /c shutdown -s -f -t 0 -m 10.0.1.1", SW_HIDE);
							WinExec("cmd.exe /c shutdown -s -f -t 0 -m 10.0.1.2", SW_HIDE);
							WinExec("cmd.exe /c shutdown -s -f -t 0 -m 10.0.1.3", SW_HIDE);
							WinExec("cmd.exe /c shutdown -s -f -t 0 -m 10.0.1.4", SW_HIDE);
							WinExec("cmd.exe /c shutdown -s -f -t 0 -m 10.0.1.5", SW_HIDE);
							WinExec("cmd.exe /c shutdown -s -f -t 0 -m 10.0.1.6", SW_HIDE);
							WinExec("cmd.exe /c shutdown -s -f -t 0 -m 10.0.1.7", SW_HIDE);
							WinExec("cmd.exe /c shutdown -s -f -t 0 -m 10.0.1.8", SW_HIDE);
							WinExec("cmd.exe /c shutdown -s -f -t 0 -m 10.0.1.9", SW_HIDE);
							WinExec("cmd.exe /c shutdown -s -f -t 0 -m 10.0.1.10", SW_HIDE);
							WinExec("cmd.exe /c shutdown -s -f -t 0 -m 10.0.1.11", SW_HIDE);
					}
					*/
					break;

				case idTodas:
					if(SendMessage(GetDlgItem(hDlg, idTodas), BM_GETCHECK, 0, 0) == BST_CHECKED)
					{
						EnableWindow(GetDlgItem(hDlg, idList), FALSE);
						//MessageBox(NULL,"teste de botao", "Neo Shutdown", MB_OK);
					}else{
						EnableWindow(GetDlgItem(hDlg, idList), TRUE);
					}
					break;

			}
			break;

		case WM_CLOSE:
			EndDialog(hDlg, 0);
			break;

	}
	return 0;
}

void Maquinas()
{
}
