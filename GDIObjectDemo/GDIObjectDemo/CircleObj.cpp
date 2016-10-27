#include "stdafx.h"
#include "CircleObj.h"


CCircleObj::CCircleObj()
{
	m_EndPoint.x = 0;
	m_EndPoint.y = 0;
	leftUp.SetPoint(100, 100); // ���ñ�ͼ�������Ͻ�����
	width = 500; // ���������ο��
	r = width / 2; // ����Բ�İ뾶
	interval = 100; // ���ü��
	rectHeight = 10; // ͼ���߶�
	rectWidth = 20; // ͼ�����
	row = 10; // ����
	space = 15; // ���μ��
	widthSpace = 65; // �������Ҽ��
	addItem(10, L"�����ı�");
	addItem(10, L"�����ı�");
	addItem(10, L"�����ı�");
	addItem(10, L"�����ı�");
	addItem(10, L"�����ı�");
	addItem(10, L"�����ı�");
	addItem(10, L"�����ı�");
	addItem(10, L"�����ı�");
	addItem(10, L"�����ı�");
	addItem(10, L"�����ı�");
	addItem(10, L"�����ı�");
	addItem(10, L"�����ı�");
}


CCircleObj::~CCircleObj()
{

}

void CCircleObj::Draw(CDC * pDC)
{
	float sumNow = 0;
	float sum = 0;
	sum = getSum(value);
	

	m_Point.SetPoint(leftUp.x, leftUp.y);
	CRect rect(leftUp.x, leftUp.y, leftUp.x + width, leftUp.y + width);	// ���ñ�ͼ��С
	CPoint O(leftUp.x + width / 2, leftUp.y + width / 2); // ����Բ��Բ��
	CPoint startP(O.x, O.y + width / 2); // ����Բ��ʼ�滭��λ��
	m_Point = startP;
	
	for (int i = 0; i < pieItem.size() ;i++) // ����ͼ
	{
		// ��ͼ�����в���
		rectLeftup.x = leftUp.x + (i / row ) * (widthSpace + rectWidth) + width + interval;  
		rectLeftup.y = leftUp.y + (i % row) * (space + rectHeight);

		CRect legend(rectLeftup.x, rectLeftup.y, rectLeftup.x + rectWidth , rectLeftup.y + rectHeight); // ͼ������

		float oldan = sumNow / sum * 3.14 * 2;
		float an = (value[i] + sumNow) / sum * 3.14 * 2;
		m_EndPoint.x = O.x + r*sin(an);
		m_EndPoint.y = O.y + r*cos(an);
		sumNow += value[i];

		pieItem[i]->initData(O, m_Point, m_EndPoint, legend, rect,r,an,an-oldan);
		pieItem[i]->Draw(pDC);
		m_Point.x = m_EndPoint.x;
		m_Point.y = m_EndPoint.y;
	}

}

void CCircleObj::HitTest(CPoint point)
{
	if ((point.x > min(m_Point.x, m_EndPoint.x)) && (point.x < max(m_Point.x, m_EndPoint.x)) &&
		(point.y > min(m_Point.y, m_EndPoint.y)) && (point.y < max(m_Point.y, m_EndPoint.y)))
	{
		this->m_IsSelected = true;
	}
	else
	{
		this->m_IsSelected = false;
	}
}



// �����ݺ�
int CCircleObj::getSum(const CArray<float>& value)
{
	int sum = 0;
	for (int i = 0; i < value.GetSize();i++) // ���
	{
		sum += value[i];
	}
	return sum;
}


// �������
void CCircleObj::addItem(float value,CString string)
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

	pieItem.push_back(new CPieItem(temp, hbitmap, string));
	
}
