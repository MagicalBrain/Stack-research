#pragma once
#include <iostream>

using namespace std;

#define ElemType int
#define maxsize 100

typedef struct GStack
{
	ElemType stack[maxsize];
	int top1, top2;
}GStack;

bool GStack_Init(GStack *L)
{
	//L->stack = (GStack*)malloc(maxsize*sizeof(GStack));
	if (L == NULL)
	{
		return false;
	}
	L->top1 = 0, L->top2 = maxsize-1;
	return true;
}

bool func05_push(GStack *L, int s, ElemType x)
{
	if (L->top2 - L->top1 >= 1)
	{
		if (s)
		{
			L->stack[L->top2--] = x;
		}
		else
		{
			L->stack[L->top1++] = x;
		}
		return true;
	}
	return false;
}

bool func05_pop(GStack *L, int s, ElemType &x)
{
	if (s)
	{
		if (L->top2 == -1)
			return false;
		x = L->stack[L->top2++];
	}
	else
	{
		if (L->top1 == -1)
			return false;
		x = L->stack[L->top1--];
	}
	return true;
	//return false;
}