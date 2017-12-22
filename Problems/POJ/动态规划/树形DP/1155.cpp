/*
TELE
题意：有一个电视台要用电视网络转播节目。这种电视网络是一树，树的节点为中转站或者用户。树节点的编号为1~N,其中1为总站，2~(N-M)为中转站，（总站和中转站统称为转发站）N-M+1~N为用户，电视节目从一个地方传到另一个地方都要费用，同时每一个用户愿意出相应的钱来付电视节目。现在的问题是，在电视台不亏本的前提下，要你求最多允许有多少个用户可以看到电视节目。
思路：在树上进行背包，对于以u为根的子树,该子树供给给j个用户亏本的最少钱，对每个子树，维护当前的最大大小，以实现优化，然后枚举共计j个用户，其中k个在此子树内
	  方程：opt[u][j]=max(opt[u][j],opt[u][j-k]-w(e)+val[v]+opt[v][k]
	  注意子树为用户的情况 
*/
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<bitset>
#include<vector> 
using namespace std;
const int INF=0x3f3f3f3f,MAXN=3000;
struct edge{
	int u,v,w;
	edge(int u,int v,int w):u(u),v(v),w(w){}
};
vector<edge> es;
vector<int> g[MAXN+3];
int n,m,val[MAXN+3],opt[MAXN+3][MAXN+3];
void addedge(int u,int v,int w){
	es.push_back(edge(u,v,w));
	es.push_back(edge(v,u,w));
	g[u].push_back(es.size()-2);
	g[v].push_back(es.size()-1);
}
int dp(int u,int fa){
	//if(g[u].size()==0){/*opt[u][1]=val[u];*/return 1;}
	int ans=0,p,now;
	for(int i=0;i<g[u].size();i++){
		edge &e=es[g[u][i]];
		if(e.v==fa)continue;
		now=dp(e.v,u);  
        if(e.v>=n-m+1)++now,p=1;//是用户 
        else p=0;
        ans+=now;
        for(int j=min(m,ans);j>=1;j--){//这里注意一定要j=min(m,ans),复杂度为O(n^3)=>接近O(n^2)  
            for(int k=min(j,now);k>=1;k--){//以u为根的子树供给给j个用户并且有k个用户属于v为根的子树时亏损的最少钱  
                opt[u][j]=max(opt[u][j],opt[u][j-k]+opt[e.v][k-p]-e.w+val[e.v]);  
            }
        }
	}
	return ans;
}
void input(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)opt[i][j]=-INF;
	int k,v,c;
	for(int i=1;i<=n-m;i++){
		scanf("%d",&k);
		val[i]=0;
		while(k--){
			scanf("%d%d",&v,&c);
			addedge(i,v,c);
		}
	}
	for(int i=n-m+1;i<=n;i++)scanf("%d",&val[i]);
}
int main(){
	input();
	dp(1,-1);
	int ans=0;
	for(int i=m;i>0;i--){
		if(opt[1][i]>=0){
			printf("%d\n",i);
			break;
		}
	}
	return 0;
}

