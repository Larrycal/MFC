#include "stdafx.h"
#include "Histogram.h"


CHistogram::CHistogram()
{
	leftUP.SetPoint(100, 100);
}


CHistogram::~CHistogram()
{
}


// ������ͼ
void CHistogram::Draw(CDC *pDC)
{

	for (int i = 0;i < item.size();i++){

	}
}


// ��Ӳ���
void CHistogram::addItem(float value, CString string)
{

}


// ��������ϵ
void CHistogram::DrawCoordinate()
{
	CPoint startPoint;
	for (int i = 0;i < item.size();++i){

	}
}
