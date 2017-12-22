/*
Cell Phone Network
题意：一棵树，选一个点集S，使得对于树中所有点i，均存在一条边(s,i)，s属于S ，树的最小支配集
分析：定义状态：
	  	①dp[i][0]：表示点i属于支配集，并且以点i为根的子树都被覆盖了的情况下支配集中所包含的的最少点的个数。
	  	②dp[i][1]：i不属于支配集，且以i为根的子树都被覆盖，且i被其中不少于1个子节点覆盖的情况下支配集中所包含最少点的个数。
	  	③dp[i][2]：i不属于支配集，且以i为根的子树都被覆盖，且i没被子节点覆盖的情况下支配集中所包含最少点的个数。
	  对于第一种状态，dp[i][0]等于每个儿子节点的3种状态（其儿子是否被覆盖没有关系）的最小值之和加1，即只要每个以i的儿子为根的子树都被覆盖，再加上当前点i,所需要的最少点的个数，方程如下：
	  	dp[i][0]=1+Σmin(dp[u][0],dp[u][1],dp[u][2])(p[u]=i).
	  对于第二种状态，如果点i没有子节点，那么dp[i][1]=INF；
	  	否则，需要保证它的每个以i的儿子为根的子树都被覆盖，那么要取每个儿子节点的前两种状态的最小值之和，
	  	因为此时i点不属于支配集，不能支配其子节点，所以子节点必须已经被支配，与子节点的第三种状态无关。
	  	如果当前所选的状态中，每个儿子都没有被选择进入支配集，即在每个儿子的前两种状态中，第一种状态都不是所需点最少的，
		那么为了满足第二种状态的定义，需要重新选择点i的一个儿子的状态为第一种状态，这时取花费最少的一个点，即取min(dp[u][0]-dp[u][1])的儿子节点u，强制取其第一种状态，其他儿子节点都取第二种状态，转移方程为：
	  对于第三种状态，i不属于支配集，且以i为根的子树都被覆盖，又i没被子节点覆盖，那么说明点i和点i的儿子节点都不属于支配集，则点i的第三种状态只与其儿子的第二种状态有关，方程为
		dp[i][2]=Σdp[u][1]
	  最终答案便是：min(dp[root][0],dp[root][1])
	  具体实现有一些细节，要仔细 
*/
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<bitset>
#include<vector> 
using namespace std;
const int INF=0x3f3f3f3f,MAXN=10000;
int opt[MAXN+3][3],n;
bitset<MAXN+3> vis;
vector<int> g[MAXN+3];
void dp(int u){
	vis[u]=1;
	int &a=opt[u][0],&b=opt[u][1],&c=opt[u][2];
	a=1;b=0;c=0;bool flg=false;int inc=INF;//flg记录是否存在v使得opt[v][0]<opt[v][1]，即可以当前点被子节点覆盖 
	for(int i=0;i<g[u].size();i++){
		int v=g[u][i];
		if(vis[v])continue;
		dp(v);
		a+=min(opt[v][0],min(opt[v][1],opt[v][2]));
		if(opt[v][0]<opt[v][1]){
			b+=opt[v][0];flg=true;
		}
		else{
			b+=opt[v][1];
			inc=min(inc,opt[v][0]-opt[v][1]);
		}
		if(c!=INF&&opt[v][1]!=INF)c+=opt[v][1]; 
		else c=INF;//如果子节点既不能被其子节点覆盖又不能被当前节点覆盖 
	}
	if(g[u].size()==0)b=INF;
	else if(!flg)b+=inc;
}
void addedge(int u,int v){
	g[u].push_back(v);
	g[v].push_back(u); 
} 
void input(){
	scanf("%d",&n);
	vis=0;
	int a,b;
	for(int i=1;i<n;i++){
		scanf("%d%d",&a,&b);
		addedge(a,b);
	}
}
int main(){
	input();
	dp(1);
	printf("%d",min(opt[1][0],opt[1][1])); 
	return 0;
}

