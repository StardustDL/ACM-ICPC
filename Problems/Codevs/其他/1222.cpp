/*
信与信封问题
分析：先求最大匹配，若不足n个，那么一定无解，否则依次判断每条边： 
	  若完美匹配中一条边必须存在, 那如果删掉这条边就不会存在完美匹配
	  这里用邻接矩阵更简单
	  这道题码了很久。。。有待深入研究 
*/ 
#include<cstdio>
#include<cstring>
#include<bitset>
using namespace std;
const int MAXN=100;
bitset<MAXN+3> map[MAXN+3];
bitset<MAXN+3> vis;
int linky[MAXN+3],linkx[MAXN+3];
int n,ans;
bool find(int u){
	for(int i=1;i<=n;i++){
		if(map[u][i]||vis[i])continue;
		vis[i]=1;
		if(!linky[i]||find(linky[i])){
			linky[i]=u;
			linkx[u]=i;
			return true;
		}
	}
	return false;
}
int main() {
	scanf("%d",&n) ;
	int x,y;
	while(scanf("%d%d",&x,&y) && x && y)map[x][y]=1;
	for(int i=1;i<=n;i++){
		vis=0;
		if(find(i))ans++; 
	}
	if(ans!=n){
		printf("none");
		return 0;
	}
	ans=0;
	for(int i=1;i<=n;i++){
		vis=0;
		int v=linkx[i];
		map[i][v]=1;
		linky[v]=linkx[i]=0;
		if(!find(i)){
			printf("%d %d\n",i,v);
			linkx[i]=v;
			linky[v]=i;
			ans=1;
		}
		map[i][v]=0;
	}
	if(!ans)printf("none");
	return 0;
}
