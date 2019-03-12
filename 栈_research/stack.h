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

typedef struct
{
	ElemType *elem;
	int top;
	int size;
	int increment;
}SqStack;


//��ʼ��ջ
Status InitStack_Sq(SqStack &S, int size, int inc)
{
	S.elem = (ElemType*)malloc(size * sizeof(ElemType));
	if (NULL == S.elem) return OVERFLOW;
	S.top = 0;
	S.size = size;
	S.increment = inc;
	return OK;
}


//�пպ���
Status StackBlanks(SqStack S)
{
	if (S.top == 0)
		return OK;
	else
		return ERROR;
}


//�ÿպ���
void ClearStack(SqStack &S)
{
	S.top = 0;
}


//����ջ
void DestoryStack(SqStack &S)
{
	free(S.elem);
}

//��ջ
Status pop(SqStack &S, ElemType &e)
{
	//�ж�ջ�Ƿ�Ϊ��
	if (S.top == 0) //���top����Ϊָ����Ϊ��S.top==S.elem��
		return ERROR;
	S.top -= 1;
	e = S.elem[S.top];
	return OK;
}


//��ջ
Status push(SqStack &S, ElemType e)
{
	//�ж�ջ�Ƿ�Ϊ��
	if (S.top >= S.size) //���top����Ϊָ����Ϊ��S.top-S.elem>=S.size��
	{
		S.elem = (ElemType*)realloc(S.elem,(S.size + S.increment) * sizeof(ElemType));
		if (S.elem == NULL)
			return OVERFLOW;
		S.top = S.size;
		S.size += S.increment;
	}
	S.elem[S.top] = e;
	S.top++;
	return OK;
}


//���ջ�����Ԫ��
void OutStack(SqStack S)
{
	ElemType e;
	//SqStack L = S;
	while (S.top)
	{
		pop(S,e);
		cout << e << " ";
	}
	cout << endl;
}


//�������ջ�����Ԫ��
void OutStack_Inv(SqStack S)
{
	SqStack S0;
	InitStack_Sq(S0, 10, 4);

	ElemType e;
	//SqStack L = S;

	while (S.top)
	{
		pop(S, e);
		push(S0, e);
	}

	while (S0.top)
	{
		pop(S0, e);
		cout << e << " ";
	}
	cout << endl;
}