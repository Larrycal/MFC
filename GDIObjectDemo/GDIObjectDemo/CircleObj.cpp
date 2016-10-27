#include "stdafx.h"
#include "CircleObj.h"


CCircleObj::CCircleObj()
{
	m_EndPoint.x = 0;
	m_EndPoint.y = 0;
	leftUp.SetPoint(100, 100); // 设置饼图矩形左上角坐标
	width = 500; // 设置正方形宽度
	r = width / 2; // 设置圆的半径
	interval = 100; // 设置间隔
	rectHeight = 10; // 图例高度
	rectWidth = 20; // 图例宽度
	row = 10; // 行数
	space = 15; // 矩形间隔
	widthSpace = 65; // 矩形左右间距
	addItem(10, L"测试文本");
	addItem(10, L"测试文本");
	addItem(10, L"测试文本");
	addItem(10, L"测试文本");
	addItem(10, L"测试文本");
	addItem(10, L"测试文本");
	addItem(10, L"测试文本");
	addItem(10, L"测试文本");
	addItem(10, L"测试文本");
	addItem(10, L"测试文本");
	addItem(10, L"测试文本");
	addItem(10, L"测试文本");
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
	CRect rect(leftUp.x, leftUp.y, leftUp.x + width, leftUp.y + width);	// 设置饼图大小
	CPoint O(leftUp.x + width / 2, leftUp.y + width / 2); // 设置圆的圆心
	CPoint startP(O.x, O.y + width / 2); // 设置圆开始绘画的位置
	m_Point = startP;
	
	for (int i = 0; i < pieItem.size() ;i++) // 画饼图
	{
		// 对图例进行布局
		rectLeftup.x = leftUp.x + (i / row ) * (widthSpace + rectWidth) + width + interval;  
		rectLeftup.y = leftUp.y + (i % row) * (space + rectHeight);

		CRect legend(rectLeftup.x, rectLeftup.y, rectLeftup.x + rectWidth , rectLeftup.y + rectHeight); // 图例矩形

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



// 求数据和
int CCircleObj::getSum(const CArray<float>& value)
{
	int sum = 0;
	for (int i = 0; i < value.GetSize();i++) // 求和
	{
		sum += value[i];
	}
	return sum;
}


// 添加扇形
void CCircleObj::addItem(float value,CString string)
{
	bool isHave = true;
	// 添加数据
	this->value.Add(value);
	//随机颜色
	COLORREF temp;
	// 计算非重复画刷颜色
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

	HBITMAP hbitmap = (HBITMAP)::LoadImage(::AfxGetInstanceHandle(), _T(".\\res\\ICON\\004.bmp"), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);//从文件中加载

	pieItem.push_back(new CPieItem(temp, hbitmap, string));
	
}
