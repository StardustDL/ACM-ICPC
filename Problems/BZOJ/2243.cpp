/*
[SDOI2011]染色
分析：树链剖分，注意c属于[0..1e9]，而且要注意两条链的相接触的端点颜色是否相同 
	  但自己的代码WA，拷了一份网上的AC，抽个时间看看 
*/
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<bitset>
#include<vector> 
#define LC(x) (x<<1)
#define RC(x) (x<<1|1)
using namespace std;
const int INF=0x3f3f3f3f,MAXN=100000;
vector<int> g[MAXN+3];
int dep[MAXN+3],fa[MAXN+3],son[MAXN+3],sz[MAXN+3],w[MAXN+3],id[MAXN+3],top[MAXN+3],tot=0,val[MAXN+3]; 
void addedge(int u,int v){
	g[u].push_back(v);
	g[v].push_back(u);
}
/*void dfs(int u,int p){
	fa[u]=p;dep[u]=dep[p]+1;sz[u]=1;int mx=0;
	for(int i=0;i<g[u].size();i++){
		if(g[u][i]==p)continue;
		dfs(g[u][i],u);
		sz[u]+=sz[g[u][i]];
		if(sz[g[u][i]]>mx){
			mx=sz[g[u][i]];
			son[u]=g[u][i];
		}
	}
}
void build(int u,int p){
	if(!son[u])return;
	top[son[u]]=top[u];
	id[son[u]]=++tot;
	build(son[u],u);
	for(int i=0;i<g[u].size();i++){
		if(g[u][i]==son[u]||g[u][i]==p)continue;
		top[g[u][i]]=g[u][i];
		id[g[u][i]]=++tot;
		build(g[u][i],u);//printf("%d %d\n",son[u],u); 
	}
}*/
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
		int l,r,lc,rc,sum,tag;
		node(){
			lc=rc=tag=-1;
			l=r=sum=0;
		}
	}ns[MAXN<<2];
	
	void update(int x){
		ns[x].sum=ns[LC(x)].sum+ns[RC(x)].sum-(ns[LC(x)].rc==ns[RC(x)].lc);
		ns[x].lc=ns[LC(x)].lc;
		ns[x].rc=ns[RC(x)].rc;
	}
	
	void pushdown(int x){
		if(ns[x].tag!=-1){
			node &l=ns[LC(x)],&r=ns[RC(x)];
			l.tag=ns[x].tag;
			r.tag=ns[x].tag;
			l.lc=l.rc=r.lc=r.rc=ns[x].tag;
			l.sum=r.sum=1;
			ns[x].tag=-1;
		}
	}
	
	void build(int *a,int l,int r,int x){
		ns[x].l=l,ns[x].r=r;
		if(l==r){
			ns[x].lc=ns[x].rc=a[l];
			ns[x].sum=1;
			return;
		}
		build(a,l,(l+r)>>1,LC(x));
		build(a,((l+r)>>1)+1,r,RC(x));
		update(x);
	}
	
	void change(int l,int r,int x,int val){
		node &X=ns[x];
		if(l<=X.l&&r>=X.r){
			X.tag=val;
			X.lc=X.rc=val;
			X.sum=1;
			return;
		}
		pushdown(x);
		int mid=(X.l+X.r)>>1;
		if(l<=mid)change(l,r,LC(x),val);
		if(r>mid)change(l,r,RC(x),val);
		update(x);
	}
	
	int query_color(int p,int x){
		if(ns[x].l==ns[x].r)return ns[x].lc;
		int mid=(ns[x].l+ns[x].r)>>1;pushdown(x);
		if(p<=mid)return query_color(p,LC(x));
		else return query_color(p,RC(x));
	}
	
	int query(int l,int r,int x){
		node &X=ns[x];
		if(l<=X.l&&r>=X.r)return X.sum;
		pushdown(x);
		int mid=(X.l+X.r)>>1;
		int ans=0;
		if(l<=mid)ans+=query(l,r,LC(x));
		if(r>mid)ans+=query(l,r,RC(x));
		return ans;
	}
}S;
void set(int a,int b,int val){
	int ta=top[a],tb=top[b];
	while(ta!=tb){
		if(dep[ta]<dep[tb]){
			swap(ta,tb);swap(a,b);	
		}
		S.change(id[ta],id[a],1,val);
		a=fa[ta];ta=top[a];
	}
	if(dep[a]>dep[b])swap(a,b);
	S.change(id[a],id[b],1,val);
}
int sum(int a,int b){
	int ans=0;
	int ta=top[a],tb=top[b];
	while(ta!=tb){
		if(dep[ta]<dep[tb]){swap(a,b);swap(ta,tb);}
		ans+=S.query(id[ta],id[a],1);
		a=fa[ta];
		if(S.query_color(id[a],1)==S.query_color(id[ta],1))ans--;
		ta=top[a];
	}
	if(dep[a]>dep[b])swap(a,b);
	return ans+S.query(id[a],id[b],1);
}
int n,m;
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)scanf("%d",&w[i]);
	int a,b,c;char t;
	for(int i=1;i<n;i++){
		scanf("%d%d",&a,&b);
		addedge(a,b);
	}
	dfs(1,1);
	build_tree(1,1);
	for(int i=1;i<=n;i++){
		val[id[i]]=w[i];
	}
	S.build(val,1,n,1);//printf("!!!");
	while(scanf("\n%c %d %d",&t,&a,&b)==3){
		if(t=='C'){
			scanf("%d",&c);
			set(a,b,c);
		}
		else if(t=='Q'){
			printf("%d\n",sum(a,b));
		}
	}
	return 0;
}
/*
#include <cstdio>
#include <cstdlib>
#include <algorithm>
char ch;
#define max(A, B)
#define son (k << 1)
#define mid ((l + r) >> 1)
#define gs (ch < '0' || ch > '9')
int getint() { int wis = 0; ch = getchar(); while (gs) ch = getchar(); while (!gs) wis = wis * 10 + ch - '0', ch = getchar(); return wis; }
const int ys = 300010;
using namespace std;

bool t[ys];
int n, m, nowp, sg, x, y, co;
int size[ys], da[ys], f[ys], up[ys], point[ys], v[ys], d[ys];
int g[ys], next[ys * 2], c[ys * 2], col[ys], push[ys * 4]; 

struct Lek
{
    int left, right, tot;
}   p[ys * 4];
void dfs(int z)
{
    t[z] = true;  size[z] = 1;  int w = 0;  
    for (int x = g[z]; x; x = next[x])
      if (!t[c[x]])  
        if (dfs(c[x]), size[z] += size[c[x]], size[c[x]] > w)
          point[z] = x, w = size[c[x]];    
}
void mak(int z, int dt)
{
    t[z] = false;   v[++sg] = z;  da[z] = sg;  f[z] = nowp;   d[z] = dt; 
    if (point[z])  mak(c[point[z]], dt);
    for (int x = g[z]; x; x = next[x])
      if (t[c[x]])  up[c[x]] = z, nowp = c[x], mak(c[x], dt + 1);
}
void marge(Lek &a, Lek b)
{
    a.tot += b.tot;
    if (a.left == b.right)  a.tot--;
    if (!a.right)  a.right = b.right;
    if (b.left)  a.left = b.left; 
}
Lek build(int l, int r, int k)
{
    if (l == r)  return p[k] = (Lek){col[v[l]], col[v[l]], 1};
    p[k] = build(mid + 1, r, son + 1);
    return marge(p[k], build(l, mid, son)), p[k]; 
}
void pus(int k)
{
    if (push[k])  
    p[son].right = p[son].left = p[son + 1].right = p[son + 1].left = push[k],
    p[son].tot = p[son + 1].tot = 1, push[son + 1] = push[son] = push[k], push[k] = 0;
}
Lek tot(int x, int y, int l, int r, int k)
{
    pus(k);
    if (y < l  ||  x > r)  return (Lek){0, 0, 0};
    if (x <= l  &&  y >= r)  return p[k];
    Lek q = tot(x, y, mid + 1, r, son + 1);
    return marge(q, tot(x, y, l, mid, son)), q; 
}
void cov(int x, int y, int c, int l, int r, int k)
{
    if (y < l  ||  x > r)  return;  pus(k);
    if (x <= l  &&  y >= r)  p[k] = (Lek){c, c, 1}, push[k] = c;
    else  cov(x, y, c, l, mid, son), cov(x, y, c, mid + 1, r, son + 1),
          p[k] = p[son + 1], marge(p[k], p[son]); 
}
int query(int x, int y)
{
    Lek y_tot = {0, 0, 0}, x_tot = {0, 0, 0};
    while (f[x] != f[y])
      if (d[f[x]] < d[f[y]])  marge(y_tot, tot(da[f[y]], da[y], 1, n, 1)), y = up[f[y]];
      else  marge(x_tot, tot(da[f[x]], da[x], 1, n, 1)), x = up[f[x]];  
    if (da[x] > da[y]) return swap(y_tot.left, y_tot.right), marge(x_tot, tot(da[y], da[x], 1, n, 1)), marge(x_tot, y_tot), x_tot.tot;
    else  return swap(x_tot.left, x_tot.right), marge(y_tot, tot(da[x], da[y], 1, n, 1)), marge(y_tot, x_tot), y_tot.tot;
}
void change(int x, int y, int c)
{
    while (f[x] != f[y])
      if (d[f[x]] < d[f[y]])  cov(da[f[y]], da[y], c, 1, n, 1), y = up[f[y]];
      else  cov(da[f[x]], da[x], c, 1, n, 1), x = up[f[x]];
    if (da[x] > da[y])  swap(x, y);
    cov(da[x], da[y], c, 1, n, 1);
}
void add(int x, int y)
{
    c[++sg] = y, next[sg] = g[x], g[x] = sg;
    c[++sg] = x, next[sg] = g[y], g[y] = sg;
}
int main()
{
    n = getint(); m = getint();
    for (int i = 1; i <= n; ++i)  col[i] = getint() + 1;
    for (int i = 1; i < n; ++i) 
      x = getint(), y = getint(), add(x, y);  
    sg = 0;
    dfs(1);  nowp = 1, mak(1, 1);  build(1, n, 1); 
    for (int i = 1; i <= m; ++i)
      {
          while (ch != 'C'  &&  ch != 'Q')  ch = getchar();
          if (ch == 'Q')  x = getint(), y = getint(), printf("%d\n", query(x, y));
          else  x = getint(), y = getint(), co = getint(), change(x, y, co + 1);
      }      
}
*/
