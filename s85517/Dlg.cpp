
// Dlg.cpp: Implementierungsdatei
//

#include "pch.h"
#include "framework.h"
#include "s85517.h"
#include "Dlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CDlg-Dialogfeld



CDlg::CDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_S85517_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CDlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_WM_MOUSEMOVE()
	ON_WM_LBUTTONDOWN()
END_MESSAGE_MAP()


// CDlg-Meldungshandler

BOOL CDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	if (!m_bkg.Load("background700x400.bmp")) {
		AfxMessageBox(L"background700x400.bmp not found");
		OnCancel();
	}
	m_bkg.SetZ(0);
	m_buff.Load("background700x400.bmp");

	if (!m_font.Load("name350x125.bmp")) {
		AfxMessageBox(L"name350x125.bmp not found");
		OnCancel();
	}
	m_font.SetZ(1);
	m_font.SetPosition(175, 50);
	for (int i = 0; i < 2; i++) {
		if (!m_btn[i].Load("buttons_111x31.bmp", CSize(111, 31))) {
			AfxMessageBox(L"buttons_111x31.bmp not found");
			OnCancel();
		}
	}
	m_btn[0].SetZ(2);
	m_btn[1].SetZ(2);
	m_btn[0].SetPosition(50,200);
	m_btn[1].SetPosition(50, 250);
	m_btn[0].SetSpriteNumber(0, 0);
	m_btn[1].SetSpriteNumber(0, 2);



	// add to spritelist
	m_list.SetWorkspace(&m_buff);
	m_list.Insert(&m_bkg);
	m_list.Insert(&m_font);
	m_list.Insert(&m_btn[0]);
	m_list.Insert(&m_btn[1]);

	SetWindowPos(NULL, 0, 0,
		m_bkg.DibWidth(),
		m_bkg.DibHeight() + 20,
		SWP_NOZORDER | SWP_NOMOVE
	);


	SetIcon(m_hIcon, TRUE);			
	SetIcon(m_hIcon, FALSE);		


	return TRUE;  
}

void CDlg::OnPaint()
{
	CPaintDC dc(this);
	if (IsIconic())
	{
		CPaintDC dc(this); 

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Symbol in Clientrechteck zentrieren
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Symbol zeichnen
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
		m_list.RedrawAll(&dc, 0, 0);
	}
}

HCURSOR CDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CDlg::OnMouseMove(UINT nFlags, CPoint point)
{
	CClientDC dc(this);
	CSize offset;
	CPoint moveto;

	// TODO: Fügen Sie hier Ihren Meldungshandlercode ein, und/oder benutzen Sie den Standard.
	CString s;
	s.Format(L"x = %d  |  y = %d", point.x, point.y);
	SetWindowText(s);

	if (m_captured && (nFlags & MK_RBUTTON)) {
		offset = point - m_mPos;
		moveto = m_captured->GetPos() + offset;
		m_captured->SetPosition(moveto.x, moveto.y);
		m_mPos = point;
	}
	else {
		m_captured = NULL;
		CSprite* hit = m_list.HitTest(point);
		if (hit == &m_btn[0]) {
			m_btn[0].SetSpriteNumber(0, 1);
		}
		else { m_btn[0].SetSpriteNumber(0, 0); }
		if (hit == &m_btn[1]) {
			m_btn[1].SetSpriteNumber(0, 3);
		}
		else { m_btn[1].SetSpriteNumber(0, 2); }
	}

	m_list.Update(&dc, 0, 0);
	CDialogEx::OnMouseMove(nFlags, point);
}


void CDlg::OnLButtonDown(UINT nFlags, CPoint point)
{
	CClientDC dc(this);
	CSprite* hit = m_list.HitTest(point);
	if (hit == &m_btn[0]) {
		m_list.Remove(&m_btn[1]);
		m_list.Remove(&m_btn[0]);
		m_list.Remove(&m_font);
	}m_list.Update(&dc, 0, 0);

	CDialogEx::OnLButtonDown(nFlags, point);
}
