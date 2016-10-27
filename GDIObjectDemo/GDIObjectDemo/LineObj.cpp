// LineObj.cpp: implementation of the CLineObj class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "GDIObjectDemo.h"
#include "LineObj.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CLineObj::CLineObj()
{
	m_EndPoint.x = 0;
	m_EndPoint.y = 0;
}

CLineObj::~CLineObj()
{

}
void CLineObj::Draw(CDC * pDC)
{

	CPen  *oldpen;
	CBrush * oldbrush;
	if (m_IsSelected)
	{
		oldbrush = pDC->SelectObject(&m_SelectedBrush);
		oldpen = pDC->SelectObject(&m_SelectedPen);
	}else{
		oldbrush = pDC->SelectObject(&m_Brush);
		oldpen = pDC->SelectObject(&m_Pen);
	}
	pDC->MoveTo(m_Point);
	pDC->LineTo(m_EndPoint);

    pDC->SelectObject(oldbrush);
    pDC->SelectObject(oldpen);

}
void CLineObj::HitTest(CPoint point)
{
	if ((point.x > min(m_Point.x, m_EndPoint.x)) && (point.x < max(m_Point.x, m_EndPoint.x)) &&
		(point.y > min(m_Point.y, m_EndPoint.y)) && (point.y < max(m_Point.y, m_EndPoint.y)))
	{
		this->m_IsSelected = true;
	}
	else
	{
		this->m_IsSelected = false;
	}
	
	//CRect rect(m_Point.x, m_Point.y, m_EndPoint.x, m_EndPoint.y);	 
	//if (PtInRect(&rect, point))
	//	this->m_IsSelected = true;
	//else
	//	this->m_IsSelected = false;

	

}