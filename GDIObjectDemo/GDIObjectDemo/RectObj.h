// RectObj.h: interface for the CRectObj class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_RECTOBJ_H__899C2CE2_EA93_4DDE_A353_7505E722E920__INCLUDED_)
#define AFX_RECTOBJ_H__899C2CE2_EA93_4DDE_A353_7505E722E920__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "DrawObj.h"

class CRectObj : public CDrawObj  
{
public:
	CRectObj();
	virtual ~CRectObj();
	
	virtual void Draw(CDC * pDC);
	virtual void HitTest(CPoint point);
};

#endif // !defined(AFX_RECTOBJ_H__899C2CE2_EA93_4DDE_A353_7505E722E920__INCLUDED_)
