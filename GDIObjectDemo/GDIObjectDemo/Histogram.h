#pragma once
#include "HistogramItem.h"
class CHistogram
{
public:
	CHistogram();
	~CHistogram();

	// 画柱形图
	void Draw(CDC *pDC);
	// 添加柱体Item
	void addItem(float value, CString string);
private:
	// 柱状图左上角矩形坐标
	CPoint leftUP;
	// 柱状图矩形右下角坐标
	CPoint rightDown;
	// 柱体iterm
	vector<CHistogramItem *> item;
	// 画刷颜色
	CArray<COLORREF> mColor;
	// 添加的数据
	CArray<float> value;
	// 矩形
	CRect rect;
	// 柱体之间的空隙
	int space;
	// 柱体高度
	int rectHeight;
	// 柱体宽度
	int rectWidth;
	// 柱体距离右边界的距离
	int rightSpace;

public:
	// 绘制坐标系
	void DrawCoordinate();
	// 计算矩形的各类参数
	void CalcuItemData();
	// 获取最大数据长度
	float GetMaxValue();
};

