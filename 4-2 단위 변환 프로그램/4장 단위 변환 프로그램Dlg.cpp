﻿
// 4장 단위 변환 프로그램Dlg.cpp: 구현 파일
//

#include "pch.h"
#include "framework.h"
#include "4장 단위 변환 프로그램.h"
#include "4장 단위 변환 프로그램Dlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 응용 프로그램 정보에 사용되는 CAboutDlg 대화 상자입니다.

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

// 구현입니다.
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


// CMy4장단위변환프로그램Dlg 대화 상자



CMy4장단위변환프로그램Dlg::CMy4장단위변환프로그램Dlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_MY4____DIALOG, pParent)
	
	, m_dPresentValue(0)
	, m_dChangeValue(0)
	, m_strPresentUnit(_T(""))
	, m_dstrChangeUnit(_T(""))
	, m_strUnit(_T(""))
	, m_strChangeUnit(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	m_bUnitViewed = false;
}

void CMy4장단위변환프로그램Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	//  DDX_Text(pDX, IDC_EDIT_PRESENT_VALUE, m_dPresentValue);
	//  DDX_Control(pDX, IDC_EDIT2_CHANGE_VALUE, m_dChangeValue);
	DDX_Text(pDX, IDC_EDIT_PRESENT_VALUE, m_dPresentValue);
	DDX_Text(pDX, IDC_EDIT2_CHANGE_VALUE, m_dChangeValue);
	DDX_Text(pDX, IDC_EDIT_PRESENT_UNIT, m_strPresentUnit);
	DDX_Text(pDX, IDC_EDIT_CHANGE_UNIT, m_dstrChangeUnit);
	DDX_Text(pDX, IDC_EDIT_UNIT, m_strUnit);
	DDX_Control(pDX, IDC_LIST_CHANGE_UNIT, m_listChangeUnit);
	DDX_Control(pDX, IDC_LIST_PRESENT_UNIT, m_listPresentUnit);
	//  DDX_Control(pDX, IDC_EDIT_CHANGE_UNIT, m_strChangeUnit);
	DDX_Text(pDX, IDC_EDIT_CHANGE_UNIT, m_strChangeUnit);
}

BEGIN_MESSAGE_MAP(CMy4장단위변환프로그램Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_EN_CHANGE(IDC_EDIT_PRESENT_UNIT, &CMy4장단위변환프로그램Dlg::OnEnChangeEditPresentUnit)
	ON_COMMAND(IDC_RADIO_LEGNTH, &CMy4장단위변환프로그램Dlg::OnRadioLegnth)
	ON_COMMAND(IDC_RADIO_WEIGHT, &CMy4장단위변환프로그램Dlg::OnRadioWeight)
	ON_EN_CHANGE(IDC_EDIT_PRESENT_VALUE, &CMy4장단위변환프로그램Dlg::OnChangeEditPresentValue)
	ON_LBN_SELCHANGE(IDC_LIST_PRESENT_UNIT, &CMy4장단위변환프로그램Dlg::OnSelchangeListPresentUnit)
	ON_LBN_SELCHANGE(IDC_LIST_CHANGE_UNIT, &CMy4장단위변환프로그램Dlg::OnSelchangeListChangeUnit)
	ON_BN_CLICKED(IDC_BUTTON_UNIT_VIEW, &CMy4장단위변환프로그램Dlg::OnClickedButtonUnitView)

	
	
	ON_COMMAND(IDC_RADIO_Volum, &CMy4장단위변환프로그램Dlg::OnRadioVolum1)
END_MESSAGE_MAP()


// CMy4장단위변환프로그램Dlg 메시지 처리기

BOOL CMy4장단위변환프로그램Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 시스템 메뉴에 "정보..." 메뉴 항목을 추가합니다.

	// IDM_ABOUTBOX는 시스템 명령 범위에 있어야 합니다.
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

	// 이 대화 상자의 아이콘을 설정합니다.  응용 프로그램의 주 창이 대화 상자가 아닐 경우에는
	//  프레임워크가 이 작업을 자동으로 수행합니다.
	SetIcon(m_hIcon, TRUE);			// 큰 아이콘을 설정합니다.
	SetIcon(m_hIcon, FALSE);		// 작은 아이콘을 설정합니다.

	// TODO: 여기에 추가 초기화 작업을 추가합니다.

	return TRUE;  // 포커스를 컨트롤에 설정하지 않으면 TRUE를 반환합니다.
}

void CMy4장단위변환프로그램Dlg::OnSysCommand(UINT nID, LPARAM lParam)
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

// 대화 상자에 최소화 단추를 추가할 경우 아이콘을 그리려면
//  아래 코드가 필요합니다.  문서/뷰 모델을 사용하는 MFC 애플리케이션의 경우에는
//  프레임워크에서 이 작업을 자동으로 수행합니다.

void CMy4장단위변환프로그램Dlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 그리기를 위한 디바이스 컨텍스트입니다.

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 클라이언트 사각형에서 아이콘을 가운데에 맞춥니다.
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 아이콘을 그립니다.
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// 사용자가 최소화된 창을 끄는 동안에 커서가 표시되도록 시스템에서
//  이 함수를 호출합니다.
HCURSOR CMy4장단위변환프로그램Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CMy4장단위변환프로그램Dlg::OnEnChangeEditPresentUnit()
{
	// TODO:  RICHEDIT 컨트롤인 경우, 이 컨트롤은
	// CDialogEx::OnInitDialog() 함수를 재지정 
	//하고 마스크에 OR 연산하여 설정된 ENM_CHANGE 플래그를 지정하여 CRichEditCtrl().SetEventMask()를 호출하지 않으면
	// 이 알림 메시지를 보내지 않습니다.

	// TODO:  여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


void CMy4장단위변환프로그램Dlg::OnRadioLegnth()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	m_nUnitSelect = 1;
	m_listPresentUnit.ResetContent();
	m_listChangeUnit.ResetContent();
	m_strUnit.Empty();
	m_dPresentValue = m_dChangeValue = 0;

	m_listPresentUnit.AddString(_T("미터(m)"));
	m_listPresentUnit.AddString(_T("인치(in)"));
	m_listPresentUnit.AddString(_T("야드(yd)"));

	m_listChangeUnit.AddString(_T("미터(m)"));
	m_listChangeUnit.AddString(_T("인치(in)"));
	m_listChangeUnit.AddString(_T("야드(yd)")); 
	m_listPresentUnit.SetCurSel(0);
	m_listChangeUnit.SetCurSel(0);
	m_strUnit = + _T("미터(m)--> 미터(m)");
	m_strPresentUnit = _T("m");
	m_dstrChangeUnit = _T("m");
	UpdateData(FALSE);
}


void CMy4장단위변환프로그램Dlg::OnRadioWeight()
{
	
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	m_nUnitSelect = 2;
	m_listPresentUnit.ResetContent();
	m_listChangeUnit.ResetContent();
	m_strUnit.Empty();
	m_dPresentValue = m_dChangeValue = 0;

	m_listPresentUnit.AddString(_T("그램(g)"));
	m_listPresentUnit.AddString(_T("온즈(oz)"));
	m_listPresentUnit.AddString(_T("파운드(Ib)"));

	m_listChangeUnit.AddString(_T("그램(g)"));
	m_listChangeUnit.AddString(_T("온즈(oz)"));
	m_listChangeUnit.AddString(_T("파운드(Ib)"));
	m_listPresentUnit.SetCurSel(0);
	m_listChangeUnit.SetCurSel(0);
	m_strUnit = _T("그램(m)--> 그램(m)");
	m_strPresentUnit = _T("g");
	m_dstrChangeUnit = _T("g");
	UpdateData(FALSE);
}


void CMy4장단위변환프로그램Dlg::ComputeUnitValue()
{	
	// TODO: 여기에 구현 코드 추가.
	UpdateData(TRUE);
	int index1,index2,index3;
	index1 = m_listPresentUnit.GetCurSel();
	index2 = m_listChangeUnit.GetCurSel();

	m_dChangeValue = m_dPresentValue;

	switch (m_nUnitSelect)
	{
	case 1:
		if (index1 == 0 && index2 == 1)
			m_dChangeValue = m_dPresentValue * 39.370079;
		if (index1 == 0 && index2 == 2)
			m_dChangeValue = m_dPresentValue * 1.093613;
		
		if (index1 == 1 && index2 == 0)
			m_dChangeValue = m_dPresentValue * 0.0254;
		if (index1 == 1 && index2 == 0)
			m_dChangeValue = m_dPresentValue * 0.027778;

		if (index1 == 2 && index2 == 0)
			m_dChangeValue = m_dPresentValue * 0.9144;
		if (index1 == 2 && index2 == 1)
			m_dChangeValue = m_dPresentValue * 36;
		break;
	case 2:
		if (index1 == 0 && index2 == 1)
			m_dChangeValue = m_dPresentValue * 0.035274;
		if (index1 == 0 && index2 == 2)
			m_dChangeValue = m_dPresentValue * 0.002205;

		if (index1 == 1 && index2 == 0)
			m_dChangeValue = m_dPresentValue * 28.349523;
		if (index1 == 1 && index2 == 2)
			m_dChangeValue = m_dPresentValue * 0.0625;

		if (index1 == 2 && index2 == 0)
			m_dChangeValue = m_dPresentValue * 453.5937;
		if (index1 == 2 && index2 == 1)
			m_dChangeValue = m_dPresentValue * 16;
		break;
	case 3:
		if (index1 == 0 && index2 == 1)
			m_dChangeValue = m_dPresentValue * 0.264172;
		if (index1 == 0 && index2 == 2)
			m_dChangeValue = m_dPresentValue / 0.0295735;

		if (index1 == 1 && index2 == 0)
			m_dChangeValue = m_dPresentValue * 3.78541;
		if (index1 == 1 && index2 == 2)
			m_dChangeValue = m_dPresentValue  *128;

		if (index1 == 2 && index2 == 0)
			m_dChangeValue = m_dPresentValue * 0.0295735;
		if (index1 == 2 && index2 == 1)
			m_dChangeValue = m_dPresentValue / 128;
		
	}
	UpdateData(FALSE);
}


void CMy4장단위변환프로그램Dlg::OnChangeEditPresentValue()
{
	// TODO:  RICHEDIT 컨트롤인 경우, 이 컨트롤은
	// CDialogEx::OnInitDialog() 함수를 재지정 
	//하고 마스크에 OR 연산하여 설정된 ENM_CHANGE 플래그를 지정하여 CRichEditCtrl().SetEventMask()를 호출하지 않으면
	// 이 알림 메시지를 보내지 않습니다.

	// TODO:  여기에 컨트롤 알림 처리기 코드를 추가합니다.
	ComputeUnitValue();
}


void CMy4장단위변환프로그램Dlg::OnSelchangeListPresentUnit()
{	
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	int index1, index2;
	index1 = m_listPresentUnit.GetCurSel();
	index2 = m_listChangeUnit.GetCurSel();
	CString strPresentUnit, strChangeUnit;
	m_strUnit.Empty();

	if (m_nUnitSelect == 1)
	{
		switch (index1) {
		case 0:
			m_strPresentUnit = _T("m");
			break;
		case 1:
			m_strPresentUnit = _T("in");
			break;
		case 2:
			m_strPresentUnit = _T("yd");
			break;
		}

	}
	else if(m_nUnitSelect == 2)
	{
		switch (index1) {
		case 0:
			m_strPresentUnit = _T("g");
			break;
		case 1:
			m_strPresentUnit = _T("oz");
			break;
		case 2:
			m_strPresentUnit = _T("Ib");
			break;
		}

	}
	else if (m_nUnitSelect == 3)
	{
		switch (index1)
		{
		case  0:
			m_strPresentUnit = _T("I");
			break;
		case 1:
			m_strPresentUnit = _T("gal");
			break;
		case 2:
			m_strPresentUnit = _T("oz");
			break;
		default:
			break;
		}
	
		}
	m_listPresentUnit.GetText(index1, strPresentUnit);
	m_listChangeUnit.GetText(index2, strChangeUnit);
	m_strUnit = strPresentUnit + _T("-->") + strChangeUnit;

	UpdateData(FALSE);
	ComputeUnitValue();
}


void CMy4장단위변환프로그램Dlg::OnSelchangeListChangeUnit()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	int index1, index2;
	index1 = m_listPresentUnit.GetCurSel();
	index2 = m_listChangeUnit.GetCurSel();
	CString strPresentUnit, strChangeUnit;
	m_strUnit.Empty();

	if (m_nUnitSelect == 1)
	{
		switch (index2) {
		case 0:
			m_strChangeUnit = _T("m");
			break;
		case 1:
			m_strChangeUnit = _T("in");
			break;
		case 2:
			m_strChangeUnit = _T("yd");
			break;
		}

	}
	else if (m_nUnitSelect == 2)
	{
		switch (index2) {
		case 0:
			m_strChangeUnit = _T("g");
			break;
		case 1:
			m_strChangeUnit = _T("oz");
			break;
		case 2:
			m_strChangeUnit = _T("Ib");
			break;
		}

	}
	else if (m_nUnitSelect == 3)
	{
		switch (index2) {
		case 0:
			m_strChangeUnit = _T("I");
			break;
		case 1:
			m_strChangeUnit = _T("gal");
			break;
		case 2:
			m_strChangeUnit = _T("oz");
			break;
		}
	}
	m_listPresentUnit.GetText(index1, strPresentUnit);
	m_listChangeUnit.GetText(index2, strChangeUnit);
	m_strUnit =  strPresentUnit + _T("-->") + strChangeUnit;

	UpdateData(FALSE);
	ComputeUnitValue();
}


void CMy4장단위변환프로그램Dlg::OnClickedButtonUnitView()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	if (!m_bUnitViewed)
	{
		m_dlgUnitTable.Create(IDD_DIALOG_UNIT_TABLE, this);

		CRect rectMain, rectUnitTable;
		GetWindowRect(&rectMain);

		m_dlgUnitTable.GetWindowRect(&rectUnitTable);
		m_dlgUnitTable.MoveWindow(rectMain.right, rectMain.top, rectUnitTable.Width(), rectUnitTable.Height());

		m_dlgUnitTable.ShowWindow(SW_SHOW);
		m_bUnitViewed = TRUE;

	}
	else {
		m_dlgUnitTable.ShowWindow(SW_HIDE);
		m_dlgUnitTable.DestroyWindow();
		m_bUnitViewed = FALSE;
	}
}








void CMy4장단위변환프로그램Dlg::OnRadioVolum1()
{
	m_nUnitSelect = 3;
	m_listPresentUnit.ResetContent();
	m_listChangeUnit.ResetContent();
	m_strUnit.Empty();
	m_dPresentValue = m_dChangeValue = 0;

	m_listPresentUnit.AddString(_T("리터(I)"));
	m_listPresentUnit.AddString(_T("갤런(gal)"));
	m_listPresentUnit.AddString(_T("온즈oz)"));

	m_listChangeUnit.AddString(_T("리터(I)"));
	m_listChangeUnit.AddString(_T("갤런(gal)"));
	m_listChangeUnit.AddString(_T("온즈(oz)"));
	m_listPresentUnit.SetCurSel(0);
	m_listChangeUnit.SetCurSel(0);
	m_strUnit = _T("그램(m)--> 그램(m)");
	m_strPresentUnit = _T("g");
	m_dstrChangeUnit = _T("g");
	UpdateData(FALSE);

	// TODO: 여기에 명령 처리기 코드를 추가합니다.
}
