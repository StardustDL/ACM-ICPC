/*
[HEOI2012]旅行问题
分析：题意是求两个串的一个最长公共后缀在字典树中。
	  其实就是两个串的最长后缀=所有串（不一定是这两个串）中某个串的前缀
	  AC自动机，求出fail树，结果便是两个点在fail树上的LCA，因为fail[i]表示i节点的最长后缀=所有串中某个串的前缀转移到的节点
	  LCA便是公共后缀
	  但是DFS会爆栈！ （为什么呢。。） 
*/
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<queue>
using namespace std;
const int MAXN=1000000,INF=0x3f3f3f3f;
typedef long long LL;
const LL MOD=1000000007;
int ch[MAXN+3][26],fail[MAXN+3],sz=1;
LL val[MAXN+3];
int pos[2*MAXN+3],len[MAXN+3];
inline int idx(char c){return c-'a';}
queue<int> q;
void build(){
	while(!q.empty())q.pop();
	for(int i=0;i<26;i++){
		int u=ch[0][i];
		fail[u]=0;
		if(u)q.push(u);
	}
	while(!q.empty()){
		int u=q.front();q.pop();
		for(int i=0;i<26;i++){
			int t=ch[u][i];
			if(t==0)continue;
			q.push(t);
			int v=fail[u];
			while(v && ch[v][i]==0)v=fail[v];
			fail[t]=ch[v][i];
		}
	}
}
vector<int> g[MAXN+3];
int d[MAXN+3],pa[MAXN+3][20];
void load_tree(){
	for(int i=1;i<sz;i++){
		//g[i].push_back(fail[i]);
		g[fail[i]].push_back(i);
	}
}
void dfs(int u,int fa){
	d[u]=d[fa]+1;pa[u][0]=fa;
	for(int i=1;i<20;i++)pa[u][i]=pa[pa[u][i-1]][i-1];
	for(int i=0;i<g[u].size();i++){
		if(g[u][i]==fa)continue;
		dfs(g[u][i],u);
	}
}
void bfs(int s){
	while(!q.empty())q.pop();
	q.push(s);
	while(!q.empty()){
		int u=q.front();q.pop();
		for(int i=0;i<g[u].size();i++){
			int v=g[u][i];
			d[v]=d[u]+1;
			pa[v][0]=u;
			for(int i=1;i<20;i++)pa[v][i]=pa[pa[v][i-1]][i-1];
			q.push(v);
		}
	}
}
int lca(int a,int b){
	if(d[a]<d[b])swap(a,b);
	int h=d[a]-d[b];
	for(int i=0;i<20;i++)if(h>>i&1)a=pa[a][i];
	if(a==b)return a;
	for(int i=19;i>=0;i--){
		if(pa[a][i]!=pa[b][i])a=pa[a][i],b=pa[b][i];
	}
	return pa[a][0];
}
int n,m;
char str[MAXN+3];
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%s",str);len[i]=len[i-1];int t=strlen(str);
		int u=0;
		for(int j=0;j<t;j++){
			int c=idx(str[j]);
			if(!ch[u][c]){
				memset(ch[sz],0,sizeof(ch[sz]));
				val[sz]=(val[u]*26+c)%MOD;
				ch[u][c]=sz++;
			}
			u=ch[u][c];
			pos[++len[i]]=u;
		}
	}
	build();
	load_tree();
	//dfs(0,-1);
	bfs(0);
	scanf("%d",&m);
	for(int i=1,q,w,e,r;i<=m;i++){
		scanf("%d%d%d%d",&q,&w,&e,&r);
		int a=pos[len[q-1]+w],b=pos[len[e-1]+r];
		//cout<<a<<" "<<b<<endl;
		printf("%lld\n",val[lca(a,b)]);
	}
	return 0;
}
