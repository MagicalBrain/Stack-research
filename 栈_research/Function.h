/*
*
*
*/
#pragma once
#pragma once
#include <iostream>
#include <string.h>
#include <stdio.h>
#include "StrError.h"

using namespace std;



bool func03()
//�������� ջ �ۺ��� T3
{
	//ElemType e;
	SqStack L;
	char s1[9];
	int l = 0;

	cin >> s1;
	
	InitStack_Sq(L,9,5);
	try
	{
		if (s1[8] != '\0')
		{
			Error err(-1, "�ַ������һλ������'\\0'!");
			throw (err);
			//exit(0);// return false;
		}
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