#pragma once
#include <iostream>

using namespace std;

//typedef unsigned long Item;

template<class Type>
class LNode_T
{
private:
	Type data;
	class LNode_T* next;
public:
	LNode_T(int tou);
	void copy(LNode_T p)
	{
		this->data = p->data;
		this->next = p->next;
	}
	void copy(LNode_T *p)
	{
		this->data = p->data;
		this->next = p->next;
	}
	//LNode_T*(int tou);
	int Length(int tou);
	//bool isEmpty() const;
	//bool isFull() const;
	int LocateElem(int tou, Type e);
	int GetElem(int tou, int loca);
	int LinkListInsert(int tou, Type e, int loca);
	void LinkListDelete(int tou, Type e);
	//bool pop(Type& item);
	bool LinkedOutput_T(int tou);
	void LinkedInput_T(Type a[], int length, int tou);
};
// LinkedList_T, LNode_T*;

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
		this->copy(NULL);// = NULL;//将next设置为NULL,初始长度为0的单链表   
	//return L;
}



template<class Type>
int LNode_T<Type>::Length(int tou)
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
int LNode_T<Type>::LocateElem(int tou, Type e)
{
	LNode_T* p;
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
int LNode_T<Type>::GetElem(int tou, int loca)
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
int LNode_T<Type>::LinkListInsert(int tou, Type e, int loca)
{
	LNode_T* p, * q;
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

//template<class Type>
//int LNode_T<Type>::LinkListInsert(int tou, Type e, int loca)
template<class Type>
void LNode_T<Type>::LinkListDelete(int tou, Type e)
{
	LNode_T* p, * q;
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


//给链表输入数据
////带头结点的
template<class Type>
void LNode_T<Type>::LinkedInput_T(Type a[], int length, int tou)
{
	/*参数:
	tou:
		1:初始化成带头结点的
		0：~不带头节点的
	*/
	if (tou)
	{

		LNode_T<Type>* q = this;
		for (int i = length - 1; i >= 0; --i)
		{
			LNode_T<Type> p0(1);
			LNode_T<Type>* p = new LNode_T<Type>(1);
			p->data = a[i];
			p->next = q->next;
			q->next = p;
		}
	}
	else
	{
		LNode_T<Type>* q = this;
		//q->data = a[0];
		for (int i = length - 1; i >= 0; --i)
		{
			LNode_T<Type> p0(1);
			LNode_T<Type>* p = new LNode_T<Type>(1);
			//LNodes* p = (LinkedList)malloc(sizeof(LNodes));
			p->data = a[i];
			p->next = this;
			this->copy(p);// = p;
		}
	}

}

template<class Type>
bool LNode_T<Type>::LinkedOutput_T(int tou)
{
	if (tou)
	{
		if (this->next != NULL)
		{
			//LNodes* p = L->next;
			LNode_T<Type>* p = new LNode_T<Type>(1);
			p = this->next;
			while (p != NULL)
			{
				cout << p->data << " ,";
				p = p->next;

			}
			cout << endl;
			return true;
		}
	}
	else
	{
		if (this != NULL)
		{
			LNode_T<Type>* p = new LNode_T<Type>(1);
			p = this->next;
			while (p != NULL)
			{
				cout << p->data << " ";
				p = p->next;
			}
			cout << endl;
			return 1;
		}
	}
	return false;
}