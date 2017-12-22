/*
Ombrophobic Bovines
题意：给定一个无向图，点i处有Ai头牛，点i处的牛棚能容纳Bi头牛，求一个最短时间T使得在T时间内所有的牛都能进到某一牛棚里去。（1?<=?N?<=?200,?1?<=?M?<=?1500,?0?<=?Ai?<=?1000,?0?<=?Bi?<=?1000,?1?<=?Dij?<=?1,000,000,000） 
分析：本来很水的一道题。。这么难AC
	  将每个点i拆成两个点i’, i’’，连边(s, i’, Ai), (i’’, t, Bi)。二分最短时间T，若d[i][j]<=T（d[i][j]表示点i, j之间的最短距离）则加边(i’, j’’, ∞)。每次根据最大流调整二分的上下界即可。 
*/

#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<queue>
#include<vector>
using namespace std;
typedef long long LL;
const LL INF = 1e16;
const int inf = 0x3f3f3f3f;
const int maxn = 410;
const int maxm = 160010;
struct Edge{ 
    int v, c, next;//指向点,流量,下一个点
}p[maxm<<1];
int head[maxn], e;
int d[maxn], cur[maxn];//层次记录，当前弧优化
int n, m, st, en;
void init(){
    e=0;
    memset(head, -1, sizeof(head));
}
void addEdge(int u, int v, int c){
    p[e].v = v; p[e].c = c; 
    p[e].next = head[u];head[u]=e++;
    p[e].v = u; p[e].c = 0; //无向图时逆边赋值流量cap，有向图时赋值0.
    p[e].next = head[v];head[v]=e++;
}
int bfs(int st, int en){
    queue<int> q;
    memset(d,0,sizeof(d));
    d[st]=1;
    q.push(st);
    while(!q.empty()){
        int u = q.front(); q.pop();
        for (int i = head[u]; i != -1; i = p[i].next){
            if (p[i].c > 0 && !d[p[i].v]){
                d[p[i].v] = d[u] + 1;
                q.push(p[i].v);
            }
        }
    }
    return d[en];
}
int dfs(int u, int a){//a表示流量
    if (u == en || a == 0) return a;
    int f, flow = 0;
    for (int& i = cur[u]; i != -1; i = p[i].next){
        if (d[u] + 1 == d[p[i].v] && (f = dfs(p[i].v,min(a,p[i].c))) > 0){
            p[i].c -= f;
            p[i^1].c += f;
            flow += f;
            a -= f;
            if (!a) break;
        }
    }
    return flow;
}
int dinic(int st, int en){
    int res = 0;
    while (bfs(st, en)){
        for (int i = 0; i <= n; ++i)cur[i] = head[i];
        res += dfs(st, inf);
    }
    return res;
}
int w[maxn], c[maxn], tt; 
LL a[maxn][maxn];
void rebuild(LL mid){
    init();
    for (int i = 1; i <= tt; ++i){
        addEdge(st, i, w[i]);
        addEdge(i + tt, en, c[i]);
    }
    for (int i = 1; i <= tt; ++i)addEdge(i, i + tt, inf);
    for (int i = 1; i <= tt; ++i){
        for (int j = i + 1; j <= tt; ++j)
            if (a[i][j] <= mid){
                addEdge(i, j + tt, inf);
                addEdge(j, i + tt, inf);
            }
    }
}
int main(){
    while(~scanf("%d%d",&n,&m)){
        tt=n;st=0;en=(n<<1)+1;
        int sum=0;
        for(int i=1;i<=n;++i){
            scanf("%d%d",&w[i],&c[i]);
            sum+=w[i];
        }
        for (int i = 1; i <= n; ++i)
            for (int j = 1; j <= n; ++j)
                a[i][j] = INF;
        for (int i = 1; i <= m; ++i){
            int uu, vv, len;
            scanf("%d%d%d", &uu, &vv, &len);
            if (len < a[uu][vv])
                a[uu][vv] = a[vv][uu] = len;
        }
        for (int k = 1; k <= n; ++k)
            for (int i = 1; i <= n; ++i)
                for (int j = 1; j <= n; ++j)
                    if (a[i][j]  > a[i][k] + a[k][j])
                        a[i][j] = a[i][k] + a[k][j];
        LL ans = -1, low = 0, high = INF - 1;
        n = en;
        while (low <= high){
            LL mid = (low + high) / 2;
            rebuild(mid);
            int tmp = dinic(st, en);
            if (tmp >= sum){
                ans = mid;
                high = mid - 1;
            }
            else low = mid + 1;
        }
        printf("%I64d\n",ans);
	}
    return 0;
}
/*#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<queue> 
#include<bitset>
using namespace std;
typedef long long LL;
const int MAXN=1500;
const LL INF=2000000000000LL;
LL ANS;
struct edge{
	int u,v,f,c;
	LL w;
	edge(int u,int v,int f,int c,LL w):u(u),v(v),f(f),c(c),w(w){};
};
struct graph{
	vector<edge> es;
	vector<int> g[MAXN+3];
	void init(int n){
		es.clear();
		for(int i=1;i<=n;i++)g[i].clear();
	}
	void addedge(int u,int v,int c,LL w){
		es.push_back(edge(u,v,0,c,w));
		es.push_back(edge(v,u,0,0,w));
		g[u].push_back(es.size()-2);
		g[v].push_back(es.size()-1);
	}
};
struct Dinic{
	int d[MAXN+3],cur[MAXN+3],s,t;
	queue<int> q;
	graph g;
	bool bfs(){
		memset(d,0,sizeof(d));
		while(!q.empty())q.pop();
		q.push(s);d[s]=1;
		while(!q.empty()){
			int k=q.front();q.pop();
			for(int i=0;i<g.g[k].size();i++){
				edge &e=g.es[g.g[k][i]];
				if(!d[e.v] && e.f<e.c){
					d[e.v]=d[k]+1;
					q.push(e.v);
				}
			}
		}
		return d[t]!=0;
	}
	int dfs(int u,int mn){
		if(u==t||mn==0)return mn;
		int rel=0,f;
		for(int &i=cur[u];i<g.g[u].size();i++){
			edge &e=g.es[g.g[u][i]];
			if(d[e.v]==d[u]+1 && (f=dfs(e.v,min(mn,e.c-e.f)))>0){
				e.f+=f;
				g.es[g.g[u][i]^1].f-=f;
				rel+=f;
				mn-=f;
				if(!mn)break;
			}
		}
		return rel;
	}

	int MaxFlow(int s,int t){
		this->s=s;this->t=t;
		int ans=0;
		while(bfs()){
			memset(cur,0,sizeof(cur));
			ans+=dfs(s,0x3f3f3f3f);
		}
		return ans;
	}
};
Dinic work;
LL mp[205][205];
int f,p,sum=0,a[205],b[205];
int main(){
	scanf("%d%d",&f,&p);
	for(int i=1;i<=f;i++){
		scanf("%d%d",&a[i],&b[i]);
		sum+=a[i];
	}
	for(int i=1;i<=f;i++){
		for(int j=1;j<=f;j++)mp[i][j]=INF;
	}
	for(int i=1;i<=f;i++)mp[i][i]=0; 
	for(int i=1;i<=p;i++){
		int x,y,z;
		scanf("%d%d%d",&x,&y,&z);
		if(mp[x][y]>z)mp[x][y]=mp[y][x]=z;
	}
	for(int k=1;k<=f;k++){
		for(int i=1;i<=f;i++){
			for(int j=1;j<=f;j++)
				if(mp[i][k]+mp[k][j]>0)
					mp[i][j]=min(mp[i][j],mp[i][k]+mp[k][j]);
		}
	}
	int s=2*f+1,t=s+1;
	LL l=0,r=0;
	for(int i=1;i<=f;i++)for(int j=1;j<=f;j++)if(mp[i][j]!=INF)r=max(r,mp[i][j]);
	while(l<=r){
		LL mid=(l+r)>>1;
		work.g.init(t+1);
		for(int i=1;i<=f;i++){
			work.g.addedge(s,i,a[i],0);
			work.g.addedge(i+f,t,b[i],0);
			work.g.addedge(i,i+f,INF,0);
		}
		for(int i=1;i<=f;i++){
			for(int j=1;j<=f;j++){
				if(i!=j&&mp[i][j]<=mid){
					work.g.addedge(i,j+f,0x3f3f3f3f,mp[i][j]);
				}
			}
		}
		int k=work.MaxFlow(s,t);
		if(k==sum){
			ANS=mid;
			r=mid-1;
		}
		else l=mid+1;
	}
	printf("%lld",ANS);
	return 0;
}*/

