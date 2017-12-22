/*
最优布线问题
*/
#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
const int MAXN=100000;
typedef long long LL;
struct edge{
	int u,v,w;
	bool operator <(const edge &e)const{
		return w<e.w;
	}
}es[MAXN+3];
int n,m,pa[MAXN+3];
int find(int x){
	return pa[x]==0?x:pa[x]=find(pa[x]);
}
bool unions(int a,int b){
	a=find(a);b=find(b);
	if(a==b)return false;
	pa[a]=b;return true;
}
LL kruskal(){
	memset(pa,0,sizeof(pa));
	sort(es+1,es+m+1);
	LL ans=0;
	for(int i=1;i<=m;i++){
		edge &e=es[i];
		if(unions(e.u,e.v))ans+=e.w;
	}
	return ans;
}
int main(){
	ios::sync_with_stdio(false);
	cin>>n>>m;
	for(int i=1;i<=m;i++)cin>>es[i].u>>es[i].v>>es[i].w;
	cout<<kruskal();
	return 0;
}
