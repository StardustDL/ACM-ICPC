/*

*/
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<queue>
#include<bitset>
#include<stack>
using namespace std;
const int MAXN=1000,INF=0x3f3f3f3f;
namespace Graph {
	struct edge {
		int u,v,nxt;
	} es[MAXN*MAXN+3];
	int head[MAXN+3],tot;
	void addedge(int u,int v) {
		tot++;
		es[tot].u=u,es[tot].v=v;
		es[tot].nxt=head[u];
		head[u]=tot;
	}
	void init() {
		tot=0;
		memset(head,0,sizeof(head));
	}

	void topo_sort(int n,vector<int> &ans) {
		static int rd[MAXN+3];
		static queue<int> q;
		memset(rd,0,sizeof(rd));
		while(!q.empty())q.pop();
		for(int i=1; i<=tot; i++)rd[es[i].v]++;
		for(int i=1; i<=n; i++)if(rd[i]==0)ans.push_back(i),q.push(i);
		while(!q.empty()) {
			int u=q.front();
			q.pop();
			for(int i=head[u]; i; i=es[i].nxt) {
				if(rd[es[i].v]) {
					rd[es[i].v]--;
					if(rd[es[i].v]==0)ans.push_back(es[i].v),q.push(es[i].v);
				}
			}
		}
	}
}
namespace MinDist {
	struct edge {
		int u,v,nxt,w;
	} es[MAXN*MAXN+3];
	int head[MAXN+3],tot;
	void addedge(int u,int v,int w) {
		tot++;
		es[tot].u=u,es[tot].v=v;
		es[tot].w=w;
		es[tot].nxt=head[u];
		head[u]=tot;
	}
	void init() {
		tot=0;
		memset(head,0,sizeof(head));
	}

	int d[MAXN+3];
	typedef pair<int,int> pnode;
	void dijkstra(int S) {
		static priority_queue<pnode>pq;
		while(!pq.empty())pq.pop();
		memset(d,INF,sizeof(d));
		d[S]=0;
		pq.push(make_pair(0,S));
		while(!pq.empty()) {
			pnode u=pq.top();
			pq.pop();
			if(d[u.second]<u.first)continue;
			for(int i=head[u.second]; i; i=es[i].nxt) {
				if(d[es[i].v]>d[u.second]+es[i].w) {
					d[es[i].v]=d[u.second]+es[i].w;
					pq.push(make_pair(d[es[i].v],es[i].v));
				}
			}
		}
	}
	void spfa(int S) {
		static queue<int> q;
		static bool inq[MAXN+3];
		while(!q.empty())q.pop();
		memset(d,INF,sizeof(d));
		d[S]=0;
		q.push(S);
		inq[S]=1;
		while(!q.empty()) {
			int u=q.front();
			q.pop();
			inq[u]=0;
			for(int i=head[u]; i; i=es[i].nxt) {
				if(d[es[i].v]>d[u]+es[i].w) {
					d[es[i].v]=d[u]+es[i].w;
					if(!inq[es[i].v]) {
						inq[es[i].v]=1;
						q.push(es[i].v);
					}
				}
			}
		}
	}
	void floyd(int d[MAXN+3][MAXN+3],int n) {
		for(int k=1; k<=n; k++) {
			for(int i=1; i<=n; i++) {
				for(int j=1; j<=n; j++)
					d[i][j]=min(d[i][j],d[i][k]+d[k][j]);
			}
		}
	}
}
namespace Connexity_Undirected {
	struct edge {
		int u,v,nxt;
	} es[2*MAXN*MAXN+3];
	int head[MAXN+3],tot;
	vector<int> bridges;
	int dfsn[MAXN+3],time;
	bool iscut[MAXN+3];
	void _addedge(int u,int v) {
		tot++;
		es[tot].u=u,es[tot].v=v;
		es[tot].nxt=head[u];
		head[u]=tot;
	}
	void addedge(int u,int v) {
		_addedge(u,v);
		_addedge(v,u);
	}
	void init() {
		tot=1;
		memset(head,0,sizeof(head));
	}
	int dfs_cut(int u,int fa) {
		int lowu=dfsn[u]=++time,child=0;
		for(int i=head[u]; i; i=es[i].nxt) {
			int v=es[i].v;
			if(!dfsn[v]) {
				child++;
				int lowv=dfs_cut(v,u);
				lowu=min(lowv,lowu);

				if(lowv>=dfsn[u]) {
					iscut[u]=1;
					if(lowv!=dfsn[u])bridges.push_back(i);
				}
			} else if(v!=fa && dfsn[v]<dfsn[u]) {
				lowu=min(lowu,dfsn[v]);
			}
		}
		if(fa==-1&&child==1)iscut[u]=0;
		return lowu;
	}
	void get_cut_bridges() {
		memset(iscut,0,sizeof(iscut));
		memset(dfsn,0,sizeof(dfsn));
		time=0;
		bridges.clear();
		dfs_cut(1,-1);
	}

	int bcccnt;
	vector<int> bccs[MAXN+3];
	int bccno[MAXN+3];
	stack<int> sta;
	int dfs_bcc(int u,int fa) {
		int lowu=dfsn[u]=++time,child=0;
		for(int i=head[u]; i; i=es[i].nxt) {
			int v=es[i].v;
			if(!dfsn[v]) {
				sta.push(i);
				child++;
				int lowv=dfs_bcc(v,u);
				lowu=min(lowv,lowu);

				if(lowv>=dfsn[u]) {
					iscut[u]=1;
					bccs[++bcccnt].clear();
					while(1) {
						edge e=es[sta.top()];
						sta.pop();
						if(bccno[e.u]!=bcccnt)bccno[e.u]=bcccnt,bccs[bcccnt].push_back(e.u);
						if(bccno[e.v]!=bcccnt)bccno[e.v]=bcccnt,bccs[bcccnt].push_back(e.v);
						if(e.v==v&&e.u==u)break;
					}
				}
			} else if(v!=fa && dfsn[v]<dfsn[u]) {
				sta.push(i);
				lowu=min(lowu,dfsn[v]);
			}
		}
		if(fa==-1&&child==1)iscut[u]=0;
		return lowu;
	}
	void get_bcc(int n) {
		memset(iscut,0,sizeof(iscut));
		memset(dfsn,0,sizeof(dfsn));
		time=0;
		while(!sta.empty())sta.pop();
		bcccnt=0;
		for(int i=1; i<=n; i++)
			if(dfsn[i]==0)dfs_bcc(i,-1);
	}

	bool isbridge[MAXN*MAXN+3];
	int ebcccnt;
	vector<int> ebccs[MAXN+3];
	int ebccno[MAXN+3];
	int dfs_bridge(int u,int fa) {
		int lowu=dfsn[u]=++time,child=0;
		for(int i=head[u]; i; i=es[i].nxt) {
			edge e=es[i];
			if(!dfsn[e.v]) {
				child++;
				int lowv=dfs_bridge(e.v,u);
				lowu=min(lowu,lowv);
				if(lowv>dfsn[u]) {
					isbridge[i]=isbridge[i^1]=1;
				}
			} else if(e.v!=fa&&dfsn[e.v]<dfsn[u]) {
				lowu=min(dfsn[e.v],lowu);
			}
		}
		return lowu;
	}
	void dfs_ebcc(int u,int ebcno) {
		if(ebccno[u]!=ebcno) {
			ebccs[ebcno].push_back(u);
			ebccno[u]=ebcno;
		}
		for(int i=head[u]; i; i=es[i].nxt) {
			edge t=es[i];
			if(isbridge[i]||dfsn[t.v]!=0)continue;
			if(ebccno[t.v]!=ebcno) {
				ebccs[ebcno].push_back(t.v);
				ebccno[t.v]=ebcno;
			}
			dfsn[t.v]=1;
			dfs_ebcc(t.v,ebcno);
		}
	}
	void get_ebcc(int n) {
		memset(isbridge,0,sizeof(isbridge));
		memset(dfsn,0,sizeof(dfsn));
		time=0;
		dfs_bridge(1,0);
		ebcccnt=0;
		memset(dfsn,0,sizeof(dfsn));
		for(int i=1; i<=n; i++) {
			if(!dfsn[i]) {
				++ebcccnt;
				ebccs[ebcccnt].clear();
				dfs_ebcc(i,ebcccnt);
			}
		}
	}
}
namespace Connexity_Directed {
	struct edge {
		int u,v,nxt;
	} es[MAXN*MAXN+3];
	int head[MAXN+3],tot;
	vector<int> bridges;
	int dfsn[MAXN+3],time,low[MAXN+3];
	void addedge(int u,int v) {
		tot++;
		es[tot].u=u,es[tot].v=v;
		es[tot].nxt=head[u];
		head[u]=tot;
	}
	void init() {
		tot=0;
		memset(head,0,sizeof(head));
	}

	int scc=0;
	vector<int> sccs[MAXN+3];
	int sccno[MAXN+3];
	stack<int> sta;

	void dfs(int u) {
		dfsn[u]=low[u]=++time;
		sta.push(u);
		for(int i=head[u]; i; i=es[i].nxt) {
			edge &e=es[i];
			if(!dfsn[e.v]) { //v未被访问
				dfs(e.v);
				low[u]=min(low[u],low[e.v]);
			} else if(!sccno[e.v]) { //v已被访问且v不属于任何连通分量
				low[u]=min(low[u],dfsn[e.v]);
			}
		}
		if(dfsn[u]==low[u]) { //找到一个连通分量
			sccs[++scc].clear();
			while(1) {
				int t=sta.top();
				sta.pop();
				sccs[scc].push_back(t);
				sccno[t]=scc;
				if(t==u)break;//遇到当前节点，退出
			}
		}
	}

	void get_scc(int n) {
		time=scc=0;
		memset(dfsn,0,sizeof(dfsn));
		memset(sccno,0,sizeof(sccno));
		for(int i=1; i<=n; i++)
			if(!dfsn[i]) dfs(i);
	}

	void TransitiveClosure(bool d[MAXN+3][MAXN+3],int n) {
		for(int k=1; k<=n; k++) {
			for(int i=1; i<=n; i++) {
				for(int j=1; j<=n; j++)
					d[i][j]|=d[i][k]&&d[k][j];
			}
		}
	}
}
namespace NetworkFlow {
	struct edge {
		int u,v,nxt,c;
	} es[MAXN*MAXN+3];
	int head[MAXN+3],tot;
	void _addedge(int u,int v,int c) {
		tot++;
		es[tot].u=u,es[tot].v=v;
		es[tot].c=c;
		es[tot].nxt=head[u];
		head[u]=tot;
	}
	void addedge(int u,int v,int c) {
		_addedge(u,v,c);
		_addedge(v,u,0);
	}
	void init() {
		tot=1;
		memset(head,0,sizeof(head));
	}
	int S,T;
	int d[MAXN+3];
	bool bfs() {
		static queue<int> q;
		while(!q.empty())q.pop();
		memset(d,-1,sizeof(d));
		d[S]=0;
		q.push(S);
		while(!q.empty()) {
			int u=q.front();
			q.pop();
			for(int i=head[u]; i; i=es[i].nxt) {
				if(d[es[i].v]==-1&&es[i].c) {
					d[es[i].v]=d[u]+1;
					q.push(es[i].v);
				}
			}
		}
		return d[T]!=-1;
	}
	int cur[MAXN+3];
	int dfs(int u,int a) {
		if(u==T||a==0)return a;
		int flow=0;
		for(int &i=cur[u]; i; i=es[i].nxt) {
			if(d[es[i].v]==d[u]+1) {
				int w=dfs(es[i].v,min(es[i].c,a));
				if(w==0)continue;
				flow+=w;
				a-=w;
				es[i].c-=w;
				es[i^1].c+=w;
				if(a==0)break;
			}
		}
		if(flow==0)d[u]=-1;
		return flow;
	}
	int Maxflow(int n) {
		int ans=0;
		while(bfs()) {
			for(int i=1; i<=n; i++)cur[i]=head[i];
			ans+=dfs(S,INF);
		}
		return ans;
	}
}
namespace NetworkFlowWithCost {
	struct edge {
		int u,v,nxt,c,w;
	} es[MAXN*MAXN+3];
	int head[MAXN+3],tot;
	void _addedge(int u,int v,int c,int w) {
		tot++;
		es[tot].u=u,es[tot].v=v;
		es[tot].c=c;
		es[tot].w=w;
		es[tot].nxt=head[u];
		head[u]=tot;
	}
	void addedge(int u,int v,int c,int w) {
		_addedge(u,v,c,w);
		_addedge(v,u,0,-w);
	}
	void init() {
		tot=1;
		memset(head,0,sizeof(head));
	}
	int S,T;
	int d[MAXN+3];
	bool inq[MAXN+3];
	int pre[MAXN+3];
	bool spfa() {
		static queue<int> q;
		while(!q.empty())q.pop();
		memset(d,INF,sizeof(d));
		memset(inq,0,sizeof(inq));
		memset(pre,0,sizeof(pre));
		d[S]=0;
		inq[S]=1;
		q.push(S);
		while(!q.empty()) {
			int u=q.front();
			q.pop();
			inq[u]=0;
			for(int i=head[u]; i; i=es[i].nxt) {
				if(es[i].c && d[es[i].v]>d[u]+es[i].w) {
					d[es[i].v]=d[u]+es[i].w;
					pre[es[i].v]=i;
					if(!inq[es[i].v]) {
						q.push(es[i].v);
						inq[es[i].v]=1;
					}
				}
			}
		}
		return d[T]<INF;
	}
	int Cost;
	int augment() {
		int flow=INF;
		for(int i=pre[T]; i; i=pre[es[i].u])flow=min(flow,es[i].c);
		Cost+=flow*d[T];
		for(int i=pre[T]; i; i=pre[es[i].u])es[i].c-=flow,es[i^1].c+=flow;
		return flow;
	}
	int Maxflow(int n) {
		int ans=0;
		Cost=0;
		while(spfa())
			ans+=augment();
		return ans;
	}
}
namespace LCA {
	struct edge {
		int u,v,nxt;
	} es[2*MAXN+3];
	int head[MAXN+3],tot;
	void _addedge(int u,int v) {
		tot++;
		es[tot].u=u,es[tot].v=v;
		es[tot].nxt=head[u];
		head[u]=tot;
	}
	void addedge(int u,int v) {
		addedge(u,v);
		addedge(v,u);
	}
	void init() {
		tot=0;
		memset(head,0,sizeof(head));
	}
	const int POW=18;
	int pa[MAXN+3][POW],dep[MAXN+3];
	void dfs(int u,int fa) {
		dep[u]=dep[fa]+1;
		pa[u][0]=fa;
		for(int i=1; i<POW; i++)pa[u][i]=pa[pa[u][i-1]][i-1];
		for(int i=head[u]; i; i=es[i].nxt)if(es[i].v!=fa)dfs(es[i].v,u);
	}
	void pre() {
		dep[1]=1;
		dfs(1,0);
	}
	int lca(int a,int b) {
		if(dep[a]<dep[b])swap(a,b);
		int h=dep[a]-dep[b];
		for(int i=0; i<POW; i++)if(h>>i&1)a=pa[a][i];
		if(a==b)return a;
		else {
			for(int i=POW-1; i>=0; i--)if(pa[a][i]!=pa[b][i])a=pa[a][i],b=pa[b][i];
			return a==b?a:pa[a][0];
		}
	}
}
namespace MST {
	int pa[MAXN+3];
	int find(int x) {
		return pa[x]==0?x:pa[x]=find(pa[x]);
	}
	typedef pair<int,int> _pair;
	typedef pair<int,_pair> mst_edge;
	int Mst(vector<mst_edge> &es,int n) {
		memset(pa,0,sizeof(pa));
		sort(es.begin(),es.end());
		int ans=0;
		for(int i=0; i<es.size(); i++) {
			_pair t=es[i].second;
			if(find(t.first)!=find(t.second)) {
				pa[find(t.first)]=find(t.second);
				ans+=es[i].first;
			}
		}
		return ans;
	}
}
namespace TreeCount {
	typedef long long LL;
	LL c[MAXN+3][MAXN+3];
	void init() {
		memset(c,0,sizeof(c));
	}
	void addedge(int u,int v) {
		c[u][u]++;
		c[u][v]--;
		c[v][v]++;
		c[v][u]--;
	}
	LL det(int n,LL MOD) {
		for(int i=1; i<=n; i++)for(int j=1; j<=n; j++)(c[i][j]+=MOD)%=MOD;
		bool flg=false;
		LL ans=1;
		for(int i=1; i<=n; i++) {
			for(int j=i+1; j<=n; j++) {
				LL a=c[i][i],b=c[j][i];
				while(b) {
					LL t=a/b;
					a%=b;
					swap(a,b);
					for(int k=i; k<=n; k++)
						((c[i][k]-=t*c[j][k]%MOD)+=MOD)%=MOD;
					for(int k=i; k<=n; k++)swap(c[i][k],c[j][k]);
					flg=!flg;
				}
			}
			if(!c[i][i])return 0;
			(ans*=c[i][i])%=MOD;
		}
		return flg?((MOD-ans)%MOD):ans;
	}
	LL solve(int n,LL MOD) {
		return det(n-1,MOD);
	}
}
namespace TreeDivide {
	typedef long long LL;
	LL sum[MAXN*10+3],dis[MAXN+3];
	int fa[MAXN+3],sz[MAXN+3],dep[MAXN+3],id[MAXN+3],dfstime=0,tag[MAXN+3],dfsn[MAXN+3],top[MAXN+3];
	int n,m;
	struct edge {
		int v;
		LL w;
		edge(int v,LL w):v(v),w(w) {}
	};
	vector<edge> g[MAXN+3];
	void dfs(int u) {
		sz[u]=1;
		for(int i=0; i<g[u].size(); i++) {
			edge& e=g[u][i];
			if(e.v==fa[u])continue;
			fa[e.v]=u;
			dis[e.v]=dis[u]+e.w;
			dep[e.v]=dep[u]+1;
			dfs(e.v);
			sz[u]+=sz[e.v];
		}
	}
	void div_tree(int u,int tp) {
		id[u]=++dfstime;
		dfsn[dfstime]=u;
		top[u]=tp;
		int son=0;//注意初值
		for(int i=0; i<g[u].size(); i++) {
			edge &e=g[u][i];
			if(e.v==fa[u])continue;
			if(sz[son]<sz[e.v])son=e.v;
		}
		if(son)div_tree(son,tp);
		for(int i=0; i<g[u].size(); i++) {
			edge &e=g[u][i];
			if(e.v==fa[u] || e.v==son)continue;
			div_tree(e.v,e.v);
		}
	}
	void update(int x,int l,int r) {
		if(l!=r)sum[x]=sum[x<<1]+sum[x<<1|1];
	}
	void add_tag(int x,int l,int r,int ad) {
		tag[x]+=ad;
		sum[x]+=(r-l+1)*ad;
	}
	void down_tag(int x,int l,int r) {
		if(tag[x]==0)return;
		if(l==r)return;
		int mid=(l+r)>>1;
		add_tag(x<<1,l,mid,tag[x]);
		add_tag(x<<1|1,mid+1,r,tag[x]);
		tag[x]=0;
	}
	void _modify(int x,int l,int r,int L,int R,int ad) {
		if(L<=l&&R>=r) {
			add_tag(x,l,r,ad);
		} else {
			down_tag(x,l,r);
			int mid=(l+r)>>1;
			if(L<=mid)_modify(x<<1,l,mid,L,R,ad);
			if(R>mid)_modify(x<<1|1,mid+1,r,L,R,ad);
		}
		update(x,l,r);
	}
	LL _query(int x,int l,int r,int L,int R) {
		if(L<=l&&R>=r)return sum[x];
		LL res=0;
		down_tag(x,l,r);
		int mid=(l+r)>>1;
		if(L<=mid)res+=_query(x<<1,l,mid,L,R);
		if(R>mid)res+=_query(x<<1|1,mid+1,r,L,R);
		return res;
	}
	int lca(int a,int b) {
		while(top[a]!=top[b]) {
			if(dep[top[a]]<dep[top[b]])swap(a,b);
			a=fa[top[a]];
		}
		return dep[a]<dep[b]?a:b;
	}
	void modify_lv(int v,int lc,int ad) {
		while(top[v]!=top[lc]) {
			int tp=top[v];
			_modify(1,1,n,id[tp],id[v],ad);
			v=fa[tp];
		}
		_modify(1,1,n,id[lc],id[v],ad);
	}
	void modify(int l,int r,int ad) {
		int lc=lca(l,r);
		modify_lv(l,lc,ad);
		modify_lv(r,lc,ad);
	}
	LL query(int l,int r) {
		LL res=INF;
		while(top[l]!=top[r]) {
			if(dep[top[l]]<dep[top[r]])swap(l,r);
			res+=_query(1,1,n,id[top[l]],id[l]);
			l=fa[top[l]];
		}
		if(dep[l]>dep[r])swap(l,r);
		res+=_query(1,1,n,id[l],id[r]);
		return res;
	}
}
namespace Tree_Vertex_Divide {
	struct edge {
		int u,v,w;
		edge(int u,int v,int w):u(u),v(v),w(w) {}
	};
	int N,K;
	vector<int> g[MAXN+3];
	bitset<MAXN+3> vis=0;
	vector<edge> es;
	void addedge(int u,int v,int w) {
		es.push_back(edge(u,v,w));
		es.push_back(edge(v,u,w));
		g[u].push_back(es.size()-2);
		g[v].push_back(es.size()-1);
	}
	namespace TreeCenter {
		int sz[MAXN+3],ans,mx,n;
		void dfs(int u,int fa) {
			sz[u]=1;
			int res=0;
			for(int i=0; i<g[u].size(); i++) {
				edge &e=es[g[u][i]];
				if(e.v==fa||vis[e.v])continue;
				dfs(e.v,u);
				sz[u]+=sz[e.v];
				res=max(res,sz[e.v]);
			}
			res=max(res,n-sz[u]);
			if(res<mx) {
				ans=u,mx=res;
			}
		}
		int getCenter(int root) {
			ans=0,mx=INF;
			dfs(root,-1);
			return ans;
		}
	}
	vector<int> dat;
	int dis[MAXN+3];
	void builddata(int u,int pa) {
		dat.push_back(dis[u]);
		for(int i=0; i<g[u].size(); i++) {
			edge &e=es[g[u][i]];
			if(e.v==pa||vis[e.v])continue;
			dis[e.v]=dis[u]+e.w;
			builddata(e.v,u);
		}
	}
	int calc(int u,int d) {
		dis[u]=d;
		dat.clear();
		builddata(u,-1);
		sort(dat.begin(),dat.end());
		int ans=0,l=0,r=dat.size()-1;
		while(l<r) {
			if(dat[l]+dat[r]<=K)ans+=r-l++;
			else r--;
		}
		return ans;
	}
	int ans=0;
	void solve(int u) {
		ans+=calc(u,0);
		vis[u]=1;
		for(int i=0; i<g[u].size(); i++) {
			edge &e=es[g[u][i]];
			if(vis[e.v])continue;
			ans-=calc(e.v,e.w);
			TreeCenter::n=TreeCenter::sz[e.v];
			solve(TreeCenter::getCenter(e.v));
		}
	}
	int Ans(int root) {
		ans=0;
		vis=0;
		TreeCenter::n=N;
		solve(TreeCenter::getCenter(root));
		return ans;
	}
}
int main() {

	return 0;
}

