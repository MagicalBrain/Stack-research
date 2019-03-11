#pragma once
#include <iostream>

using namespace std;

#define ElemType char

#define TRUE 1
#define FALSE 0

#define OK 1
#define ERROR 0
//#define OVERFLOW -1

typedef int Status;

typedef struct
{
	ElemType *elem;
	int top;
	int size;
	int increment;
}SqStack;