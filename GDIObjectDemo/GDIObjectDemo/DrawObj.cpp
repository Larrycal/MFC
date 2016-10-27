// DrawObj.cpp: implementation of the CDrawObj class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "GDIObjectDemo.h"
#include "DrawObj.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CDrawObj::CDrawObj()
{
	m_Point.x = 0;
	m_Point.y = 0;
	m_SelectedPen.CreatePen(PS_SOLID, 2, RGB(255, 0, 0));
	m_SelectedBrush.CreateSolidBrush(RGB(128, 128, 128));
	m_Pen.CreatePen(PS_SOLID, 2, RGB(0, 255, 0));
	m_Brush.CreateSolidBrush(RGB(255, 255, 255));
	m_IsSelected = false;
}

CDrawObj::~CDrawObj()
{

}
