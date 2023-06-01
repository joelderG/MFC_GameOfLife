
// Dlg.h: Headerdatei
//

#pragma once
#include "spritelib.h"
#include "CUserInterface.h"


// CDlg-Dialogfeld
class CDlg : public CDialogEx
{
// Konstruktion
public:
	CDlg(CWnd* pParent = nullptr);	// Standardkonstruktor

// Dialogfelddaten
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_S85517_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV-Unterstützung


// Implementierung
protected:
	HICON m_hIcon;

	CDIB m_buff;
	CSprite m_bkg;
	CSprite m_font;
	CSprite m_btn[3];
	CSprite m_guibtn[4];
	CSprite m_filebtn[3];
	CSpriteList m_list;
	CSprite* m_captured;
	CPoint m_mPos;

	// Generierte Funktionen für die Meldungstabellen
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnTimer(UINT_PTR nIDEvent);
};
