#include <bits/stdc++.h>//����ͷ 

#define MAXN 150000//���Ľ������������ݷ�Χ�� 

using namespace std;

inline int read()//���
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

int n,T,ans;//n������Nָ�������� Tָ�޸�ʱ�����˶೤ʱ�� ans������Sһ�����޸��Ľ�����

struct node//����ÿ����������Ϣ
{
	int w; //wΪ���������������ʱ�� (T1)
	int t;//tΪ�����������ʱ�� (T2)
} a[MAXN];

priority_queue<int> Q;//���ȶ��У���

bool cmp (node x, node y)//sort�������
{
	return x.t < y.t;//��t��С��������
}
int main()
{
	n=read();//������뽨������
	for(int i = 1; i <= n; i++)//����ѭ������
	{
		a[i].w=read();// ������������������ʱ�� (T1)
		a[i].t=read();//������������������ʱ�� (T2)
	}
	sort(a + 1, a + n + 1, cmp);//����������򣨰�t��С��������cmpΪ����
	for(int i = 1; i <= n; i++) 
	{
		if(T + a[i].w > a[i].t)//����޷��޸��˽���
		{
			if(a[i].w < Q.top())//ai < aj
			{
				T -= Q.top();//ע������Ҫ����
				Q.pop();
				Q.push(a[i].w);
				T += a[i].w;
			}
		}
		else//���޸��˽��� 
		{
			Q.push(a[i].w);
			ans++;
			T+=a[i].w;
		}
	}
	cout<<ans<<endl;//����� 
	return 0;
}
