#include "TemplateStack.h"
#include <iostream>

using namespace std;

//���캯��
template<class Type>
Stack_T<Type>::Stack_T(int size, int inc)
{
	elem = (ElemType*)malloc(size * sizeof(ElemType));
	if (NULL == S.elem) return OVERFLOW;
	top = 0;
	size = size;
	increment = inc;
}

//�пպ���
template<class Type>
bool Stack_T<Type>::isEmpty() const
{
	return top == 0;
}

//��������
template<class Type>
bool Stack_T<Type>::isFull() const
{
	return top == MAX;
}

//���ջ
template<class Type>
bool Stack_T<Type>::ClearStack() const
{
	top = 0;
	return true;
}

//����ջ
template<class Type>
bool Stack_T<Type>::DestroyStack() const
{
	free(elem);
	return true;
}

//��ջ
template<class Type>
bool Stack_T<Type>::push(Type& item)
{
	if (top < size)
	{
		elem[top++] = item;
		return true;
	}
	else
		return false;
}

//��ջ�����ջ���ͷ���ռ�
template<class Type>
bool Stack_T<Type>::push_inc(Type& item)
{
	if (top >= size) //���top����Ϊָ����Ϊ��S.top-S.elem>=S.size��
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

//��ջ����
template<class Type>
bool Stack_T<Type>::pop(Type& item)
{
	if (top > 0)
	{
		item = elem[top--];
		return true;
	}
	else
		return false;
}

//���ջ�����к���
template<class Type>
void Stack_T<Type>::OutStack()
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