#include <iostream>
#include "stack.h"
//#define _CRT_SECURE_NO_WARNINGS

using namespace std;


void LineEdit(SqStack &S)
{
	//构造空栈
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
				//置为空栈
				ClearStack(S);
				break;
			default:
				//有效字符进栈，未考虑栈满情形
				Push(S, ch);
				break;
			}
			ch = getchar();
		}
		//置S为空
		OutStack_Inv(S);
		ClearStack(S);
		if (ch != EOF)
			ch = getchar();
	}
	//销毁栈
	//DestoryStack(S);
}



int main()
{
	SqStack S;
	LineEdit(S);
	
	

	return 0;
}