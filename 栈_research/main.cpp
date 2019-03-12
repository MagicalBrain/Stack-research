#include <iostream>
#include "stack.h"
#include "LStack.h"
//#define _CRT_SECURE_NO_WARNINGS

using namespace std;




int main()
{
	//SqStack S;
	//LineEdit(S);

	int in[] = {1,2,3,4,5};
	
	LStack L;
	InitLStack(L);

	for (int i = 0; i < 5; i++)
	{
		push(in[i], L);
	}

	return 0;
}