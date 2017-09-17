// MainDlg.h : interface of the CMainDlg class
//
/////////////////////////////////////////////////////////////////////////////

#pragma once
#include "MatrixFill.h"

class CMainDlg : public CDialogImpl<CMainDlg>
{
public:
	enum { IDD = IDD_MAINDLG };

	BEGIN_MSG_MAP(CMainDlg)
		MESSAGE_HANDLER(WM_INITDIALOG, OnInitDialog)
		MESSAGE_HANDLER(WM_KEYUP, vyvid)
		COMMAND_ID_HANDLER(ID_APP_ABOUT, OnAppAbout)		
		COMMAND_ID_HANDLER(IDOK, OnOK)
		COMMAND_ID_HANDLER(IDCANCEL, OnCancel)
		
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
		vuvid();
		
	

		return TRUE;
	}

	LRESULT OnAppAbout(WORD /*wNotifyCode*/, WORD /*wID*/, HWND /*hWndCtl*/, BOOL& /*bHandled*/)
	{
		CSimpleDialog<IDD_ABOUTBOX, FALSE> dlg;
		dlg.DoModal();
		return 0;
	}

	LRESULT OnOK(WORD /*wNotifyCode*/, WORD wID, HWND /*hWndCtl*/, BOOL& /*bHandled*/)
	{
		// TODO: Add validation code 
		EndDialog(wID);
		return 0;
	}

	LRESULT OnCancel(WORD /*wNotifyCode*/, WORD wID, HWND /*hWndCtl*/, BOOL& /*bHandled*/)
	{
		EndDialog(wID);
		return 0;
	}
	void vuvid()
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
	

	}

	LRESULT vyvid(UINT /*uMsg*/, WPARAM wID, LPARAM /*lParam*/, BOOL& /*bHandled*/)
	{
		MatrixFill ar;
				
		
		switch (wID) {
		case 0x57:
			ar.vlivo();
			ar.randomfill();
			break;
		case 0x26:
			ar.vverh();
			ar.randomfill();
			break;
		case 0x27:
			ar.vpravo();
			ar.randomfill();
			break;
		case 0x28:
			ar.vnyz(); 
			ar.randomfill();
			break;
		}
				
		
		return 1;
	};

};
