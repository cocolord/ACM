#include"stdafx.h"
#include<iostream>
#include<vector>
#include<queue>
using namespace std;
#define inf 0x7ffffff
struct edge
{
	int to, cost;
};
//first �Ƕ���ı�ţ�second ����̾���
typedef pair<int, int> P;
vector<edge>  G[1010];//�߱� index is the beginning point
int t, n;
int d[1010];
//��Դ���·��
void dijk(int s)
{
	//��ʼ��
	priority_queue<P, vector<P>, greater<P> > que;
	fill(d, d + n + 1, inf);
	d[s] = 0;
	que.push({s,0});
	//first �Ƕ���ı�ţ�second ����̾���
	while (!que.empty())
	{
		//��һ����̱�
		P p = que.top();
		que.pop();
		int a = p.first;
		int b = p.second;
		if (d[a] < b) continue;
		//�����a�����м�����
		//�ɳ�
		for (int i = 0; i < G[a].size(); i++)
		{
			//��a��G[a][i].to
			edge e = G[a][i];
			if (d[e.to] > d[a] + e.cost)
			{
				d[e.to] = d[a] + e.cost;
				que.push({ e.to,d[e.to] });
			}
		}
	}
}
int main()
{
	cin >> t >> n;
	while (t--)
	{
		int r, q, p;
		cin >> r >> q >> p;
		//ע������
		//�����ظ�����������ݡ�
		//������������ݴ洢�ṹ����OK��
		G[r].push_back({ q,p });
		G[q].push_back({ r,p });
	}
	dijk(1);
	cout << d[n] << endl;
	return 0;
}