// LineObj.h: interface for the CLineObj class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_LINEOBJ_H__AD7E2DCC_A518_4C53_B1DA_4DEFDA9517DE__INCLUDED_)
#define AFX_LINEOBJ_H__AD7E2DCC_A518_4C53_B1DA_4DEFDA9517DE__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "DrawObj.h"

class CLineObj : public CDrawObj  
{
public:
	CLineObj();
	virtual ~CLineObj();

	virtual void Draw(CDC * pDC);
	virtual void HitTest(CPoint point);

};

#endif // !defined(AFX_LINEOBJ_H__AD7E2DCC_A518_4C53_B1DA_4DEFDA9517DE__INCLUDED_)
