#pragma once
#include <iostream>

using namespace std;

typedef unsigned long Item;

template<class Type>
class Stack_T
{
private:
	enum { MAX = 10 };
	//Type elem[MAX];
	Type *elem;
	int top;
	int size;
	int increment;
public:
	Stack_T(int size, int inc);
	bool isEmpty() const;
	bool isFull() const;
	Type GetTop()
	{
		return elem[top-1];
	}
	bool ClearStack() const;
	bool DestroyStack() const;
	bool push(Type&item);
	bool push_inc(Type&item);
	bool pop(Type&item);
	void OutStack();
};

//构造函数
template<class Type>
Stack_T<Type>::Stack_T(int s, int inc)
{
	elem = (Type*)malloc(s * sizeof(Type));
	if (NULL == elem) return ;
	top = 0;
	size = s;
	increment = inc;
}

//判空函数
template<class Type>
bool Stack_T<Type>::isEmpty() const
{
	return top == 0;
}

//判满函数
template<class Type>
bool Stack_T<Type>::isFull() const
{
	return top == MAX;
}

//清空栈
template<class Type>
bool Stack_T<Type>::ClearStack() const
{
	top = 0;
	return true;
}

//销毁栈
template<class Type>
bool Stack_T<Type>::DestroyStack() const
{
	free(elem);
	return true;
}

//进栈
template<class Type>
bool Stack_T<Type>::push(Type& item)
{
	if (top < size || top == 0)
	{
		elem[top++] = item;
		return true;
	}
	else
		return false;
}

//进栈，如果栈满就分配空间
template<class Type>
bool Stack_T<Type>::push_inc(Type& item)
{
	if (top >= size) //如果top变量为指针则为（S.top-S.elem>=S.size）
	{
		elem = (Type*)realloc(elem, (size + increment) * sizeof(Type));
		if (elem == NULL)
			return OVERFLOW;
		top = size;
		size += increment;
	}
	elem[top++] = item;
	return true;
}

//出栈函数
template<class Type>
bool Stack_T<Type>::pop(Type& item)
{
	if (top > 0)
	{
		item = elem[--top];
		return true;
	}
	else
		return false;
}

//输出栈内所有函数
template<class Type>
void Stack_T<Type>::OutStack()
{
	Type e;
	//SqStack L = S;
	while (top)
	{
		pop(e);
		cout << e << " ,";
	}
	cout << endl;
}

//#endif