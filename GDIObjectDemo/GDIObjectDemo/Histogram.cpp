#include "stdafx.h"
#include "Histogram.h"


CHistogram::CHistogram()
{
	leftUP.SetPoint(100, 100);
}


CHistogram::~CHistogram()
{
}


// 画柱形图
void CHistogram::Draw(CDC *pDC)
{

	for (int i = 0;i < item.size();i++){

	}
}


// 添加参数
void CHistogram::addItem(float value, CString string)
{

}


// 绘制坐标系
void CHistogram::DrawCoordinate()
{
	CPoint startPoint;
	for (int i = 0;i < item.size();++i){

	}
}
