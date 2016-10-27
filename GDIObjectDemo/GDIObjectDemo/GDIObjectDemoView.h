// GDIObjectDemoView.h : interface of the CGDIObjectDemoView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_GDIOBJECTDEMOVIEW_H__E97516EC_5271_424E_97FA_AED79E2FC110__INCLUDED_)
#define AFX_GDIOBJECTDEMOVIEW_H__E97516EC_5271_424E_97FA_AED79E2FC110__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include  <Afxcoll.h>
#include "LineObj.h"
#include "RectObj.h"
#include "CircleObj.h"
class CGDIObjectDemoView : public CView
{
protected: // create from serialization only
	CGDIObjectDemoView();
	DECLARE_DYNCREATE(CGDIObjectDemoView)

// Attributes
public:
	CGDIObjectDemoDoc* GetDocument();

	CObList m_DrawObjs;
	char m_DrawType; //1为线， 2 为矩形 4为圆形 3 为选择
	bool m_DrawCurrObject;
	
	CLineObj m_CurrLine;
	CRectObj m_CurrRect;
	CCircleObj m_CurrCircle;

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CGDIObjectDemoView)
	public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CGDIObjectDemoView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CGDIObjectDemoView)
	afx_msg void OnBtnline();
	afx_msg void OnBtnrect();
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnBtnselect();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBtncircle();
};

#ifndef _DEBUG  // debug version in GDIObjectDemoView.cpp
inline CGDIObjectDemoDoc* CGDIObjectDemoView::GetDocument()
   { return (CGDIObjectDemoDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_GDIOBJECTDEMOVIEW_H__E97516EC_5271_424E_97FA_AED79E2FC110__INCLUDED_)
