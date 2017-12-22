/*
Domino Effect
���⣺����ŵ���ƣ�һЩ�ؼ��㣬��һЩ�����������������ؼ���ģ����ڸ�������һ��ͼ���Ƶ�1���ƣ�����󵹵���������ģ�
	  �ؼ��㣺�����ź�ʱ��
	  �����㣺��������������ؼ���֮�䣬���ʱ�� 
������dijkstra���ɣ������м���ɵ㣬�����õ�ʱ���Ȼ�Ǵ˱ߵ������ؼ����Ƶ�1���Ƶ����ʱ����ϴ˱ߵ�ʱ���ٳ���2
	  ���ö�ٱ߼��ɣ�ע�������ؼ���Ҫ������� 
*/
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<queue>
#include<bitset>
#include<vector> 
using namespace std;
const int INF=0x3f3f3f3f,MAXN=1000;
struct edge{
	int u,v,w;
	edge(int u,int v,int w):u(u),v(v),w(w){}
};
struct node{
	int p,d;
	node(int a,int b):p(a),d(b){}
	bool operator <(const node &t)const{
		return d<t.d;
	}
};
vector<edge> es;
vector<int> g[MAXN+3];
priority_queue<node> q;
int n;
int d[MAXN+3];
void addedge(int u,int v,int w){
	es.push_back(edge(u,v,w));
	g[u].push_back(es.size()-1);
}
bool input(){
	int m,x,y,z;
	scanf("%d %d",&n,&m);
	if(n==0&&m==0)return false;
	for(int i=1;i<=n;i++)g[i].clear();
	es.clear();
	while(m--){
		scanf("%d%d%d",&x,&y,&z);
		addedge(x,y,z);
		addedge(y,x,z);
	}
	return true;
}
void dijkstra(int s){
	while(!q.empty())q.pop();
	for(int i=1;i<=n;i++){
		d[i]=INF;
	}
	d[s]=0;q.push(node(s,0));
	while(!q.empty()){
		node t=q.top();q.pop();
		if(t.d!=d[t.p])continue;
		for(int i=0;i<g[t.p].size();i++){
			edge &e=es[g[t.p][i]];
			if(d[e.v]>d[e.u]+e.w){
				d[e.v]=d[e.u]+e.w;
				q.push(node(e.v,d[e.v]));
			}
		}
	}
}
void solve(){
	double mx1=0,mx2=0;
	int an1,an2,an3;
	for(int i=1;i<=n;i++){
		//cout<<d[i]<<endl;
		if(mx1<d[i]){
			mx1=d[i];
			an1=i;
		}
	}
	for(int i=0;i<es.size();i++){
		edge &e=es[i];
		double dist=(d[e.u]+d[e.v]+e.w)/2.0;
		if(mx2<dist){
			mx2=dist;an2=e.u;an3=e.v;
		}
	}
	an2=min(an2,an3);
	an3=max(an2,an3);
	//cout<<mx1<<" "<<mx2<<endl; 
	if(mx2>mx1){
		printf("The last domino falls after %.1f seconds, between key dominoes %d and %d.\n",mx2,an2,an3);
	}
	else {
		printf("The last domino falls after %.1f seconds, at key domino %d.\n",mx1,an1);
	}
}
int main(){
	int kase=0;
	while(input()){
		printf("System #%d\n",++kase);
		dijkstra(1);
		solve();
		puts("");
	}
	return 0;
}

