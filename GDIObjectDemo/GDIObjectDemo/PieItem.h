#pragma once
#define  PI 3.14
class CPieItem
{
public:
	CPieItem();
	CPieItem(COLORREF color, HBITMAP hbitmap, CString string);
	~CPieItem();
	// ������
	void Draw(CDC *pDC);
	// ��ʼ������
	void initData(CPoint O, CPoint startPoint, CPoint endPoint, CRect legend, CRect rect, float radius, float an,float oldan);
	// ��λͼ
	void DrawBmp(CDC *pDC);
private:
	// ��Ӿ���
	CRect outRect;
	// Բ������
	CPoint O;
	// ���ο�ʼ����
	CPoint startPoint;
	// ���ν�������
	CPoint endPoint;
	// ͼ������
	CRect legend;
	// ��ɫ
	COLORREF color;
	// ͼƬ
	CBitmap bitmap;
	// ��ˢ
	CBrush brush;
	// ͼ������
	CString string;
	// �뾶
	int radius;
	// ���νǶ�
	float an;
	// ��һ�����νǶ�
	float oldan;
};

