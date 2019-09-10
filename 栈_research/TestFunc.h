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
#include "GStack.h"


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
//《王道》 3.1 栈 综合题 T3
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
			Error err(-1, "字符串最后一位必须是'\\0'!");
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
		cout << "发生了其他异常" << endl;
		exit(0);
	}

	return true;
}

/*
* 判断全部字符是否中心对称
*/
//template<class Type>
void Testfunc04()
//3.1 王道 T4
{
	int a[5] = {1,2,3,4,5};
	LNode_T<char> L(1);
	
	char* s = "xxyyxx";
	L.LinkedInput_T(s, 6, 1);
	L.LinkedOutput_T(1);

	if (func04(&L))
	{
		cout << "该字符串是中心对称的！" << endl;
		L.LinkedOutput_T(1);
	}
	else
		cout << "不是中心对称的！" << endl;
	//LinkedInput(L, a[10], 10, 0);

}

void Testfunc05()
{
	GStack* L;
	L = (GStack*)malloc(sizeof(GStack));
	GStack_Init(L);

	int a1[5] = {1,2,3,4,5};
	int a2[5] = { 10,12,13,14,15 };

	for (int i = 0; i < 5; i++)
	{
		func05_push(L, 1, a1[i]);
		func05_push(L, 0, a2[i]);
	}
}


void Testfunc06()
{
	char* str = "(asd[)]";
	//Stack_T<char> s(10, 5);

	if (func06(str))
	{
		cout << "括号匹配！" << endl;
	}
	else
	{
		cout << "括号不匹配！" << endl;
	}
}

void Testfunc07()
{
	//ElemType e;
	//SqStack L;
	
	int num;
	cout << "输入车厢数量：" << endl;
	cin >> num;
	char *s1 = (char*)malloc(num*sizeof(char));

	cout << "输入车厢序列：" << endl;
	cin >> s1;

	int l = 0;
	while (s1[l] != '\0')
	{
		l++;
	}

	//InitStack_Sq(L, 9, 5);
	try
	{
		if (l != num )
		{
			Error err(-1, "车厢序列输入错误!");
			throw (err);
			//exit(0);// return false;
		}
		//函数调用测试在这个位置：
		func07(s1);
	}
	catch (Error e)
	{
		e.showerror();
		exit(0);
	}
	catch (...)
	{
		cout << "发生了其他异常" << endl;
		exit(0);
	}

	//return true;
}

void Testfunc08()
{
	int x,n;
	cout << "输入x,n：" << endl;
	cin >> x >> n;

	int re;
	re = func08_D(x,n);
	cout << "结果是：" << re << endl;
	re = func08_Z(x, n);
	cout << "结果是：" << re << endl;
}