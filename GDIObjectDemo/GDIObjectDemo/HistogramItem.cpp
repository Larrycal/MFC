#include "stdafx.h"
#include "HistogramItem.h"


CHistogramItem::CHistogramItem(COLORREF color, HBITMAP hbitmap, CString string)
{
	this->brush.CreateSolidBrush(color);
	this->bitmap.Attach(hbitmap);
	this->string = string;
}


CHistogramItem::CHistogramItem()
{
}

CHistogramItem::~CHistogramItem()
{
}


// 设置柱体信息
void CHistogramItem::SetItemData(int width,int height, CRect rect,CPoint startPoint, CPoint endPoint)
{
	this->width = width;
	this->height = height;
	this->startPoint = startPoint;
	this->endPoint = endPoint;
	this->rect.SetRect(startPoint,endPoint);
}


// 画柱体
void CHistogramItem::DrawItem(CDC *pDC)
{
	pDC->SelectObject(&brush);
	// 画扇形
	DrawBmp(pDC);
	// 画图例
	pDC->FillRect(rect, &brush);
	pDC->TextOutW(rect.left + 20, rect.top, string);
}
