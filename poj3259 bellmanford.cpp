/********************************************************************
AZmaple	3259	Accepted	228K	1563MS
���⣺ũ�� FJ �� N ����ء���� 1...n�� (1<=N<=500)
��ؼ��� M ��·�� ��˫��(1<= M <= 2500)
ͬʱ�� W ���׶�,���Իص���ǰ��һ��ʱ��㡾����(1<= W <=200)
�ʣ�FJ �Ƿ����������������ǰ���Լ�
�㷨��bellman_ford �ж��Ƿ��и���
˼·����ؼ��˫��·���ӱ�,ȨֵΪ��
�׶���ĵ���·���ӱ�,ȨֵΪ�������Իص���ǰ��
�ж�����ͼ�Ƿ���ڸ���
��Ϊ��������˸�����,ʱ��ͻ᲻ͣ�ļ���,
��ô FJ �Ϳ��Իص���ǰ��Զ�ĵط�,�϶���������ǰ���Լ���
*******************************************************************/

#include"stdafx.h"
#include<iostream>
#include<algorithm>
using namespace std;
#define inf 100100
//Each of FJ's farms comprises N (1 �� N �� 500) fields conveniently numbered 1..N, M (1 �� M �� 2500) paths,
//and W (1 �� W �� 200) wormholes.
int n, m, w ,f;
int num;
struct edge
{
	int from, to, cost;
};

edge es[5500];int d[510];
//���������������е����̾���
//���жϸ�Ȧ
bool bf(int s)
{
	
	//��Դ���·��ά���ľ�������
	//for (int i = 1; i <= n; i++) d[i] = inf;
	memset(d, 0x3f,sizeof(d));
	d[s] = 0;
	for (int j = 1; j < n; j++)
	{
		bool update = false;
		for (int i = 1; i < num; i++)
		{
			edge e = es[i];
			if (d[e.from] != inf && d[e.to] > d[e.from] + e.cost)
			{
				d[e.to] = d[e.from] + e.cost;
				update = true;
			}
		}
		//Ѱ��������Ŀ�����ĸ�Ȧ
		if (d[s] < 0)
			return 1;
		if (!update)
			return 0;
	}
	return 0;
}
int main()
{
	cin >> f;
	while (f--)
	{
		cin >> n >> m >> w;
		int s, e, t;
		num = 1; 
		for (int i = 0; i < m; i++)
		{
			cin >> s >> e >> t;
			es[num].from = s;
			es[num].to = e;
			es[num].cost = t;
			num++;
			es[num].from = e;
			es[num].to = s;
			es[num].cost = t;
			num++;
		}
		for (int i = 0; i < w; i++)
		{
			cin >> s >> e >> t;
			es[num].from = s;
			es[num].to = e;
			es[num].cost = (-1)*t;
			num++;
		}
		bool flag = false;
		for (int i = 1; i < num; i++)
		{
			if (bf(i))
			{
				flag = true;
				break;
			}
		}
		if (flag)
			cout << "YES" << endl;
		else
		{
			cout << "NO" << endl;
		}
	}
	return 0;
}
