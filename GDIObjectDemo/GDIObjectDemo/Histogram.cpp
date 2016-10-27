#include "stdafx.h"
#include "Histogram.h"


CHistogram::CHistogram()
{
	leftUP.SetPoint(100, 100);
	rightDown.SetPoint(1000, 1000);
	space = 20;
	rightSpace = 50;
	rect.SetRect(leftUP, rightDown);
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


// 添加柱体Item
void CHistogram::addItem(float value, CString string)
{
	bool isHave = true;
	// 添加数据
	this->value.Add(value);
	//随机颜色
	COLORREF temp;
	// 计算非重复画刷颜色
	while (isHave)
	{
		temp = RGB(((int)value*(int)rand()) % 255, (int)rand() % 255, (int)rand() % 255);
		isHave = false;
		for (int i = 0; i < mColor.GetSize(); i++)
		{
			if (temp == mColor[i])
				isHave = true;
		}
	}

	HBITMAP hbitmap = (HBITMAP)::LoadImage(::AfxGetInstanceHandle(), _T(".\\res\\ICON\\004.bmp"), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);//从文件中加载

	item.push_back(new CHistogramItem(temp, hbitmap, string));


}


// 绘制坐标系
void CHistogram::DrawCoordinate()
{

}




// 计算矩形的各类参数
void CHistogram::CalcuItemData()
{
	// 柱体开始坐标
	CPoint itemStart;
	// 柱体结束坐标
	CPoint itemEnd;
	// 计算矩形高度
	rectHeight = ((rightDown.y - leftUP.y) - (space * item.size())) / item.size();
	// 单位矩形宽度
	int perRectWidth = ((rightDown.x - leftUP.x) - rightSpace) / GetMaxValue();
	// 计算矩形宽度
	for (int i = 0;i < item.size();++i) {
		rectWidth = perRectWidth * value[i];
		itemStart.SetPoint(leftUP.x, (rightDown.y - space / 2 - rectHeight) - (rectHeight + space) * i);
		itemEnd.SetPoint(itemStart.x + rectWidth,itemStart.y + rectHeight);
		item[i]->SetItemData(rectWidth, rectHeight,rect,itemStart,itemEnd);
	}
}


// 获取最大数据长度
float CHistogram::GetMaxValue()
{
	float max = 0;
	for (int i = 0; i < item.size(); ++i){
		max = max > value[i] ? max : value[i];
	}
	return max;
}
