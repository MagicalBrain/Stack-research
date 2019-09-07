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
	bool ClearStack() const;
	bool DestroyStack() const;
	bool push(Type&item);
	bool push_inc(Type&item);
	bool pop(Type&item);
	void OutStack();
};

