#pragma once
class CHistogramItem
{
public:
	CHistogramItem();
	~CHistogramItem();
private:
	// 条形图长
	int width;
	// 条形图宽
	int height;
	// 画刷
	CBrush brush;

};

