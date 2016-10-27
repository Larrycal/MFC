// DrawObj.h: interface for the CDrawObj class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_DRAWOBJ_H__69745B6F_1DB9_464B_A0A3_4939B4865095__INCLUDED_)
#define AFX_DRAWOBJ_H__69745B6F_1DB9_464B_A0A3_4939B4865095__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CDrawObj// : public CObject  
{
public:
	CDrawObj();
	virtual ~CDrawObj();
	CPoint m_Point;
	CPoint m_EndPoint;
	CPen   m_SelectedPen;
	CBrush m_SelectedBrush;
	CPen   m_Pen;
	CBrush m_Brush;
	CPoint m_MinPoint;
	CPoint m_MaxPoint;
	CPoint m_OldPoint;


	bool   m_IsSelected;
	virtual void Draw(CDC * pDC) = 0;
	virtual void HitTest(CPoint point) = 0;
};

#endif // !defined(AFX_DRAWOBJ_H__69745B6F_1DB9_464B_A0A3_4939B4865095__INCLUDED_)
