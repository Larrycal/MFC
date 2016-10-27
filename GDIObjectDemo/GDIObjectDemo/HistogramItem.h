#pragma once
class CHistogramItem
{
public:
	CHistogramItem();
	CHistogramItem(COLORREF color, HBITMAP hbitmap, CString string);
	~CHistogramItem();
private:
	// ����ͼ��
	int width;
	// ����ͼ��
	int height;
	// ��ˢ
	CBrush brush;
	// λͼ
	CBitmap bitmap;
	// ��������
	CString string;
	// �������Ͻ�����
	CPoint startPoint;
	// �������½�����
	CPoint endPoint;
	// �������ھ���
	CRect rect;
public:
	// ����������Ϣ
	void SetItemData(int width, int height, CRect rect, CPoint startPoint, CPoint endPoint);
	// ������
	void DrawItem(CDC *pDC);
};

