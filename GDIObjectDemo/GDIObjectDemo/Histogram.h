#pragma once
#include "HistogramItem.h"
class CHistogram
{
public:
	CHistogram();
	~CHistogram();

	// 画柱形图
	void Draw(CDC *pDC);
	// 添加参数
	void addItem(float value, CString string);
private:
	// 柱状图左上角矩形坐标
	CPoint leftUP;
	// 柱体iterm
	vector<CHistogram *> item;
	// 画刷颜色
	vector<COLORREF> color;

public:
	// 绘制坐标系
	void DrawCoordinate();
};

