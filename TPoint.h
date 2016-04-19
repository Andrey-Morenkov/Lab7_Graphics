#pragma once
#include "TObject.h"
using namespace System::Drawing;

class TPoint : public TObject
{
protected:
	int x;
	int y;
public:
	TPoint(int _x, int _y)
	{
		x = _x;
		y = _y;
		Visible = false;
	}
	virtual void Draw(Graphics ^g)
	{
		g->DrawEllipse(Pens::Black, x - 1, y - 1, 3, 3);
		Visible = true;
	}
	virtual void Hide(Graphics ^g)
	{
		g->DrawEllipse(Pens::White, x - 1, y - 1, 3, 3);
		Visible = false;
	}
	virtual void Move(Graphics ^g, int dx, int dy)
	{
		Hide(g);
		x += dx;
		y += dy;
		Draw(g);
	}
	int GetX()
	{
		return x;
	}
	int GetY()
	{
		return y;
	}

};