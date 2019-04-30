#include <bits/stdc++.h>//万能头 

#define MAXN 150000//最多的建筑数量（数据范围） 

using namespace std;

inline int read()//快读
{
	int ret=0,f=1;
	char ch=getchar();
	while (ch<'0'||ch>'9')
	{
		if (ch=='-') f=-f;
		ch=getchar();
	}
	while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
	return ret*f;
}

int n,T,ans;//n即题中N指建筑总数 T指修复时经过了多长时间 ans即题中S一共能修复的建筑数

struct node//储存每个建筑的信息
{
	int w; //w为修理这个建筑所用时间 (T1)
	int t;//t为这个建筑报废时间 (T2)
} a[MAXN];

priority_queue<int> Q;//优先队列（）

bool cmp (node x, node y)//sort排序规则
{
	return x.t < y.t;//按t从小到大排序
}
int main()
{
	n=read();//快读读入建筑总数
	for(int i = 1; i <= n; i++)//经典循环读入
	{
		a[i].w=read();// 快读读入这个建筑所用时间 (T1)
		a[i].t=read();//快读读入这个建筑报废时间 (T2)
	}
	sort(a + 1, a + n + 1, cmp);//含规则的排序（按t从小到大排序cmp为规则）
	for(int i = 1; i <= n; i++) 
	{
		if(T + a[i].w > a[i].t)//如果无法修复此建筑
		{
			if(a[i].w < Q.top())//ai < aj
			{
				T -= Q.top();//注意这里要减掉
				Q.pop();
				Q.push(a[i].w);
				T += a[i].w;
			}
		}
		else//能修复此建筑 
		{
			Q.push(a[i].w);
			ans++;
			T+=a[i].w;
		}
	}
	cout<<ans<<endl;//输出答案 
	return 0;
}
