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


// ������ͼ
void CHistogram::Draw(CDC *pDC)
{

	for (int i = 0;i < item.size();i++){

	}
}


// �������Item
void CHistogram::addItem(float value, CString string)
{
	bool isHave = true;
	// �������
	this->value.Add(value);
	//�����ɫ
	COLORREF temp;
	// ������ظ���ˢ��ɫ
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

	HBITMAP hbitmap = (HBITMAP)::LoadImage(::AfxGetInstanceHandle(), _T(".\\res\\ICON\\004.bmp"), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);//���ļ��м���

	item.push_back(new CHistogramItem(temp, hbitmap, string));


}


// ��������ϵ
void CHistogram::DrawCoordinate()
{

}




// ������εĸ������
void CHistogram::CalcuItemData()
{
	// ���忪ʼ����
	CPoint itemStart;
	// �����������
	CPoint itemEnd;
	// ������θ߶�
	rectHeight = ((rightDown.y - leftUP.y) - (space * item.size())) / item.size();
	// ��λ���ο��
	int perRectWidth = ((rightDown.x - leftUP.x) - rightSpace) / GetMaxValue();
	// ������ο��
	for (int i = 0;i < item.size();++i) {
		rectWidth = perRectWidth * value[i];
		itemStart.SetPoint(leftUP.x, (rightDown.y - space / 2 - rectHeight) - (rectHeight + space) * i);
		itemEnd.SetPoint(itemStart.x + rectWidth,itemStart.y + rectHeight);
		item[i]->SetItemData(rectWidth, rectHeight,rect,itemStart,itemEnd);
	}
}


// ��ȡ������ݳ���
float CHistogram::GetMaxValue()
{
	float max = 0;
	for (int i = 0; i < item.size(); ++i){
		max = max > value[i] ? max : value[i];
	}
	return max;
}
