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


bool func04(LNode_T<char>* L)
//《王道》 3.1 栈 综合题 T4
{
	char t;
	LNode_T<char> *p = new LNode_T<char>(1);
	LNode_T<char>* q = new LNode_T<char>(1);

	Stack_T<char>* S = new Stack_T<char>(10, 5);

	if (L->isEmpty() == false)
	{
		q = L->GetNext();
		//q->copy()
		//p = q->GetNext();
		t = q->GetData();
		S->push_inc(t);
		q = q->GetNext();

		while (q)
		{
			//p = q->GetNext();

			if (q->GetData() != S->GetTop())
			{
				t = q->GetData();
				S->push_inc(t);
			}
			else if (q->GetData() == S->GetTop())
			{
				
				S->pop(t);
			}

			q = q->GetNext();
		}

		if (S->isEmpty())
			return true;
	}

	return false;
}

bool func05()
{
	return false;
}