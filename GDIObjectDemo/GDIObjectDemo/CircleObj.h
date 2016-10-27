#pragma once
#include "DrawObj.h"
#include "PieItem.h"

class CCircleObj :
	public CDrawObj
{
public:
	CCircleObj();
	virtual ~CCircleObj();

	virtual void Draw(CDC * pDC);
	virtual void HitTest(CPoint point);
	// 求数据和
	int getSum(const CArray<float>& value);
	// 添加扇形
	void addItem(float value, CString string);
private:
	// 画刷
	CArray<COLORREF> mColor;
	// 扇形
	vector<CPieItem*> pieItem;
	// 数据
	CArray<float> value;
	// 正方形左上角坐标
	CPoint leftUp;
	// 图例左上角坐标
	CPoint rectLeftup;
	 // 正方形宽度
	int width; 
	// 圆的半径
	float r; 
	// 图例和饼图的距离
	int interval;
	// 图例宽度
	int rectWidth;
	// 图例高度
	int rectHeight;
	// 行
	int row;
	// 行列索引
	int index;
	// 矩形上下之间的间距
	int space;
	// 举行左右之间的间距
	int widthSpace;
};

