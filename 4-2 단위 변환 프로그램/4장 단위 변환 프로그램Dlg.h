
// 4장 단위 변환 프로그램Dlg.h: 헤더 파일
//

#pragma once


// CMy4장단위변환프로그램Dlg 대화 상자
class CMy4장단위변환프로그램Dlg : public CDialogEx
{
// 생성입니다.
public:
	CMy4장단위변환프로그램Dlg(CWnd* pParent = nullptr);	// 표준 생성자입니다.

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MY4____DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 지원입니다.


// 구현입니다.
protected:
	HICON m_hIcon;

	// 생성된 메시지 맵 함수
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnEnChangeEditPresentUnit();
//	double m_dPresentValue;
//	double m_dChangeValue;
	double m_dPresentValue;
	double m_dChangeValue;
	CString m_strPresentUnit;
	CString m_dstrChangeUnit;
	CString m_strUnit;
	CListBox m_listChangeUnit;
	CListBox m_listPresentUnit;
	afx_msg void OnRadioLegnth();
	afx_msg void OnRadioWeight();
	void ComputeUnitValue();
	int m_nUnitSelect;
	afx_msg void OnChangeEditPresentValue();
	afx_msg void OnSelchangeListPresentUnit();
	afx_msg void OnSelchangeListChangeUnit();
//	CEdit m_strChangeUnit;
	CString m_strChangeUnit;
	bool m_bUnitViewed;
	CUnitTableDlg m_dlgUnitTable;
	afx_msg void OnClickedButtonUnitView();
	afx_msg void OnBnClickedRadio1();
	afx_msg void OnRadioVolum();
	afx_msg void OnBnClickedRadioVolum();
	afx_msg void OnRadioVolum1();
};
