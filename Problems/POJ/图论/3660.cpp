/*
Cow Contest
题意：有n只奶牛，有n个连续的实力，如果u的实力大于v的实力，就能打赢它，然后给定m种关系，求最后能确定其排名的奶牛个数。 
分析：求出传递闭包，统计每个点的比他大的点+比他小的点个数，若=n-1，则这个点位置确定
	  感觉也可以dfs求出这个值 
*/
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<bitset>
using namespace std;
const int INF=0x3f3f3f3f,MAXN=100;
bool mp[MAXN+3][MAXN+3];
int n,m,x,y,ans=0;
int main(){
	scanf("%d%d",&n,&m);
	while(m--){
		scanf("%d%d",&x,&y);
		mp[x][y]=1;
	}
	for(int k=1;k<=n;k++)
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				mp[i][j]|=mp[i][k]&mp[k][j];
	for(int i=1;i<=n;i++){
		int cnt=0;
		for(int j=1;j<=n;j++)cnt+=mp[i][j]+mp[j][i];
		if(cnt==n-1)ans++;
	}
	printf("%d",ans);
	return 0;
}

