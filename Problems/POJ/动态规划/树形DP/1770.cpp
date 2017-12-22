/*
Special Experiment
题意：N种能够释放或吸收一个任意种类光子的元素，给出这些元素的能量，和不同种类光子的能量，如果有两个能量相同的元素在一起就会爆炸
	  注意释放或吸收光子后，能量会变化，但保证变化方式唯一，问选一些元素，使得安全而且能量和最大 
分析：通过将所有不能在一起的元素连边，此题转为最大点权独立集，注意变化方式唯一，则此图是一棵树，转成树形DP，类似“没有上司的舞会”
	  实现时，注意利用map建立映射，以快速的到对应编号 
*/
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<bitset>
#include<vector>
#include<map> 
using namespace std;
const int INF=0x3f3f3f3f,MAXN=200;
vector<int> g[MAXN+3];
int val[MAXN+3],opt[MAXN+3][2],n,m;
bitset<MAXN+3> vis;
map<int,int> mp;
void dp(int u){
	vis[u]=1;
	int &f=opt[u][0],&t=opt[u][1]; 
	f=0;t=0;
	for(int i=0;i<g[u].size();i++){
		int v=g[u][i];
		if(vis[v])continue;//这里是continue，而不是 if(!vis[v])dp(v)，因为不能重复计算父节点的opt（注意下面是+=） 
		dp(v);
		f+=max(opt[v][0],opt[v][1]);
		t+=opt[v][0];
	}
	t+=val[u];
}
void addedge(int u,int v){
	g[u].push_back(v);
	g[v].push_back(u);
}
bool input(){
	scanf("%d%d",&n,&m);
	if(n==0&&m==0)return false;
	mp.clear();
	for(int i=1;i<=n;i++){
		scanf("%d",&val[i]);
		mp.insert(map<int,int>::value_type(val[i],i));
		g[i].clear();
	}
	int t=0;
	for(int i=1;i<=m;i++){
		scanf("%d",&t);
		for(int j=1;j<=n;j++){
			if(mp.count(val[j]+t))addedge(j,mp[val[j]+t]);
			/*if(mp.count(val[j]-t)){
				addedge(j,mp[val[j]-t]);
			}*/
		}
	}
	return true;
}
int main(){
	while(input()){
		vis=0;
		dp(1);
		printf("%d\n",max(opt[1][0],opt[1][1]));
	}
	return 0;
}

