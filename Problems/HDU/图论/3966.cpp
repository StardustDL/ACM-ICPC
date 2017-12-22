/*
Aragorn's Story
题意：对一棵树，修改两点间路径：+A-A，查询某点权值
分析：树链剖分，线段树区间修改，单点查询 
*/
#pragma comment(linker, "/STACK:1024000000,1024000000")
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<bitset>
#include<vector> 
#define LC(x) (x<<1)
#define RC(x) (x<<1|1)
using namespace std;
const int INF=0x3f3f3f3f,MAXN=50000;
vector<int> g[MAXN+3];
int dep[MAXN+3],fa[MAXN+3],son[MAXN+3],sz[MAXN+3],w[MAXN+3],id[MAXN+3],top[MAXN+3],tot=0,val[MAXN+3]; 
void addedge(int u,int v){
	g[u].push_back(v);
	g[v].push_back(u);
}
void dfs(int u,int d){
    sz[u]=1;son[u]=0;dep[u]=d;
    for(int i=0;i<g[u].size();i++){
        if(g[u][i]==fa[u])continue;
        fa[g[u][i]]=u;
        dfs(g[u][i],d+1);
        sz[u]+=sz[g[u][i]];
        if(sz[g[u][i]]>sz[son[u]])son[u]=g[u][i];
    }
}
void build_tree(int u,int pre){
	id[u]=++tot;top[u]=pre;
    if(son[u])build_tree(son[u],pre);
    for(int i=0;i<g[u].size();i++){
        if(g[u][i]!=fa[u]&&g[u][i]!=son[u])build_tree(g[u][i],g[u][i]);
    }
}
struct segtree{
	struct node{
		int l,r,tag,val;
		node(){val=tag=l=r=0;}
	}ns[MAXN<<2];
	void pushdown(int x){
		if(ns[x].tag!=0){
			node &l=ns[LC(x)],&r=ns[RC(x)];
			l.tag+=ns[x].tag;
			l.val+=ns[x].tag;
			r.tag+=ns[x].tag;
			r.val+=ns[x].tag;
			ns[x].tag=0;
		}
	}
	void build(int *a,int l,int r,int x){
		ns[x].l=l,ns[x].r=r;ns[x].tag=0;
		if(l==r){ns[x].val=a[l];return;}
		build(a,l,(l+r)>>1,LC(x));
		build(a,((l+r)>>1)+1,r,RC(x));
	}
	void change(int l,int r,int x,int val){
		node &X=ns[x];
		if(l<=X.l&&r>=X.r){
			X.tag+=val;
			X.val+=val;
			return;
		}
		pushdown(x);
		int mid=(X.l+X.r)>>1;
		if(l<=mid)change(l,r,LC(x),val);
		if(r>mid)change(l,r,RC(x),val);
	}
	int query(int p,int x){
		if(ns[x].l==ns[x].r)return ns[x].val;
		int mid=(ns[x].l+ns[x].r)>>1;
		pushdown(x);
		if(p<=mid)return query(p,LC(x));
		else return query(p,RC(x));
	}
}S;
void set(int a,int b,int val){
	int ta=top[a],tb=top[b];
	while(ta!=tb){//a,b不在一条链上 
		if(dep[ta]<dep[tb]){swap(ta,tb);swap(a,b);}//这样交换，保证a所在链顶深于b所在链顶，这样不会爬过 
		S.change(id[ta],id[a],1,val);
		a=fa[ta];ta=top[a];
	}
	if(dep[a]>dep[b])swap(a,b);
	S.change(id[a],id[b],1,val);
}
int n,m;
int main(){
	while(scanf("%d%d%d",&n,&m,&m)==3){
		for(int i=1;i<=n;i++)scanf("%d",&w[i]);
		for(int i=1;i<=n;i++)g[i].clear();
		tot=0; 
		int a,b,c;char t;
		for(int i=1;i<n;i++){
			scanf("%d%d",&a,&b);
			addedge(a,b);
		}
		dfs(1,1);
		build_tree(1,1);
		for(int i=1;i<=n;i++)val[id[i]]=w[i];
		S.build(val,1,n,1);
		while(m--){
			scanf("\n%c %d",&t,&a);
			if(t=='I'){
				scanf("%d%d",&b,&c);
				set(a,b,c);
			}
			else if(t=='D'){
				scanf("%d%d",&b,&c);
				set(a,b,-c);
			}
			else if(t=='Q')printf("%d\n",S.query(id[a],1));
		}
	}
	return 0;
}

