/*
[Noi2008]志愿者招募 
分析：具体实现： 
		观察X(i)的正负，因为每次都是相邻的相减嘛，又因为每个人都是连续一段的，所以正号出现在第l[i]个式子中，负号出现在第r[i]+1个式子中。
		然后y[i]就更简单了，正的出现在i+1，负的出现在i，然后初始建图部分就很好打了。
	题解在下面，还有一种是线性规划。 
	例如一共需要4天，四天需要的人数依次是4,2,5,3。有5类志愿者，如下表所示：
	
	种类	1	2	3	4	5
	时间	1-2	1-1	2-3	3-3	3-4
	费用	3	4	3	5	6
	设雇佣第i类志愿者的人数为X[i]，每个志愿者的费用为V[i]，第j天雇佣的人数为P[j]，则每天的雇佣人数应满足一个不等式，如上表所述，可以列出
	
	P[1] = X[1] + X[2] >= 4
	
	P[2] = X[1] + X[3] >= 2
	
	P[3] = X[3] + X[4] +X[5] >= 5
	
	P[4] = X[5] >= 3
	
	对于第i个不等式，添加辅助变量Y[i] (Y[i]>=0) ，可以使其变为等式
	
	P[1] = X[1] + X[2] - Y[1] = 4
	
	P[2] = X[1] + X[3] - Y[2] = 2
	
	P[3] = X[3] + X[4] +X[5] - Y[3] = 5
	
	P[4] = X[5] - Y[4] = 3
	
	在上述四个等式上下添加P[0]=0,P[5]=0，每次用下边的式子减去上边的式子，得出
	
	① P[1] - P[0] = X[1] + X[2] - Y[1] = 4
	
	② P[2] - P[1] = X[3] - X[2] -Y[2] +Y[1] = -2
	
	③ P[3] - P[2] = X[4] + X[5] - X[1] - Y[3] + Y[2] =3
	
	④ P[4] - P[3] = - X[3] - X[4] + Y[3] - Y[4] = -2
	
	⑤ P[5] - P[4] = - X[5] + Y[4] = -3
	
	观察发现，每个变量都在两个式子中出现了，而且一次为正，一次为负。所有等式右边和为0。接下来，根据上面五个等式构图。
	
	每个等式为图中一个顶点，添加源点S和汇点T。
	如果一个等式右边为非负整数c，从源点S向该等式对应的顶点连接一条容量为c，权值为0的有向边；如果一个等式右边为负整数c，从该等式对应的顶点向汇点T连接一条容量为c，权值为0的有向边。
	如果一个变量X[i]在第j个等式中出现为X[i]，在第k个等式中出现为-X[i]，从顶点j向顶点k连接一条容量为∞，权值为V[i]的有向边。
	如果一个变量Y[i]在第j个等式中出现为Y[i]，在第k个等式中出现为-Y[i]，从顶点j向顶点k连接一条容量为∞，权值为0的有向边。
	构图以后，求从源点S到汇点T的最小费用最大流，费用值就是结果。
	
	上面的方法很神奇得求出了结果，思考为什么这样构图。我们将最后的五个等式进一步变形，得出以下结果
	
	① - X[1] - X[2] + Y[1] + 4 = 0
	
	② - X[3] + X[2] + Y[2] - Y[1] - 2 = 0
	
	③ - X[4] - X[5] + X[1] + Y[3] - Y[2] + 3 = 0
	
	④ X[3] + X[4] - Y[3] + Y[4] - 2 = 0
	
	⑤ X[5] - Y[4] - 3 = 0
	
	可以发现，每个等式左边都是几个变量和一个常数相加减，右边都为0，恰好就像网络流中除了源点和汇点的顶点都满足流量平衡。
	每个正的变量相当于流入该顶点的流量，负的变量相当于流出该顶点的流量，而正常数可以看作来自附加源点的流量，负的常数是流向附加汇点的流量。因此可以据此构造网络，求出从附加源到附加汇的网络最大流，即可满足所有等式。而我们还要求sigma{x[i]*v[i]}最小，所以要在X变量相对应的边上加上权值，然后求最小费用最大流。 
*/
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<queue>
#include<vector> 
#include<cstring>
using namespace std;
const int MAXN=1000+5,INF=0x3f3f3f3f;
struct edge{
	int u,v,w,c,f;
	edge(int u,int v,int w,int c):u(u),v(v),w(w),c(c),f(0){}
};
vector<int> g[MAXN+3];
vector<edge> es;
int d[MAXN+3],p[MAXN+3];
queue<int> q;
bool inq[MAXN+3];
void addedge(int u,int v,int w,int c){
	es.push_back(edge(u,v,w,c));
	g[u].push_back(es.size()-1);
	es.push_back(edge(v,u,-w,0));
	g[v].push_back(es.size()-1);
}
bool spfa(int s,int t){
	memset(d,INF,sizeof(d));
	memset(p,-1,sizeof(p));
	memset(inq,0,sizeof(inq));
	while(!q.empty())q.pop();
	d[s]=0;q.push(s);
	while(!q.empty()){
		int u=q.front();q.pop();inq[u]=0;
		for(int i=0;i<g[u].size();i++){
			edge &e=es[g[u][i]];
			if(e.c-e.f>0 && d[e.v]>d[e.u]+e.w){
				d[e.v]=d[e.u]+e.w;
				p[e.v]=g[u][i];
				if(!inq[e.v]){q.push(e.v);inq[e.v]=1;}
			}
		}
	}
	return d[t]<INF;
}
int ans=0,n,m;
void augment(int s,int t){
	int mn=INF;
	for(int i=p[t];i!=-1;i=p[es[i].u])mn=min(mn,es[i].c-es[i].f);
	for(int i=p[t];i!=-1;i=p[es[i].u])es[i].f+=mn,es[i^1].f-=mn,ans+=mn*es[i].w;
}
int money[MAXN+3];
int main(){
	scanf("%d%d",&n,&m);
	int S=0,T=n+2;
	for(int i=1;i<=n;i++){
		scanf("%d",&money[i]);
	}
	for(int i=1;i<=n+1;i++){
		int x=money[i]-money[i-1];
		if(x>=0)addedge(S,i,0,x);
		else addedge(i,T,0,-x);
	}
	for(int i=1;i<=n;i++)addedge(i+1,i,0,INF);
	for(int i=1,a,b,c;i<=m;i++){
		scanf("%d%d%d",&a,&b,&c);
		addedge(a,b+1,c,INF);
	}
	while(spfa(S,T))augment(S,T);
	printf("%d\n",ans);
	return 0;
}

