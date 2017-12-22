/*
[ZJOI2006]物流运输trans
分析：最短路预处理+DP 
*/
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<queue>
#include<vector>
#include<bitset>
using namespace std;
const int MAXN=100,MAXM=20,INF=0x3f3f3f3f;
struct edge{
    int u,v,w;
    edge(int u,int v,int w):u(u),v(v),w(w){}
};
vector<int> g[MAXM+3];
vector<edge> es;
void addedge(int u,int v,int w){
    es.push_back(edge(u,v,w));
    g[u].push_back(es.size()-1);
    es.push_back(edge(v,u,w));
    g[v].push_back(es.size()-1);
}
int dis[MAXM+3],n,m,k,e,d;
vector<int> pt,bg,ed;
struct node{
    int p,d;
    bool operator <(const node &t)const{
        return d>t.d;
    }
    node(int p,int d):p(p),d(d){}
};
priority_queue<node> q;
bitset<MAXN+3> inc;
int dijkstra(int s,int t){
    memset(dis,INF,sizeof(dis));
    dis[s]=0;
    while(!q.empty())q.pop();
    q.push(node(s,0));
    while(!q.empty()){
        node u=q.top();q.pop();
        if(u.d>dis[u.p])continue;
        for(int i=0;i<g[u.p].size();i++){
            edge &e=es[g[u.p][i]];
            if(inc[e.v]==0&&dis[e.v]>dis[u.p]+e.w){
            	dis[e.v]=dis[u.p]+e.w;
                q.push(node(e.v,dis[e.v]));
    	    }
    	}
    }
    return dis[t];
}
void build(int l,int r){
    inc=0;
    for(int i=0;i<d;i++){
        //if(bg[i]<=l&&ed[i]>=r)inc[pt[i]]=1;
        if(bg[i]>r||ed[i]<l)continue;
        inc[pt[i]]=1;
    }
}
void input(){
    scanf("%d%d%d%d",&n,&m,&k,&e);
    for(int i=1,a,b,c;i<=e;i++){
        scanf("%d%d%d",&a,&b,&c);
        addedge(a,b,c);
    }
    scanf("%d",&d);
    for(int i=1,a,b,c;i<=d;i++){
        scanf("%d%d%d",&a,&b,&c);
        pt.push_back(a);
        bg.push_back(b);
        ed.push_back(c);
    }
}
int opt[MAXN+3],mindist[MAXN+3][MAXN+3];
int solve(){
    for(int i=1;i<=n;i++){
        for(int j=i;j<=n;j++){
                build(i,j);mindist[i][j]=dijkstra(1,m);
        }
    }
    memset(opt,INF,sizeof(opt));
    for(int i=1;i<=n;i++){
        opt[i]=mindist[1][i]<INF?mindist[1][i]*i:INF;
        for(int j=2;j<=i;j++){
            if(opt[j-1]>=INF||mindist[j][i]>=INF)continue;
            opt[i]=min(opt[i],opt[j-1]+mindist[j][i]*(i-j+1)+k);
        }
    }
    return opt[n];
}
int main(){
    input();
    printf("%d\n",solve());
    return 0;
}

