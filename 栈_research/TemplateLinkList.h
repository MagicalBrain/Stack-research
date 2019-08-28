#pragma once
#include <iostream>

using namespace std;

typedef unsigned long Item;

template<class Type>
class LNode_T
{
private:
	Type data;
	class LNodes_T *next;
public:
	LNode_T(int tou);
	int Length(int tou);
	//bool isEmpty() const;
	//bool isFull() const;
	int LocateElem(int tou, Type e);
	int GetElem(int tou, int loca);
	int LinkListInsert(int tou, Type e, int loca);
	LinkListDelete(int tou, Type e);
	bool pop(Type&item);
	void OutStack();
};

template<class Type>
LNode_T<Type>::LNode_T(int tou)
{
	if (tou)
	{
		data = -1;
		next = NULL;
	}
	//将next设置为NULL,初始长度为0的单链表
	else
		this = NULL;//将next设置为NULL,初始长度为0的单链表   
	//return L;
}

template<class Type>
LNode_T<Type>::Length(int tou)
{
	LNode_T* p;
	int re = 0;
	if (tou)
	{
		if (next == NULL)
			return 0;
		else
		{
			p = this->next;
			while (p)
			{
				re++;
				p = p->next;
			}

			return re;
		}
	}
	else
	{
		if (this == NULL)
			return 0;
		else
		{
			p = this;
			while (p)
			{
				re++;
				p = p->next;
			}
			return re;
		}
	}
	return 0;
}

template<class Type>
LNode_T<Type>::LocateElem(int tou, Type e)
{
	LNode_T * p;
	int num = 0;
	switch (tou)
	{
	case 1:
		if (next != NULL)
		{
			p = next;
			while (p)
			{
				if (p->data == e)
				{
					return num;
				}
				p = p->next;
				num++;
			}
		}
		break;
	case 0:
		if (this != NULL)
		{
			p = this;
			while (p)
			{
				if (p->data == e)
				{
					return num;
				}
				p = p->next;
				num++;
			}
		}
		break;
	default:
		break;
	}

	return -1;
}

template<class Type>
LNode_T<Type>::GetElem(int tou, int loca)
{
	LNode_T* p;
	int num = 0;
	if (loca < 0)
	{
		return -1;
	}
	if (tou == 1)
	{
		if (next != NULL)
		{
			p = this->next;
			while (p)
			{
				if (num == loca)
					return p->data;
				num++;
				p = p->next;
			}
		}
	}
	else if (tou == 0)
	{
		if (this != NULL)
		{
			p = this;
			while (p)
			{
				if (num == loca)
					return p->data;
				num++;
				p = p->next;
			}
		}
	}
	return -1;
}

template<class Type>
LNode_T<Type>::LinkListInsert(int tou, Type e, int loca)
{
	LNode_T* p, *q;
	int num = 0;
	if (loca < 0)
	{
		return -1;
	}
	if (tou == 1)
	{
		if (next != NULL)
		{
			p = next;

			if (loca == 0)
			{
				q = (LNode_T*)malloc(sizeof(LNode_T));
				q->data = e;

				q->next = p->next;
				p->next = q;

				int t;
				t = q->data;
				q->data = p->data;
				p->data = t;
				return 1;
			}

			while (p)
			{
				num++;
				if (num == loca)
				{
					q = (LNode_T*)malloc(sizeof(LNode_T));
					q->data = e;

					q->next = p->next;
					p->next = q;
					return 1;
				}

				p = p->next;
			}
		}
	}
	else if (tou == 0)
	{
		if (this != NULL)
		{
			p = this;

			if (loca == 0)
			{
				q = (LNode_T*)malloc(sizeof(LNode_T));
				q->data = e;

				q->next = p->next;
				p->next = q;

				int t;
				t = q->data;
				q->data = p->data;
				p->data = t;
				return 1;
			}

			while (p)
			{
				num++;
				if (num == loca)
				{
					q = (LNode_T*)malloc(sizeof(LNode_T));
					q->data = e;

					q->next = p->next;
					p->next = q;
					return 1;
				}
				p = p->next;
			}
		}
	}
	return 0;
}

template<class Type>
LNode_T<Type>::LinkListDelete(int tou, Type e)
{
	LNode_T *p, *q;
	int num = 0, l = this->Length(tou);

	if (tou == 1)
	{
		if (this->next != NULL)
		{
			p = this->next;
			q = this;
			while (p)
			{
				if (p->data == e)
				{
					q->next = p->next;
					free(p);
					//return L;
				}
				num++;
				p = p->next;
				q = q->next;
			}

		}
	}
	else if (tou == 0)
	{
		if (this != NULL)
		{
			q = this;
			p = this->next;
			if (this->data == e)
			{
				this = this->next;
				free(q);
				//return L;
			}
			while (p)
			{
				if (p->data == e)
				{
					q->next = p->next;
					free(p);
					
				}
				num++;
				p = p->next;
				q = q->next;
			}

		}
	}
}