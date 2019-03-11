#include <iostream>
#include "stack.h"
//#define _CRT_SECURE_NO_WARNINGS

using namespace std;


void LineEdit(SqStack &S)
{
	//�����ջ
	InitStack_Sq(S,10,4);

	char ch = getchar();

	while (ch != EOF)
	{
		while (ch != EOF && ch != '\n')
		{
			switch (ch)
			{
			case '#':
				Pop(S, ch);
				break;
			case '@':
				//��Ϊ��ջ
				ClearStack(S);
				break;
			default:
				//��Ч�ַ���ջ��δ����ջ������
				Push(S, ch);
				break;
			}
			ch = getchar();
		}
		//��SΪ��
		OutStack_Inv(S);
		ClearStack(S);
		if (ch != EOF)
			ch = getchar();
	}
	//����ջ
	//DestoryStack(S);
}



int main()
{
	SqStack S;
	LineEdit(S);
	
	

	return 0;
}