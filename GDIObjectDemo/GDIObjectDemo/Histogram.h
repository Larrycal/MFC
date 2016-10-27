#pragma once
#include "HistogramItem.h"
class CHistogram
{
public:
	CHistogram();
	~CHistogram();

	// ������ͼ
	void Draw(CDC *pDC);
	// �������Item
	void addItem(float value, CString string);
private:
	// ��״ͼ���ϽǾ�������
	CPoint leftUP;
	// ��״ͼ�������½�����
	CPoint rightDown;
	// ����iterm
	vector<CHistogramItem *> item;
	// ��ˢ��ɫ
	CArray<COLORREF> mColor;
	// ��ӵ�����
	CArray<float> value;
	// ����
	CRect rect;
	// ����֮��Ŀ�϶
	int space;
	// ����߶�
	int rectHeight;
	// ������
	int rectWidth;
	// ��������ұ߽�ľ���
	int rightSpace;

public:
	// ��������ϵ
	void DrawCoordinate();
	// ������εĸ������
	void CalcuItemData();
	// ��ȡ������ݳ���
	float GetMaxValue();
};

