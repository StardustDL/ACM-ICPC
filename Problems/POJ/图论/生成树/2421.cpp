/*
Constructing Roads
题意：有n个村庄，编号为1 ，2 ，3 ，，，n  应该建造道路使他们互相可达，有一些边已经建立了
分析：MST 
*/
#include<iostream>
#include<cstring> 
#include<algorithm>
#include<vector>
using namespace std;
const int MAXN=100;
struct edge{
	int u,v,w;
	bool operator <(const edge &t)const{
		return w<t.w;
	}
	edge(int u,int v,int w):u(u),v(v),w(w){}
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
int n,x;
vector<edge> es;
void init(){
	cin>>n;us.init();
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++){
			cin>>x;
			if(j>=i+1)es.push_back(edge(i,j,x));
		}
	cin>>n;
	for(int a,b;n;n--){
		cin>>a>>b;
		us.unions(a,b);
	}
}
int kruskal(){
	int ans=0;
	sort(es.begin(),es.end());
	for(int i=0;i<es.size();i++)
		if(us.unions(es[i].u,es[i].v))ans+=es[i].w;
	return ans;
}
int main(){
	ios::sync_with_stdio(false);
	init();
	cout<<kruskal();
	return 0;
}

