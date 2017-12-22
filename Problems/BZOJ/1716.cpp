/*
[Usaco2006 Dec]The Fewest Coins ����Ǯ
��������һ�����ر�����һ����ȫ������ö����Ǯ�Ķ��٣���𰸡����ݷ�Χ���Ǻܴ�ֱ�ӱ������ر���Ҳ�ǿ��Ե� 
*/
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
const int MAXN=100,INF=0x3f3f3f3f,UP=120,T=10000;
int a[UP+3],b[T+UP+3],v[MAXN+3],c[MAXN+3],n,t;
int main(){
	scanf("%d%d",&n,&t);
	for(int i=1;i<=n;i++)scanf("%d",&v[i]);
	for(int i=1;i<=n;i++)scanf("%d",&c[i]);
	memset(a,INF,sizeof(a));
	memset(b,INF,sizeof(b));
	a[0]=0;
	for(int i=1;i<=n;i++)for(int j=v[i];j<=UP;j++)a[j]=min(a[j],a[j-v[i]]+1);
	b[0]=0;
	for(int i=1;i<=n;i++)for(int j=t+UP;j>=v[i];j--)for(int k=1;k<=min(j/v[i],c[i]);k++)b[j]=min(b[j-k*v[i]]+k,b[j]);
	int ans=INF;
	for(int i=0;i<=UP;i++)ans=min(ans,a[i]+b[t+i]);
	printf("%d\n",ans==INF?-1:ans);
	return 0;
}

