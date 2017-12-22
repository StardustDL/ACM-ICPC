/*
[Usaco2008 Open] Clear And Present Danger 寻宝之路
分析：floyd+扫一遍 
*/
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
const int MAXN=100,MAXM=10000,INF=0x3f3f3f3f;
int d[MAXN+3][MAXN+3],a[MAXM+3],n,m;
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++)scanf("%d",&a[i]);
	for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)scanf("%d",&d[i][j]);
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++)d[i][j]=min(d[i][j],d[i][k]+d[k][j]);
		}
	}
	int ans=0;
	for(int i=2;i<=m;i++)ans+=d[a[i-1]][a[i]];
	printf("%d\n",ans);
	return 0;
}

