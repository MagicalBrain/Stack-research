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
//《王道》 3.1 栈 综合题 T3
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
			cout << "原序列合法！" << endl;
		else
			cout << "原序列不合法！" << endl;
	
	return true;
}

bool func04(LNodes* L)
//《王道》 3.1 栈 综合题 T4
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