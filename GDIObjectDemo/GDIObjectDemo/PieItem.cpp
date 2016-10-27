#include "stdafx.h"
#include "PieItem.h"


CPieItem::CPieItem()
{
}


CPieItem::CPieItem(COLORREF color, HBITMAP hbitmap,CString string)
{
	this->color = color;
	this->bitmap.Attach(hbitmap);
	this->string = string;
	this->brush.CreateSolidBrush(this->color);
}

CPieItem::~CPieItem()
{
}


// ������
void CPieItem::Draw(CDC *pDC)
{
	pDC->SelectObject(&brush);
	// ������
	pDC->Pie(outRect, startPoint, endPoint);
	DrawBmp(pDC);
	// ��ͼ��
	pDC->FillRect(legend, &brush);
	pDC->TextOutW(legend.left + 20, legend.top,string);
}


// ��ʼ������
void CPieItem::initData(CPoint O, CPoint startPoint, CPoint endPoint, CRect legend, CRect rect,float radius,float an,float oldan)
{
	this->outRect = rect;
	this->startPoint = startPoint;
	this->endPoint = endPoint;
	this->O = O;
	this->legend = legend;
	this->radius = radius;
	this->an = an;
	this->oldan = oldan;
}





// ��λͼ
void CPieItem::DrawBmp(CDC *pDC)
{
	// ����λͼ����
	CPoint imgO;
	// �е����꣬��������������
	CPoint middel;
	middel.SetPoint((startPoint.x + endPoint.x) / 2.0, (startPoint.y + endPoint.y) / 2.0);
	//ͼƬ���
	const static int imgWidth = 25, imgHeight = 25;
	
	imgO.SetPoint((O.x + middel.x) / 2.0, (O.y +  middel.y) / 2.0);
	
	CPoint moveImgO = imgO;
	if (oldan < 0.2)
	{
		moveImgO.SetPoint((imgO.x - O.x) * 2.5 + O.x, (imgO.y - O.y) * 2.5 + O.y);
		pDC->MoveTo(moveImgO);
		pDC->LineTo(imgO);
	}
	// ��λͼ
	BITMAP bmp;
	bitmap.GetBitmap(&bmp);

	CDC memDC;
	memDC.CreateCompatibleDC(pDC);
	memDC.SelectObject(bitmap);

	//���ͼƬѹ����ʧ�������
	SetStretchBltMode(pDC->m_hDC, STRETCH_HALFTONE);

	pDC->TransparentBlt(moveImgO.x-imgWidth/2, moveImgO.y-imgHeight/2, imgWidth, imgHeight, &memDC, 0, 0, bmp.bmWidth, bmp.bmHeight, RGB(255, 255, 255));


}
