
// ApplicationDlg.h : header file
//

#pragma once

#include "HalconBase.h"

#define TIMER 100
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
public:
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
	afx_msg void OnBnClickedButton3();



public:

	CHalconBase* m_pHalconBase;
	afx_msg void OnBnClickedButton4();
	afx_msg void OnBnClickedButton5();

	CSliderCtrl* m_pSlider[eCamParam::eEndCamParam];

	int			 m_nSlider[eCamParam::eEndCamParam];
};

