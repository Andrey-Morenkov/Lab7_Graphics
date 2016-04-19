#pragma once
#include "TPoint.h"
using namespace System::Drawing;

class TCircle : public TPoint
{
protected:
	int R;
public:
	TCircle(int _x, int _y, int _R) : TPoint(_x, _y)
	{
		R = _R;
		Visible = false;
	}
	virtual void Draw(Graphics ^g)
	{
		g->DrawEllipse(Pens::Black, x - R, y - R, 2 * R, 2 * R);
		Visible = true;
	}
	virtual void Hide(Graphics ^g)
	{
		g->DrawEllipse(Pens::White, x - R, y - R, 2 * R, 2 * R);
		Visible = false;
	}
	virtual void Move(Graphics ^g, int dx, int dy)
	{
		Hide(g);
		x += dx;
		y += dy;
		Draw(g);
	}
	virtual void Move(Graphics ^g, int dR)
	{
		Hide(g);
		R += dR;
		Draw(g);
	}
	virtual void Move(Graphics ^g, int dx, int dy, int dR)
	{
		Hide(g);
		x += dx;
		y += dy;
		R += dR;
		Draw(g);
	}
};