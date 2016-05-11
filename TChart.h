#pragma once
#include <stdlib.h>
#include "TObject.h"
#include "TPoint.h"
#include "TStack.h"
#include <math.h>

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

	TObject* DrawRec(Graphics^ gr, TObject* t)
	{

		TChart* CurrLine;
		TPoint *pFp, *pLp;
		if (dynamic_cast<TPoint*>(t) != NULL)
			return t;
		else
		{
			CurrLine = dynamic_cast<TChart*>(t);
			pFp = dynamic_cast<TPoint*>(DrawRec(gr, CurrLine->GetFirst()));
			pLp = dynamic_cast<TPoint*>(DrawRec(gr, CurrLine->GetLast()));
			if (pFp&&pLp)
			{
				gr->DrawLine(Pens::Black, pFp->GetX(), pFp->GetY(), pLp->GetX(), pLp->GetY());
			}
		}
	}

	virtual void Draw(Graphics^ g)
	{
		
	}

	void AddClosestLine(int x1, int y1, int x2, int y2)
	{
		if (begin == NULL && end == NULL)
		{
			begin = new TPoint(x1, y1);
			end = new TPoint(x2, y2);
		}
		else
		{
			TStack<TObject*> stack1;
			TStack<TPoint*> stack2;
			TChart *curr = this;
			TObject *min1, *min2;
			TChart *min;
			int xmin, ymin;
			double difference = 0;
			double differencetmp = 0;


			stack1.Push(curr->begin);
			stack1.Push(curr->end);
			while (true)
			{
				if (dynamic_cast<TPoint*>(stack1.Top()) != NULL)
				{
					stack2.Push(dynamic_cast<TPoint*>(stack1.Pop()));
				}
				else
				{
					curr = dynamic_cast<TChart*>(stack1.Pop());
					stack1.Push(curr->begin);
					stack1.Push(curr->end);
				}
				if (stack1.IsEmpty())
					break;
			}//в stack2 лежат все точки с которыми надо сравнить

			min1 = stack2.Pop();
			int tmp = (dynamic_cast<TPoint*>(min1)->GetX() - x1)*(dynamic_cast<TPoint*>(min1)->GetX() - x1) + (dynamic_cast<TPoint*>(min1)->GetY() - y1)*(dynamic_cast<TPoint*>(min1)->GetY() - y1);
			difference = sqrt((float)tmp);
			while (!stack2.IsEmpty())
			{
				min2 = stack2.Pop();
				if ((differencetmp = sqrt((float)((dynamic_cast<TPoint*>(min2)->GetX() - x1)*(dynamic_cast<TPoint*>(min2)->GetX() - x1) +
					(dynamic_cast<TPoint*>(min2)->GetY() - y1)*(dynamic_cast<TPoint*>(min2)->GetY() - y1)))) < difference)
				{
					min1 = min2;
					difference = differencetmp;
				}
			}//теперь в min1 лежит точка с наименьшим отклонением
			xmin = dynamic_cast<TPoint*>(min1)->GetX();
			ymin = dynamic_cast<TPoint*>(min1)->GetY();
			delete min1;
			min1 = new TChart();
			dynamic_cast<TChart*>(min1)->begin = new TPoint(xmin, ymin);
			dynamic_cast<TChart*>(min1)->end = new TPoint(x2, y2);
		}
	}
				
};