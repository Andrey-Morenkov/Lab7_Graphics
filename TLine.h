#pragma once
#include "TPoint.h"
using namespace System::Drawing;

class TLine : public TPoint
{
protected:

	int x1;
	int y1;
public:
	TLine(int _x0, int _y0, int _x, int _y) :TPoint(_x0, _y0)
	{
		x1 = _x;
		y1 = _y;
		Visible = false;
	}
	virtual void Draw(Graphics ^g)
	{
		g->DrawLine(Pens::Black, x, y, x1, y1);
		Visible = true;
	}
	virtual void Hide(Graphics ^g)
	{
		g->DrawLine(Pens::White, x, y, x1, y1);
		Visible = false;
	}
	virtual void Move(Graphics ^g, int dx, int dy)
	{
		Hide(g);
		x += dx;
		x1 += dx;
		y += dy;
		y1 += dy;
		Draw(g);
	}
};