// GDIObjectDemoView.cpp : implementation of the CGDIObjectDemoView class
//

#include "stdafx.h"
#include "GDIObjectDemo.h"

#include "GDIObjectDemoDoc.h"
#include "GDIObjectDemoView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CGDIObjectDemoView

IMPLEMENT_DYNCREATE(CGDIObjectDemoView, CView)

BEGIN_MESSAGE_MAP(CGDIObjectDemoView, CView)
	//{{AFX_MSG_MAP(CGDIObjectDemoView)
	ON_COMMAND(ID_BTNLINE, OnBtnline)
	ON_COMMAND(ID_BTNRECT, OnBtnrect)
	ON_WM_LBUTTONDOWN()
	ON_WM_MOUSEMOVE()
	ON_WM_LBUTTONUP()
	ON_COMMAND(ID_BTNSELECT, OnBtnselect)
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
	ON_COMMAND(ID_BTNCIRCLE, &CGDIObjectDemoView::OnBtncircle)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CGDIObjectDemoView construction/destruction

CGDIObjectDemoView::CGDIObjectDemoView()
{
	// TODO: add construction code here
	m_DrawType = 1;
	m_DrawCurrObject = false;
}

CGDIObjectDemoView::~CGDIObjectDemoView()
{
}

BOOL CGDIObjectDemoView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CGDIObjectDemoView drawing

void CGDIObjectDemoView::OnDraw(CDC* pDC)
{
	CGDIObjectDemoDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here
	CRect rect;
	this->GetClientRect(&rect);
	CDC* memDC = new CDC;  
	CBitmap* pBmp = new CBitmap;
	CBitmap* pOldBmp;
	memDC->CreateCompatibleDC(pDC);
	pBmp->CreateCompatibleBitmap(pDC, rect.Width(), rect.Height());
	pOldBmp = memDC->SelectObject(pBmp);
	memDC->FillSolidRect(&rect, RGB(255, 255, 255));

	if (m_DrawCurrObject)
	{
		if (m_DrawType == 1)
		{
			m_CurrLine.Draw(memDC);
		}
		if (m_DrawType == 2)
		{
			m_CurrRect.Draw(memDC);
		}
		if (m_DrawType == 4)
		{
			m_CurrCircle.Draw(memDC);
		}
	}
	POSITION pos = m_DrawObjs.GetHeadPosition();	
	while(pos)
	{ 
		((CDrawObj*)(m_DrawObjs.GetNext(pos)))->Draw(memDC);
	}

	pDC->BitBlt(0, 0, rect.Width(), rect.Height(), memDC, 0, 0, SRCCOPY);

}

/////////////////////////////////////////////////////////////////////////////
// CGDIObjectDemoView printing

BOOL CGDIObjectDemoView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CGDIObjectDemoView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CGDIObjectDemoView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CGDIObjectDemoView diagnostics

#ifdef _DEBUG
void CGDIObjectDemoView::AssertValid() const
{
	CView::AssertValid();
}

void CGDIObjectDemoView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CGDIObjectDemoDoc* CGDIObjectDemoView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CGDIObjectDemoDoc)));
	return (CGDIObjectDemoDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CGDIObjectDemoView message handlers

void CGDIObjectDemoView::OnBtnline() 
{
	// TODO: Add your command handler code here
		m_DrawType = 1;
}

void CGDIObjectDemoView::OnBtnrect() 
{
	// TODO: Add your command handler code here
		m_DrawType = 2;
}

void CGDIObjectDemoView::OnBtncircle()
{
	// ±ýÍ¼»æÖÆ
	m_DrawType = 4;
	m_CurrLine.m_IsSelected = false;
	m_CurrRect.m_IsSelected = false;
	m_CurrCircle.m_IsSelected = true;
	m_DrawCurrObject = true;
	Invalidate();
}

void CGDIObjectDemoView::OnLButtonDown(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	
// 	CView::OnLButtonDown(nFlags, point);
// 	
// 	if (m_DrawType == 1)
// 	{
// 		m_CurrLine.m_Point = point;
// 		m_CurrLine.m_EndPoint = point;
// 		m_CurrLine.m_OldPoint = point;
// 		m_CurrLine.m_IsSelected = true;
// 		m_CurrRect.m_IsSelected = false;
// 		m_CurrCircle.m_IsSelected = false;
// 		m_DrawCurrObject = true;
// 
// 	}else if (m_DrawType == 2)
// 	{
// 		m_CurrRect.m_Point = point;
// 		m_CurrRect.m_EndPoint = point;
// 		m_CurrRect.m_OldPoint = point;
// 		m_CurrLine.m_IsSelected = false;
// 		m_CurrRect.m_IsSelected = true;
// 		m_CurrCircle.m_IsSelected = false;
// 		m_DrawCurrObject = true;
// 	}
// 	else if (m_DrawType == 3)
// 	{
// 		POSITION pos = m_DrawObjs.GetHeadPosition();
// 		while (pos)
// 		{
// 
// 			((CDrawObj*)(m_DrawObjs.GetNext(pos)))->HitTest(point);
// 		}
// 	}
// 	//Invalidate();
}

void CGDIObjectDemoView::OnMouseMove(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
// 	
// 	CView::OnMouseMove(nFlags, point);
// 	if (m_DrawCurrObject)
// 	{
// 
// 		if (m_DrawType == 1)
// 		{
// 			CRect rect(m_CurrLine.m_OldPoint, m_CurrLine.m_EndPoint);
// 			m_CurrLine.m_EndPoint = point;
// 			InvalidateRect(rect);
// 		}
// 		else 	if (m_DrawType == 2)
// 		{
// 			CRect rect(m_CurrRect.m_Point, m_CurrRect.m_EndPoint);
// 			m_CurrRect.m_EndPoint = point;
// 			InvalidateRect(rect);
// 		}
// 		else   if (m_DrawType == 4)
// 		{
// 			m_CurrCircle.m_EndPoint = point;
// 		}
// 		
// 	}
}

void CGDIObjectDemoView::OnLButtonUp(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	
	CView::OnLButtonUp(nFlags, point);
// 
// 	if (m_DrawType == 1)
// 	{
// 		m_CurrLine.m_EndPoint = point;
// 
// 		CLineObj *  pline = new CLineObj( );
//  	    pline->m_Point= m_CurrLine.m_Point;
// 		pline->m_EndPoint = m_CurrLine.m_EndPoint;
// 		pline->m_IsSelected = false;
// 		m_DrawObjs.AddTail((CObject*)pline);
// 	
// 		
// 	}else 	if (m_DrawType == 2)
// 	{
// 		m_CurrRect.m_EndPoint = point;
// 
// 		CRectObj * prect= new CRectObj();
// 		prect->m_Point = m_CurrRect.m_Point;
// 		prect->m_EndPoint = m_CurrRect.m_EndPoint;
// 		prect->m_IsSelected = false;
// 		m_DrawObjs.AddTail((CObject*)prect);
// 	}
// 	m_DrawCurrObject = false;
// 	Invalidate();
}

void CGDIObjectDemoView::OnBtnselect() 
{
	// TODO: Add your command handler code here
	m_DrawType = 3;
	m_DrawCurrObject = false;
	m_CurrLine.m_IsSelected = false;
	m_CurrRect.m_IsSelected = false;
	m_CurrCircle.m_IsSelected = false;
	Invalidate();
	
}



