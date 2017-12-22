/*
[ZJOI2007]矩阵游戏
分析：同行同列的点无论经过多少次变换仍然同行或同列，所以题目可转换为能不能找到n个互相不同行或同列的点。或说给每行找到一个列上的点
	  二分图匹配 
*/
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
const int MAXN=200,INF=0x3f3f3f3f;
int mp[MAXN+3][MAXN+3],match[MAXN+3],vis[MAXN+3],n;
bool augment(int u){
	for(int i=1;i<=n;i++){
		if(vis[i] || mp[u][i]==0)continue;
		vis[i]=1;//注意是在这里，而不是vis[u]=1，这是两侧的点 
		if(match[i]==0 || augment(match[i])){match[i]=u;return true;}
	}
	return false;
}
bool solve(){
	memset(match,0,sizeof(match));
	for(int i=1;i<=n;i++){
		memset(vis,0,sizeof(vis));
		if(!augment(i))return false;
	}
	return true;
}
int main(){
	int t;scanf("%d",&t);
	for(;t;t--){
		scanf("%d",&n);
		for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)scanf("%d",&mp[i][j]);
		printf("%s\n",solve()?"Yes":"No");
	}
	return 0;
}

