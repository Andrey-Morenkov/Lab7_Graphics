#pragma once
#include <stdlib.h>
#include "TObject.h"
#include "TPoint.h"
#include "TStack.h"

#define pfp pFirstPoint;
#define plp pLastPoint;


class TChart :public TObject
{
protected:
	TObject* begin;
	TObject* end;
	struct  TChartLine
	{
		TChart* pLine;
		TPoint* pFirstPoint;
		TPoint* pLastPoint;
	};
public:
	TChart()
	{
		begin = NULL;
		end = NULL;
	}
	TObject *GetFirst()
	{
		return begin;
	}
	TObject *GetLast()
	{
		return end;
	}
	void SetFirst(TObject *p)
	{
		begin = p;
	}
	void SetLast(TObject *p)
	{
		end = p;
	}
	virtual void Hide(Graphics ^g)
	{}
	virtual void Move(Graphics ^g, int dx, int dy)
	{}
	virtual void Draw(Graphics^ gr)
	{
		TChartLine CurrLine;
		TStack<TChartLine> st;
		TObject* t;
		TPoint* q;

		st.Clear();
		CurrLine.pLine = this;
		CurrLine.pFirstPoint = NULL;
		CurrLine.pLastPoint = NULL;
		st.Push(CurrLine);

		while (!st.IsEmpty())
		{
			CurrLine = st.Pop();
			while (CurrLine.pFirstPoint == NULL)
			{
				t = this->GetFirst();
				q = dynamic_cast<TPoint*>(t);
				if (q != NULL)
				{
					CurrLine.pFirstPoint = q;
					//q->Draw(Lab7_Graphics::MyForm::g);
					// отрисовка точки
				}
				else
				{
					st.Push(CurrLine);
					CurrLine.pLine = dynamic_cast<TChart*>(t);
				}
			}

			if (CurrLine.pLastPoint == NULL)
			{
				t = this->GetLast();
				q = dynamic_cast<TPoint*>(t);
				if (q != NULL)
				{
					CurrLine.pLastPoint = q;
					//q->Draw(Lab7_Graphics::MyForm::g);                           // отрисовка точки
				}
				else
				{
					st.Push(CurrLine);
					CurrLine.pLine = dynamic_cast<TChart*>(t);
					CurrLine.pFirstPoint = NULL;
					st.Push(CurrLine);
				}
			}


			if ((CurrLine.pFirstPoint != NULL) && (CurrLine.pLastPoint != NULL))
			{
				gr->DrawLine(Pens::Black, CurrLine.pFirstPoint->GetX(), CurrLine.pFirstPoint->GetY(), CurrLine.pLastPoint->GetX(), CurrLine.pLastPoint->GetY());


				if (!st.IsEmpty())
				{
					q = CurrLine.pLastPoint;
					CurrLine = st.Pop();

					if (CurrLine.pFirstPoint == NULL)
					{
						CurrLine.pFirstPoint = q;
					}
					else
					{
						CurrLine.pLastPoint = q;
					}
					st.Push(CurrLine);
				}
			}
		}
	}
				
};