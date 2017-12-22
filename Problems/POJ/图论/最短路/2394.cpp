/*
Checking an Alibi
题意：一个地方有F个农场，分别为f1,f2,...,fp。其中，f1是谷仓！有几只牛站在这些农场上，它们闲着没事干就想着去偷吃谷子。可惜，在它们吃到谷子之前M秒，有个摄像头把它们的位置拍下来了！fi与fj之间有路径连通(无向图)，并且知道走这条路径的时间t。我们还知道总共有C只牛，它们各自站在不同或者相同的农场上！让你求一下有多少头牛可能会去偷吃谷子，并按升序将它们的序号输出。
   输入:
   f(农场数目)
   p(这f个农场之间的p条路径,注意是无向图)
   c(牛的数目)  
   m(牛如果想偷吃到谷子,那么它到谷仓的最短距离必须小于或等于m)
   p条路径的信息：起点 终点 权重
   c头牛的信息(第i行即表示编号为i的牛所在的农场编号)
分析：dijkstra求最短路，然后将到谷仓的时间小于等于m的牛输出
	  有重边，但总边数是2N级别，就不管了 
*/
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<queue>
#include<bitset> 
using namespace std;
const int MAXN=500,INF=0x3f3f3f3f;
vector<int> to[MAXN+3];
vector<int> wt[MAXN+3];
void addedge(int u,int v,int w){
	to[u].push_back(v);
	wt[u].push_back(w);
}
int d[MAXN+3];
struct node{int p,d;node(int p,int d):p(p),d(d){}bool operator < (const node &t)const{return d>t.d;}};
priority_queue<node> q;
void dijkstra(int s){
	memset(d,INF,sizeof(d));
	d[s]=0;
	q.push(node(s,0));
	while(!q.empty()){
		node t=q.top();q.pop();
		if(t.d>d[t.p])continue;
		for(int i=0;i<to[t.p].size();i++){
			if(d[to[t.p][i]]>d[t.p]+wt[t.p][i]){
				d[to[t.p][i]]=d[t.p]+wt[t.p][i];
				q.push(node(to[t.p][i],d[to[t.p][i]]));
			}
		}
	}
}
int f,p,c,m;
vector<int> ans;
int main(){
	scanf("%d%d%d%d",&f,&p,&c,&m);
	for(int a,b,w;p;p--){
		scanf("%d%d%d",&a,&b,&w);
		addedge(a,b,w);
		addedge(b,a,w);
	}
	dijkstra(1);
	for(int t,i=1;i<=c;i++){
		scanf("%d",&t);
		if(d[t]<=m)ans.push_back(i);
	}
	printf("%d\n",ans.size());
	for(int i=0;i<ans.size();i++)printf("%d\n",ans[i]); 
	return 0;
}

