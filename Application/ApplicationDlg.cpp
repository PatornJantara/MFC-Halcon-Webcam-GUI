
// ApplicationDlg.cpp : implementation file
//

#include "pch.h"
#include "framework.h"
#include "Application.h"
#include "ApplicationDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

static UINT TestStartThread(LPVOID param);

// CAboutDlg dialog used for App About

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

// Implementation
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CApplicationDlg dialog



CApplicationDlg::CApplicationDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_APPLICATION_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CApplicationDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);


}

BEGIN_MESSAGE_MAP(CApplicationDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON2, &CApplicationDlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON3, &CApplicationDlg::OnBnClickedButton3)
	ON_WM_TIMER()
	ON_WM_VSCROLL()
	ON_BN_CLICKED(IDC_BUTTON4, &CApplicationDlg::OnBnClickedButton4)
	ON_BN_CLICKED(IDC_BUTTON5, &CApplicationDlg::OnBnClickedButton5)
END_MESSAGE_MAP()


// CApplicationDlg message handlers

BOOL CApplicationDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	// TODO: Add extra initialization here
	SetTimer(ID_TIMER,TIMER,NULL);

	OpenWindow(0, 0, 640, 480, (Hlong)this->m_hWnd, "visible", "", &m_pHalconBase->hv_WindowHandle);
	SetPart(m_pHalconBase->hv_WindowHandle, 0, 0, 479, 639);
	m_pHalconBase->ho_Image.GenEmptyObj();

	for (size_t i = 0; i < eCamParam::eEndCamParam; i++)
	{
		m_pSlider[i] = new CSliderCtrl();
	}

	int min = 1, max = 255;

	m_pSlider[eBrightness]->Create(WS_CHILD | WS_VISIBLE, CRect(650,170,800, 180), this, IDC_SLIDER1);
	m_pSlider[eBrightness]->SetRange(min, max);
	m_pSlider[eBrightness]->SetPos((max - min) / 2);

	m_pSlider[eConstrast]->Create(WS_CHILD | WS_VISIBLE, CRect(650, 190, 800, 200), this, IDC_SLIDER2);
	m_pSlider[eConstrast]->SetRange(min, max);
	m_pSlider[eConstrast]->SetPos((max - min) / 2);

	min = 10; max =200;
	m_pSlider[eSaturation]->Create(WS_CHILD | WS_VISIBLE, CRect(650, 210, 800, 220), this, IDC_SLIDER3);
	m_pSlider[eSaturation]->SetRange(min, max);
	m_pSlider[eSaturation]->SetPos((max - min) / 2);

	m_pSlider[eSharpness]->Create(WS_CHILD | WS_VISIBLE, CRect(650, 230, 800, 240), this, IDC_SLIDER4);
	m_pSlider[eSharpness]->SetRange(min, max);
	m_pSlider[eSharpness]->SetPos((max - min) / 2);

	min = 2800; max = 6500;
	m_pSlider[eWhiteBalance]->Create(WS_CHILD | WS_VISIBLE, CRect(650, 250, 800, 260), this, IDC_SLIDER5);
	m_pSlider[eWhiteBalance]->SetRange(min, max);
	m_pSlider[eWhiteBalance]->SetPos(((max - min) / 2) + min);

	min = 30; max =30;
	m_pSlider[eFramerate]->Create(WS_CHILD | WS_VISIBLE, CRect(650, 270, 800, 280), this, IDC_SLIDER6);
	m_pSlider[eFramerate]->SetRange(min, max);
	m_pSlider[eFramerate]->SetPos((max - min) / 2);

	min = 1; max = 150;
	m_pSlider[eZoom]->Create(WS_CHILD | WS_VISIBLE, CRect(650, 290,800, 300), this, IDC_SLIDER7);
	m_pSlider[eZoom]->SetRange(min, max);
	m_pSlider[eZoom]->SetPos((max - min) / 2);


	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CApplicationDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CApplicationDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CApplicationDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

void CApplicationDlg::OnTimer(UINT_PTR nIDEvent)
{
	int n = 0;


	if (m_pHalconBase->m_bFlgBusy) {

		for (size_t i = 0; i < eCamParam::eEndCamParam; i++)
		{
			n = m_pSlider[i]->GetPos();
			m_pHalconBase->SetParam(i, m_pSlider[i]->GetPos());
		}
		
		m_pHalconBase->Live();
	}

	DispObj(m_pHalconBase->ho_Image, m_pHalconBase->hv_WindowHandle);


	CDialog::OnTimer(nIDEvent);
}




//	Multi webcam thread
static UINT TestStartThread(LPVOID param) {

	UINT uRetCode = eNoErr;

	CHalconBase* sudoHalconBase = (CHalconBase*)param;

	///////////// add To Do here //////////////////////



	return uRetCode;
}

// Multi webcam shot
// !!!!! Not complete

void CApplicationDlg::OnBnClickedButton2()
{

	DWORD dwRetThread = 0;

	CWinThread* pThread;


	LPVOID lpFlgThread = static_cast<LPVOID>(m_pHalconBase);


	pThread = AfxBeginThread(TestStartThread
		, lpFlgThread, THREAD_PRIORITY_NORMAL, 0, 0, NULL);


	WaitForSingleObject(pThread, INFINITE);


}



void CApplicationDlg::OnBnClickedButton3()
{
	// TODO: Add your control notification handler code here


	HObject HSnapImg = m_pHalconBase->ho_Image.Clone();

	CFileDialog DialogSave(FALSE, // TRUE for FileOpen, FALSE for FileSaveAs
							_T(".jpeg"),
							NULL,
							OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT,
							_T("(*.jpeg)|*.jpeg||"),
							NULL,
							0,
							TRUE);

	// A dialog box with several filters for various media file types
	static int LastIndex = -1;          // Holds the last used filter. You can store it in the Registry to use it during next run.


	if (LastIndex != -1) DialogSave.m_ofn.nFilterIndex = LastIndex; // restore last used index 
														// from last time

	if (DialogSave.DoModal() == IDOK)
	{
		LastIndex = DialogSave.m_ofn.nFilterIndex; // Store last used index for next time
		CString sFilePath = DialogSave.GetPathName();

		CStringA str(sFilePath);

		const char* ImgSave = str;

		HalconCpp::WriteImage(HSnapImg, "jpeg", 0, ImgSave);

	}
}

// Stop button
void CApplicationDlg::OnBnClickedButton4()
{
	// TODO: Add your control notification handler code here

	m_pHalconBase->Stop();

}

// Connect cam button
void CApplicationDlg::OnBnClickedButton5()
{
	// TODO: Add your control notification handler code here
	if (m_pHalconBase->m_bFlgBusy)		return;

	m_pHalconBase->OpenCam();


}
