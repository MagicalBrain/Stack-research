#pragma once
#include <iostream>
//#include "LinkList.h"
#include <time.h>
#include <windows.h>
#include "Strerror.h"

using namespace std;

/*
CreatFunction.h:
ֻ�Ÿ������Ժ���
���������Ե������һЩ�������������������������ʲô��
*/

//
int Randtou()
{
	srand((unsigned int)time(0));
	int re = rand();
	//re = re % 10;
	re = (re+1) % 2;
	return re;
}

int Randnum(int n)
{
	srand((unsigned int)time(0));
	int re = rand();
	re = re % n;
	return re;
}

//����������к���
int* CreatRand(int x)
/*
x:1������0������
��������n������n�����Ԫ�ص�����
*/
{
	int* p;
	cout << "����������ĸ���" << endl;
	int n, len, tmp;
	cin >> n;
	cout << "����������Ĵ�С��Χ��" << endl;
	cin >> len;

	p = (int*)malloc((n + 1) * sizeof(int));
	p[0] = n;

	cout << endl << "���ɵ��������" << endl;
	srand((unsigned int)time(0));
	for (int i = 1; i < n + 1; i++)
	{
		int re = rand();
		p[i] = re % len;
		cout << p[i] << " ";
	}
	cout << endl;

	if (x == 1)
	{
		for (int j = 1; j < p[0] + 1; j++)
		{
			for (int i = 1; i < p[0]; i++)
			{
				if (p[i] > p[i + 1])
				{
					tmp = p[i];
					p[i] = p[i + 1];
					p[i + 1] = tmp;
				}
			}
		}
		for (int i = 1; i <= p[0]; i++)
		{
			cout << p[i] << " ";
		}
		cout << endl;
	}

	return p;
}

int* CreatRand(int n, int x)
/*
x:1������0������
��������n������n�����Ԫ�ص�����
*/
{
	int* p;
	//cout << "����������ĸ���" << endl;
	int len, tmp;
	//cin >> n;
	cout << "����������Ĵ�С��Χ��" << endl;
	cin >> len;

	p = (int*)malloc((n + 1) * sizeof(int));
	p[0] = n;

	cout << endl << "���ɵ��������" << endl;
	srand((unsigned int)time(0));
	for (int i = 1; i < n + 1; i++)
	{
		int re = rand();
		p[i] = re % len;
		cout << p[i] << " ";
	}
	cout << endl;

	if (x == 1)
	{
		for (int j = 1; j < p[0] + 1; j++)
		{
			for (int i = 1; i < p[0]; i++)
			{
				if (p[i] > p[i + 1])
				{
					tmp = p[i];
					p[i] = p[i + 1];
					p[i + 1] = tmp;
				}
			}
		}
		for (int i = 1; i <= p[0]; i++)
		{
			cout << p[i] << " ";
		}
		cout << endl;
	}

	return p;
}

int* CreatRand(int n, int len, int x)
/*
x:1������0������
��������n������n�����Ԫ�ص�����
*/
{
	int* p;
	//cout << "����������ĸ���" << endl;
	int tmp;
	//cin >> n;
	//cout << "����������Ĵ�С��Χ��" << endl;
	//cin >> len;

	p = (int*)malloc((n + 1) * sizeof(int));
	p[0] = n;

	cout << endl << "���ɵ��������" << endl;
	srand((unsigned int)time(0));
	for (int i = 1; i < n + 1; i++)
	{
		int re = rand();
		p[i] = re % len;
		cout << p[i] << " ";
	}
	cout << endl;

	if (x == 1)
	{
		for (int j = 1; j < p[0] + 1; j++)
		{
			for (int i = 1; i < p[0]; i++)
			{
				if (p[i] > p[i + 1])
				{
					tmp = p[i];
					p[i] = p[i + 1];
					p[i + 1] = tmp;
				}
			}
		}
		for (int i = 1; i <= p[0]; i++)
		{
			cout << p[i] << " ";
		}
		cout << endl;
	}

	return p;
}