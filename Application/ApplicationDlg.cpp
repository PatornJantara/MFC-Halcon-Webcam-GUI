
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
	ON_WM_TIMER()
	ON_WM_VSCROLL()
	ON_BN_CLICKED(IDC_BUTTON_SNAP, &CApplicationDlg::OnBnClickedButtonSnap)
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

	m_pHalconBase = new CHalconBase();

	Init();
	InitDialog();
	
	SetTimer(ID_TIMER, TIMER, NULL);

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

	for (int nProp = eBrightness; nProp < eEndCamParam; nProp++) {

		if (m_nSlider[nProp] != m_pSlider[nProp]->GetPos()) {
			
			m_nSlider[nProp] = m_pSlider[nProp]->GetPos();

			m_pHalconBase->SetCam(nProp, m_nSlider[nProp]);
		}
	
	}

	m_pHalconBase->Live();


	CDialog::OnTimer(nIDEvent);
}








void CApplicationDlg::Init() {

	TCHAR buff[MAX_PATH];
	memset(buff, 0, MAX_PATH);
	
	::GetModuleFileName(NULL, buff, sizeof(buff));

	m_strFolder = buff;
	m_strFolder = m_strFolder.Left(m_strFolder.ReverseFind(_T('\\')) + 1);




}




void CApplicationDlg::InitDialog() {

	OpenWindow(0, 0, 640, 480, (Hlong)this->m_hWnd, "visible", "", &m_pHalconBase->hv_WindowHandle);
	SetPart(m_pHalconBase->hv_WindowHandle, 0, 0, 479, 639);

	
	for (size_t i = 0; i < eCamParam::eEndCamParam; i++)
	{
		m_pSlider[i] = new CSliderCtrl();
	}
	memset(m_nSlider, 0, sizeof(m_nSlider));



	for (int nPropBar = eBrightness; nPropBar < eEndCamParam; nPropBar++) {

		m_pSlider[nPropBar]->Create(	WS_CHILD | WS_VISIBLE,
										CRect(650, 170 +nPropBar*20, 800, 180 + nPropBar*20),
										this, IDC_SLIDER1);

		m_pSlider[nPropBar]->SetRange(CAM_PROP[nPropBar][eMin], CAM_PROP[nPropBar][eMax]);
		m_pSlider[nPropBar]->SetPos(CAM_PROP_DEFAULT[nPropBar]);
		m_nSlider[nPropBar] = m_pSlider[nPropBar]->GetPos();

	}


}






void CApplicationDlg::OnBnClickedButtonSnap()
{
	// TODO: Add your control notification handler code here

	KillTimer(ID_TIMER);


	m_pHalconBase->Snap(m_strFolder);

	SetTimer(ID_TIMER, TIMER, NULL);
}
