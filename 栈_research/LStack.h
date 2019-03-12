#pragma once
#include <iostream>

using namespace std;

#define ElemType char

#define TRUE 1
#define FALSE 0

#define OK 1
#define ERROR 0
//#define OVERFLOW -1

typedef int Status;

//链栈结点定义
typedef struct LSNode
{
	int data;
	LSNode *next;
}LSNode;

//链栈定义
typedef struct
{
	LSNode *elem;
	LSNode *top; 
	int size;
}LStack;


//
Status InitLStack(LStack &L)
{
	L.elem = NULL;
	L.top = L.elem;
	L.size = 0;
	return OK;
}


//判空函数
Status isEmpty(LStack L)
{
	if (L.elem == NULL)
		return TRUE;
	else
		return FALSE;
}


//入栈
Status push(int e, LStack &L)
{
	if (isEmpty(L))
	{
		L.elem = (LSNode*)malloc(sizeof(LSNode));
		if (L.elem == NULL)
			return OVERFLOW;
		L.elem->data = e;
		L.elem->next = NULL;
		L.top = L.elem; 
		L.size++;
		return OK;
	}
	else
	{
		LSNode *p = L.top;
		
		LSNode *q = (LSNode*)malloc(sizeof(LSNode));
		if (q == NULL)
			return OVERFLOW;
		q->data = e;
		q->next = p->next;
		p->next = q;
		L.top = p->next;
		L.size++;
		return OK;
	}
}

//出栈
Status pop(int &x,LStack &L)
{
	if (isEmpty(L))
		return FALSE;

	LSNode *p = L.elem;
	while (p->next != L.top)
	{
		p = p->next;
	}
	LSNode*q = L.top;
	p->next = q->next;
	x = q->data;
	free(q);
	L.top = p;
	L.size--;
	return OK;
}


//链栈的销毁
