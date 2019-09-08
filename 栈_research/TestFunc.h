#pragma once
#include <iostream>
#include <string.h>
#include <stdio.h>
#include "StrError.h"
#include "LinkList.h"
#include "stack.h"
#include "Function.h"
#include "TemplateStack.h"
#include "TemplateLinkList.h"


using namespace std;

void TestfuncTemplateLink()
{
	int a[5] = { 1,2,3,4,5 };
	LNode_T<int> L(1);
	//L = LinkedListInit(0);
	L.LinkedInput_T(a, 5, 1);
	L.LinkedOutput_T(1);
}

void TestfuncTemplateStack()
{
	int a[5] = { 1,2,3,4,5 };
	Stack_T<int> L(10, 5);

	for (int i = 0; i < 5; i++)
	{
		L.push(a[i]);
	}
	
	L.OutStack();
}

bool Testfunc03()
//�������� 3.1 ջ �ۺ��� T3
{
	//ElemType e;
	SqStack L;
	char s1[9];
	//int l = 0;

	cin >> s1;

	InitStack_Sq(L, 9, 5);
	try
	{
		if (s1[8] != '\0')
		{
			Error err(-1, "�ַ������һλ������'\\0'!");
			throw (err);
			//exit(0);// return false;
		}
		func03(s1);
	}
	catch (Error e)
	{
		e.showerror();
		exit(0);
	}
	catch (...)
	{
		cout << "�����������쳣" << endl;
		exit(0);
	}

	return true;
}

/*
* �ж�ȫ���ַ��Ƿ����ĶԳ�
*/
//template<class Type>
void Testfunc04()
//3.1 ���� T4
{
	int a[5] = {1,2,3,4,5};
	LNode_T<char> L(1);
	
	char* s = "xxyyxx";
	L.LinkedInput_T(s, 6, 1);
	L.LinkedOutput_T(1);

	if (func04(&L))
	{
		cout << "���ַ��������ĶԳƵģ�" << endl;
		L.LinkedOutput_T(1);
	}
	else
		cout << "�������ĶԳƵģ�" << endl;
	//LinkedInput(L, a[10], 10, 0);

}

void Testfunc05()
{

}
