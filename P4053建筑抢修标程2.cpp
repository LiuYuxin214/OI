#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<queue>
#include<vector>
#include<map>
#include<set>
#include<stack>
#include<string>
#include<cmath>
#include<cctype>
using namespace std;
const int maxlongint=2147483647;
const int inf=1000000000;
int lc[500010][20];
int getint()
{
	int a=0,b=0;
	char c;
	while(1)
	{
		c=getchar();
		if(c>=48&&c<=57)
		{
			a=a*10+c-48;
			b=1;
		}
		else
			if(b)
				return a;
	}
}
struct Bian
{
	int s,t,last;
}bian[1000010];
int maxbian=0,last[500010];
void addbian(int s,int t)
{
	maxbian++;
	bian[maxbian].s=s;
	bian[maxbian].t=t;
	bian[maxbian].last=last[s];
	last[s]=maxbian;
}
bool v[500010];
int d[500010],maxd=1;
void dfs(int i)
{
	v[i]=1;
	int j;
	for(j=last[i];j;j=bian[j].last)
		if(!v[bian[j].t])
		{
			lc[bian[j].t][0]=i;
			d[bian[j].t]=d[i]+1;
			maxd=max(maxd,bian[j].t);
			dfs(bian[j].t);
		}
}
inline int lca(int i,int j)
{
	if(d[i]<d[j])
		swap(i,j);
	int d1;
	for(d1=maxd;d1>=0;d1--)
		if(d[lc[i][d1]]>=d[j])
			i=lc[i][d1];
	if(i==j)
		return i;
	for(d1=maxd;d1>=0;d1--)
		if(lc[i][d1]!=lc[j][d1])
		{
			i=lc[i][d1];
			j=lc[j][d1];
		}
	return lc[i][0];
}
inline int di(int i,int j)
{
	int k=lca(i,j);
	return d[i]-d[k]+d[j]-d[k];
}
int main()
{
	int n,m,t1,t2,t3,d1,n1,m1;
	cin>>n>>m;
	for(n1=1;n1<n;n1++)
	{
		scanf("%d%d",&t1,&t2);
		addbian(t1,t2);
		addbian(t2,t1);
	}
	d[(n+1)/2]=1;
	dfs((n+1)/2);
	maxd=(int)(log(maxd+0.5)/log(2))+1;
	for(d1=1;d1<=maxd;d1++)
		for(n1=1;n1<=n;n1++)
			lc[n1][d1]=lc[lc[n1][d1-1]][d1-1];
	for(m1=1;m1<=m;m1++)
	{
		scanf("%d%d%d",&t1,&t2,&t3);
		int i=lca(t1,t2),j=lca(t2,t3),k=lca(t1,t3);
		int a1=di(i,t1)+di(i,t2)+di(i,t3),a2=di(j,t1)+di(j,t2)+di(j,t3),a3=di(k,t1)+di(k,t2)+di(k,t3);
		if(a1<a2&&a1<a3)
			printf("%d %d\n",i,a1);
		else
			if(a2<a3)
				printf("%d %d\n",j,a2);
			else
				printf("%d %d\n",k,a3);
	}
}

