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

//��ջ��㶨��
typedef struct LSNode
{
	int data;
	LSNode *next;
}LSNode;

//��ջ����
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
	L.top = NULL;
	L.size = 0;
	return OK;
}


//�пպ���
Status isEmpty(LStack L)
{
	if (L.elem == NULL)
		return TRUE;
	else
		return FALSE;
}


//��ջ
Status push(int e, LStack &L)
{
	if (isEmpty(L))
	{
		L.elem = (LSNode*)malloc(sizeof(LSNode));
		if (L.elem == NULL)
			return OVERFLOW;
		L.elem->data = e;
		L.elem->next = NULL;
		L.top = L.elem->next; 
		L.size++;
		return OK;
	}
	else
	{
		LSNode *p = L.elem;
		while (p->next != L.top)
			p = p->next;
		LSNode *q = (LSNode*)malloc(sizeof(LSNode));
		if (q == NULL)
			return OVERFLOW;
		q->data = e;
		q->next = p->next;
		p->next = q;
		L.top = q->next;
		L.size++;
		return OK;
	}
}

//��ջ
Status pop(int &x,LStack &L)
{
	if (isEmpty(L))
		return FALSE;

	LSNode *p = L.elem;
	LSNode*q = p;
	while (p->next != L.top)
	{
		q = p;
		p = p->next;
	}
	q->next = L.top;
	//p->next = q->next;
	x = p->data;
	free(p);
	L.top = q->next;
	L.size--;
	return OK;
}


//��ջ������

//��ջ���������
void LStackoutput(LStack L)
{
	int x;
	while (L.size!=0)
	{
		pop(x, L);
		cout << x << endl;
	}
	
}
