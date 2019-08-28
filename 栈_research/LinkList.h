#pragma once
#include <iostream>
#include <string.h>
#include "CreatFunction.h"

using namespace std;

#define ElemType char

typedef struct LNodes
{
	ElemType data;
	struct LNodes *next;
} LNodes, *LinkedList;

//����������

////1����ʼ������
LinkedList LinkedListInit(int tou) {
	/*����:
	tou:
	1:��ʼ���ɴ�ͷ����
	0��~����ͷ�ڵ��
	*/
	LinkedList L;
	L = (LinkedList)malloc(sizeof(LNodes));   //������ռ�   
	if (L == NULL) { //�ж��Ƿ����㹻���ڴ�ռ�   
		printf("�����ڴ�ռ�ʧ��\n");
	}
	if (tou)
	{
		L->data = -1;
		L->next = NULL;
	}
	//��next����ΪNULL,��ʼ����Ϊ0�ĵ�����
	else
		L = NULL;//��next����ΪNULL,��ʼ����Ϊ0�ĵ�����   
	return L;
}

////2�����
int Length(LNodes* L,int tou)
{
	LNodes* p;
	int re = 0;
	if (tou)
	{
		if (L->next == NULL)
			return 0;
		else
		{
			p = L->next;
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
		if (L == NULL)
			return 0;
		else
		{
			p = L;
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

////3����ֵ����
int LocateElem(LNodes* L, int tou,int e)
{
	LNodes* p;
	int num = 0;
	switch (tou)
	{
	case 1:
		if (L->next != NULL)
		{
			p = L->next;
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
		if (L != NULL)
		{
			p = L;
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


////4������Ų���
int GetElem(LNodes* L, int tou, int loca)
{
	LNodes* p;
	int num = 0;
	if (loca < 0)
	{
		return -1;
	}
	if (tou == 1)
	{
		if (L->next != NULL)
		{
			p = L->next;
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
		if (L != NULL)
		{
			p = L;
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

////5���������
int LinkListInsert(LNodes* L, int tou, int e, int loca)
{
	LNodes* p, * q;
	int num = 0;
	if (loca < 0)
	{
		return -1;
	}
	if (tou == 1)
	{
		if (L->next != NULL)
		{
			p = L->next;

			if (loca == 0)
			{
				q = (LNodes*)malloc(sizeof(LNodes));
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
					q = (LNodes*)malloc(sizeof(LNodes));
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
		if (L != NULL)
		{
			p = L;

			if (loca == 0)
			{
				q = (LNodes*)malloc(sizeof(LNodes));
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
					q = (LNodes*)malloc(sizeof(LNodes));
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

////6��ɾ������
LNodes* LinkListDelete(LNodes* L, int tou, int e)
{
	LNodes* p, * q;
	int num = 0, l = Length(L, tou);
	
	if (tou == 1)
	{
		if (L->next != NULL)
		{
			p = L->next;
			q = L;
			while (p)
			{
				if (p->data == e)
				{
					q->next = p->next;
					free(p);
					return L;
				}
				num++;
				p = p->next;
				q = q->next;
			}

		}
	}
	else if (tou == 0)
	{
		if (L != NULL)
		{
			q = L;
			p = L->next;
			if (L->data == e)
			{
				L = L->next;
				free(q);
				return L;
			}
			while (p)
			{
				if (p->data == e)
				{
					q->next = p->next;
					free(p);
					//L = q;
					//break;
					return L;
				}
				num++;
				p = p->next;
				q = q->next;
			}

		}
	}
	return NULL;
}


LNodes* LinkListDelete(LNodes* L, int tou, int loca, int* e)
{
	LNodes* p, * q;
	int num = 0, l=Length(L,tou);
	if (loca < 0 || loca >= l)
	{
		return 0;
	}
	if (tou == 1)
	{
		if (L->next != NULL)
		{
			p = L->next;

			while (p)
			{
				if (num == loca)
				{
					q = p;
					p = p->next;
					*e = q->data;
					free(q);
					break;
					//return e;
				}
				num++;
				p = p->next;
			}
			
		}
	}
	else if (tou == 0)
	{
		if (L != NULL)
		{
			p = L;
			if (loca > 0)
			{
				while (p)
				{
					if (num == loca)
					{
						q = p;
						p = p->next;
						*e = q->data;
						free(q);
						break;
						//return e;
					}
					num++;
					p = p->next;
				}
			}
			else
			{
				q = p;
				L = p->next;
				L->next = p->next->next;
				*e = q->data;
				free(q);
				//return e;
			}
			
		}
	}
	return L;
}

////7���������
//�������������Ԫ�ص�����
int LinkedOutput(LinkedList L, int tou)
{
	//put(str);
	if (tou)
	{
		if (L->next!=NULL)
		{
			LNodes* p = L->next;
			while (p != NULL)
			{
				cout << p->data << " ,";
				p = p->next;

			}
			cout << endl;
			return 1;
		}
		
	}
	else
	{
		if (L!=NULL)
		{
			LNodes* p = L;
			while (p != NULL)
			{
				cout << p->data << " ";
				p = p->next;
			}
			cout << endl;
			return 1;
		}
		
	}

	cout << "���ʧ�ܣ���Ϊ�գ�" << endl;
	return 0;
}

////8���пղ���
int isEmpty(LNodes* L, int tou)
{
	if (tou)
	{
		if (L->next == NULL)
			return 1;
		else
			return 0;
	}
	else
	{
		if (L == NULL)
			return 1;
		else
			return 0;
	}
	return 0;
}

////9�����ٲ���
LNodes* LinkListDestroy(LNodes* L,int tou)
{
	LNodes* p, *q;
	if (tou==1)
	{
		if (L->next != NULL)
		{
			p = L->next;
			while (p)
			{
				q = p;
				p = p->next;
				
				free(q);
			}
			L->next = NULL;
			return L;
		}
	}
	else if (tou==0)
	{
		if (L != NULL)
		{
			p = L;
			while (p)
			{
				q = p;
				p = p->next;
				free(q);
			}
			L = NULL;
			return L;
		}
	}
	return NULL;
}


//��������������
////��ͷ����
void LinkedInput(LinkedList &L, ElemType a[], int length,int tou) {
	/*����:
	tou: 
		1:��ʼ���ɴ�ͷ����
		0��~����ͷ�ڵ��
	*/
	if (tou)
	{
		LinkedList q = L;
		for (int i = length - 1; i >= 0; --i)
		{
			LNodes* p = (LinkedList)malloc(sizeof(LNodes));
			p->data = a[i];
			p->next = q->next;
			q->next = p;
		}
	}
	else
	{
		LinkedList q = L;
		//q->data = a[0];
		for (int i = length - 1; i >= 0; --i)
		{
			LNodes* p = (LinkedList)malloc(sizeof(LNodes));
			p->data = a[i];
			p->next = L;
			L = p;
		}
	}
	
}


void LinkedInput(LinkedList& L, int tou) {
	/*����:
	tou:
		1:��ʼ���ɴ�ͷ����
		0��~����ͷ�ڵ��
	*/
	int* a;
	a = CreatRand(0);
	int length = a[0];
	if (tou)
	{
		LinkedList q = L;
		for (int i = length; i > 0; --i)
		{
			LNodes* p = (LinkedList)malloc(sizeof(LNodes));
			p->data = a[i];
			p->next = q->next;
			q->next = p;
		}
	}
	else
	{
		LinkedList q = L;
		//q->data = a[0];
		for (int i = length; i > 0; --i)
		{
			LNodes* p = (LinkedList)malloc(sizeof(LNodes));
			p->data = a[i];
			p->next = L;
			L = p;
		}
	}

}

void LinkedInput(LinkedList& L, int tou,int x) {
	/*����:
	tou:
		1:��ʼ���ɴ�ͷ����
		0��~����ͷ�ڵ��
	*/
	int* a;
	switch (x)
	{
	case 1:
		a = CreatRand(1);
		break;
	default:
		a = CreatRand(0);
		break;
	}
	
	int length = a[0];
	if (tou)
	{
		LinkedList q = L;
		for (int i = length; i > 0; --i)
		{
			LNodes* p = (LinkedList)malloc(sizeof(LNodes));
			p->data = a[i];
			p->next = q->next;
			q->next = p;
		}
	}
	else
	{
		LinkedList q = L;
		//q->data = a[0];
		for (int i = length; i > 0; --i)
		{
			LNodes* p = (LinkedList)malloc(sizeof(LNodes));
			p->data = a[i];
			p->next = L;
			L = p;
		}
	}

}

