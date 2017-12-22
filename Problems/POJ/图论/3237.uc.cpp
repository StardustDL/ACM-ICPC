/*
Î´½» 
*/
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<vector>
#include<bitset>
#define LC(x) (x<<1)
#define RC(x) (x<<1|1)
using namespace std;
const int INF=0x3f3f3f3f,MAXN=10000;
struct edge{
	int u,v,w,k;
	edge(int u,int v,int w):u(u),v(v),w(w){} 
};
vector<int> g[MAXN+3];
vector<edge> es;
void addedge(int u,int v,int w){
	es.push_back(edge(u,v,w));
	es.push_back(edge(v,u,w));
	g[u].push_back(es.size()-2);
	g[v].push_back(es.size()-1);
}
int dep[MAXN+3],sz[MAXN+3],son[MAXN+3],top[MAXN+3],fa[MAXN+3],id[MAXN+3],tot=0,w[MAXN+3],n,to[MAXN+3];
void dfs(int u,int d){
	sz[u]=1;dep[u]=d;son[u]=0;
	for(int i=0;i<g[u].size();i++){
		edge &e=es[g[u][i]];
		if(e.v==fa[u])continue;
		fa[e.v]=u;
		w[e.v]=e.w;
		//to[g[u][i]]=e.v;
		e.k=e.v;
		es[g[u][i]^1].k=e.v;
		dfs(e.v,d+1);
		sz[u]+=sz[e.v];
		if(sz[e.v]>sz[son[u]])son[u]=e.v;
	}
}
void build_tree(int u,int pre){
	id[u]=++tot;top[u]=pre;
	if(son[u])build_tree(son[u],pre);
	for(int i=0;i<g[u].size();i++){
		edge &e=es[g[u][i]];
		if(e.v==son[u]||e.v==fa[u])continue;
		build_tree(e.v,e.v);
	}
}
struct node{
	int l,r,mn,mx,tag;
	node():l(0),r(0),mn(INF),mx(-INF),tag(0){}
};
node dat[MAXN<<2];
void update(int x){
	dat[x].mn=min(dat[LC(x)].mn,dat[RC(x)].mn);
	dat[x].mx=max(dat[LC(x)].mx,dat[RC(x)].mx);
}
void pushdown(int x){
	node &X=dat[x],&l=dat[LC(x)],&r=dat[RC(x)];
	if(!X.tag)return;
	l.tag^=1;r.tag^=1;
	l.mx*=-1;l.mn*=-1;
	r.mx*=-1;r.mn*=-1;
	swap(l.mx,l.mn);
	swap(r.mx,r.mn);
}
void build(int *a,int l,int r,int x){
	node &X=dat[x];
	X.l=l;X.r=r;
	if(l==r){
		X.mn=X.mx=a[l];
		return;
	}
	build(a,l,(l+r)>>1,LC(x));
	build(a,((l+r)>>1)+1,r,RC(x));
	update(x);
}
void change(int p,int x,int val){
	if(dat[x].l==dat[x].r){
		dat[x].mn=dat[x].mx=val;
		return;
	}
	pushdown(x);
	int mid=(dat[x].l+dat[x].r)>>1;
	if(p<=mid)change(p,LC(x),val);
	else change(p,RC(x),val);
	update(x);
}
void _negate(int l,int r,int x){
	node &X=dat[x];
	if(l<=X.l&&r>=X.r){
		X.tag^=1;
		X.mx=-1;X.mn*=-1;
		swap(X.mx,X.mn);
		return;
	}
	int mid=(X.l+X.r)>>1;
	pushdown(x); 
	if(l<=mid)_negate(l,r,LC(x));
	if(r>mid)_negate(l,r,RC(x));
	update(x);
}
int query(int l,int r,int x){
	node &X=dat[x];
	if(l<=X.l&&r>=X.r){
		return X.mx;
	}
	int mid=(X.l+X.r)>>1,ans=-INF;
	pushdown(x);
	if(l<=mid)ans=max(ans,query(l,r,LC(x)));
	if(r>mid)ans=max(ans,query(l,r,RC(x)));
	return ans;
}
void Negate(int a,int b){
	int ta=top[a],tb=top[b];
	while(ta!=tb){
		if(dep[ta]<dep[tb]){swap(ta,tb);swap(a,b);}
		_negate(id[a],id[ta],1);
		a=fa[ta],ta=top[a]; 
	}
	if(dep[a]>dep[b])swap(a,b);
	_negate(id[a],id[b],1);
}
int Max(int a,int b){
	int ta=top[a],tb=top[b],ans=-INF;
	while(ta!=tb){
		if(dep[ta]<dep[tb]){swap(ta,tb);swap(a,b);}
		ans=max(ans,query(id[a],id[ta],1));
		a=fa[ta],ta=top[a];
	}
	if(a==b)return ans;
	if(dep[a]>dep[b])swap(a,b);
	ans=max(ans,query(son[id[a]],id[b],1));
	return ans;
}
int main(){
	int T;scanf("%d",&T);
	char str[13];
	while(T--){
		scanf("%d",&n);
		int u,v,t;tot=0;
		memset(dat,0,sizeof(dat));
		memset(to,0,sizeof(to));
		memset(w,0,sizeof(w));
		for(int i=1;i<=n;i++)g[i].clear();
		es.clear();
		//printf("!!!");
		for(int i=1;i<n;i++){
			scanf("%d%d%d",&u,&v,&t);
			addedge(u,v,t);
		}
		dfs(1,1);
		build_tree(1,1);
		build(w,1,n,1);
		while(scanf("\n%s",str),str[0]!='D'){
			scanf("%d%d",&u,&v);
			if(str[0]=='C'){
				change(id[es[(u-1)*2].k],1,v);
				//cout<<es[u].k<<endl;
				//cout<<to[u]<<id[to[u]]<<endl;
				//cout<<query(id[to[u]],id[to[u]],1)<<endl;;
			}
			else if(str[0]=='N')Negate(id[u],id[v]);
			else if(str[0]=='Q')printf("%d\n",Max(id[u],id[v])); 
		}
	}
	return 0;
}

