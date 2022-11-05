
// ApplicationDlg.h : header file
//

#pragma once

#include "HalconBase.h"

#define TIMER 100			// msec
#define ID_TIMER 11			

// CApplicationDlg dialog
class CApplicationDlg : public CDialogEx
{
// Construction
public:
	CApplicationDlg(CWnd* pParent = nullptr);	// standard constructor

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_APPLICATION_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support

private :

	void Init();
	void InitDialog();

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()

	afx_msg void OnTimer(UINT_PTR nIDEvent);



private :

	CHalconBase*	m_pHalconBase;
	CSliderCtrl*	m_pSlider[eCamParam::eEndCamParam];
	int				m_nSlider[eCamParam::eEndCamParam];
	CString			m_strFolder;


public:
	afx_msg void OnBnClickedButtonSnap();
};

