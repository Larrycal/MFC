#pragma once
class CHistogramItem
{
public:
	CHistogramItem();
	CHistogramItem(COLORREF color, HBITMAP hbitmap, CString string);
	~CHistogramItem();
private:
	// 条形图长
	int width;
	// 条形图宽
	int height;
	// 画刷
	CBrush brush;
	// 位图
	CBitmap bitmap;
	// 数据文字
	CString string;
	// 柱体左上角坐标
	CPoint startPoint;
	// 柱体右下角坐标
	CPoint endPoint;
	// 柱体所在矩形
	CRect rect;
public:
	// 设置柱体信息
	void SetItemData(int width, int height, CRect rect, CPoint startPoint, CPoint endPoint);
	// 画柱体
	void DrawItem(CDC *pDC);
};

