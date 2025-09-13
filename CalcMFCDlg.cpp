
// CalcMFCDlg.cpp : implementation file
//

#include "pch.h"
#include "framework.h"
#include "CalcMFC.h"
#include "CalcMFCDlg.h"
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


// CCalcMFCDlg dialog



CCalcMFCDlg::CCalcMFCDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_CALCMFC_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CCalcMFCDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT1, m_EditInput);
}

BEGIN_MESSAGE_MAP(CCalcMFCDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON20, &CCalcMFCDlg::OnBnClickedButton20)
	ON_BN_DOUBLECLICKED(IDC_BUTTON20, &CCalcMFCDlg::OnBnDoubleclickedButton20)
	ON_BN_CLICKED(IDC_BUTTON2, &CCalcMFCDlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON4, &CCalcMFCDlg::OnBnClickedButton4)
	ON_BN_CLICKED(IDC_BUTTON5, &CCalcMFCDlg::OnBnClickedButton5)
	ON_BN_CLICKED(IDC_BUTTON6, &CCalcMFCDlg::OnBnClickedButton6)
	ON_BN_CLICKED(IDC_BUTTON7, &CCalcMFCDlg::OnBnClickedButton7)
	ON_BN_CLICKED(IDC_BUTTON8, &CCalcMFCDlg::OnBnClickedButton8)
	ON_BN_CLICKED(IDC_BUTTON9, &CCalcMFCDlg::OnBnClickedButton9)
	ON_BN_CLICKED(IDC_BUTTON10, &CCalcMFCDlg::OnBnClickedButton10)
	ON_BN_CLICKED(IDC_BUTTON11, &CCalcMFCDlg::OnBnClickedButton11)
	ON_BN_CLICKED(IDC_BUTTON12, &CCalcMFCDlg::OnBnClickedButton12)
	ON_BN_CLICKED(IDC_BUTTON13, &CCalcMFCDlg::OnBnClickedButton13)
	ON_BN_CLICKED(IDC_BUTTON15, &CCalcMFCDlg::OnBnClickedButton15)
	ON_BN_CLICKED(IDC_BUTTON14, &CCalcMFCDlg::OnBnClickedButton14)
	ON_BN_CLICKED(IDC_BUTTON16, &CCalcMFCDlg::OnBnClickedButton16)
	ON_BN_CLICKED(IDC_BUTTON17, &CCalcMFCDlg::OnBnClickedButton17)
	ON_BN_CLICKED(IDC_BUTTON18, &CCalcMFCDlg::OnBnClickedButton18)
	ON_BN_CLICKED(IDC_BUTTON1, &CCalcMFCDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON3, &CCalcMFCDlg::OnBnClickedButton3)
END_MESSAGE_MAP()


// CCalcMFCDlg message handlers

BOOL CCalcMFCDlg::OnInitDialog()
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
	m_EditInput.SetWindowTextA("");
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CCalcMFCDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CCalcMFCDlg::OnPaint()
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
HCURSOR CCalcMFCDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}
int c_click = 0;
unsigned lastTm = 0;
void CCalcMFCDlg::OnBnClickedButton20()
{
	// TODO: Add your control notification handler code here
	unsigned currTm = GetTickCount();
	if (currTm - lastTm <= 500)
		c_click++;
	else
		c_click = 0;

	lastTm = currTm;

	if (c_click >= 2)
	{
		OnBnDoubleclickedButton20();
		c_click = 0;
	}

	CString currInput;
	m_EditInput.GetWindowTextA(currInput);
	currInput.TrimRight();
	ULONGLONG len = currInput.GetLength();
	
	currInput.Delete(len - 1);
	m_EditInput.SetWindowTextA(currInput);

}

void CCalcMFCDlg::OnBnDoubleclickedButton20()
{
	// TODO: Add your control notification handler code here
	m_EditInput.SetWindowTextA("");
}
void CCalcMFCDlg::OnBnClickedButton2()
{
	// TODO: Add your control notification handler code here
	AddNumber(0);
}

void CCalcMFCDlg::OnBnClickedButton4()
{
	// TODO: Add your control notification handler code here
	AddNumber(1);
}

void CCalcMFCDlg::OnBnClickedButton5()
{
	// TODO: Add your control notification handler code here
	AddNumber(2);
}

void CCalcMFCDlg::OnBnClickedButton6()
{
	// TODO: Add your control notification handler code here
	AddNumber(3);
}

void CCalcMFCDlg::OnBnClickedButton7()
{
	// TODO: Add your control notification handler code here
	AddNumber(4);
}

void CCalcMFCDlg::OnBnClickedButton8()
{
	// TODO: Add your control notification handler code here
	AddNumber(5);
}

void CCalcMFCDlg::OnBnClickedButton9()
{
	// TODO: Add your control notification handler code here
	AddNumber(6);
}

void CCalcMFCDlg::OnBnClickedButton10()
{
	// TODO: Add your control notification handler code here
	AddNumber(7);
}

void CCalcMFCDlg::OnBnClickedButton11()
{
	// TODO: Add your control notification handler code here
	AddNumber(8);
}

void CCalcMFCDlg::OnBnClickedButton12()
{
	// TODO: Add your control notification handler code here
	AddNumber(9);
}

void CCalcMFCDlg::OnBnClickedButton13()
{
	// TODO: Add your control notification handler code here
	AddOperation('+');
}

void CCalcMFCDlg::OnBnClickedButton15()
{
	// TODO: Add your control notification handler code here
	AddOperation('-');
}

void CCalcMFCDlg::OnBnClickedButton14()
{
	// TODO: Add your control notification handler code here
	AddOperation('x');
}

void CCalcMFCDlg::OnBnClickedButton16()
{
	// TODO: Add your control notification handler code here
	AddOperation(':');
}

void CCalcMFCDlg::OnBnClickedButton17()
{
	// TODO: Add your control notification handler code here
	AddPercent();
}
void CCalcMFCDlg::OnBnClickedButton18()
{
	// TODO: Add your control notification handler code here
	AddSR();
}
void CCalcMFCDlg::OnBnClickedButton1()
{
	// TODO: Add your control notification handler code here
	AddDot();
}
void CCalcMFCDlg::AddSR()
{
	CString s;
	m_EditInput.GetWindowTextA(s);
	if (!s.IsEmpty())
	{
		char last = s.GetAt(s.GetLength() - 1);
		switch (last)
		{
		case '+':
		case'%':
		case'-':
		case':':
		case'x':
			return;
		}
		if (last >= '0' && last <= '9') s += '^';
	}
	else
		s += '^';
	m_EditInput.SetWindowTextA(s);
}
void CCalcMFCDlg::AddNumber(char num)
{
	if (num >= 0 && num <= 9)
	{
		num += '0';
		CString s;
		m_EditInput.GetWindowTextA(s);
		if (s.IsEmpty())
		{
			s += num;
		}
		else
		{
			char last = s.GetAt(s.GetLength() - 1);
			switch (last)
			{
			case '+':
			case '-':
			case 'x':
			case ':':
				s += ' ';
				break;
			case '%':
				return;
			}

			if (num == '0')
			{
				if (s.FindOneOf("-+:x") >= 0)
				{
					if (last == '+' || last == '-' || last == ':' || last == 'x')s += num;
					else
					{
						int i = s.GetLength() - 1;
						while (s[i] >= '0' && s[i] <= '9') i--;
						i++;
						if (s[i] != '0')  // if first digit of last number isn't 0
							s += num;
					}
				}
				else
				{
					if ((last == num && s.FindOneOf("123456789") >= 0) || s.IsEmpty() || last != num) s += num;
				}
			}
			else
				s += num;
		}

		m_EditInput.SetWindowTextA(s);
	}
}
void CCalcMFCDlg::AddOperation(char op)
{
	if (op == '+' || op == ':' || op == 'x' || op == '-')
	{
		CString s;
		m_EditInput.GetWindowTextA(s);

		//if (s.IsEmpty() && op == '-') // for neg numbers
		//{
		//	s += op;
		//}
		//else
		if (s.IsEmpty()) return;

		s.TrimRight();
		char last = s.GetAt(s.GetLength() - 1);
		if ((last >= '0' && last <= '9') || last == '%')
		{
			s += ' ';
			s += op;
		}
		m_EditInput.SetWindowTextA(s);


	}
}
static void AddAfterDig(CString& s,char c)
{
	if (!s.IsEmpty())
	{
		char last = s.GetAt(s.GetLength() - 1);
		if (last >= '0' && last <= '9')
		{
			s += c;
		}
	}
}
void CCalcMFCDlg::AddPercent()
{
	CString s;
	m_EditInput.GetWindowTextA(s);
	AddAfterDig(s, '%');
	m_EditInput.SetWindowTextA(s);
}
void CCalcMFCDlg::AddDot()
{
	CString s;
	m_EditInput.GetWindowTextA(s);
	if (s.FindOneOf("+-:x") >= 0) // if multiple numbers
	{
		int c_dot = 0;
		int i = s.GetLength() - 1;
		while (s[i] != ' ' && s[i] != '+' && s[i] != '-' && s[i] != ':' && s[i] != 'x')
		{
			if (s[i] == '.') c_dot++;
			i--;
		}
		if(c_dot == 0) //if no decimal dots
			AddAfterDig(s, '.');
	}
	else
		if(s.Find('.',0) < 0) // if only one num and no dots
		AddAfterDig(s, '.');

	m_EditInput.SetWindowTextA(s);
}

enum Type{value, operation};
struct Entry 
{
	Type type;
	CString value;
};
CArray<Entry> entries;

void CCalcMFCDlg::OnBnClickedButton3()
{
	// TODO: Add your control notification handler code here
	CString expr;
	m_EditInput.GetWindowTextA(expr);

	expr.Trim();

	int len = expr.GetLength();
	switch (expr[len - 1])
	{
	case '+':
	case '-':
	case'x':
	case ':':
		AfxMessageBox("Cannot finish without number");
		return;
	}
	int pos = 0;
	for (;;)
	{
		int i = expr.Find(':', pos);
		if (i >= 0)
		{
			while (i < len && (expr[i] < '0' || expr[i] > '9'))i++;
			if (expr[i] == '0')
			{
				AfxMessageBox("Cannot divide by 0");
				return;
			}
			pos = i;
		}
		else
			break;
	}
	pos = 0;	
	entries.RemoveAll();

	while(pos < len)
	{
		CString val = expr.Tokenize(" ", pos);
		Entry et;
		et.value = val;

		et.type = value;
		if (val.FindOneOf("+-:x") >= 0) et.type = operation;
		entries.Add(et);
		
		if (et.type == value)
		{
			Entry et2;
			et2.type = operation;
			int lenVal = val.GetLength();
			if (val[lenVal - 1] == '%' || val[lenVal - 1] == '^')
			{
				et2.value += val[lenVal - 1];
				entries.Add(et2);
			}
		}
	}
	
	for (int i = 0; i < entries.GetCount(); i++)
	{
		CString v = entries[i].value;
		if (entries[i].type == operation && (v == "^" || v == "%"))
		{
			double val =atof(entries[i - 1].value);
			if (v == "^")
			{
				val = sqrt(val);
			}
			else
				val /= 100;
			Entry et;
			
			CString valStr;
			valStr.Format("%f", val);
			et.value = valStr;
			et.type = value;

			entries.RemoveAt(i - 1, 2);
			entries.InsertAt(i - 1, et);
			i--;
		}
	}
	for (int i = 0;i < entries.GetCount();i++)
	{
		if (entries[i].type == operation && (entries[i].value == "x" || entries[i].value == ":"))
		{
			double val1 = atof(entries[i - 1].value), val2 = atof(entries[i + 1].value);
			Entry et;
			et.value.Format("%f", entries[i].value == "x" ? val1 * val2 : val1 / val2);
			et.type = value;

			entries.RemoveAt(i - 1, 3);
			entries.InsertAt(i - 1, et);
			i--;
		}
	}

	double res = 0;
	if (entries.GetCount() > 0)
		res = atof(entries[0].value);
	
	for (int i = 1; i < entries.GetCount(); i += 2)
	{
		if (entries[i].type == operation)
		{
			double val = atof(entries[i + 1].value);
			if (entries[i].value == "+")
				res += val;
			else if (entries[i].value == "-")
				res -= val;
		}
	}
	expr.Format("%g", res);
	m_EditInput.SetWindowTextA(expr);
}
