#pragma once
#define  PI 3.14
class CPieItem
{
public:
	CPieItem();
	CPieItem(COLORREF color, HBITMAP hbitmap, CString string);
	~CPieItem();
	// 画扇形
	void Draw(CDC *pDC);
	// 初始化数据
	void initData(CPoint O, CPoint startPoint, CPoint endPoint, CRect legend, CRect rect, float radius, float an,float oldan);
	// 画位图
	void DrawBmp(CDC *pDC);
private:
	// 外接矩形
	CRect outRect;
	// 圆心坐标
	CPoint O;
	// 扇形开始坐标
	CPoint startPoint;
	// 扇形结束坐标
	CPoint endPoint;
	// 图例矩形
	CRect legend;
	// 颜色
	COLORREF color;
	// 图片
	CBitmap bitmap;
	// 画刷
	CBrush brush;
	// 图例文字
	CString string;
	// 半径
	int radius;
	// 扇形角度
	float an;
	// 上一个扇形角度
	float oldan;
};

