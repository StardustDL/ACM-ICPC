/*
稳定婚姻
分析：强连通缩点，因为如果构成一个环，那么就是不稳定的 
*/
#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<vector>
#include<stack>
#include<queue>
#include<bitset>
#include<string>
#include<map>
using namespace std;
const int MAXN=4000,INF=0x3f3f3f3f;
map<string,int> mp;
int n,m,match[MAXN+3][2],ps=0;
vector<int> g[2*MAXN+3];
void input(){
	string s,t;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		cin>>s>>t;
		match[i][0]=++ps;
		match[i][1]=++ps;
		mp[s]=match[i][0];
		mp[t]=match[i][1];
		g[match[i][0]].push_back(match[i][1]);
		//g[n+i].push_back(i);
	}
	scanf("%d",&m);
	for(int i=1;i<=m;i++){
		cin>>s>>t;
		int a=mp[s],b=mp[t];
		//cout<<s<<" "<<t<<endl;
		//g[a].push_back(b);
		g[b].push_back(a);
	}
}
stack<int> sta;
int sccno[2*MAXN+3],scc=0,low[2*MAXN+3],pre[2*MAXN+3],tme=0;
void tarjan(int u,int fa){
	pre[u]=low[u]=++tme;
	sta.push(u);
	for(int i=0;i<g[u].size();i++){
		int v=g[u][i];
		if(v==fa)continue;
		if(!pre[v]){ 
			tarjan(v,u);
			low[u]=min(low[u],low[v]);
		}
		else if(!sccno[v]){
			low[u]=min(low[u],pre[v]);
		}
	}
	if(pre[u]==low[u]){ 
		++scc;
		while(1){
			int t=sta.top();sta.pop();
			sccno[t]=scc;
			if(t==u)break;
		}
	}
}
void find_scc(){
	tme=scc=0;
	memset(pre,0,sizeof(pre));
	memset(sccno,0,sizeof(sccno));
	for(int i=1;i<=(n<<1);i++){
		if(!pre[i])tarjan(i,-1);
	}
}
int main(){
	//freopen("marriage.in","r",stdin);
	//freopen("marriage.out","w",stdout);
	input();
	find_scc();
	for(int i=1;i<=n;i++){
		if(sccno[match[i][0]]!=sccno[match[i][1]]){
			puts("Safe");
		}
		else puts("Unsafe");
	}
	//fclose(stdin);
	//fclose(stdout);
	return 0;
}
