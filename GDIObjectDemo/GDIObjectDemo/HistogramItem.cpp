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


// ����������Ϣ
void CHistogramItem::SetItemData(int width,int height, CRect rect,CPoint startPoint, CPoint endPoint)
{
	this->width = width;
	this->height = height;
	this->startPoint = startPoint;
	this->endPoint = endPoint;
	this->rect.SetRect(startPoint,endPoint);
}


// ������
void CHistogramItem::DrawItem(CDC *pDC)
{
	pDC->SelectObject(&brush);
	// ������
	DrawBmp(pDC);
	// ��ͼ��
	pDC->FillRect(rect, &brush);
	pDC->TextOutW(rect.left + 20, rect.top, string);
}
