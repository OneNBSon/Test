
// Calc2Dlg.cpp: 구현 파일
//

#include "pch.h"
#include "framework.h"
#include "Calc2.h"
#include "Calc2Dlg.h"
#include "afxdialogex.h"
#include<iostream>
#include<string>
#include "stdio.h"

using namespace std;

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


// CCalc2Dlg 대화 상자



CCalc2Dlg::CCalc2Dlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_CALC2_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CCalc2Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CCalc2Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(Btn_PLUS, &CCalc2Dlg::OnBnClickedButton11)
	ON_BN_CLICKED(Btn_MINUS, &CCalc2Dlg::OnBnClickedButton12)
	ON_BN_CLICKED(Btn_Result, &CCalc2Dlg::OnBnClickedResult)
	ON_BN_CLICKED(Btn_Clear, &CCalc2Dlg::OnBnClickedClear)
	ON_BN_CLICKED(Btn_BackSpace, &CCalc2Dlg::OnBnClickedBackspace)
	ON_BN_CLICKED(Btn_Sign, &CCalc2Dlg::OnBnClickedSign)
	ON_BN_CLICKED(Btn_MULTYPL, &CCalc2Dlg::OnBnClickedMultypl)
	ON_BN_CLICKED(Btn_DIVID, &CCalc2Dlg::OnBnClickedDivid)
	ON_BN_CLICKED(Btn_POINT, &CCalc2Dlg::OnBnClickedPoint)
END_MESSAGE_MAP()


// CCalc2Dlg 메시지 처리기

BOOL CCalc2Dlg::OnInitDialog()
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

void CCalc2Dlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CCalc2Dlg::OnPaint()
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
HCURSOR CCalc2Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



BOOL CCalc2Dlg::OnCommand(WPARAM wParam, LPARAM lParam)
{
	CString str, Integer, realnumber;
	CString str_number;
	CString str2;
	CString intBuffer, doublebuffer, LengthCheck;
	CString str3;
	double DisplayVlue;
	int Lenght_Limit = 16;

	if (Btn_Number0 <= wParam && wParam <= Btn_Number9)//(Btn_Number0 <= wParam && wParam <= Btn_POINT)
	{
		if (Overflow == TRUE)
		{
			Overflow = FALSE;
			SetDlgItemText(Print_Result, L"");
		}
		str_number.Format(L"%d", wParam - Btn_Number0);

		/*if (wParam == Btn_POINT && PointUse == FALSE)
		{
			str_number.Format(L".");
			PointUse = TRUE;
		}
		else if (wParam == Btn_POINT && PointUse == TRUE)
		{
			return CDialogEx::OnCommand(wParam, lParam);
		}
		else
		{
			str_number.Format(L"%d", wParam - Btn_Number0);
		}*/

		if (m_step == 0)
		{
			GetDlgItemText(Print_Result, str2);
			str2.Remove(',');
		}
		else if (m_step == 1)
		{
			GetDlgItemText(Print_Result, str);
			m_step = 0;
			str.Remove(',');
			m_value = _wtof(str);
		}

		if (str2.Find('.') != -1)
		{
			//AfxExtractSubString(Integer, str, 0, '.');
			//AfxExtractSubString(realnumber, str, 1, '.');
			//str = Integer;
			//str2 =intBuffer + doublebuffer;
			Lenght_Limit = 17;
		}

		if (str2.GetLength() < Lenght_Limit)
		{
			//SetDlgItemText(Print_Result, str2);
			//SetDlgItemText(Print_Result, str2 + str_number
			//Buffer = str2;
			//Buffer.Remove('.');
			str3 = Comma(str2 + str_number);
			SetDlgItemText(Print_Result, str3);
		}

		/*DisplayVlue = _wtof(str2 + str_number);
		OverFlow = ChckforOverFlow(DisplayVlue);

		if (OverFlow == TRUE)
		{
			SetDlgItemText(Print_Result, str2 + str_number);
		}
		else
		{
			Overflow = TRUE;
			SetDlgItemText(Print_Result, exception);
		}*/
	}

	// TODO: 여기에 특수화된 코드를 추가 및/또는 기본 클래스를 호출합니다.

	return CDialogEx::OnCommand(wParam, lParam);
}


void CCalc2Dlg::OnBnClickedButton11() //PLUS
{
	Fourbasicoperations(PLUS);
	LastOperate = LAST_PLUS;

}


void CCalc2Dlg::OnBnClickedButton12() //MINUS
{
	Fourbasicoperations(MINUS);
	LastOperate = LAST_MINUS;
	
}


void CCalc2Dlg::OnBnClickedResult()
{
	CString str,str2;
	CString historystr, BeforHistorystr;
	CString Result;
	BOOL OverFlow;
	int Lenght_Limit = 16;
	int count;
	double Print_Value;

	GetDlgItemText(Print_Result, str);
	str.Remove(',');
	Print_Value = _wtof(str);

	//CEdit* pEdit2 = (CEdit*)GetDlgItem(Print_Result);
	//pEdit2->SetWindowTextW(L" ");

	if (m_count >= 1)//LastOperate == LAST_NONE || 
	{
		CalcOperate(Print_Value);
	}

	m_count = 0;

	if (LastOperate != LAST_Equal)
	{
		GetDlgItemText(Print_History, BeforHistorystr);
		
		count = PointCountCheck(BeforHistorystr, str);

		historystr.Format(L"%*f", count, Print_Value);
		historystr.TrimRight(L"0");
		historystr.TrimRight(L".");

		SetDlgItemText(Print_History, BeforHistorystr + historystr + '=');

		//OverFlow = ChckforOverFlow(m_value);

		str.Format(L"%*f", count, m_value);
		str.TrimRight(L"0");
		str.TrimRight(L".");
		if (str.Find('.') != -1)
		{
			Lenght_Limit = 17;
		}

		if (str.GetLength() < Lenght_Limit)
		{
			Result = Comma(str);
			SetDlgItemText(Print_Result, Result);
		}
		else
		{
			SetDlgItemText(Print_Result, exception);
		}

		/*if (OverFlow == TRUE)
		{
			str.Format(L"%f", m_value);
			str.TrimRight(L"0");
			str.TrimRight(L".");
			SetDlgItemText(Print_Result, str);
		}
		else
		{
			Overflow = TRUE;
			SetDlgItemText(Print_Result, exception);
		}*/

	}

	LastOperate = LAST_Equal;

	//SetDlgItemInt(Print_Edit, m_value);

	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


void CCalc2Dlg::OnBnClickedClear()
{
	UpdateData(TRUE);

	Clear();
	
	UpdateData(FALSE);
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


void CCalc2Dlg::OnBnClickedBackspace()
{
	CString str;
	GetDlgItemText(Print_Result, str);
	//str.Remove(str.GetLength() - 1, 1);
	str.Delete(str.GetLength() - 1, 1);
	if (str.Find('.') == FALSE)
	{
		PointUse = FALSE;
	}
	str = Comma(str);
	SetDlgItemText(Print_Result, str);
}


void CCalc2Dlg::OnBnClickedSign()
{
	CString str;
	CString res;

	GetDlgItemText(Print_Result, str);
	res = SignCalc(str);
	SetDlgItemText(Print_Result, res);

	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}

void CCalc2Dlg::CalcOperate(double m_value_two)
{
	CString str;
	switch (operater_flag)
	{
	case PLUS:
		m_value += m_value_two;
		break;
	case MINUS:
		m_value = m_value - m_value_two;
		break;
	case MULTYPL:
		m_value *= m_value_two;
		break;
	case DIVID:
		if (m_value_two != 0)
		{
			m_value /= m_value_two;
		}
		else
		{
			m_value = 0;
		}
		break;
		
	default:
		break;
	}
	str.Format(L"%.15f", m_value);
	str.TrimRight(L"0");
	str.TrimRight(L".");

	SetDlgItemText(Print_Result, str);

}

void CCalc2Dlg::Fourbasicoperations(OperaterFlag Flag)
{
	CString str, str2, str_PrintResult, operate;
	int Lenght_Limit = 16;
	int count;
	double Print_Value;
	GetDlgItemText(Print_Result, str_PrintResult);
	str_PrintResult.Remove(',');

	Print_Value = _wtof(str_PrintResult);

	m_count++;

	if (m_count == 1 || m_step == 1)
	{
		m_value = Print_Value;
	}
	else
	{
		CalcOperate(Print_Value);
	}

	operater_flag = Flag;
	m_step = 1;

	GetDlgItemText(Print_Result, str2);
	GetDlgItemText(Print_History, str);

	operate = ConvertOperate(operater_flag);

	//std::string a;
	//char Test1[225];
	//a = to_string(m_value);
    //sprintf_s(Test1, "%.15lf",a, m_value);
	
	str2.Remove(',');
	SetDlgItemText(Print_History, str2 + operate);

	count = PointCountCheck(str, str2);
	/*if (operater_flag == MULTYPL)
	{
		count++;
	}
	if (operater_flag == DIVID)
	{
		count--;
	}*/

	str_PrintResult.Format(L"%.*f", count, m_value);
	
	//str_PrintResult.Format(L"%f",m_value);
	//str_PrintResult.TrimRight(L"0");
    //str_PrintResult.TrimRight(L".");
	str_PrintResult = Comma(str_PrintResult);
	SetDlgItemText(Print_Result, str_PrintResult);
}

CString CCalc2Dlg::SignCalc(CString str)
{
	CString Sign = L"-";

	if (str.Find('-') != -1)
	{
		str.Remove('-');
	}
	else if(str.GetLength() == 0)
	{
		SetDlgItemText(Print_History, L"negate(0)");
	}
	else
	{
		str = Sign + str;
	}

	return str;
}

void CCalc2Dlg::Clear()
{
	CString Clear = L"";

	SetDlgItemText(Print_Result, Clear);
	SetDlgItemText(Print_History, Clear);
	m_value = 0;
	m_step = 0;
	operater_flag = NONE;
	LastOperate = LAST_NONE;
	m_count = 0;

	/*CEdit* pEdit = (CEdit*)GetDlgItem(Print_Result);
	pEdit->SetWindowTextW(L"");
	CEdit* pEdit2 = (CEdit*)GetDlgItem(Print_History);
	pEdit2->SetWindowTextW(L"");*/

}
CString CCalc2Dlg::ConvertOperate(OperaterFlag Operate)
{
	CString str;

	switch (Operate)
	{
	case PLUS:
		str = '+';
		break;
	case MINUS:
		str = '-';
		break;
	case MULTYPL:
		str = '*';
		break;
	case DIVID:
		str = '/';
		break;
	default:
		break;
	}

	return str;
}

BOOL CCalc2Dlg::ChckforOverFlow(double Value)
{
	
	if (INT_MIN < Value && Value <= INT_MAX)
	{
		return TRUE;
	}
	else
	{
		return FALSE;
	}



}
CString CCalc2Dlg::Comma(CString nData)
{
	CString str, strReturn = L"";
	CString Integer, realnumber;
	CString Sign;
	str = nData;
	str.Remove(',');

	if (str.GetLength() > 3)
	{
		CheckCharacter(str, Integer, realnumber, Sign);

		for (int i = 0; i < str.GetLength(); i++)
		{
			if (nData.Find('.') != -1)
			{
				strReturn += Integer.GetAt(i);
			}
			else
			{
				strReturn += str.GetAt(i);
			}
			if ((str.GetLength() - i) > 2 && (str.GetLength() - i) % 3 == 1)
			{
				strReturn += ',';
			}
		}

		if (nData.Find('.') != -1)
		{
			strReturn += ('.' + realnumber);
			return Sign + strReturn;
		}
		else
		{
			return Sign + strReturn;
		}
	}
	return str;
}

void CCalc2Dlg::OnBnClickedMultypl()
{
	Fourbasicoperations(MULTYPL);
	LastOperate = LAST_MULTYPL;
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


void CCalc2Dlg::OnBnClickedDivid()
{
	Fourbasicoperations(DIVID);
	LastOperate = LAST_DIVID;
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


void CCalc2Dlg::OnBnClickedPoint()
{
	CString str;
	GetDlgItemText(Print_Result,str);
	if (str.Find('.') == -1)
	{		
		SetDlgItemText(Print_Result, str + '.');
	}
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}

void CCalc2Dlg::CheckCharacter(CString& str, CString& Integer, CString& realnumber, CString& Sign)
{
	if (str.Find('-') != -1)
	{
		str.Remove('-');
		Sign = L"-";
	}

	if (str.Find('.') != -1)
	{
		AfxExtractSubString(Integer, str, 0, '.');
		AfxExtractSubString(realnumber, str, 1, '.');
		str = Integer;
	}

}

int CCalc2Dlg::PointCountCheck(CString txtHistory, CString txtResult)
{
	CString Text_History, Text_Result, realnumber, str;
	int count = 0;
	int StrLength;
	BOOL Operate = false;
	Text_History = txtHistory;
	Text_Result = txtResult;

	if (Text_History.GetLength() > Text_Result.GetLength())
	{
		str = Text_History;
		Operate = true;
	}
	else
	{
		str = Text_Result;
	}

	if (str.GetLength() >15)
	{

	}
	StrLength = str.GetLength();

	if (Operate == true)
	{
		str.Delete(StrLength-1,1);
	}

	if (str.Find('.') != -1)
	{
		AfxExtractSubString(realnumber, str, 1, '.');
	}
	count = realnumber.GetLength();

	return count;
}
