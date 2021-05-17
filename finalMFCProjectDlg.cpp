
// finalMFCProjectDlg.cpp : implementation file
//

#include "pch.h"
#include "framework.h"
#include "finalMFCProject.h"
#include "finalMFCProjectDlg.h"
#include "afxdialogex.h"
#include "Pizza.h"

#include <vector>
#include <string>
#include <sstream>

using namespace std;

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


// CfinalMFCProjectDlg dialog



CfinalMFCProjectDlg::CfinalMFCProjectDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_FINALMFCPROJECT_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CfinalMFCProjectDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CfinalMFCProjectDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, &CfinalMFCProjectDlg::OnBnClickedButton1)
	ON_CBN_SELCHANGE(IDC_COMBO6, &CfinalMFCProjectDlg::OnCbnSelchangeCombo6)
	ON_CBN_SELCHANGE(IDC_COMBO7, &CfinalMFCProjectDlg::OnCbnSelchangeCombo7)
	ON_CBN_SELCHANGE(IDC_COMBO8, &CfinalMFCProjectDlg::OnCbnSelchangeCombo8)
	ON_CBN_SELCHANGE(IDC_COMBO9, &CfinalMFCProjectDlg::OnCbnSelchangeCombo9)
END_MESSAGE_MAP()


// CfinalMFCProjectDlg message handlers

BOOL CfinalMFCProjectDlg::OnInitDialog()
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

	// Sauce combo box dropdown choices
	CComboBox* pCombo1 = reinterpret_cast<CComboBox*>(GetDlgItem(IDC_COMBO1));
	pCombo1->InsertString(0, _T("Marinara"));
	pCombo1->InsertString(1, _T("Parmesan"));
	pCombo1->InsertString(2, _T("Buffalo"));
	// Sauce amount combo box dropdown choices
	CComboBox* pCombo4 = reinterpret_cast<CComboBox*>(GetDlgItem(IDC_COMBO4));
	pCombo4->InsertString(0, _T("Light"));
	pCombo4->InsertString(1, _T("Regular"));
	pCombo4->InsertString(2, _T("Extra"));

	// Cheese combo box choices
	CComboBox* pCombo2 = reinterpret_cast<CComboBox*>(GetDlgItem(IDC_COMBO2));
	pCombo2->InsertString(0, _T("Mozzarella"));
	pCombo2->InsertString(1, _T("Goat Cheese"));
	pCombo2->InsertString(2, _T("Soy Cheese"));
	pCombo2->InsertString(3, _T("Four Cheese"));
	// Cheese amount combo box choices
	CComboBox* pCombo5 = reinterpret_cast<CComboBox*>(GetDlgItem(IDC_COMBO5));
	pCombo5->InsertString(0, _T("Light"));
	pCombo5->InsertString(1, _T("Regular"));
	pCombo5->InsertString(2, _T("Extra"));

	// Size combo box choices
	CComboBox* pCombo14 = reinterpret_cast<CComboBox*>(GetDlgItem(IDC_COMBO14));
	pCombo14->InsertString(0, _T("Small"));
	pCombo14->InsertString(1, _T("Medium"));
	pCombo14->InsertString(2, _T("Large"));

	// Toppings #1 combo box choices
	CComboBox* pCombo6 = reinterpret_cast<CComboBox*>(GetDlgItem(IDC_COMBO6));
	pCombo6->InsertString(0, _T("None"));
	pCombo6->InsertString(1, _T("Pepperoni"));
	pCombo6->InsertString(2, _T("Sausage"));
	pCombo6->InsertString(3, _T("Bacon"));
	pCombo6->InsertString(4, _T("Mushrooms"));
	pCombo6->InsertString(5, _T("Red Onions"));
	pCombo6->InsertString(6, _T("Pineapple"));
	pCombo6->InsertString(7, _T("Olives"));
	pCombo6->InsertString(8, _T("Bell Peppers"));
	// Toppings #1 amount combo box choices
	CComboBox* pCombo10 = reinterpret_cast<CComboBox*>(GetDlgItem(IDC_COMBO10));
	pCombo10->InsertString(0, _T("Light"));
	pCombo10->InsertString(1, _T("Regular"));
	pCombo10->InsertString(2, _T("Extra"));

	// Toppings #2 combo box choices
	CComboBox* pCombo7 = reinterpret_cast<CComboBox*>(GetDlgItem(IDC_COMBO7));
	pCombo7->InsertString(0, _T("None"));
	pCombo7->InsertString(1, _T("Pepperoni"));
	pCombo7->InsertString(2, _T("Sausage"));
	pCombo7->InsertString(3, _T("Bacon"));
	pCombo7->InsertString(4, _T("Mushrooms"));
	pCombo7->InsertString(5, _T("Red Onions"));
	pCombo7->InsertString(6, _T("Pineapple"));
	pCombo7->InsertString(7, _T("Olives"));
	pCombo7->InsertString(8, _T("Bell Peppers"));
	// Toppings #2 amount combo box choices
	CComboBox* pCombo11 = reinterpret_cast<CComboBox*>(GetDlgItem(IDC_COMBO11));
	pCombo11->InsertString(0, _T("Light"));
	pCombo11->InsertString(1, _T("Regular"));
	pCombo11->InsertString(2, _T("Extra"));

	// Toppings #3 combo box choices
	CComboBox* pCombo8 = reinterpret_cast<CComboBox*>(GetDlgItem(IDC_COMBO8));
	pCombo8->InsertString(0, _T("None"));
	pCombo8->InsertString(1, _T("Pepperoni"));
	pCombo8->InsertString(2, _T("Sausage"));
	pCombo8->InsertString(3, _T("Bacon"));
	pCombo8->InsertString(4, _T("Mushrooms"));
	pCombo8->InsertString(5, _T("Red Onions"));
	pCombo8->InsertString(6, _T("Pineapple"));
	pCombo8->InsertString(7, _T("Olives"));
	pCombo8->InsertString(8, _T("Bell Peppers"));
	// Toppings #3 amount combo box choices
	CComboBox* pCombo12 = reinterpret_cast<CComboBox*>(GetDlgItem(IDC_COMBO12));
	pCombo12->InsertString(0, _T("Light"));
	pCombo12->InsertString(1, _T("Regular"));
	pCombo12->InsertString(2, _T("Extra"));

	// Toppings #1 combo box choices
	CComboBox* pCombo9 = reinterpret_cast<CComboBox*>(GetDlgItem(IDC_COMBO9));
	pCombo9->InsertString(0, _T("None"));
	pCombo9->InsertString(1, _T("Pepperoni"));
	pCombo9->InsertString(2, _T("Sausage"));
	pCombo9->InsertString(3, _T("Bacon"));
	pCombo9->InsertString(4, _T("Mushrooms"));
	pCombo9->InsertString(5, _T("Red Onions"));
	pCombo9->InsertString(6, _T("Pineapple"));
	pCombo9->InsertString(7, _T("Olives"));
	pCombo9->InsertString(8, _T("Bell Peppers"));
	// Toppings #1 amount combo box choices
	CComboBox* pCombo13 = reinterpret_cast<CComboBox*>(GetDlgItem(IDC_COMBO13));
	pCombo13->InsertString(0, _T("Light"));
	pCombo13->InsertString(1, _T("Regular"));
	pCombo13->InsertString(2, _T("Extra"));

	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CfinalMFCProjectDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CfinalMFCProjectDlg::OnPaint()
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
HCURSOR CfinalMFCProjectDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CfinalMFCProjectDlg::OnBnClickedOk()
{
	// TODO: Add your control notification handler code here
	CDialogEx::OnOK();
}


void CfinalMFCProjectDlg::OnBnClickedButton1()
{
	// Get sauce text
	CComboBox* pCombo1 = reinterpret_cast<CComboBox*>(GetDlgItem(IDC_COMBO1));
	int n = pCombo1->GetCurSel();
	CString mCombo1;
	pCombo1->GetWindowTextW(mCombo1);
	string sauce = CStringA(mCombo1);
	// Get sauce amount text
	CComboBox* pCombo4 = reinterpret_cast<CComboBox*>(GetDlgItem(IDC_COMBO4));
	n = pCombo4->GetCurSel();
	CString mCombo4;
	pCombo4->GetWindowTextW(mCombo4);
	string sauceAmount = CStringA(mCombo4);

	// Get cheese text
	CComboBox* pCombo2 = reinterpret_cast<CComboBox*>(GetDlgItem(IDC_COMBO2));
	n = pCombo2->GetCurSel();
	CString mCombo2;
	pCombo2->GetWindowTextW(mCombo2);
	string cheese = CStringA(mCombo2);
	// Get cheese amount text
	CComboBox* pCombo5 = reinterpret_cast<CComboBox*>(GetDlgItem(IDC_COMBO5));
	n = pCombo5->GetCurSel();
	CString mCombo5;
	pCombo5->GetWindowTextW(mCombo5);
	string cheeseAmount = CStringA(mCombo5);

	// Get size text
	CComboBox* pCombo14 = reinterpret_cast<CComboBox*>(GetDlgItem(IDC_COMBO14));
	n = pCombo14->GetCurSel();
	CString mCombo14;
	pCombo14->GetWindowTextW(mCombo14);
	string size = CStringA(mCombo14); // make a C++ string from CString

	// Get toppings #1 text
	CComboBox* pCombo6 = reinterpret_cast<CComboBox*>(GetDlgItem(IDC_COMBO6));
	n = pCombo6->GetCurSel();
	CString mCombo6;
	pCombo6->GetWindowTextW(mCombo6);
	string topping1 = CStringA(mCombo6);
	// Get toppings #1 amount text
	CComboBox* pCombo10 = reinterpret_cast<CComboBox*>(GetDlgItem(IDC_COMBO10));
	n = pCombo10->GetCurSel();
	CString mCombo10;
	pCombo10->GetWindowTextW(mCombo10);
	string topping1Amount = CStringA(mCombo10);

	// Get toppings #2 text
	CComboBox* pCombo7 = reinterpret_cast<CComboBox*>(GetDlgItem(IDC_COMBO7));
	n = pCombo7->GetCurSel();
	CString mCombo7;
	pCombo7->GetWindowTextW(mCombo7);
	string topping2 = CStringA(mCombo7);
	// Get toppings #2 amount text
	CComboBox* pCombo11 = reinterpret_cast<CComboBox*>(GetDlgItem(IDC_COMBO11));
	n = pCombo11->GetCurSel();
	CString mCombo11;
	pCombo11->GetWindowTextW(mCombo11);
	string topping2Amount = CStringA(mCombo11);

	// Get toppings #3 text
	CComboBox* pCombo8 = reinterpret_cast<CComboBox*>(GetDlgItem(IDC_COMBO8));
	n = pCombo8->GetCurSel();
	CString mCombo8;
	pCombo8->GetWindowTextW(mCombo8);
	string topping3 = CStringA(mCombo8);
	// Get toppings #3 amount text
	CComboBox* pCombo12 = reinterpret_cast<CComboBox*>(GetDlgItem(IDC_COMBO12));
	n = pCombo12->GetCurSel();
	CString mCombo12;
	pCombo12->GetWindowTextW(mCombo12);
	string topping3Amount = CStringA(mCombo12);

	// Get toppings #4 text
	CComboBox* pCombo9 = reinterpret_cast<CComboBox*>(GetDlgItem(IDC_COMBO9));
	n = pCombo9->GetCurSel();
	CString mCombo9;
	pCombo9->GetWindowTextW(mCombo9);
	string topping4 = CStringA(mCombo9);
	// Get toppings #4 amount text
	CComboBox* pCombo13 = reinterpret_cast<CComboBox*>(GetDlgItem(IDC_COMBO13));
	n = pCombo13->GetCurSel();
	CString mCombo13;
	pCombo13->GetWindowTextW(mCombo13);
	string topping4Amount = CStringA(mCombo13);


	// Create sauce, cheese objects
	Sauce* const s = new Sauce(sauce, sauceAmount);
	Cheese* const c = new Cheese(cheese, cheeseAmount);

	Toppings* const t1 = new Toppings(topping1, topping1Amount);
	Toppings* const t2 = new Toppings(topping2, topping2Amount);
	Toppings* const t3 = new Toppings(topping3, topping3Amount);
	Toppings* const t4 = new Toppings(topping4, topping4Amount);
	// Determine which/if toppings were selected
	vector<Toppings*> ts;
	ts.push_back(t1);
	ts.push_back(t2);
	ts.push_back(t3);
	ts.push_back(t4);
	
	// Determine starting price based off selected pizza size
	double price;
	if (size == "Small")
		price = 11.99;
	else if (size == "Medium")
		price = 15.99;
	else
		price = 19.99;

	// Get addition charge if any for extra cheese/sauce
	price += c->getPrice();
	price += s->getPrice();

	// Start making output for pizza summary
	ostringstream sout;
	sout << size << " Pizza with " << c << s << "\r\n";
	// Loop to output only toppings that are selected
	for (unsigned int i = 0; i < ts.size(); i++) {
		if (ts[i]->getType() != "None") {
			sout << ts[i] << " ";
			price += ts[i]->getPrice();
		}
	}
	sout << roundTwo << "$" << price << roundOff;

	// Create pointer and set edit box to contain output
	CEdit* pEdit2 = reinterpret_cast<CEdit*>(GetDlgItem(IDC_EDIT2));
	pEdit2->SetWindowText(CString(sout.str().c_str()));
}

// Toppings #1 Handler
void CfinalMFCProjectDlg::OnCbnSelchangeCombo6()
{
	// Get combo box and corresponding picture control
	CComboBox* pCombo = reinterpret_cast<CComboBox*>(GetDlgItem(IDC_COMBO6));
	CStatic* pPicture = reinterpret_cast<CStatic*>(GetDlgItem(IDC_STATIC14));
	HBITMAP hb;

	// Switch statement for when each topping gets selected
	switch (pCombo->GetCurSel()) {
		case 0: { // "None" topping
			pPicture->ShowWindow(SW_HIDE); // Hide picture control when no topping selected
			break;
		}
		case 1: { // "Pepperoni" topping
			hb = (HBITMAP)::LoadImage(AfxGetInstanceHandle(), // Load in correct bitmap
				MAKEINTRESOURCE(IDB_BITMAP1), IMAGE_BITMAP, 0, 0, LR_CREATEDIBSECTION);
			pPicture->SetBitmap(hb); // Set bitmap to display in picture control
			pPicture->ShowWindow(SW_SHOW); // Show picture control window

			break;
		}
		case 2: { // "Sausage" topping
			pPicture->ShowWindow(SW_SHOW);
			hb = (HBITMAP)::LoadImage(AfxGetInstanceHandle(),
				MAKEINTRESOURCE(IDB_BITMAP2), IMAGE_BITMAP, 0, 0, LR_CREATEDIBSECTION);
			pPicture->SetBitmap(hb);
			break;
		}
		case 3: { // "Bacon" topping
			pPicture->ShowWindow(SW_SHOW);
			hb = (HBITMAP)::LoadImage(AfxGetInstanceHandle(),
				MAKEINTRESOURCE(IDB_BITMAP3), IMAGE_BITMAP, 0, 0, LR_CREATEDIBSECTION);
			pPicture->SetBitmap(hb);
			break;
		}
		case 4: { // "Mushrooms" topping
			pPicture->ShowWindow(SW_SHOW);
			hb = (HBITMAP)::LoadImage(AfxGetInstanceHandle(),
				MAKEINTRESOURCE(IDB_BITMAP4), IMAGE_BITMAP, 0, 0, LR_CREATEDIBSECTION);
			pPicture->SetBitmap(hb);
			break;
		}
		case 5: { // "Red Onions" topping
			pPicture->ShowWindow(SW_SHOW);
			hb = (HBITMAP)::LoadImage(AfxGetInstanceHandle(),
				MAKEINTRESOURCE(IDB_BITMAP5), IMAGE_BITMAP, 0, 0, LR_CREATEDIBSECTION);
			pPicture->SetBitmap(hb);
			break;
		}
		case 6: { // "Pineapple" topping
			pPicture->ShowWindow(SW_SHOW);
			hb = (HBITMAP)::LoadImage(AfxGetInstanceHandle(),
				MAKEINTRESOURCE(IDB_BITMAP6), IMAGE_BITMAP, 0, 0, LR_CREATEDIBSECTION);
			pPicture->SetBitmap(hb);
			break;
		}
		case 7: { // "Olives" topping
			pPicture->ShowWindow(SW_SHOW);
			hb = (HBITMAP)::LoadImage(AfxGetInstanceHandle(),
				MAKEINTRESOURCE(IDB_BITMAP7), IMAGE_BITMAP, 0, 0, LR_CREATEDIBSECTION);
			pPicture->SetBitmap(hb);
			break;
		}
		case 8: { // "Bell Peppers" topping
			pPicture->ShowWindow(SW_SHOW);
			hb = (HBITMAP)::LoadImage(AfxGetInstanceHandle(),
				MAKEINTRESOURCE(IDB_BITMAP8), IMAGE_BITMAP, 0, 0, LR_CREATEDIBSECTION);
			pPicture->SetBitmap(hb);
			break;
		}
	}
}

void CfinalMFCProjectDlg::OnCbnSelchangeCombo7()
{
	
	CComboBox* pCombo = reinterpret_cast<CComboBox*>(GetDlgItem(IDC_COMBO7));
	CStatic* pPicture = reinterpret_cast<CStatic*>(GetDlgItem(IDC_STATIC15));
	HBITMAP hb;

	switch (pCombo->GetCurSel()) {
		case 0: { // "None" topping
			pPicture->ShowWindow(SW_HIDE);
			break;
		}
		case 1: { // "Pepperoni" topping
			hb = (HBITMAP)::LoadImage(AfxGetInstanceHandle(),
				MAKEINTRESOURCE(IDB_BITMAP1), IMAGE_BITMAP, 0, 0, LR_CREATEDIBSECTION);
			pPicture->SetBitmap(hb);
			pPicture->ShowWindow(SW_SHOW);

			break;
		}
		case 2: { // "Sausage" topping
			pPicture->ShowWindow(SW_SHOW);
			hb = (HBITMAP)::LoadImage(AfxGetInstanceHandle(),
				MAKEINTRESOURCE(IDB_BITMAP2), IMAGE_BITMAP, 0, 0, LR_CREATEDIBSECTION);
			pPicture->SetBitmap(hb);
			break;
		}
		case 3: { // "Bacon" topping
			pPicture->ShowWindow(SW_SHOW);
			hb = (HBITMAP)::LoadImage(AfxGetInstanceHandle(),
				MAKEINTRESOURCE(IDB_BITMAP3), IMAGE_BITMAP, 0, 0, LR_CREATEDIBSECTION);
			pPicture->SetBitmap(hb);
			break;
		}
		case 4: { // "Mushrooms" topping
			pPicture->ShowWindow(SW_SHOW);
			hb = (HBITMAP)::LoadImage(AfxGetInstanceHandle(),
				MAKEINTRESOURCE(IDB_BITMAP4), IMAGE_BITMAP, 0, 0, LR_CREATEDIBSECTION);
			pPicture->SetBitmap(hb);
			break;
		}
		case 5: { // "Red Onions" topping
			pPicture->ShowWindow(SW_SHOW);
			hb = (HBITMAP)::LoadImage(AfxGetInstanceHandle(),
				MAKEINTRESOURCE(IDB_BITMAP5), IMAGE_BITMAP, 0, 0, LR_CREATEDIBSECTION);
			pPicture->SetBitmap(hb);
			break;
		}
		case 6: { // "Pineapple" topping
			pPicture->ShowWindow(SW_SHOW);
			hb = (HBITMAP)::LoadImage(AfxGetInstanceHandle(),
				MAKEINTRESOURCE(IDB_BITMAP6), IMAGE_BITMAP, 0, 0, LR_CREATEDIBSECTION);
			pPicture->SetBitmap(hb);
			break;
		}
		case 7: { // "Olives" topping
			pPicture->ShowWindow(SW_SHOW);
			hb = (HBITMAP)::LoadImage(AfxGetInstanceHandle(),
				MAKEINTRESOURCE(IDB_BITMAP7), IMAGE_BITMAP, 0, 0, LR_CREATEDIBSECTION);
			pPicture->SetBitmap(hb);
			break;
		}
		case 8: { // "Bell Peppers" topping
			pPicture->ShowWindow(SW_SHOW);
			hb = (HBITMAP)::LoadImage(AfxGetInstanceHandle(),
				MAKEINTRESOURCE(IDB_BITMAP8), IMAGE_BITMAP, 0, 0, LR_CREATEDIBSECTION);
			pPicture->SetBitmap(hb);
			break;
		}
	}
	
}


void CfinalMFCProjectDlg::OnCbnSelchangeCombo8()
{
	CComboBox* pCombo = reinterpret_cast<CComboBox*>(GetDlgItem(IDC_COMBO8));
	CStatic* pPicture = reinterpret_cast<CStatic*>(GetDlgItem(IDC_STATIC16));
	HBITMAP hb;

	switch (pCombo->GetCurSel()) {
		case 0: { // "None" topping
			pPicture->ShowWindow(SW_HIDE);
			break;
		}
		case 1: { // "Pepperoni" topping
			hb = (HBITMAP)::LoadImage(AfxGetInstanceHandle(),
				MAKEINTRESOURCE(IDB_BITMAP1), IMAGE_BITMAP, 0, 0, LR_CREATEDIBSECTION);
			pPicture->SetBitmap(hb);
			pPicture->ShowWindow(SW_SHOW);

			break;
		}
		case 2: { // "Sausage" topping
			pPicture->ShowWindow(SW_SHOW);
			hb = (HBITMAP)::LoadImage(AfxGetInstanceHandle(),
				MAKEINTRESOURCE(IDB_BITMAP2), IMAGE_BITMAP, 0, 0, LR_CREATEDIBSECTION);
			pPicture->SetBitmap(hb);
			break;
		}
		case 3: { // "Bacon" topping
			pPicture->ShowWindow(SW_SHOW);
			hb = (HBITMAP)::LoadImage(AfxGetInstanceHandle(),
				MAKEINTRESOURCE(IDB_BITMAP3), IMAGE_BITMAP, 0, 0, LR_CREATEDIBSECTION);
			pPicture->SetBitmap(hb);
			break;
		}
		case 4: { // "Mushrooms" topping
			pPicture->ShowWindow(SW_SHOW);
			hb = (HBITMAP)::LoadImage(AfxGetInstanceHandle(),
				MAKEINTRESOURCE(IDB_BITMAP4), IMAGE_BITMAP, 0, 0, LR_CREATEDIBSECTION);
			pPicture->SetBitmap(hb);
			break;
		}
		case 5: { // "Red Onions" topping
			pPicture->ShowWindow(SW_SHOW);
			hb = (HBITMAP)::LoadImage(AfxGetInstanceHandle(),
				MAKEINTRESOURCE(IDB_BITMAP5), IMAGE_BITMAP, 0, 0, LR_CREATEDIBSECTION);
			pPicture->SetBitmap(hb);
			break;
		}
		case 6: { // "Pineapple" topping
			pPicture->ShowWindow(SW_SHOW);
			hb = (HBITMAP)::LoadImage(AfxGetInstanceHandle(),
				MAKEINTRESOURCE(IDB_BITMAP6), IMAGE_BITMAP, 0, 0, LR_CREATEDIBSECTION);
			pPicture->SetBitmap(hb);
			break;
		}
		case 7: { // "Olives" topping
			pPicture->ShowWindow(SW_SHOW);
			hb = (HBITMAP)::LoadImage(AfxGetInstanceHandle(),
				MAKEINTRESOURCE(IDB_BITMAP7), IMAGE_BITMAP, 0, 0, LR_CREATEDIBSECTION);
			pPicture->SetBitmap(hb);
			break;
		}
		case 8: { // "Bell Peppers" topping
			pPicture->ShowWindow(SW_SHOW);
			hb = (HBITMAP)::LoadImage(AfxGetInstanceHandle(),
				MAKEINTRESOURCE(IDB_BITMAP8), IMAGE_BITMAP, 0, 0, LR_CREATEDIBSECTION);
			pPicture->SetBitmap(hb);
			break;
		}
	}
}


void CfinalMFCProjectDlg::OnCbnSelchangeCombo9()
{
	CComboBox* pCombo = reinterpret_cast<CComboBox*>(GetDlgItem(IDC_COMBO9));
	CStatic* pPicture = reinterpret_cast<CStatic*>(GetDlgItem(IDC_STATIC17));
	HBITMAP hb;

	switch (pCombo->GetCurSel()) {
		case 0: { // "None" topping
			pPicture->ShowWindow(SW_HIDE);
			break;
		}
		case 1: { // "Pepperoni" topping
			hb = (HBITMAP)::LoadImage(AfxGetInstanceHandle(),
				MAKEINTRESOURCE(IDB_BITMAP1), IMAGE_BITMAP, 0, 0, LR_CREATEDIBSECTION);
			pPicture->SetBitmap(hb);
			pPicture->ShowWindow(SW_SHOW);

			break;
		}
		case 2: { // "Sausage" topping
			pPicture->ShowWindow(SW_SHOW);
			hb = (HBITMAP)::LoadImage(AfxGetInstanceHandle(),
				MAKEINTRESOURCE(IDB_BITMAP2), IMAGE_BITMAP, 0, 0, LR_CREATEDIBSECTION);
			pPicture->SetBitmap(hb);
			break;
		}
		case 3: { // "Bacon" topping
			pPicture->ShowWindow(SW_SHOW);
			hb = (HBITMAP)::LoadImage(AfxGetInstanceHandle(),
				MAKEINTRESOURCE(IDB_BITMAP3), IMAGE_BITMAP, 0, 0, LR_CREATEDIBSECTION);
			pPicture->SetBitmap(hb);
			break;
		}
		case 4: { // "Mushrooms" topping
			pPicture->ShowWindow(SW_SHOW);
			hb = (HBITMAP)::LoadImage(AfxGetInstanceHandle(),
				MAKEINTRESOURCE(IDB_BITMAP4), IMAGE_BITMAP, 0, 0, LR_CREATEDIBSECTION);
			pPicture->SetBitmap(hb);
			break;
		}
		case 5: { // "Red Onions" topping
			pPicture->ShowWindow(SW_SHOW);
			hb = (HBITMAP)::LoadImage(AfxGetInstanceHandle(),
				MAKEINTRESOURCE(IDB_BITMAP5), IMAGE_BITMAP, 0, 0, LR_CREATEDIBSECTION);
			pPicture->SetBitmap(hb);
			break;
		}
		case 6: { // "Pineapple" topping
			pPicture->ShowWindow(SW_SHOW);
			hb = (HBITMAP)::LoadImage(AfxGetInstanceHandle(),
				MAKEINTRESOURCE(IDB_BITMAP6), IMAGE_BITMAP, 0, 0, LR_CREATEDIBSECTION);
			pPicture->SetBitmap(hb);
			break;
		}
		case 7: { // "Olives" topping
			pPicture->ShowWindow(SW_SHOW);
			hb = (HBITMAP)::LoadImage(AfxGetInstanceHandle(),
				MAKEINTRESOURCE(IDB_BITMAP7), IMAGE_BITMAP, 0, 0, LR_CREATEDIBSECTION);
			pPicture->SetBitmap(hb);
			break;
		}
		case 8: { // "Bell Peppers" topping
			pPicture->ShowWindow(SW_SHOW);
			hb = (HBITMAP)::LoadImage(AfxGetInstanceHandle(),
				MAKEINTRESOURCE(IDB_BITMAP8), IMAGE_BITMAP, 0, 0, LR_CREATEDIBSECTION);
			pPicture->SetBitmap(hb);
			break;
		}
	}
}
