#pragma once
#include <iostream>
#include <string.h>
#include <stdio.h>
#include "StrError.h"
#include "LinkList.h"
#include "stack.h"
#include "Function.h"

using namespace std;

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

void Testfunc04()
{
	ElemType a[10] = {};
	LNodes *L;
	L = LinkedListInit(0);

	LinkedInput(L, a[10], 10, 0);

}