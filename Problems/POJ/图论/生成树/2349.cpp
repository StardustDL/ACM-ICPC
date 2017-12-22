/*
Arctic Network
题意：有两种不同的通信技术，有卫星通信的两个城市之间可以任意联络，但用无线电通信的城市只能和距离不超过D的城市联系。无线电的能力越高（即传输距离D越大），花费就越大。已知无线电的数目m，让求最小的D。
分析：先求MST，然后选择MST中第m大的边，
	  需要把最小生成树分成m份，即删除m-1条边，得到m个连通分量。关键是删除哪些边呢，题目要求最小的D，故把构成最小生成树的边从大到小排序，删除前m-1条边，第m条边即所要求的最小D。 
*/
#include<cstring> 
#include<algorithm>
#include<vector>
#include<cstdio>
#include<cmath>
#define sqr(x) ((x)*(x)*1.0)
#define dist(i,j) (sqrt(sqr(x[i]-x[j])+sqr(y[i]-y[j]))) 
using namespace std;
const int MAXN=500;
struct edge{
	int u,v;
	double w;
	bool operator <(const edge &t)const{
		return w<t.w;
	}
	edge(int u,int v,double w):u(u),v(v),w(w){}
};
struct uniset{
	int pa[MAXN+3];
	void init(){memset(pa,0,sizeof(pa));}
	int find(int x){
		return pa[x]==0?x:pa[x]=find(pa[x]);
	}
	bool unions(int a,int b){
		if(find(a)==find(b))return false;
		else pa[find(a)]=find(b);
		return true;
	}
}us;
vector<edge> es;vector<edge> ans;
double dis[MAXN+3][MAXN+3]; 
int x[MAXN+3],y[MAXN+3];
int s,p;
void init(){
	ans.clear();es.clear();us.init();
	scanf("%d%d",&s,&p);
	for(int i=1;i<=p;i++)scanf("%d%d",&x[i],&y[i]);
	for(int i=1;i<=p;i++){
		for(int j=1;j<i;j++){
			es.push_back(edge(i,j,dist(i,j)));
		}
	}
}
void kruskal(){
	sort(es.begin(),es.end());
	for(int i=0;i<es.size();i++)
		if(us.unions(es[i].u,es[i].v))ans.push_back(es[i]);
}
int main(){
	int T;scanf("%d",&T);
	while(T--){
		init();
		kruskal();
		printf("%.2f\n",ans[ans.size()-s].w);
	}
	return 0;
}

