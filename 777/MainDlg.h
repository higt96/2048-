// MainDlg.h : interface of the CMainDlg class
//
/////////////////////////////////////////////////////////////////////////////
#include "MatrixFill.h"
#pragma once

class CMainDlg : public CDialogImpl<CMainDlg>, public CUpdateUI<CMainDlg>,
		public CMessageFilter, public CIdleHandler
{
public:
	enum { IDD = IDD_MAINDLG };

	virtual BOOL PreTranslateMessage(MSG* pMsg)
	{
		if (pMsg->message == WM_KEYDOWN)
			 {
			vyvid(pMsg->wParam);
			}
		return CWindow::IsDialogMessage(pMsg);
		
	}
	

	virtual BOOL OnIdle()
	{
		UIUpdateChildWindows();
		return FALSE;
	}

	BEGIN_UPDATE_UI_MAP(CMainDlg)
	END_UPDATE_UI_MAP()

	BEGIN_MSG_MAP(CMainDlg)
		MESSAGE_HANDLER(WM_INITDIALOG, OnInitDialog)
		MESSAGE_HANDLER(WM_DESTROY, OnDestroy)
		COMMAND_ID_HANDLER(ID_APP_ABOUT, OnAppAbout)
		COMMAND_ID_HANDLER(IDOK, OnOK)
		COMMAND_ID_HANDLER(IDCANCEL, OnCancel)
		COMMAND_HANDLER(IDC_BUTTON1, BN_CLICKED, OnBnClickedButton1)
	END_MSG_MAP()

// Handler prototypes (uncomment arguments if needed):
//	LRESULT MessageHandler(UINT /*uMsg*/, WPARAM /*wParam*/, LPARAM /*lParam*/, BOOL& /*bHandled*/)
//	LRESULT CommandHandler(WORD /*wNotifyCode*/, WORD /*wID*/, HWND /*hWndCtl*/, BOOL& /*bHandled*/)
//	LRESULT NotifyHandler(int /*idCtrl*/, LPNMHDR /*pnmh*/, BOOL& /*bHandled*/)

	LRESULT OnInitDialog(UINT /*uMsg*/, WPARAM /*wParam*/, LPARAM /*lParam*/, BOOL& /*bHandled*/)
	{
		// center the dialog on the screen
		CenterWindow();

		// set icons
		HICON hIcon = AtlLoadIconImage(IDR_MAINFRAME, LR_DEFAULTCOLOR, ::GetSystemMetrics(SM_CXICON), ::GetSystemMetrics(SM_CYICON));
		SetIcon(hIcon, TRUE);
		HICON hIconSmall = AtlLoadIconImage(IDR_MAINFRAME, LR_DEFAULTCOLOR, ::GetSystemMetrics(SM_CXSMICON), ::GetSystemMetrics(SM_CYSMICON));
		SetIcon(hIconSmall, FALSE);

		// register object for message filtering and idle updates
		CMessageLoop* pLoop = _Module.GetMessageLoop();
		ATLASSERT(pLoop != NULL);
		pLoop->AddMessageFilter(this);
		pLoop->AddIdleHandler(this);

		UIAddChildWindowContainer(m_hWnd);
		//vuvid();

		return TRUE;
	}

	LRESULT OnDestroy(UINT /*uMsg*/, WPARAM /*wParam*/, LPARAM /*lParam*/, BOOL& /*bHandled*/)
	{
		// unregister message filtering and idle updates
		CMessageLoop* pLoop = _Module.GetMessageLoop();
		ATLASSERT(pLoop != NULL);
		pLoop->RemoveMessageFilter(this);
		pLoop->RemoveIdleHandler(this);

		return 0;
	}

	LRESULT OnAppAbout(WORD /*wNotifyCode*/, WORD /*wID*/, HWND /*hWndCtl*/, BOOL& /*bHandled*/)
	{
		CAboutDlg dlg;
		dlg.DoModal();
		return 0;
	}

	LRESULT OnOK(WORD /*wNotifyCode*/, WORD wID, HWND /*hWndCtl*/, BOOL& /*bHandled*/)
	{
		// TODO: Add validation code 
		CloseDialog(wID);
		return 0;
	}

	LRESULT OnCancel(WORD /*wNotifyCode*/, WORD wID, HWND /*hWndCtl*/, BOOL& /*bHandled*/)
	{
		CloseDialog(wID);
		return 0;
	}

	void CloseDialog(int nVal)
	{
		DestroyWindow();
		::PostQuitMessage(nVal);
	}

	/*void vuvid()
	{
		MatrixFill ar;
		int k = 1000;
		ar.clearm();
		ar.field[0][1] = 2;
		ar.field[0][3] = 2;
		ar.field[1][1] = 8;
		ar.field[2][0] = 2;
		ar.field[2][2] = 4;
		ar.field[2][3] = 2;
		ar.field[3][2] = 2;
		wchar_t s[256];

		for (int i = 0; i < 4; i++) {
			for (int n = 0; n < 4; n++) {

				wsprintfW(s, L"%d", ar.field[i][n]);
				SetDlgItemText(k, s);
				//		MessageBoxW(nullptr, s, MB_OK);
				k++;
			}
		}


	}*/

	void vyvid(WPARAM wID)
	{
		MatrixFill ar;
		wchar_t s[1000];
		int k;	
		switch (wID) {
		case 37:
			ar.vlivo();
			ar.randomfill();
			k = 1000;
			for (int i = 0; i < 4; i++) {
				for (int n = 0; n < 4; n++) {

					wsprintfW(s, L"%d", field[i][n]);
					SetDlgItemText(k, s);
					if (field[i][n] == 2048) {
						MessageBoxW(nullptr, L"Win", MB_OK);
					}
					//		MessageBoxW(nullptr, s, MB_OK);
					k++;
				}
			}
			break;
		case 38:
			ar.vverh();
			ar.randomfill();
			k = 1000;
			for (int i = 0; i < 4; i++) {
				for (int n = 0; n < 4; n++) {
					wsprintfW(s, L"%d", field[i][n]);
					SetDlgItemText(k, s);
					if (field[i][n]==2048) {
						MessageBoxW(nullptr, L"Win", MB_OK);
					}
					//		MessageBoxW(nullptr, s, MB_OK);
					k++;
				}
			}
			break;
		case 39:
			ar.vpravo();
			ar.randomfill();
			k = 1000;
			for (int i = 0; i < 4; i++) {
				for (int n = 0; n < 4; n++) {

					wsprintfW(s, L"%d", field[i][n]);
					SetDlgItemText(k, s);
					if (field[i][n] == 2048) {
						MessageBoxW(nullptr, L"Win", MB_OK);
					}
					//		MessageBoxW(nullptr, s, MB_OK);
					k++;
				}
			}

			
			break;
		case 40:
			ar.vnyz();
			ar.randomfill();
			k = 1000;
			for (int i = 0; i < 4; i++) {
				for (int n = 0; n < 4; n++) {

					wsprintfW(s, L"%d", field[i][n]);
					SetDlgItemText(k, s);
					if (field[i][n] == 2048) {
						MessageBoxW(nullptr, L"Win", MB_OK);
					}
					//		MessageBoxW(nullptr, s, MB_OK);
					k++;
				}
			}
			break;
		case 88:
			ar.clearm();
			ar.randomfill();
			k = 1000;
			step=0;
			for (int i = 0; i < 4; i++) {
				for (int n = 0; n < 4; n++) {

					wsprintfW(s, L"%d", field[i][n]);
					SetDlgItemText(k, s);
					//		MessageBoxW(nullptr, s, MB_OK);
					k++;
				}
			}
			break;
			
		}

		wsprintfW(s, L"%d", step);
		SetDlgItemText(1016, s);
		//return 1;
	};
	LRESULT OnBnClickedButton1(WORD /*wNotifyCode*/, WORD /*wID*/, HWND /*hWndCtl*/, BOOL& /*bHandled*/)
	{
		MatrixFill ar;
		ar.clearm();
		ar.randomfill();
		wchar_t s[1000];
		int k = 1000;
		step = 0;
		for (int i = 0; i < 4; i++) {
			for (int n = 0; n < 4; n++) {

				wsprintfW(s, L"%d", field[i][n]);
				SetDlgItemText(k, s);
				//		MessageBoxW(nullptr, s, MB_OK);
				k++;
			}
		}

		return 0;
	}

};
