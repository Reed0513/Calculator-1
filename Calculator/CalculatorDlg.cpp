
// CalculatorDlg.cpp : implementation file
//

#include "stdafx.h"
#include "Calculator.h"
#include "CalculatorDlg.h"
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
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

// Implementation
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CCalculatorDlg dialog


CCalculatorDlg::CCalculatorDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CCalculatorDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CCalculatorDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_TABLE, m_info);
}

BEGIN_MESSAGE_MAP(CCalculatorDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_CE, &CCalculatorDlg::OnBnClickedCe)
	ON_BN_CLICKED(IDC_CLEAR, &CCalculatorDlg::OnBnClickedClear)
	ON_BN_CLICKED(IDC_NUM7, &CCalculatorDlg::OnBnClickedNum7)
	ON_BN_CLICKED(IDC_NUM8, &CCalculatorDlg::OnBnClickedNum8)
	ON_BN_CLICKED(IDC_NUM9, &CCalculatorDlg::OnBnClickedNum9)
	ON_BN_CLICKED(IDC_NUM4, &CCalculatorDlg::OnBnClickedNum4)
	ON_BN_CLICKED(IDC_NUM5, &CCalculatorDlg::OnBnClickedNum5)
	ON_BN_CLICKED(IDC_NUM6, &CCalculatorDlg::OnBnClickedNum6)
	ON_BN_CLICKED(IDC_NUM1, &CCalculatorDlg::OnBnClickedNum1)
	ON_BN_CLICKED(IDC_NUM2, &CCalculatorDlg::OnBnClickedNum2)
	ON_BN_CLICKED(IDC_NUM3, &CCalculatorDlg::OnBnClickedNum3)
	ON_BN_CLICKED(IDC_POINT, &CCalculatorDlg::OnBnClickedPoint)
	ON_BN_CLICKED(IDC_ADD, &CCalculatorDlg::OnBnClickedAdd)
	ON_BN_CLICKED(IDC_SUB, &CCalculatorDlg::OnBnClickedSub)
	ON_BN_CLICKED(IDC_DIV, &CCalculatorDlg::OnBnClickedDiv)
	ON_BN_CLICKED(IDC_MUL, &CCalculatorDlg::OnBnClickedMul)
	ON_BN_CLICKED(IDC_RESULT, &CCalculatorDlg::OnBnClickedResult)
	ON_BN_CLICKED(IDC_NUM0, &CCalculatorDlg::OnBnClickedNum0)
	ON_BN_CLICKED(IDC_DAO, &CCalculatorDlg::OnBnClickedDao)
	ON_BN_CLICKED(IDC_SQRT, &CCalculatorDlg::OnBnClickedSqrt)
	ON_BN_CLICKED(IDC_ADDORSUB, &CCalculatorDlg::OnBnClickedAddorsub)
	ON_BN_CLICKED(IDC_BAI, &CCalculatorDlg::OnBnClickedBai)
	ON_BN_CLICKED(IDC_DELETE, &CCalculatorDlg::OnBnClickedDelete)
END_MESSAGE_MAP()


// CCalculatorDlg message handlers

BOOL CCalculatorDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
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

	ShowWindow(SW_MINIMIZE);

	// TODO: Add extra initialization here
	CFont font;
	font.CreatePointFont(150,_T("Consolas"));
	m_info.SetWindowTextW(_T("0"));
	m_info.SetFont(&font);
	opflag=pointflag=0;
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CCalculatorDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CCalculatorDlg::OnPaint()
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
HCURSOR CCalculatorDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


void CCalculatorDlg::Handle(int num)
{
	CString temp;
	temp.Format(_T("%d"),num);
	if(opflag==0)
	{
		num1+=temp;
		m_info.SetWindowTextW(num1);
	}
	else
	{
		num2+=temp;
		m_info.SetWindowTextW(num2);
	}
}


void  CCalculatorDlg::Operator(int num)
{
	opflag=num;
	pointflag=0;
	m_info.SetWindowTextW(_T("0"));
}


void CCalculatorDlg::OnBnClickedCe()
{
	// TODO: Add your control notification handler code here
	if(opflag==0)num1="";
	else num2="";
	m_info.SetWindowTextW(_T("0"));
}


void CCalculatorDlg::OnBnClickedClear()
{
	// TODO: Add your control notification handler code here
	num1=num2="";
	m_info.SetWindowTextW(_T("0"));
}


void CCalculatorDlg::OnBnClickedNum7()
{
	// TODO: Add your control notification handler code here
	Handle(7);
}


void CCalculatorDlg::OnBnClickedNum8()
{
	// TODO: Add your control notification handler code here
	Handle(8);
}


void CCalculatorDlg::OnBnClickedNum9()
{
	// TODO: Add your control notification handler code here
	Handle(9);
}


void CCalculatorDlg::OnBnClickedNum4()
{
	// TODO: Add your control notification handler code here
	Handle(4);
}


void CCalculatorDlg::OnBnClickedNum5()
{
	// TODO: Add your control notification handler code here
	Handle(5);
}


void CCalculatorDlg::OnBnClickedNum6()
{
	// TODO: Add your control notification handler code here
	Handle(6);
}


void CCalculatorDlg::OnBnClickedNum1()
{
	// TODO: Add your control notification handler code here
	Handle(1);
}


void CCalculatorDlg::OnBnClickedNum2()
{
	// TODO: Add your control notification handler code here
	Handle(2);
}


void CCalculatorDlg::OnBnClickedNum3()
{
	// TODO: Add your control notification handler code here
	Handle(3);
}


void CCalculatorDlg::OnBnClickedNum0()
{
	// TODO: Add your control notification handler code here
	int temp;
	if(opflag==0)
	{
		if(pointflag==0&&num1!="")
		{
			temp=_ttoi(num1);
			if(temp!=0)num1+="0";
		}
		else num1+="0";
		m_info.SetWindowTextW(num1);
	}
	else
	{
		if(pointflag==0&&num2!="")
		{
			temp=_ttoi(num2);
			if(temp!=0)num2+="0";
		}
		else num2+="0";
		m_info.SetWindowTextW(num2);
	}
}


void CCalculatorDlg::OnBnClickedPoint()
{
	// TODO: Add your control notification handler code here
	if(pointflag==0)
	{
		if(opflag==0)
		{
			num1+=".";
			m_info.SetWindowTextW(num1);
		}
		else
		{
			num2+=".";
			m_info.SetWindowTextW(num2);
		}
	}
	pointflag=1;
}


void CCalculatorDlg::OnBnClickedAdd()
{
	// TODO: Add your control notification handler code here
	Operator(1);
}


void CCalculatorDlg::OnBnClickedSub()
{
	// TODO: Add your control notification handler code here
	Operator(2);
}


void CCalculatorDlg::OnBnClickedMul()
{
	// TODO: Add your control notification handler code here
	Operator(3);
}


void CCalculatorDlg::OnBnClickedDiv()
{
	// TODO: Add your control notification handler code here
	Operator(4);
}


void CCalculatorDlg::OnBnClickedResult()
{
	// TODO: Add your control notification handler code here
	double a=_wtof(num1),b=_wtof(num2);
	int ok=1;
	if(num1=="")
	{
		a=_wtof(tempnum);
		if(num2=="")
		{
			b=_wtof(tempnum1);
			opflag=topflag;
		}
	}
	switch(opflag)
	{
		case 1:a+=b;break;
		case 2:a-=b;break;
		case 3:a*=b;break;
		case 4:
			if(fabs(b-0.0)>1e-6)a/=b;
			else ok=0;
			break;
	}
	if(ok==0)m_info.SetWindowTextW(_T("除数不能为0，按C继续"));
	else
	{
		if(fabs(a-(int)a)<1e-6)num1.Format(_T("%d"),(int)a);
		else num1.Format(_T("%lf"),a);
		m_info.SetWindowTextW(num1);
		if(num1!="")tempnum=num1;
		if(num2!="")tempnum1=num2;
		topflag=opflag;
		opflag=pointflag=0;
	}
	num1=num2="";
}


void CCalculatorDlg::OnBnClickedDao()
{
	// TODO: Add your control notification handler code here
	double temp;
	if(opflag==0)
	{
		temp=_wtof(num1);
		if(fabs(temp-0.0)>1e-6)
		{
			temp=1.0/temp;
			if(fabs(temp-(int)temp)<1e-6)num1.Format(_T("%d"),(int)temp);
			else num1.Format(_T("%lf"),temp);
			m_info.SetWindowTextW(num1);
		}
		else
		{
			m_info.SetWindowTextW(_T("0没有倒数，按CE重新输入"));
			num1="";
		}
	}
	else
	{
		temp=_wtof(num2);
		if(fabs(temp-0.0)>1e-6)
		{
			temp=1.0/temp;
			if(fabs(temp-(int)temp)<1e-6)num2.Format(_T("%d"),(int)temp);
			else num2.Format(_T("%lf"),temp);
			m_info.SetWindowTextW(num2);
		}
		else
		{
			m_info.SetWindowTextW(_T("0没有倒数，按CE重新输入"));
			num2="";
		}
	}
}


void CCalculatorDlg::OnBnClickedSqrt()
{
	// TODO: Add your control notification handler code here
	double temp;
	if(opflag==0)
	{
		if(num1=="")temp=_wtof(tempnum);
		else temp=_wtof(num1);
		if(temp>=0.0)
		{
			temp=sqrt(temp);
			if(fabs(temp-(int)temp)<1e-6)num1.Format(_T("%d"),(int)temp);
			else num1.Format(_T("%lf"),temp);
			if(fabs(temp-0.0)<1e-6)
			{
				num1="";
				m_info.SetWindowTextW(_T("0"));
			}
			else m_info.SetWindowTextW(num1);
		}
		else
		{
			m_info.SetWindowTextW(_T("不可负数平方根，按CE重输"));
			num1="";
		}
	}
	else
	{
		temp=_wtof(num2);
		if(temp>=0.0)
		{
			temp=sqrt(temp);
			if(fabs(temp-(int)temp)<1e-6)num2.Format(_T("%d"),(int)temp);
			else num2.Format(_T("%lf"),temp);
			if(fabs(temp-0.0)<1e-6)
			{
				num2="";
				m_info.SetWindowTextW(_T("0"));
			}
			else m_info.SetWindowTextW(num2);
		}
		else
		{
			m_info.SetWindowTextW(_T("不可负数平方根，按CE重输"));
			num2="";
		}
	}
}


void CCalculatorDlg::OnBnClickedAddorsub()
{
	// TODO: Add your control notification handler code here
	double temp;
	if(opflag==0)
	{
		temp=_wtof(num1);
		if(fabs(temp-(int)temp)<1e-6)num1.Format(_T("%d"),(int)-temp);
		else num1.Format(_T("%lf"),-temp);
		if(fabs(temp-0.0)<1e-6)
		{
			num1="";
			m_info.SetWindowTextW(_T("0"));
		}
		else m_info.SetWindowTextW(num1);
	}
	else
	{
		temp=_wtof(num2);
		if(fabs(temp-(int)temp)<1e-6)num2.Format(_T("%d"),(int)-temp);
		else num2.Format(_T("%lf"),-temp);
		if(fabs(temp-0.0)<1e-6)
		{
			num2="";
			m_info.SetWindowTextW(_T("0"));
		}
		else m_info.SetWindowTextW(num2);
	}
}


void CCalculatorDlg::OnBnClickedBai()
{
	// TODO: Add your control notification handler code here
	double temp;
	if(opflag==0)
	{
		temp=_wtof(num1);
		temp/=100.0;
		if(fabs(temp-(int)temp)<1e-6)num1.Format(_T("%d"),(int)temp);
		else num1.Format(_T("%lf"),temp);
		if(fabs(temp-(int)temp)<1e-6)
		{
			num1="";
			m_info.SetWindowTextW(_T("0"));
		}
		else m_info.SetWindowTextW(num1);
	}
	else
	{
		temp=_wtof(num2);
		temp/=100.0;
		if(fabs(temp-(int)temp)<1e-6)num2.Format(_T("%d"),(int)temp);
		else num2.Format(_T("%lf"),temp);
		if(fabs(temp-(int)temp)<1e-6)
		{
			num2="";
			m_info.SetWindowTextW(_T("0"));
		}
		else m_info.SetWindowTextW(num2);
	}
}


void CCalculatorDlg::OnBnClickedDelete()
{
	// TODO: Add your control notification handler code here
	if(opflag==0)
	{
		num1.Delete(num1.GetLength()-1,1);
		if(num1=="")m_info.SetWindowTextW(_T("0"));
		else m_info.SetWindowTextW(num1);
	}
	else
	{
		num2.Delete(num2.GetLength()-1,1);
		if(num2=="")m_info.SetWindowTextW(_T("0"));
		else m_info.SetWindowTextW(num2);
	}
}


BOOL CCalculatorDlg::PreTranslateMessage(MSG* pMsg)
{
	// TODO: Add your specialized code here and/or call the base class
	if(pMsg->message==WM_KEYDOWN)
	{
		switch(pMsg->wParam)
		{
			case 0x30:
			case VK_NUMPAD0:OnBnClickedNum0();break;
			case 0x31:
			case VK_NUMPAD1:OnBnClickedNum1();break;
			case 0x32:
			case VK_NUMPAD2:OnBnClickedNum2();break;
			case 0x33:
			case VK_NUMPAD3:OnBnClickedNum3();break;
			case 0x34:
			case VK_NUMPAD4:OnBnClickedNum4();break;
			case 0x35:
			case VK_NUMPAD5:OnBnClickedNum5();break;
			case 0x36:
			case VK_NUMPAD6:OnBnClickedNum6();break;
			case 0x37:
			case VK_NUMPAD7:OnBnClickedNum7();break;
			case 0x38:
				if(GetAsyncKeyState(VK_SHIFT))
				{
					OnBnClickedMul();
					break;
				}
			case VK_NUMPAD8:OnBnClickedNum8();break;
			case 0x39:
			case VK_NUMPAD9:OnBnClickedNum9();break;
			case VK_ADD:OnBnClickedAdd();break;
			case VK_SUBTRACT:OnBnClickedSub();break;
			case VK_MULTIPLY:OnBnClickedMul();break;
			case VK_DIVIDE:OnBnClickedDiv();break;
			case VK_DECIMAL:OnBnClickedPoint();break;
			case VK_BACK:OnBnClickedDelete();break;
			case VK_OEM_PLUS:if(GetAsyncKeyState(VK_SHIFT))OnBnClickedAdd();break;
			case VK_OEM_MINUS:if(GetAsyncKeyState(VK_SHIFT))OnBnClickedSub();break;
			case VK_OEM_2:if(GetAsyncKeyState(VK_SHIFT))OnBnClickedDiv();break;
			case VK_RETURN:OnBnClickedResult();break;
			default:break;
		}
		return true;
	}
	return CDialogEx::PreTranslateMessage(pMsg);
	//return true;
}
