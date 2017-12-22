#include<iostream>
#include<cmath>
#include<cstdio>
#include<cstring>
using namespace std;
int mp[103][103],n,m;
int main(){
	memset(mp,0x3f,sizeof(mp));
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)mp[i][i]=0;
	for(int i=1,u,v,w;i<=m;i++){
		scanf("%d%d%d",&u,&v,&w);
		mp[u][v]=mp[v][u]=min(mp[u][v],w);
	}
	for(int k=1;k<=n;k++)
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				mp[i][j]=min(mp[i][j],mp[i][k]+mp[k][j]);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++)printf("%d ",mp[i][j]);
		puts("");
	}
	return 0;
}