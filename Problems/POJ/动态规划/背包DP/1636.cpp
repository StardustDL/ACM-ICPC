/*
Prison rearrangement
题意：M个罪犯，分在两个监狱中，现在尽量交换他们的所在的监狱，但有几对人不能在同一个监狱中，问最大交换多少对人
分析：注意对于给的一些对，实际上可能组成森林，这样交换就变成了两拨人的交换，这样其实变成了一个二维背包问题
	  具体实现：可以染色，也可以像下面的代码一样拆点，记录每个联通块中的两拨人数
	  注意比较此题与二分图最大独立集的区别，和 Team them up的区别 
*/
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<bitset>
#include<vector>
using namespace std;
const int INF=0x3f3f3f3f,MAXN=200;
vector<int> g[MAXN*2+3];
bitset<MAXN*2+3> vis;
bitset<MAXN+3> opt[MAXN+3];
int cnt[2],mark[MAXN*2+3],m,wx[MAXN*2+3],wy[MAXN*2+3],wn;
void dfs(int u){
	cnt[mark[u]]++;
	for(int i=0;i<g[u].size();i++){
		if(!vis[g[u][i]]){
			vis[g[u][i]]=1;
			dfs(g[u][i]);
		}
	}
}
void input(){
	int r,x,y;
	scanf("%d%d",&m,&r);
	memset(mark,0,sizeof(mark));
	for(int i=1;i<=m<<1;i++)g[i].clear();
	for(int i=1;i<=m;i++){
		mark[i]=0;mark[i+m]=1;
	}
	while(r--){
		scanf("%d%d",&x,&y);
		g[x].push_back(y+m);
		g[y+m].push_back(x);
	}
	wn=0;
	vis=0;
	for(int i=1;i<=m<<1;i++){
		if(vis[i])continue;
		cnt[0]=cnt[1]=0;
		vis[i]=1;
		dfs(i);
		if(cnt[0]>0||cnt[1]>0){
			wx[++wn]=cnt[0];
			wy[wn]=cnt[1];
		}
	}
	/*for(int i=1;i<=wn;i++){
		cout<<wx[i]<<" "<<wy[i]<<endl;
	}*/
}
int dp(){
	int n=m>>1;
	for(int i=0;i<=n;i++)opt[i]=0;
	opt[0][0]=1;
	for(int i=1;i<=wn;i++){
		for(int j=n;j>=wx[i];j--){
			for(int k=n;k>=wy[i];k--){
				opt[j][k]=opt[j][k]||opt[j-wx[i]][k-wy[i]];
			}
		}
	}
	while(!opt[n][n])n--;
	return n;
}
int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		input();
		printf("%d\n",dp());
	}
	return 0;
}


