/*
绿豆蛙的归宿
分析：期望的公式：sigma{x*p(x)}，先拓扑排序，然后逆着做：
	  opt[i]=sigma{p(i,j)*(opt[j]+w(i,j))|存在(i,j)} 
	  但是这种方法编伪了，于是改成了记忆化搜索 
*/ 
#include<iostream>
#include<vector>
#include<cstdio> 
#include<queue> 
#include<cstring> 
using namespace std;
const int MAXN=100000;
struct edge{
	int u,v,w;
};
vector<edge> es;
vector<int> g[MAXN+3];
double opt[MAXN+3]; 
void add(int u,int v,int w){
	es.push_back((edge){u,v,w});
	g[u].push_back(es.size()-1);
}
int n;
void input(){
	int m,a,b,c;
	cin>>n>>m;
	while(m-->0){
		cin>>a>>b>>c;
		add(a,b,c);
	}
}
/*int tmp[MAXN+3];
int rel[MAXN+3],cnt;
queue<int> q;
void ntopo(){
	memset(tmp,0,sizeof(tmp));
	for(int i=0;i<es.size();i++){
		tmp[es[i].v]++;
	}
	for(int i=1;i<=n;i++){
		if(tmp[i]==0)q.push(i);
	}
	cnt=n;memset(rel,0,sizeof(rel));
	while(!q.empty()){
		int u=q.front();q.pop();
		rel[cnt--]=u;
		for(int i=0;i<g[u].size();i++){
			if(--tmp[es[g[u][i]].v]==0){
				q.push(es[g[u][i]].v);
			}
		}
	}
}
double dp(){
	memset(opt,0,sizeof(opt));
	for(int i=1;i<=n;i++){
		for(int j=0;j<g[i].size();j++){
			edge &e=es[g[i][j]];
			opt[i]+=(opt[j]+e.w)/g[i].size();
		}
	}
	return opt[1];
}*/ 
double dfs(int u){
	if(opt[u]!=0)return opt[u];
	for(int i=0;i<g[u].size();i++){
		edge &e=es[g[u][i]];
		opt[u]+=dfs(e.v)+e.w;
	}
	opt[u]/=g[u].size();
	return opt[u];
}
int main(){
	input();
	//ntopo();
	memset(opt,0,sizeof(opt));
	opt[n]=1;//这样就方便初始化了，结果-1即可 
	printf("%.2lf",dfs(1)-1);
	return 0;
}
