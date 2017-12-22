/*
[Sdoi2016]游戏
分析：线段树维护直线，每个节点维护直线与区间最小值，最小值只有可能在直线两端点 取得，
		对于一条直线的下传，可以求出当前两条直线的交点，把试用范围小的一条下传下去 ，更新mn 
		查询时，查询所有访问节点的直线最小值和mn值
	  这题卡栈 
*/
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<queue>
using namespace std;
const int MAXN=100000;
typedef long long LL;
const LL INF=123456789123456789LL;
LL mn[MAXN*10+3],A[MAXN*10+3],B[MAXN*10+3],dis[MAXN+3];
int fa[MAXN+3],sz[MAXN+3],dep[MAXN+3],id[MAXN+3],dfstime=0,hastag[MAXN*10+3],dfsn[MAXN+3],top[MAXN+3];
int n,m;
struct edge{
	int v;LL w;
	edge(int v,LL w):v(v),w(w){}
};
vector<edge> g[MAXN+3];
/*queue<int> q;
void bfs(int s){
	while(!q.empty())q.pop();
	q.push(s);
	while(!q.empty()){
		int u=q.front();q.pop();sz[u]=1;
		for(int i=0;i<g[u].size();i++){
			edge& e=g[u][i];
			if(e.v==fa[u])continue;
			fa[e.v]=u;
			dis[e.v]=dis[u]+e.w;
			dep[e.v]=dep[u]+1;
			dfs(e.v);
			sz[u]+=sz[e.v];
		}
	}
}*/
void dfs(int u){
	sz[u]=1;
	for(int i=0;i<g[u].size();i++){
		edge& e=g[u][i];
		if(e.v==fa[u])continue;
		fa[e.v]=u;
		dis[e.v]=dis[u]+e.w;
		dep[e.v]=dep[u]+1;
		dfs(e.v);
		sz[u]+=sz[e.v];
	}
}
void div_tree(int u,int tp){
	id[u]=++dfstime;
	dfsn[dfstime]=u;
	top[u]=tp;
	int son=0;//注意初值 
	for(int i=0;i<g[u].size();i++){
		edge &e=g[u][i];
		if(e.v==fa[u])continue;
		if(sz[son]<sz[e.v])son=e.v;
	}
	if(son)div_tree(son,tp);
	for(int i=0;i<g[u].size();i++){
		edge &e=g[u][i];
		if(e.v==fa[u] || e.v==son)continue;
		div_tree(e.v,e.v);
	}
}
void update(int x,int l,int r){
	if(hastag[x])mn[x]=min(A[x]*(dis[dfsn[r]]-dis[dfsn[l]]),0LL)+B[x];
	if(l!=r)mn[x]=min(mn[x],min(mn[x<<1],mn[x<<1|1]));
}
void add_tag(int x,int l,int r,LL a,LL b){
	if(hastag[x]==0){
		A[x]=a,B[x]=b;hastag[x]=1;update(x,l,r);return;
	}
	if(A[x]==a||l==r){B[x]=min(B[x],b);update(x,l,r);return;}
	if(A[x]<a&&B[x]<b)return;
	else if(A[x]>a&&B[x]>b){A[x]=a;B[x]=b;update(x,l,r);return;}
	LL ta=A[x]-a,tb=b-B[x];int mid=(l+r)>>1;LL lmid=dis[dfsn[mid+1]]-dis[dfsn[l]];
	if(ta>0){//x<pos A[x] is good 
		LL pos=tb/ta;
		if(pos<=lmid){
			add_tag(x<<1,l,mid,A[x],B[x]);
			A[x]=a,B[x]=b;
		}
		else{
			add_tag(x<<1|1,mid+1,r,a,b+a*lmid);
		}
	}
	else{//x>pos A[x] is good 
		LL pos=(-tb-ta+1)/(-ta);//注意上取整 
		if(pos>lmid){
			add_tag(x<<1|1,mid+1,r,A[x],B[x]+A[x]*lmid);
			A[x]=a,B[x]=b;
		}
		else{
			add_tag(x<<1,l,mid,a,b);
		}
		/*LL pos=(B[x]-b+a-A[x]-1)/(a-A[x]);
		if(pos<=lmid)add_tag(x<<1,l,mid,a,b);
		else{
			add_tag(x<<1|1,mid+1,r,A[x],B[x]+A[x]*lmid);
			A[x]=a;B[x]=b;
		}*/
	}
	update(x,l,r);
}
void _modify(int x,int l,int r,int L,int R,LL a,LL b){
	if(L<=l&&R>=r){
		add_tag(x,l,r,a,b+a*(dis[dfsn[l]]-dis[dfsn[L]]));
	}
	else{
		int mid=(l+r)>>1;
		if(L<=mid)_modify(x<<1,l,mid,L,R,a,b);
		if(R>mid)_modify(x<<1|1,mid+1,r,L,R,a,b);
	}
	update(x,l,r);
}
LL _query(int x,int l,int r,int L,int R){
	LL res=INF;
	if(hastag[x]){
		int tl=max(l,L),tr=min(r,R);
		res=min(res,min(A[x]*(dis[dfsn[tl]]-dis[dfsn[l]]),A[x]*(dis[dfsn[tr]]-dis[dfsn[l]]))+B[x]);
	}
	if(L<=l&&R>=r)return min(res,mn[x]);
	int mid=(l+r)>>1;
	if(L<=mid)res=min(res,_query(x<<1,l,mid,L,R));
	if(R>mid)res=min(res,_query(x<<1|1,mid+1,r,L,R));
	return res;
}
int lca(int a,int b){
	while(top[a]!=top[b]){
		if(dep[top[a]]<dep[top[b]])swap(a,b);
		a=fa[top[a]];
	}
	return dep[a]<dep[b]?a:b;
}
void modify_lv(int v,int lc,LL a,LL b){//以lc为中心，向两边处理距离 
	while(top[v]!=top[lc]){
		int tp=top[v];
		_modify(1,1,n,id[tp],id[v],a,b+a*(dis[tp]-dis[lc]));
		v=fa[tp];
	}
	_modify(1,1,n,id[lc],id[v],a,b);
}
void modify(int l,int r,LL a,LL b){//注意拆解修改 
	int lc=lca(l,r);
	modify_lv(l,lc,-a,b+a*(dis[l]-dis[lc]));
	modify_lv(r,lc,a,b+a*(dis[l]-dis[lc]));
}
LL query(int l,int r){
	LL res=INF;
	while(top[l]!=top[r]){
		if(dep[top[l]]<dep[top[r]])swap(l,r);
		res=min(res,_query(1,1,n,id[top[l]],id[l]));
		l=fa[top[l]];
	}
	if(dep[l]>dep[r])swap(l,r);
	res=min(res,_query(1,1,n,id[l],id[r]));
	return res;
}
int main(){
	/*freopen("menci_game20.in","r",stdin);
	freopen("3.out","w",stdout);*/
    bool line = true;
	scanf("%d%d",&n,&m);
	for(int a,b,i=1;i<n;i++){
		LL w;
		scanf("%d%d%lld",&a,&b,&w);
		g[a].push_back(edge(b,w));
		g[b].push_back(edge(a,w));
		if(b != a+1) line = false;
	}
	if(line)
    {
        for(int i=1;i<=n;i++) 
        {
            fa[i] = i-1; sz[i] = n+1-i; dep[i] = i; id[i] = dfsn[i] = i; top[i] = 1;
            for(int j=0;j<g[i].size();j++) if(g[i][j].v == i-1) dis[i] = dis[i-1]+g[i][j].w;
        }
    }
    else{
		dfs(1);
		div_tree(1,1);
	}
	for(int i=0;i<=MAXN*10;i++)mn[i]=INF;
	while(m--){
		int op,s,t;LL a,b;
		scanf("%d",&op);
		if(op==1){
			scanf("%d%d%lld%lld",&s,&t,&a,&b);
			modify(s,t,a,b);
		}
		else{
			scanf("%d%d",&s,&t);
			printf("%lld\n",query(s,t));
		}
	}
	/*fclose(stdin);
	fclose(stdout);*/
	return 0;
}

