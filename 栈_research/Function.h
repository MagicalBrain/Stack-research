/*
*
*
*/
#pragma once
#include <iostream>
#include <string.h>
#include <stdio.h>
#include "StrError.h"
#include "LinkList.h"
#include "TemplateLinkList.h"
#include "TemplateStack.h"

using namespace std;



bool func03(char s1[9])
//�������� 3.1 ջ �ۺ��� T3
{
	//ElemType e;
	SqStack L;
	;
	int l = 0;
	
	InitStack_Sq(L,9,5);
	
		
		l = strlen(s1);
		puts(s1);

		for (int i = 0; i < l; i++)
		{
			if (s1[i] == 'I')
				push(L, s1[i]);

			if (s1[i] == 'O')
				pop(L, s1[i]);
		}
		if (isEmpty(L))
			cout << "ԭ���кϷ���" << endl;
		else
			cout << "ԭ���в��Ϸ���" << endl;
	
	return true;
}

bool func04(LNodes* L)
//�������� 3.1 ջ �ۺ��� T4
{
	LNodes *p, *q;

	if (L != NULL)
	{
		q = L;
		p = L->next;

		while (p)
		{
			if (p->data == q->data)
		}

		return true;
	}

	return false;
}