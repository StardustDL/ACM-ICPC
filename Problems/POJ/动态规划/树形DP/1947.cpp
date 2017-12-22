/*
Rebuilding Roads
题意：给出n,p，一共有n个节点，要求最少减去最少的边是多少，剩下p个节点
分析：dp[s][i]:记录s结点，要得到一棵j个节点的子树去掉的最少边数
	  考虑其儿子k：
	  	1)如果不去掉k子树，则dp[s][i]=min(dp[s][j]+dp[k][i-j])  0<=j<=i
		2)如果去掉k子树，则dp[s][i]=dp[s][i]+1
*/
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<bitset>
#include<vector>
using namespace std;
const int INF=0x3f3f3f3f,MAXN=150;
vector<int> g[MAXN+3];
int n,p,opt[MAXN+3][MAXN+3];
void addedge(int u,int v){
	g[u].push_back(v);
	g[v].push_back(u);
}
void input(){
	scanf("%d%d",&n,&p);
	int x,y;
	for(int i=1;i<n;i++){
		scanf("%d%d",&x,&y);
		addedge(x,y);
	}
}
void dp(int u,int pa){
	memset(opt[u],INF,sizeof(opt[u]));
	opt[u][1]=0;
	for(int i=0;i<g[u].size();i++){
		int v=g[u][i];
		if(v==pa)continue;
		dp(v,u);
		for(int j=p;j>=1;j--){
			int tmp=opt[u][j]+1;
			for(int k=1;k<j;k++){
				tmp=min(tmp,opt[u][k]+opt[v][j-k]);
			}
			opt[u][j]=tmp;
		}
	}
}
int solve(int root){//这里要遍历所有点（每个点都可能成为根） 
	dp(root,-1);
	int ans=opt[root][p];
	for(int i=1;i<=n;i++){
		ans=min(ans,opt[i][p]+1);//除根节点外，其余各点若想成为根，必须先和父亲断边 
	}
	return ans;
}
int main(){
	input();
	printf("%d",solve(1));
	return 0;
}

