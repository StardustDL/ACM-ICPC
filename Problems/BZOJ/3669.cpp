/*
[Noi2014]魔法森林
分析：动态加边最短路。
		我们对a排序，枚举a，对于每一次枚举求b权最大值的最小值即可
		跑M遍最短路肯定超时无误 网上很多人写了LInk-Cut-Tree维护动态最小生成树，但其实 
		这里要用的最短路的动态加点（边）法 我们每加一条边 就把边的两端点入队 继续dijkstra 不用对f数组进行memset
		这方法非常快 比LCT好写了不知多少 然后这里还有剪枝
		剪枝1 每加一条边就dijkstra自然很浪费，我们把a值相同的点统统加入队列，然后dijkstra一次解决
		剪枝2 对于一条双向边 我们不必向队列中加两个点，直接在主函数中更新f值大的，能更新就加入队列
*/
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<queue> 
using namespace std;
const int MAXN=50000,MAXM=100000,INF=0x3f3f3f3f;
struct edge{
	int u,v,a,b;
}E[MAXM*2+100],es[MAXM+3];
bool cmp(edge x,edge y){
	return x.a<y.a;
}
struct node{
	int p,d;
	bool operator <(const node &t)const{
		return d>t.d;
	}
	node(int p,int d):p(p),d(d){}
};
int head[MAXN+3],nxt[2*MAXM+100],cnt=1;//注意next数组开的是M 
void addedge(int id){
	E[++cnt]=es[id];
	nxt[cnt]=head[E[cnt].u];
	head[E[cnt].u]=cnt;
	E[++cnt]=es[id];
	swap(E[cnt].u,E[cnt].v);
	nxt[cnt]=head[E[cnt].u];
	head[E[cnt].u]=cnt;
}
priority_queue<node> q;
int f[MAXN+3];
void dijkstra(){
	while(!q.empty()){
		node u=q.top();q.pop();
		if(u.d>f[u.p])continue;
		for(int i=head[u.p];i;i=nxt[i]){
			if(f[E[i].v]>max(E[i].b,f[E[i].u])){
				f[E[i].v]=max(E[i].b,f[E[i].u]);
				q.push(node(E[i].v,f[E[i].v]));
			}
		}
	}
}
int ans=INF,n,m;
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++){
		scanf("%d%d%d%d",&es[i].u,&es[i].v,&es[i].a,&es[i].b);
	}
	sort(es+1,es+m+1,cmp);
	memset(f,INF,sizeof(f));
	f[1]=0;
	for(int i=1;i<=m;i++){
		addedge(i);
		if(f[es[i].u]>f[es[i].v])  
            swap(es[i].u,es[i].v);  
        if(max(f[es[i].u],es[i].b)<f[es[i].v]){  
            f[es[i].v]=max(f[es[i].u],es[i].b);
			q.push(node(es[i].v,f[es[i].v]));  
		}
        if(es[i].a!=es[i+1].a)
            dijkstra();
        ans=min(ans,es[i].a+f[n]);
	}
	printf("%d\n",ans==INF?-1:ans); 
	return 0;
}

