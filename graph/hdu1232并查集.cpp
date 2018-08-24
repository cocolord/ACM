#include"stdafx.h"
#include<iostream>
#include<algorithm>
using namespace std;

int par[2018];
int n, m;
int find(int x)
{
	if(x!=par[x])
		par[x] = find(par[x]);
	return par[x];
}
void merge(int x, int y)
{
	int tempx = find(x), tempy = find(y);
	if (tempx == tempy)
		return;
	//��x�ĸ��ڵ�ָ��y
	else
		par[tempx] = tempy;
}
int main()
{
	while (scanf("%d",&n) && n)
	{
		scanf("%d", &m);
		int ans = 0;
		for (int i = 1; i <= n; i++)
			par[i] = i;

		for (int i = 0; i < m; i++)
		{
			int x, y;
			cin >> x >> y;
			merge(x, y);
		}
		//ֻ��ȷ����ͨ��֧������
		for (int i = 1; i <= n; i++)
		{
			//�жϸ��ڵ�����
			if (par[i]==i)
			{
				ans++;
			}
		}
		std::cout << ans - 1 << endl;
	}
	return 0;
}