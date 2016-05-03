#pragma once
#include "TPoint.h"
using namespace System::Drawing;

class TRectangle : public TPoint
{
protected:

	int r;
	int h;
public:
	TRectangle(int _x0, int _y0, int _r, int _h) :TPoint(_x0, _y0)
	{
		r = _r;
		h = _h;
		Visible = false;
	}
	virtual void Draw(Graphics ^g)
	{
		g->DrawLine(Pens::Black, x - r, y + h, x + r, y + h);
		g->DrawLine(Pens::Black, x + r, y + h, x + r, y - h);
		g->DrawLine(Pens::Black, x + r, y - h, x - r, y - h);
		g->DrawLine(Pens::Black, x - r, y - h, x - r, y + h);
		Visible = true;
	}
	virtual void Hide(Graphics ^g)
	{
		g->DrawLine(Pens::White, x - r, y + h, x + r, y + h);
		g->DrawLine(Pens::White, x + r, y + h, x + r, y - h);
		g->DrawLine(Pens::White, x + r, y - h, x - r, y - h);
		g->DrawLine(Pens::White, x - r, y - h, x - r, y + h);
		Visible = false;
	}
	virtual void Move(Graphics ^g, int dx, int dy)
	{
		Hide(g);
		x += dx;
		y += dy;
		Draw(g);
	}
};