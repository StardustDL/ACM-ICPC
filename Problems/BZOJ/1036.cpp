/*
[ZJOI2008]树的统计Count
分析：树链剖分，线段树单点修改，区间查询 
*/ 
#include<cstdio>
#include<cstring>
#include<algorithm>
#define LC(x) (x<<1)
#define RC(x) (x<<1|1)
using namespace std;
const int INF=1<<30,MAXN=30010;
struct Edge{
    int u,v,next;
    Edge(){}
    Edge(int u,int v,int next):u(u),v(v),next(next){}
}edge[MAXN<<1];
int head[MAXN],cnt;
int sz[MAXN],top[MAXN],fa[MAXN],dep[MAXN],pos[MAXN],w[MAXN],son[MAXN],num;
void init(){memset(head,-1,sizeof(head));cnt=num=0;}
void add(int u,int v){
    edge[cnt]=Edge(u,v,head[u]);head[u]=cnt++;
    edge[cnt]=Edge(v,u,head[v]);head[v]=cnt++;
}
void dfs(int u,int d){
    sz[u]=1;son[u]=0;dep[u]=d;
    for(int k=head[u];k!=-1;k=edge[k].next){
        int v=edge[k].v;
        if(v==fa[u])continue;
        fa[v]=u;
        dfs(v,d+1);
        sz[u]+=sz[v];
        if(sz[v]>sz[son[u]])son[u]=v;
    }
}
void build_tree(int u,int pre){
	pos[u]=++num;top[u]=pre;
    if(son[u])build_tree(son[u],pre);
    for(int k=head[u];k!=-1;k=edge[k].next){
        int v=edge[k].v;
        if(v!=fa[u]&&v!=son[u])build_tree(v,v);
    }
}
struct segtree{
    int mx[MAXN<<2],sum[MAXN<<2];
    void update(int n){
        sum[n]=sum[LC(n)]+sum[RC(n)];
        mx[n]=max(mx[LC(n)],mx[RC(n)]);
    }
    void change(int nn,int x,int l,int r,int n){
        if(l==r){mx[n]=sum[n]=x;return;}
        int m=(l+r)>>1;
        if(nn<=m)change(nn,x,l,m,LC(n));
        else change(nn,x,m+1,r,RC(n));
        update(n);
    }
    int Max(int ll,int rr,int l,int r,int n){
        if(ll==l&&rr==r)return mx[n];
        int m=(l+r)>>1;
        if(rr<=m)return Max(ll,rr,l,m,LC(n));
        else if(ll>m)return Max(ll,rr,m+1,r,RC(n));
        else return max(Max(ll,m,l,m,LC(n)),Max(m+1,rr,m+1,r,RC(n)));
    }
    int Sum(int ll,int rr,int l,int r,int n){
		if(ll==l&&rr==r)return sum[n];
        int m=(l+r)>>1;
        if(rr<=m)return Sum(ll,rr,l,m,LC(n));
        else if(ll>m)return Sum(ll,rr,m+1,r,RC(n));
        else return Sum(ll,m,l,m,LC(n))+Sum(m+1,rr,m+1,r,RC(n));
    }
}seg;
int QueryMax(int a,int b,int n){
    int ta=top[a],tb=top[b],ans=-INF;
    while(ta!=tb){
        if(dep[ta]<dep[tb]){swap(ta,tb);swap(a,b);}
        ans=max(ans,seg.Max(pos[ta],pos[a],1,n,1));
        a=fa[ta];ta=top[a];
    }
    if(dep[a]>dep[b])swap(a,b);
	return max(ans,seg.Max(pos[a],pos[b],1,n,1));
}
int QuerySum(int a,int b,int n){
    int ta=top[a],tb=top[b],ans=0;
    while(ta!=tb){
        if(dep[ta]<dep[tb]){swap(ta,tb);swap(a,b);}
		ans+=seg.Sum(pos[ta],pos[a],1,n,1);
		a=fa[ta];ta=top[a];
    }
    if(dep[a]>dep[b])swap(a,b);
    return ans+seg.Sum(pos[a],pos[b],1,n,1);
}
int main(){
    int n,a,b,q;
    char op[10];
    while(~scanf("%d",&n)){
        init();
        for(int i=1;i<n;i++){
			scanf("%d%d",&a,&b);
            add(a,b);
        }
        for(int i=1;i<=n;i++)scanf("%d",&w[i]);
        dfs(1,1);
		build_tree(1,1);
    	for(int i=1;i<=n;i++)seg.change(pos[i],w[i],1,n,1);
        scanf("%d",&q);
        while(q--){
            scanf("%s%d%d",op,&a,&b);
            if(strcmp(op,"QMAX")==0){
                printf("%d\n",QueryMax(a,b,n));
            }else if(strcmp(op,"QSUM")==0){
                printf("%d\n",QuerySum(a,b,n));
            }else seg.change(pos[a],b,1,n,1);
        }
    }
    return 0;
}
