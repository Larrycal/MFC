#pragma once
#include "HistogramItem.h"
class CHistogram
{
public:
	CHistogram();
	~CHistogram();

	// ������ͼ
	void Draw(CDC *pDC);
	// ��Ӳ���
	void addItem(float value, CString string);
private:
	// ��״ͼ���ϽǾ�������
	CPoint leftUP;
	// ����iterm
	vector<CHistogram *> item;
	// ��ˢ��ɫ
	vector<COLORREF> color;

public:
	// ��������ϵ
	void DrawCoordinate();
};

