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
priority_queue<int> q;
typedef pair<int,int> pii;
pii p[150010];
int main()
{
	int n,n1;
	cin>>n;
	for(n1=1;n1<=n;n1++)
		scanf("%d%d",&p[n1].second,&p[n1].first);
	sort(p+1,p+n+1);
	int ans=0,sum=0;
	for(n1=1;n1<=n;n1++)
		if(sum+p[n1].second<=p[n1].first)
		{
			sum+=p[n1].second;
			q.push(p[n1].second);
			ans++;
		}
		else
			if(p[n1].second<q.top()&&sum+p[n1].second-q.top()<=p[n1].first)
			{
				sum=sum+p[n1].second-q.top();
				q.pop();
				q.push(p[n1].second);
			}
		cout<<ans<<endl;
		
}

