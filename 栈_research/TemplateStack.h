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
	Stack();
	bool isEmpty() const;
	bool isFull() const;
	bool ClearStack() const;
	bool DestroyStack() const;
	bool push(Type&item);
	bool push_inc(Type&item);
	bool pop(Type&item);
	void OutStack();
};

template<class Type>
Stack_T<Type>::Stack(int size, int inc)
{
	elem = (ElemType*)malloc(size * sizeof(ElemType));
	if (NULL == S.elem) return OVERFLOW; 
	top = 0;
	size = size;
	increment = inc;
}

template<class Type>
Stack_T<Type>::isEmpty()
{
	return top == 0;
}

template<class Type>
Stack_T<Type>::isFull()
{
	return top == MAX;
}

template<class Type>
Stack_T<Type>::ClearStack()
{
	top = 0;
	return true;
}

template<class Type>
Stack_T<Type>::DestroyStack() const
{
	free(elem);
	return true;
}

template<class Type>
Stack_T<Type>::push(const Type& item)
{
	if (top < size)
	{
		elem[top++] = item;
		return true;
	}
	else
		return false;
}

template<class Type>
Stack_T<Type>::push_inc(const Type& item)
{
	if (top >= size) //如果top变量为指针则为（S.top-S.elem>=S.size）
	{
		elem = (ElemType*)realloc(elem, (size + increment) * sizeof(ElemType));
		if (elem == NULL)
			return OVERFLOW;
		top = size;
		size += increment;
	}
	elem[top++] = item;
	return true;
}

template<class Type>
Stack_T<Type>::pop(const Type& item)
{
	if (top > 0)
	{
		item = elem[top--];
		return true;
	}
	else
		return false;
}

template<class Type>
Stack_T<Type>::OutStack()
{
	Type e;
	//SqStack L = S;
	while (top)
	{
		pop(e);
		cout << e << " ";
	}
	cout << endl;
}

//#endif