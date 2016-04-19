#pragma once
using namespace System::Drawing;

class TObject
{
protected:
	bool Visible;
public:
	virtual void Draw(Graphics ^g) = 0;
	virtual void Hide(Graphics ^g) = 0;
	virtual void Move(Graphics ^g, int dx, int dy) = 0;
};