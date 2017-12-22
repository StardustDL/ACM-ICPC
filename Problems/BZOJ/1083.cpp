/*
[SCOI2005]繁忙的都市
分析：最小生成树中的最大边 
*/ 
#include<cstdio> 
#include<algorithm>
#include<vector>
#include<cstring>
using namespace std;
const int MAXN=300;
struct edge{
	int u,v,w;
	bool operator <(const edge &e)const{return w<e.w;}
};
struct uniset{
	int pa[MAXN+3];
	void init(){memset(pa,0,sizeof(pa));}
	int find(int x){return pa[x]==0?x:pa[x]=find(pa[x]);}
	bool unions(int x,int y){
		x=find(x);y=find(y);
		if(x!=y)pa[x]=y;
		return x!=y;
	}
}S;
vector<edge> es;
int n;
void input(){
	int m,u,v,c;
	scanf("%d %d",&n,&m);
	while(m--){
		scanf("%d %d %d",&u,&v,&c);
		es.push_back((edge){u,v,c}); 
	}
}
int kruskal(){
	sort(es.begin(),es.end());
	S.init();
	int ans=0;
	for(int i=0;i<es.size();i++){
		edge &e=es[i];
		if(S.unions(e.u,e.v))ans=max(ans,e.w);
	}
	return ans;
}
int main(){
	input();
	printf("%d %d",n-1,kruskal());
	return 0;
}
