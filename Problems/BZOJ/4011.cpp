/*
[HNOI2015]落忆枫音
题意：给定一张有向无环图，现在要求加入一条边，求加入后以1为根的树形图个数  
分析：http://blog.csdn.net/popoqqq/article/details/45194103
		首先不考虑加入的这条边，那么这个图是一个DAG 
		由朱刘算法的推论可知，如果除根节点外每个点都选择一条入边，由于没有环，因此一定会形成一个树形图 
		因此答案就是∏i=2..n degreei 其中degreei表示第i个点的入度
		现在加入这条边之后，我们仍然可以套用这个公式，但是这样就会有一些不合法的方案被统计进来，我们需要把这些不合法的方案减掉 
		一个方案如果不合法，那么一定会形成一个环，而环一定包含新加入的那条边 
		因此我们减掉的方案其实是：  
		sigma{S是原图中t→s的一条路径的点集 ,∏i=2..n,i不属于S degreei}
		然后就可以DP了 
		f[i]= sigma{S是原图中t->i的一条路径的点集 ,∏i=2..n,i不属于S degreei}
		f[i]=sigma{f[j]|j->i}/degree[i]
		f[t]=( ∏i=2..n degreei)/degree[t]
		注意t=1时要特判
*/
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long LL;
const int MAXN=100000,MAXM=200000;
const LL MOD=1000000007;
struct edge{
	int v,nxt;
}es[MAXM+3];
int head[MAXN+3],tot,dg[MAXN+3],dg2[MAXN+3],n,m,s,t,q[MAXN+3];
LL inv[MAXM+3],ans,dp[MAXN+3];
void addedge(int u,int v){
	es[++tot].v=v;
	es[tot].nxt=head[u];
	head[u]=tot;
}
void topo_sort(){
	int h=0,w=0;
	dp[t]=ans;
	for(int i=1;i<=n;i++){
		if(dg[i]==0)q[w++]=i;
	}
	while(h<w){
		int u=q[h];h++;
		dp[u]=dp[u]*inv[dg2[u]]%MOD;
		for(int i=head[u];i;i=es[i].nxt){
			(dp[es[i].v]+=dp[u])%=MOD;
			if(--dg[es[i].v] == 0)
				q[w++]=es[i].v;
		}
	}
}
int main(){
	scanf("%d%d%d%d",&n,&m,&s,&t);
	inv[1]=1;for(int i=2;i<=m+1;i++)inv[i]=(MOD-MOD/i)*inv[MOD%i]%MOD;
	for(int i=1,a,b;i<=m;i++){
		scanf("%d%d",&a,&b);
		addedge(a,b);dg[b]++;
	}
	memcpy(dg2,dg,sizeof(dg));
	dg2[t]++;
	ans=1;
	for(int i=2;i<=n;i++)ans=ans*dg2[i]%MOD;
	
	if(t==1){
		printf("%lld\n",ans);
		return 0;
	}
	topo_sort();
	printf("%lld\n",(ans-dp[s]+MOD)%MOD);
	return 0;	
}


