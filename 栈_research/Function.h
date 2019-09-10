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

bool func06(char* str)
//《王道》 3.3 T1
{
	Stack_T<char> s(10,5);

	if (str == NULL)
		return false;
	int t = 0;
	char c;
	while (str[t] != '\0')
	{
		switch (str[t])
		{
		case '(':
		case '[':
		case '{':
			s.push(str[t]);
			break;
		case ')':
			if ('(' == s.GetTop())
				s.pop(c);
			break;
		case ']':
			if ('[' == s.GetTop())
				s.pop(c);
			break;
		case '}':
			if ('{' == s.GetTop())
				s.pop(c);
			break;
		default:
			break;
		}
		t++;
	}

	if (s.isEmpty())
		return true;
	else
		return false;

}

bool func07(char* q)
// 《王道》 3.3 T2
{
	if (NULL == q)
		return false;

	Stack_T<char> s(10, 5);
	//Stack_T<char> re(10, 5);

	int n = 0;
	char t;

	try
	{
		while (q[n] != '\0')
		{
			if (q[n] != 'H' && q[n] != 'S')
			{
				Error err(-1, "输入字符串中有非法字符");
				throw(err);
			}

			switch (q[n])
			{
			case 'H':
				s.push_inc(q[n]);
				break;
			case 'S':
				cout << q[n] << ", ";
				break;
			default:
				break;
			}
			
			n++;
		}

		while (s.pop(t))
		{
			cout << t << ", ";
		}
		cout << endl;
	}
	catch (Error e)
	{
		e.showerror();
		exit(0);
	}
	return true;
}

int func08_D(int x,int n)
{
	if (n == 0)
		return 1;
	if (n == 1)
		return 2 * x;
	if (n > 1)
	{
		return 2 * x * func08_D(x, n - 1) - 2 * (n - 1) * func08_D(x, n - 2);
	}
}

int func08_Z(double x, int n)
{
	struct func
	{
		int num;
		double px;
	}Sfunc[100];

	//Sfunc s = {};

	int top = -1;
	double p2 = 2 * x, p1 = 1;

	for (int i = n; i >= 2; i--)
	{
		//top++;
		Sfunc[++top].num = i;
	}

	while (top>=0)
	{
		Sfunc[top].px = 2 * x * p2 - 2 * (Sfunc[top].num - 1) * p1;
		p1 = p2;
		p2 = Sfunc[top].px;
		top--;
	}
	if (n == 0)
		return p1;
	return p2;
}