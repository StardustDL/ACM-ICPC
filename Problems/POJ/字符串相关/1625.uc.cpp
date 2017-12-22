/*
Censored!
���⣺��������n���ɼ��ַ����ַ��������������ַ������ɸ��ַ����е��ַ����ɡ�����p�����Ȳ�����10���ַ�������Ϊm�Ҳ���������p���ַ������ַ����ж��ٸ���
������״̬��ƣ�dp[i][j]��i ��֮��δ����Σ�ս���ҵ� i �������� j ��·����Ŀ��
	  ״̬ת�ƣ�dp[i][j]=��dp[i-1][k]���ڽ�� k ������ s[i] ��������� j
	  ��ʼ����dp[0][0]=1����������� i ��dp[0][i]=0
	  ע�⣺����������ܴ󣬶�������û�ᵽȡģ������Ҫ�õ�������ӡ�
*/
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
using namespace std;
struct rec{int s,a[100];}f[110][110],ans;
int trie[110][55],g[110],num[1000];
char str[110];
bool v[110]; 
int n,m,t,p,i,j,k,x,y;

void add(int x,int l)
{
	if(l>strlen(str+1)) {v[x]=1; return;}
	int y=num[str[l]+200];
	if(!trie[x][y]) trie[x][y]=++n;
	add(trie[x][y],l+1);
}

void bfs()
{
	queue<int> q;
	q.push(1);
	while(q.size())
	{
		x=q.front(); q.pop();
		for(i=0;i<t;i++)
		{
			for(j=g[x];j;j=g[j])
				if(trie[j][i]) break;
			if(y=trie[x][i])
			{
				g[y]=j?trie[j][i]:1;
				v[y]|=v[g[y]];
				q.push(y);
			}
			else trie[x][i]=j?trie[j][i]:1;
		}
	}
}

rec inc(rec a,rec b)
{
	rec c;
	memset(&c,0,sizeof(c));
	c.s=max(a.s,b.s);
	int i,jin=0;
	for(i=1;i<=c.s;i++)
	{
		jin+=a.a[i]+b.a[i];
		c.a[i]=jin%10;
		jin/=10;
	}
	if(jin) c.a[++c.s]=jin;
	return c;
}

void dp()
{
	f[0][1].s=f[0][1].a[1]=1;
	for(i=0;i<m;i++)
		for(j=1;j<=n;j++)
			for(k=0;k<t;k++)
				if(!v[trie[j][k]])
					f[i+1][trie[j][k]]=inc(f[i+1][trie[j][k]],f[i][j]);
}

int main()
{
	cin>>t>>m>>p;
	scanf("%s",str);
	for(i=0;i<t;i++) num[str[i]+200]=i;
	n=1;
	for(i=1;i<=p;i++)
	{
		scanf("%s",str+1);
		add(1,1);
	}
	bfs();
	dp();
	ans.s=1;
	for(i=1;i<=n;i++) ans=inc(ans,f[m][i]);
	for(i=ans.s;i;i--) printf("%d",ans.a[i]);
	cout<<endl;
	return 0; 
}
