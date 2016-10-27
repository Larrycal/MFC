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
	// �����ݺ�
	int getSum(const CArray<float>& value);
	// �������
	void addItem(float value, CString string);
private:
	// ��ˢ
	CArray<COLORREF> mColor;
	// ����
	vector<CPieItem*> pieItem;
	// ����
	CArray<float> value;
	// ���������Ͻ�����
	CPoint leftUp;
	// ͼ�����Ͻ�����
	CPoint rectLeftup;
	 // �����ο��
	int width; 
	// Բ�İ뾶
	float r; 
	// ͼ���ͱ�ͼ�ľ���
	int interval;
	// ͼ�����
	int rectWidth;
	// ͼ���߶�
	int rectHeight;
	// ��
	int row;
	// ��������
	int index;
	// ��������֮��ļ��
	int space;
	// ��������֮��ļ��
	int widthSpace;
};

