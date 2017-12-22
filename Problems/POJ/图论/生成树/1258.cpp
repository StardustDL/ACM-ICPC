/*
Agri-Net
题意：有n个农场，已知这n个农场都互相相通，有一定的距离，现在每个农场需要装光纤，问怎么安装光纤能将所有农场都连通起来，并且要使光纤距离最小，输出安装光纤的总距离
分析：最小生成树，这里用的Prim，不用建边了 
*/
#include<iostream>
#include<cstdio>
#include<bitset>
#include<algorithm>
#include<cstring>
using namespace std;
const int MAXN=100,INF=0x3f3f3f3f; 
bitset<MAXN+3> vis;
int d[MAXN+3],mp[MAXN+3][MAXN+3],n;
int prim(){
	int mi,v,ans=0;
	vis=0; 
	memcpy(d,mp[1],sizeof(d));
	for(int i=1;i<=n;i++){
		mi=INF;
		for(int j=1;j<=n;j++)
			if(!vis[j]&&d[j]<mi){
				mi=d[j];
				v=j;
			}
		vis[v]=1;
		for(int j=1;j<=n;j++)
			if(!vis[j])d[j]=min(d[j],mp[v][j]);
	}
	for(int i=1;i<=n;i++)ans+=d[i];
	return ans;
}
int main(){
	while(~scanf("%d",&n)){
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				scanf("%d",&mp[i][j]);
		printf("%d\n",prim());
	}
	return 0;
}

